#include <algorithm>
#include <iostream>

#include <cuda.h>
#include <cuda_runtime.h>

__global__ void run(int* perThreadSums, size_t numItemsPerThread, size_t numItems) {
  int sum = 0;
  int t = blockIdx.x * blockDim.x + threadIdx.x; 
  int i = t * numItemsPerThread;
  int j = i + numItemsPerThread;
  if (numItems < j) {
    j = (int) numItems;
  }
  for (int k = i; k < j; k++) {
    sum += k * ((k % 3 == 0) || (k % 5 == 0));
  }
  perThreadSums[t] = sum;
}

int main() {
  size_t numItems = 1000;
  size_t numThreadsPerBlock = 128;
  size_t numItemsPerThread = 8;
  size_t numItemsPerBlock = numThreadsPerBlock * numItemsPerThread;
  size_t numBlocks = numItems / numItemsPerBlock;
  if (numItems % numItemsPerBlock != 0) {
    numBlocks++;
  }
  size_t numThreads = numThreadsPerBlock * numBlocks;
  
  int* perThreadSumsDevice;
  int perThreadSumsHost[numThreads];
  cudaMalloc((void **)&perThreadSumsDevice, sizeof(int)*numThreads);

  run<<<numBlocks, numThreadsPerBlock>>>(perThreadSumsDevice, numItemsPerThread, numItems);

  cudaMemcpy(perThreadSumsHost, perThreadSumsDevice, sizeof(int)*numThreads, cudaMemcpyDeviceToHost);
  int sum = 0;
  for (int i = 0; i < numThreads; i++) {
    sum += perThreadSumsHost[i];
  }
  std::cout << sum << std::endl;
  cudaFree(perThreadSumsDevice);
}
