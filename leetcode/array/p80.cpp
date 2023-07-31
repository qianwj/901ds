//
// Created by elvis on 2023/7/31.
//


#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n_idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (n_idx < 2 || nums[i] != nums[n_idx - 2]) {
                nums[n_idx++] = nums[i];
            }
        }
        return n_idx;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    int size = s.removeDuplicates(nums);
    for (int i = 0; i < size; i++) {
        cout << nums[i] << endl;
    }
}