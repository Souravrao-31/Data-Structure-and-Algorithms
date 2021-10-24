#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> mynos = { 11,22,33,44,55,22,22,33,44,55};

	cout << "Original array of values\n";
	for (auto val : mynos)
	{
		cout << val << " ";
	}
	cout << endl;

	//replace all occurrences of 22 by 20
	cout << "\nReplaced all occurrences of 22 by 20\n";
	replace(mynos.begin(), mynos.end(), 22, 20);
	
	for (auto val : mynos)
	{
		cout << val << " ";
	}
	cout << endl;

	//replace all occurrences of 44 by 40
	cout << "\nReplaced all occurrences of 44 by 40\n";
	replace(mynos.begin(), mynos.end(), 44, 40);

	for (auto val : mynos)
	{
		cout << val << " ";
	}
	cout << endl;

	return 0;
}