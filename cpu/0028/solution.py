i = 0
s = 1 
alter = 2
total = 1001 * 1001
for x in xrange(1, total):
  if x % alter == 0:
    s += x + 1
    i += 1
    if i % 4 == 0:
      alter += 2
print(s)
