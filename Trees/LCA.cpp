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

//Lowest common ancestor.
class Custom{
 public:
    bool haskey1;
    bool haskey2;
    node*n;   //Store the value of LCA

};
Custom* helper(node*root,node*p,node*q){
    //Base case
    if(root==NULL){
       return NULL;
    }

    Custom* leftans = helper(root->left,p,q);
    if(leftans != NULL and leftans->n != NULL){
        return leftans;
    }

    Custom *rightans = helper(root->right, p, q);
    if(rightans != NULL and rightans->n != NULL){
        return rightans;
    }

    Custom* result =new Custom();
    if(leftans != NULL and rightans != NULL){
        result->n = root;
        result->haskey1 = true;
        result->haskey2 = true;
        return result;
    }
    else if(root->data == p->data){
        result->haskey1 =true;
        result->haskey2 =(leftans)?leftans->haskey2:false or (rightans)?rightans->haskey2:false;
        if(result->haskey1 and result->haskey2){
            result->n =root;
        }
        return result;
   }
   else if (root->data == q->data)
   {
       result->haskey2 = true;
       result->haskey1 = (leftans) ? leftans->haskey1 : false or (rightans) ? rightans->haskey1 : false;
       if (result->haskey1 and result->haskey2)
       {
           result->n = root;
       }
       return result;
   }
   else if(leftans){
      return leftans;
   }
   else if (rightans)
   {
       return rightans;
   }

   return NULL;

}

node* lowestCommonAncestor(node* root,node*p,node*q){

    Custom* result = helper(root,p,q);
    if(result==NULL){
        return NULL;
    }
    else{
        return result->n;
    }


}
int main()
{
    //space - O(n)
    //time  - O(n)
    //single traversal
    node *root = buildTree();
    //3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1
    int p,q;
    

    node*lowestCommonAncestor(root,5,7);

    return 0;
}