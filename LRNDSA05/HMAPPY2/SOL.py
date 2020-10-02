# Solution:
# Number of Problems solved by a = N / a
# Number of Problems solved by b = N / b
# Number of Problems which are common for a and b = 2*(N/lcm(a, b))
# Total Problems solved = N/a + N/b - 2*(N/lcm(a, b))


def hcf(x, y):
    if x == 0:
        return y
    return hcf(y % x, x)


def lcm(x, y):
    return (x / hcf(x, y)) * y


t = int(input())

while t > 0:
    t -= 1
    n, a, b, k = map(int, input().split())
    if a == b:
        print("Lose")
        continue
    if b < a:
        # hcf function expects a <= b
        a, b = b, a
    solved_a = n // a
    solved_b = n // b
    common_ab = n // lcm(a, b)
    total_solved = solved_a + solved_b - (2 * common_ab)
    if total_solved >= k:
        print("Win")
    else:
        print("Lose")
