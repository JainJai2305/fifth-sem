print("enter the limits l and r")
l=int(input())
r=int(input())

j=0
for i in range (l,r+1) :
    if i in range(1,100) and i%11 == 0  :
        continue
    if i in range(100,1000) and i%111 == 0  :
        continue
    if i in range(1000,10000) and i%1111 == 0  :
        continue
    print(i,end=" ")

