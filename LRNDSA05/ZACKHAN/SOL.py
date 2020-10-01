# Solution:
# Largest handkerchieves' size will be the largest number dividing L and B
# .i.e. Highest Common Factor of L and B


def hcf(x: int, y: int):
    if x == 0:
        return y
    else:
        return hcf(y % x, x)


t = int(input())

while t > 0:
    t -= 1
    l, b = map(int, input().split())
    if b < l:  # hcf functions expects b >= l
        l, b = b, l
    print(hcf(l, b))
