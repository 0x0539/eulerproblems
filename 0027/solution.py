def prime(v):
  if v % 2 == 0:
    return False
  for i in xrange(3, abs(v), 2):
    if v % i == 0:
      return False
  return True

memo = {}
def mprime(v):
  if v not in memo:
    memo[v] = prime(v)
  return memo[v]

def primes(a, b):
  i = 0
  while True:
    n = i ** 2 + a * i + b
    if mprime(n):
      yield n
    else:
      break
    i += 1

best = 0
best_a = 0
best_b = 0
for a in xrange(-9999, 10000):
  print(a)
  for b in xrange(-9999, 10000):
    value = len(set(primes(a, b)))
    if value > best:
      best = value
      best_a = a
      best_b = b

print("(%s, %s) == %s, %s primes" % (best_a, best_b, best_a*best_b, best))
print(set(primes(best_a, best_b)))
print(len(memo))
