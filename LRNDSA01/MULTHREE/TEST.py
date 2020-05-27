l = [5, 5]
for k in range(20):
    l.append(sum(l)%10)

r = ''.join([str(d) for d in l])
print(r)