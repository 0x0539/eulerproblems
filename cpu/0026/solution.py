def digits(n, d):
  idx = 0
  nds = {}
  while n > 0:
    n *= 10
    dis = str(n) + '-' + str(d)
    if dis in nds:
      yield ('repeat', nds[dis])
    nds[str(n) + '-' + str(d)] = idx
    idx += 1
    if n > d:
      yield ('digit', n / d)
      n = n % d
    else:
      yield ('digit', 0)

def cycle(i):
  result = []
  for t, v in digits(1, i):
    if t == 'digit':
      result.append(v)
    else:
      return len(result) - v
  return 0

longest = 0
arglong = 0
for i in xrange(1, 1000):
  value = cycle(i)
  if value > longest:
    longest = value
    arglong = i
print(arglong)
