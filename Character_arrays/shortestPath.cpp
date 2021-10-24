#include<iostream>
using namespace std;
int main(){
char direction[1000];
cout<<"Enter the direction First letter"<<endl;
cin.getline(direction,1000);
int x=0,y=0;
for(int i=0;direction[i]!='\0';i++){
switch(direction[i]){
case 'N':y++;break;
case 'S':y--;break;
case 'E':x++;break;
case 'W':x--;break;
}
}
cout<<"X and Y is "<<x<<" "<<y<<endl;
if(x>=0 and y>=0){
    while(y--){
        cout<<'N';
    }
    while(x--){
        cout<<'E';
    }
}
if(x<=0 and y>=0){
    while(y--){
        cout<<'N';
    }
    while(x++){
        cout<<'W';
    }
}
if(x<=0 and y<=0){
    while(y++){
        cout<<'S';
    }
    while(x++){
        cout<<'W';
    }
}
if(x>=0 and y<=0){
    while(y++){
        cout<<'S';
    }
    while(x--){
        cout<<'E';
    }
}
return 0;
}