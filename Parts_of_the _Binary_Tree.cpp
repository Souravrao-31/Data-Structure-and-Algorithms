#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

struct node{
string data;
struct node* left;
struct node* right;
};
struct node*newNode(string data){
	struct node* node= new struct node();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}
int main(){

	int n;
	bool lt=true;
	string oh;
	while(lt){
	cout<<"_________________________________________________"<<endl;
	cout<<"|                  MAIN MENU                    |"<<endl;
	cout<<"|                 -----------                   |"<<endl;
	cout<<"| [1] Root: A,                                  |"<<endl<<"| LeftTree: A,B,D,E,F RightTree:A,C,G,H,J,K,L   |"<<endl<< "| LeftSuccessor: A,B,E RightSuccessor: A,C,H,J  |"<<endl<<"| Terminology1: D,F Terminology2:G,L,K          |"<<endl<<"|                                               |"<<endl;
	cout<<"| [2] Root: A,                                  |"<<endl<<"| LeftTree: A,B,D,E RightTree:A,C,F             |"<<endl<< "| LeftSuccessor: A,B RightSuccessor: A,C        |"<<endl<<"| Terminology1: D,E Terminology2: F             |"<<endl;
	cout<<"|_______________________________________________|"<<endl;
	cout<<"Please select no.: ";
	cin>>n;

	switch(n){
	
	case 1:{
	struct node* newRoot=newNode("A");
	
	cout<<"\t\t\t  " << newRoot->data<<endl;
	cout<<"\t\t        " << "/"<<"   "<<"\\"<<endl;
	newRoot->left=newNode("B");
	newRoot->right=newNode("C");
	cout<<"\t\t      "<<newRoot->left->data<<"       "<<newRoot->right->data<<endl;
	cout<<"\t            "<<"/"<<"   "<<"\\"<<"   "<<"/"<<"   "<<"\\"<<endl;
	newRoot->left->left=newNode("D");
	newRoot->left->right=newNode("E");
	newRoot->right->left=newNode("G");
	newRoot->right->right=newNode("H");
	cout<<"\t           "<<newRoot->left->left->data<<"     "<<newRoot->left->right->data<<" "<<newRoot->right->left->data<<"     "<<newRoot->right->right->data<<endl;
	cout<<"\t\t        "<<"/"<<"      "<<"/"<<"   "<<"\\"<<endl;
	newRoot->left->right=newNode("F");
	newRoot->right->left=newNode("J");
	newRoot->right->right=newNode("K");
	
	cout<<"\t\t       "<<newRoot->left->right->data<<"      "<<newRoot->right->left->data<<"     "<<newRoot->right->right->data<<endl;
	cout<<"\t\t\t     "<<"/";
	newRoot->right->left=newNode("L");
	cout<<"\t           "<<endl;
	cout<<"\t\t\t    "<<newRoot->right->left->data<<endl<<endl;
	cout<<"PREORDER: A, B, D, E, C, G, H, J, L, K"<<endl<< "INORDER: D, B, E, A, G, C, L, J, H, K" <<endl<< "POSTORDER: D, E, B, G, L, J, K, H, C, A"<<endl<<endl;

		   }
		   break;
		   
	case 2:{

struct node* newRoot=newNode("A");
	cout<<"\t\t\t  "<<newRoot->data<<endl;
	cout<<"\t\t        " << "/"<<"   "<<"\\"<<endl;
	newRoot->left=newNode("B");
	newRoot->right=newNode("C");
	cout<<"\t\t      "<<newRoot->left->data<<"       "<<newRoot->right->data<<endl;
	cout<<"\t            "<<"/"<<"   "<<"\\"<<"   "<<"/"<<endl;
	newRoot->left->left=newNode("D");
	newRoot->left->right=newNode("E");
	newRoot->right->left=newNode("F");
	cout<<"\t\t   "<<newRoot->left->left->data<<"    "<<newRoot->left->right->data<<"   "<<newRoot->right->left->data<<"   "<<endl<<endl;
	cout<<"PREORDER: A, B, D, E, C, F"<<endl<< "INORDER: D, B, E, A, F, C" <<endl<< "POSTORDER: D, E, B, F, C, A"<<endl<<endl;	   
		   }
	}
cout<<"Go to main?[Y/N]: ";
		   cin>>oh;
		   if(oh=="Y"||oh=="y"){
			   
		   }else{

			   lt=false;
		   }
		   system("cls");
		   }
	system("pause");
}
