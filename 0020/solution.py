def fact(i):
  product = i
  for v in xrange(1, i):
    product *= v
  return product

r = fact(100)
s = 0

while r > 0:
  s += r % 10
  r /= 10

print(s)
