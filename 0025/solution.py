def digits(i):
  d = 0
  while i > 0:
    i /= 10
    d += 1
  return d

def fib():
  index = 2
  i = 1
  j = 1
  while digits(j) < 1000:
    k = i + j
    i = j
    j = k
    index += 1
  return index

print(fib())
