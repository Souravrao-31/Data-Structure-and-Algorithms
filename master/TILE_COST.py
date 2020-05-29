test = int(input())
li = []
for _ in range(test):
    a, b, c, l, r = map(int, input().split())
    cost = 0
    t = (r*(r+1)*((2*r)+1))//6
    if l > 1:
        x = l-1
        z = (x*(x+1)*((2*x)+1))//6
        t -= z
    cost += a*t
    t = (r*(r+1))//2
    if l > 1:
        x = l-1
        z = (x*(x+1))//2
        t -= z
    cost += b*t
    t = c*(r-l+1)
    cost += t
    print(cost % ((10**9)+7))
