#include <iostream>
#include <queue>
using namespace std;

/*
here we have to construct a tree using pre and inorder traveral
for that first we have to find
  -->root
  -->left boundary
  -->right boundary

*/
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

node*Helper(int *inorder,int *preorder,int preS,int preE, int inS,int inE){

    if(inS > inE) return NULL;
    
    int rootData = preorder[preS];
    
    int rootIndex =-1;
    for(int i=inS;i<= inE;i++){
       if(inorder[i] == rootData){
           rootIndex = i;
           break;
       }
    }
    int LinS = inS;
    int LpreS = preS +1;
    int LinE = rootIndex-1;  //left boundaries
    int LpreE = LinE - LinS + LpreS; 
    int RpreS = LpreE +1;
    int RpreE = preE;
    int RinS = rootIndex+1;
    int RinE = inE;  //right boundaries

    node*root = new node(rootData);

    root->left = Helper(inorder,preorder,LpreS, LpreE, LinS,LinE);
    root->right = Helper(inorder,preorder,RpreS, RpreE, RinS,RinE);

   return root;

}

node*buildTree(int *inorder,int *preorder,int size){
  
  return Helper( inorder,preorder,0,size-1,0,size-1);
}



//////////

node* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    if(ps > pe){
        return NULL;
    }
    node* rootData = new node(preorder[ps]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == rootData->data){
            pos = i;
            break;
        }
    }
    rootData->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
    rootData->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
    return rootData;
}


node *buildTree_2(vector<int> &preorder, vector<int> &inorder) {
    return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
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
int main()
{
    
   //int inorder[] = {9,3,15,20,7};
   //int preorder[]= {3,9,20,15,7};
   //node*root = buildTree(inorder,preorder,5);
   //BFS_2(root);

  
  // 2 approach
 vector<int> inorder = {9,3,15,20,7};
 vector<int> preorder = {3,9,20,15,7};
  node*root = buildTree_2(preorder,inorder);
   BFS_2(root);

    return 0;
}