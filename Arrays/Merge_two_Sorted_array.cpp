class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
        int index1 = m - 1;
        int index2 = n - 1;
        for (int i = m + n - 1; i >= 0 ; --i) {
            if (index2 == - 1) {
                return;
            } else if (index1 == -1) {
                arr1[i] = arr2[index2];
                --index2;
            } else if (arr1[index1] > arr2[index2]) {
                arr1[i] = arr1[index1];
                --index1;
            } else {
                arr1[i] = arr2[index2];
                --index2;
            }
        }
    }
};