names = sorted([name.strip('"') for name in open('names.txt', 'r').read().split(',')])
total = 0

for i in xrange(len(names)):
  name = names[i]
  score = 0
  for char in name:
    value = ord(char) - 64
    score += value
  score *= i + 1
  total += score
 
print(total)
