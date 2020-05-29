# 5 3 4
# 34748

l = [3, 4]
for k in range(20):
    l.append(sum(l)%10)

r = ''.join([str(d) for d in l])
print(r)