#include<iostream>
#include<queue>
using namespace std;

class node{
   public:
       int data;
       node*left;
       node*right;

    node(int d){
       data =d;
       right=NULL;
       left=NULL;
    }   

};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
       return NULL;
    }

    node*root =new node(d);
    root->left =buildTree();
    root->right =buildTree();

    return root;
    
}

void print(node*root){
    if(root==NULL){
      return;
    }

    cout<<root->data<<" ";
   
    print(root->left);
    print(root->right);
}

void PreOrder(node *root)    //Same if use print 
{
    if (root == NULL)
    {
        return;
    }

    // root  left  right
    cout << root->data << " ";
    PreOrder(root->left);   
    PreOrder(root->right);
}
//Inorder
void Inorder(node*root){
  if(root==NULL){
    return;
  }

  //Left root right
   Inorder(root->left);
   cout<<root->data<<" ";
   Inorder(root->right);

}
void PostOrder(node*root)
{
    if (root == NULL)
    {
        return;
    }

    //Left  right  root
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
   
}
int Tree_Height(node*root){
    if(root==NULL){
      return 0;
    }
    int Lst =Tree_Height(root->left);
    int Rst =Tree_Height(root->right);
    return max(Lst,Rst) + 1;
}
void KthLevel(node*root, int k);

void LevelOrder(node*root){   //O(k*K) not good complexity
    

    int H=Tree_Height(root);

    for(int i=0;i<=H;i++){
        KthLevel(root,i);
        cout<<endl;
    }
    return;

}

void KthLevel(node*root, int k){
    if(root==NULL){
      return;
    }
    if(k==1){
      cout<<root->data<<" ";
      return;
    }
    KthLevel(root->left,k-1);
    KthLevel(root->right,k-1);

}
/*
BFS(Breadth first search)
O(n)
in function levelorder complexity is more thats why we are using BFS

using queue

*/
void BFS(node*root){

    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        node*f=q.front();
        cout<<f->data<<", ";
        q.pop();

        if(f->left){
           q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
    return;

}
void BFS_2(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);


    while (!q.empty())
    {

        node *f = q.front();

        if(f == NULL){

           cout<<endl;
           q.pop();
           if(!q.empty()){
              q.push(NULL);

           }

        }
        else{
            cout << f->data << " ";
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
        
    }
    return;
}

int Count(node *root)
{
    /*
    it will count the total node
    O(n)
    */
if(root == NULL){
  return 0;
}

 return 1 +Count(root->left) + Count(root->right);
}

int diameter(node*root){    //O(n*n)
  if(root==NULL){
    return 0;
  }
  int h1=Tree_Height(root->left);
  int h2 = Tree_Height(root->right);
  int op1 =h1+h2;
  int op2=diameter(root->left);
  int op3=diameter(root->right);

  return max(op1 ,max(op2,op3));
}

class Pair{
    public:
    int height;
    int diameter;
};

Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
      p.diameter = p.height =0;
      return p;
    }
    //otherwise
    Pair left =fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height =max(left.height,right.height) + 1;
    p.diameter =max(left.height + right.height, max(left.diameter,right.diameter));
    return p;

}

int main(){

    node*root =buildTree();
    print(root);
    // cout<<endl;
    //8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    //1 2 10 -1 -1 5 6 -1 -1 -1 3 -1 4 -1 -1
    PreOrder(root);
    cout << endl;
    // Inorder(root);
    //cout<<endl;
    //PostOrder(root);
    //cout << endl;
    //cout<<Tree_Height(root)<<endl;
    // KthLevel(root,3);   //1 6 14

    LevelOrder(root);

    //BFS(root);
    //BFS_2(root);
    //cout<<Count(root)<<endl;

    //cout<<diameter(root)<<endl;
    //Pair p =fastDiameter(root);
   // cout<<p.height<<endl;
   // cout<<p.diameter<<endl;
    
    
    return 0;
}