import random
t = int(input())
while(t > 0):
    n = int(input())
    a = random.randint(1,n)
    b = random.randint(1,n)
    c = random.randint(1,n)
    while(b == a or b ==-1):
        b = random.randint(1,n)
    while(c == a or c == b or c == -1):
        c = random.randint(1,n)
    res = -1
    while(True):
        print(f'? {a} {b} {c}')
        res = int(input())
        x = random.choice([a,b,c])
        if(res == 0):
            break
        if(x==a):
            a = res
        if(x==b):
            b = res
        if(x==c):
            c = res

    print(f'! {a} {b} {c}')
    t = t -1