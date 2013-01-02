def digits(n):
  d = 0
  while n > 0:
    n /= 10
    d += 1
  return d

def cycles(n):
  d = digits(n)
  for i in xrange(1, d):
    lhs = n / (10 ** i)
    rhs = n % (10 ** i)
    yield rhs * (10 ** (d - i)) + lhs
  
def the_primes():
  primes = {}
  marked = [False] * 1000000

  def declare_prime(n):
    primes[n] = True
    multiple = 1
    while n * multiple < len(marked):
      marked[n * multiple] = True
      multiple += 1

  declare_prime(2)
  for number in xrange(3, len(marked), 2):
    if not marked[number]:
      declare_prime(number)

  return primes

primes = the_primes()
s = 0
for k in primes:
  for c in cycles(k):
    if c not in primes:
      break
  else:
    s += 1
print(s)
