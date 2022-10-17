
// link to problem: https://leetcode.com/problems/container-with-most-water/
// problem number: 11

// solution:
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        int n = height.size();
        int width;
        int start = 0;
        int end = n - 1;
        int val;
        while (start < end)
        {
            width = end - start;
            int val = min(height[start], height[end]);
            int area = width * val;
            if (max < area)
            {
                max = area;
            }
            if (height[start] < height[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return max;
    }
};