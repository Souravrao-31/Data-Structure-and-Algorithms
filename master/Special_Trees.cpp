/*
* @Date    : 2020-05-05 12:41:46
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *createBT(int a[], int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int max_index = max_element(a + s, a + (e + 1)) - a;
    node *root = new node(a[max_index]);
    root->left = createBT(a, s, max_index - 1);
    root->right = createBT(a, max_index + 1, e);
    return root;
}
void InOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
int main()
{
    node *root = NULL;
    int n;
    cin >> n;
    int a[10005];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    root = createBT(a, 0, n - 1);
    InOrder(root);
    cout << endl;
    return 0;
}
