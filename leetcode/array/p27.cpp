//
// Created by elvis on 2023/7/31.
//

#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n_idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[n_idx++] = nums[i];
            }
        }
        return n_idx;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(9);
    Solution s;
    int size = s.removeElement(nums, 0);
    cout << size << endl;
}