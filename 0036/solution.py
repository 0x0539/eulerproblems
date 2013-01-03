def digits(i, base):
  while i > 0:
    yield i % base
    i /= base

def is_palindrome(array):
  for i in xrange(len(array)/2):
    if array[i] != array[len(array)-1-i]:
      return False
  return True

s = 0
for i in xrange(1000000):
  if is_palindrome(list(digits(i, 2))) and is_palindrome(list(digits(i, 10))):
    s += i
print(s)
