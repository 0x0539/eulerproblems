def frac(n, d):
  for i in xrange(2, n+1):
    while n % i == 0 and d % i == 0:
      n /= i
      d /= i
  return (n, d)

def answer(n, d):
  n1 = n / 10
  n2 = n % 10
  d1 = d / 10
  d2 = d % 10
  if n2 == 0 and d2 == 0:
    return False # trivial
  if n1 == d1 and frac(n2, d2) == frac(n, d):
    return True
  elif n1 == d2 and frac(n2, d1) == frac(n, d):
    return True
  elif n2 == d1 and frac(n1, d2) == frac(n, d):
    return True
  elif n2 == d2 and frac(n1, d1) == frac(n, d):
    return True
  return False

result = []
for n in xrange(10, 100):
  for d in xrange(n + 1, 100):
    if answer(n, d):
      result.append(frac(n, d))

n = 1
d = 1
for (ni, di) in result:
  n *= ni
  d *= di

print(frac(n, d))
