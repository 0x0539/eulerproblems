target = 200

denoms = [1, 2, 5, 10, 20, 50, 100, 200]
ways = [[1 if d == 1 else 0 for d in denoms]]
for i in xrange(1, target+1):
  i_ways = []
  for j in xrange(len(denoms)):
    denom = denoms[j]
    total = 0
    if i - denom >= 0:
      prev_ways = ways[i - denom]
      for e in xrange(j+1):
        total += prev_ways[e]
    i_ways.append(total)
  ways.append(i_ways)

print(sum(ways[target]))
