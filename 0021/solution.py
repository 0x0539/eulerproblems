def divisor_sum(i):
  s = 0
  for d in xrange(1, i):
    if i % d == 0:
      s += d
  return s

amicable = {}

for a in xrange(1, 10000):
  b = divisor_sum(a)
  if divisor_sum(b) == a and b != a:
    amicable[a] = True
    amicable[b] = True
    print("%i, %i" % (a, b))

print(reduce(lambda mem, i: mem + i, amicable, 0))
