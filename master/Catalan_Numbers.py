# @Date    : 2020-05-28 15:23:25
# @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)

n = int(input())


def catlan(n):
    res = 1
    for i in range(n + 2, 2 * n + 1):
        res *= i
    for i in range(2, n + 1):
        res //= i
    return int(res)


print(catlan(n))
