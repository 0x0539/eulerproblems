from collections import Counter
from math import sqrt, ceil

def permutations(items):
  if len(items) == 1:
    yield [items[0]]
  else:
    tried = set()
    for i in xrange(len(items)):
      if items[i] in tried:
        continue
      item = items.pop(i)
      tried.add(item)
      for permutation in permutations(items):
        yield [item] + permutation
      items.insert(i, item)

def intize(ary):
  return int(reduce(lambda x, y: x + y, ary, ''))

digits = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
seen = set()
answer = 0

for perm in permutations(digits):
  for e in xrange(2, len(perm)-1):
    for t in xrange(1, e):
      m1 = intize(perm[0:t])
      m2 = intize(perm[t:e])
      pr = intize(perm[e:])
      if m1 * m2 == pr and pr not in seen:
        answer += pr
        seen.add(pr)
        print(str(m1) + '*' + str(m2) + '=' + str(pr))

print(answer)
