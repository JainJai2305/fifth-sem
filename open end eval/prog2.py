def uniq (i) :
    ls=[]
    a=1
    while i!=0 :
        j=i%10
        if j in ls :
            a=-1 
            break
        ls.append(j)
        i=int(i/10)
    return a


print("enter the limits l and r")
l=int(input())
r=int(input())

j=0
for i in range (l,r+1) :
    if uniq(i) == -1 : continue
    print(i,end=" ")
