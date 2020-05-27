#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *height = new int[n + 1];

    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    int left = 0;
    int right = n - 1;
    int area = 0;
    while (left < right)
    {
        area = max(area, (min(height[left], height[right]) * (right - left)));

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << area << endl;

    return 0;
}
