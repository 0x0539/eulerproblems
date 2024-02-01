#include <algorithm>
#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>

__device__ int get_digits(uint32_t* x, uint32_t n) {
  int d = 0;
  while (n > 0) {
    x[d] = n % 10;
    n /= 10;
    d++;
  }
  return d;
}

__global__ void run(uint32_t* perBlockResult) {
  __shared__ uint32_t maxPalindrome;
  int x = blockIdx.x * blockDim.x + threadIdx.x;
  int y = blockIdx.y * blockDim.y + threadIdx.y;
  if (threadIdx.x == 0 && threadIdx.y == 0) {
    maxPalindrome = 0;
  }
  __syncthreads();
  uint32_t n = x * y;
  uint32_t digits[6] = {0};
  uint32_t d = get_digits(digits, n);
  bool palindrome = true;
  for (int i = 0; i < d / 2; i++) {
    int r = i;
    int l = d - 1 - i;
    palindrome = palindrome && (digits[r] == digits[l]);
  }
  if (palindrome && x < 1000 && y < 1000) {
    atomicMax(&maxPalindrome, n);
  }
  if (threadIdx.x == 0 && threadIdx.y == 0) {
    perBlockResult[blockIdx.x * gridDim.y + blockIdx.y] = maxPalindrome;
  }
}


int main() {
  dim3 blockDim = dim3(16, 16);
  dim3 gridDim = dim3(64, 64);  // 64 * 16 = 1024 (>999)

  size_t numBlocks = sizeof(uint32_t) * gridDim.x * gridDim.y;

  uint32_t* perBlockResultDevice;
  cudaMalloc((void **)&perBlockResultDevice, sizeof(uint32_t) * numBlocks);

  std::cout << "running with numBlocks " << numBlocks << std::endl;

  run<<<gridDim, blockDim>>>(perBlockResultDevice);

  std::cout << "done" << std::endl;

  uint32_t* perBlockResultHost = (uint32_t*)malloc(sizeof(uint32_t) * numBlocks);
  cudaMemcpy(perBlockResultHost, perBlockResultDevice, sizeof(uint32_t) * numBlocks, cudaMemcpyDeviceToHost);
  
  uint32_t maxPalindrome = 0;
  for (int i = 0; i < gridDim.x; i++) {
    for (int j = 0; j < gridDim.y; j++) {
      uint32_t p = perBlockResultHost[i * gridDim.y + j];
      if (p > maxPalindrome) {
        maxPalindrome = p;
      }
    }
  }

  std::cout << maxPalindrome << std::endl;

  cudaFree(perBlockResultDevice);
  free(perBlockResultHost);
}
