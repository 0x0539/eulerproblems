fact = [1]
for i in xrange(1, 10):
  fact.append(fact[-1]*i)

def sfact(n):
  s = 0
  while n > 0:
    s += fact[n % 10]
    n /= 10
  return s

s = 0
for i in xrange(10, 10000000):
  if i == sfact(i):
    s += i
print(s)
