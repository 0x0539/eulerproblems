i = 2 ** 1000
s = 0
while i > 0:
        s += i % 10
        i /= 10
print(s)
