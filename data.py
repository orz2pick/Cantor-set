from random import *
f=open("input.txt",'w')
for i in range(10):
    x=random()*100000
    y=random()*100000+x
    x=int(x)
    y=int(y)
    f.write(str(x)+'/'+str(y)+'\n')