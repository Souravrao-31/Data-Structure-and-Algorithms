def order(N,E,H,A,B,C,Z):
    cost=0
    for i in range(0,3):
       # print("cost", "", cost, '' ,"N",N)
        if (A==Z[i] and N>0):
            O=int(E/2)
            if O>N:
                O=N 
            cost=cost+O*A 
            E=int(E-(O*2))
            N=N-O
            
        if (B==Z[i] and N>0):
            CM=int(H/3)
            if CM>N:
                CM=N 
            cost=cost+CM*B
            H=H-(CM*3)
            N=N-CM 
            
        if (C==Z[i] and N>0):
            CC=min(E,H)
            if CC>N:
                CC=N 
            cost=cost+CC*C
            E=E-CC
            H=H-CC
            N=N-CC
    print(int(cost))    



def Possiblity(N,E,H,A,B,C):
    Cc=min(E,H)
    E=E-Cc
    H=H-Cc
    
    Cm=(int(H/3))
    H=H-(Cm*3)
    
    o=(int(E/2))
    E=E-(o*2)
    Final=Cc+Cm+o
    if(Final>=N):
      order(N1,E1,H1,A,B,C,Z)
    else:
        print("-1")
        
t=int(input())
while(t>0):
    s=input()
    s=s.split()
    t=t-1

    N=int(s[0])
    E=int(s[1])
    H=int(s[2])
    A=int(s[3])
    B=int(s[4])
    C=int(s[5])
    Z=[A,B,C]
    Z=sorted(Z)
    N1=N
    E1=E 
    H1=H
    
    Possiblity(N,E,H,A,B,C)