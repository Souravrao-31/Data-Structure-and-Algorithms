#include<bits/stdc++.h>
using namespace std;


class node
{
    public:
    int data;
    int hd;
    node*left;
    node*right;
    public:
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
        hd=INT_MAX;
    }
};


node *buildtree()
{
    int count=0;
    int d;
    queue<node*> q;

    cin>>d;
    node *root=new node(d);
    node *cur=root;
    root=cur;

    while(1)
    {
        cin>>d;
        if(d!=-1)
        {
            if(count==0)
            {
                cur->left=new node(d);
                count++;
                q.push(cur->left);
        
            }

            else if(count==1)
            {
                cur->right=new node(d);
                q.push(cur->right);
                
                count=0;
                
                if(q.front())
                cur=q.front();
                
                q.pop();
            }
        } 

        else if(d==-1)
        {
            if(count==0)
            count++;

            else
            {
                count=0;
                if(q.front())
                cur=q.front();

                q.pop();
            }
        }       

        if(q.empty())
        return root;

        
    }

}



void topview(node*root)
{
    if(root==NULL)
        return;
    
    queue<node*>q;
    map<int ,int> m;
    int hd=0;
    root->hd=hd;
    q.push(root);
    while(q.size())
    {
        hd=root->hd;
        if(m.count(hd)==0)// count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        {
            m[hd]=root->data;
        }
        if(root->left)
        {
            root->left->hd=hd-1;
            q.push(root->left);
        }
         if(root->right)
        {
            root->right->hd=hd+1;
            q.push(root->right);
        }
        q.pop();
        root=q.front();


    }
     for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }
}
int main() {
    node*root=buildtree();

    //1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
	topview(root);

	return 0;
}
