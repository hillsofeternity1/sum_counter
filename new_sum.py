num = 123
res = 0

while num > 0:
  res = res + num % 10
  num = int(num / 10)

print(res)
