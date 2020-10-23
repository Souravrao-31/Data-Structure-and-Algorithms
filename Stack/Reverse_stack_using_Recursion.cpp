#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s, int x)
{
	if(s.empty())   // since we need to insert at bottom so s should be empty 
	{
		s.push(x);
		return;
	}

	int y = s.top();
	s.pop();
	insert_at_bottom(s, x);
	s.push(y);
}

void reverse(stack<int> &s)
{
	if(s.empty())
		return;

	int x = s.top();   // remove last ele
	s.pop();

	reverse(s);  // now reverse remaining stack by recursion

	insert_at_bottom(s, x);    // the removed element should now be at bottom
}

int main() 
{
	int n;
	cin >> n;

	stack<int> s;

	for(int i = 0; i < n; i++)
	{	
		int x;
		cin >> x;
		s.push(x);
	}

	reverse(s);

	while(!s.empty())
	{
		cout << s.top() <<endl;
		s.pop();
	}
}