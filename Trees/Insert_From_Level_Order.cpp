#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node *left,*right;

    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

// Breadth First Search (BFS)
void BFS(node *root)
{
	queue<node*> q;
	
	q.push(root);
	q.push(NULL);	//	To print each level on new line
		
	while(!q.empty())
	{
		node *f=q.front();
		if(f==NULL)
		{
			cout<<"\n";
			q.pop();
			
			if(!q.empty())
			q.push(NULL);
		}
		
		else
		{
			cout<<f->data<<" ";
			q.pop();
		
		if(f->left)
			{
				q.push(f->left);
			}
		
		if(f->right)
			{
				q.push(f->right);
			}
		
		}
		
	}
}


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



int main()
{
    node *root=buildtree();
    
    BFS(root);


    return 0;
}