def proper_divisors(i):
  d = []
  for j in xrange(1, i):
    if i % j == 0:
      d.append(j)
  return d

def abundant(i):
  return sum(proper_divisors(i)) > i

slist = set()

alist = [i for i in xrange(1, 28124) if abundant(i)]
for a in alist:
  for b in alist:
    slist.add(a+b)

s = 0
for n in xrange(1, 28124):
  if n not in slist:
    s += n

print(s)
