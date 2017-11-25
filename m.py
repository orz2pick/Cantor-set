def is_power_of_3(b):
    while b>0:
        if b%3!=0 and b!=1:
            return False
        b/=3
    return True
def check(a,l,r):
    if r-l==1:
        print("YES")
        return
    l1=l+(r-l)/3
    l2=l+2*(r-l)/3
    if l1 < a and a < l2:
        print("NO")
        return
    elif a<=l1:
        check(a,l,l1)
    elif a>=l2:
        check(a,l2,r)
def check2(a,b):
    a0=a
    if 1==a*3/b:
            print("NO")
            return 
    else:
            a=(a*3)%b
    while a!=a0:
        if 1==a*3/b:
            print("NO")
            return 
        else:
            a=(a*3)%b
    print("YES")
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
while True:
    a,b=raw_input().split('/')
    a=int(a)
    b=int(b)
    g=gcd(a,b)
    a/=g
    b/=g
    if a==b or a==0:
        print("YES")
        continue
    elif not is_power_of_3(b):
        check2(a,b)
    else:
        check(a,0,b)