#include<bits/stdc++.h>
using namespace std;
void Order(int N,int E,int H,int A,int B,int C,int Z[])
{
	int cost=0;
    for(int i=0;i<3;i++)
    {
       // print("cost", "", cost, '' ,"N",N)
          
        if (B==Z[i] && N>0)
        {
            int CM=(H/3);
            if (CM>N)
             {   
             	CM=N; 
             }
            cost=cost+(CM*B);
            H=H-(CM*3);
           N=N-CM ;
          }  
           if (A==Z[i] && N>0)
        {
            int O=(E/2);
            if( O>N)
            {
                O=N ;
            }
            cost=cost+(O*A); 
            E=E-(O*2);
            N=N-O;
        } 
        if (C==Z[i] && N>0)
           { 
           	int CC=min(E,H);
            if (CC>N)
              {  CC=N;
              } 
            cost=cost+CC*C;
            E=E-CC;
            H=H-CC;
            N=N-CC;
        }
    }
    cout<<cost<<endl; 


}
void possibility(int N,int E,int H,int A,int B,int C,int Z[])
{
int N1=N;
int E1=E;
int H1=H;
int A1=A;
int B1=B;
int C1=C;
	int Cc=min(E,H);
	E=E-Cc;
	H=H-Cc;

	int Cm=(H/3);
	H=H-(Cm*3);

	int o=(E/2);
	E=E-(o*2);

	int Final=Cc+Cm+o;
	if(Final>N)
	{
	//	cout<<"Done"<<endl;
		Order( N1, E1, H1, A1, B1, C1, Z);
	}
	else{ cout<<"-1"<<endl;}
}


int main()
{ 
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

int T,N,E,H,A,B,C;
cin>>T;
int z[3];
while(T--> 0)
{
cin>>N>>E>>H>>A>>B>>C;

 z[0]= A;
 z[1] = B;
 z[2] = C;
sort(z,z+3);
// for(int i=0;i<3;i++)
// {
// 	cout<<z[i]<<" ";
// }
possibility( N, E, H, A, B, C,z);

}

return 0;
}
