solset = set()
for i in xrange(2, 101):
  for j in xrange(2, 101):
    solset.add(i ** j)
print(len(solset))
