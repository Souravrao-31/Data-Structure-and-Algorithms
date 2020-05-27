#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}
void print(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    print(root->left);
    print(root->right);
}
class HBpair{
 public:
 int height;
 bool balance;

};
HBpair Height_Balanced(node*root){
   HBpair p;
   if(root == NULL){
     p.height=0;
     p.balance=true;
     return p;
   }
   //Recurssive Case
   HBpair left  = Height_Balanced(root->left);
   HBpair right = Height_Balanced(root->right);
  
   p.height = max(left.height,right.height) + 1;

   if(abs(left.height - right.height) <= 1 && left.balance && right.balance){
      p.balance=true;
   }
   else{
       p.balance=false;
   }
   return p;

}

int main()
{

    node *root = buildTree();
    if(Height_Balanced(root).balance){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
    //8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    //1 2 3 -1 -1 4 -1 -1 5 -1 -1
    //1 2 3 -1 -1 -1 -1 4 -1 -1 5 -1 -1
    return 0;
}