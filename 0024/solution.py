# 1: 0123456789
# 2: 0123456798
# 3: 0123456879
# 4: 0123456897
# 5: 0123456978
# 6: 0123456987
# 7: 0123457689

def permute(available, index, current):
  if len(available) == 0:
    index += 1
    if index == 1000000:
      print(current)
      exit()
  else:
    for i in xrange(len(available)):
      c = available.pop(i)
      index = permute(available, index, current + c)
      available.insert(i, c)
  return index

permute([str(i) for i in xrange(10)], 0, '')
