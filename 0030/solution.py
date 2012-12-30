def digits(i):
  while i > 0:
    yield i % 10
    i /= 10
total = 0
for i in xrange(2, 1000000):
  if i == sum([digit ** 5 for digit in digits(i)]):
    print(i)
    total += i
print(total)


