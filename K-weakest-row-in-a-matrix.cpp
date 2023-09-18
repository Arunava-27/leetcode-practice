#include <iostream>
#include <vector>
#include <algorithm> // Include this for the sort function
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<pair<int, int>> strength; // {strength, row_index}
        
        for (int i = 0; i < m; ++i) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (mat[i][mid] == 1) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            strength.push_back({left, i});
        }
        
        // Define a custom comparison function for sorting
        sort(strength.begin(), strength.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(strength[i].second);
        }
        
        return result;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<vector<int>> mat1 = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k1 = 3;
    vector<int> result1 = solution.kWeakestRows(mat1, k1);
    vector<int> expected1 = {2, 0, 3};
    assert(result1 == expected1);

    // Test Case 2
    vector<vector<int>> mat2 = {
        {1, 0},
        {1, 0},
        {1, 1},
        {1, 1}
    };
    int k2 = 2;
    vector<int> result2 = solution.kWeakestRows(mat2, k2);
    vector<int> expected2 = {0, 1};
    assert(result2 == expected2);

    cout << "All test cases passed!" << endl;

    return 0;
}
