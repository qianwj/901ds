//
// Created by elvis on 2023/7/31.
//

#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] != 0) {
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }
            }
        }
    }

    // 时间最优
    void moveZeroes2(vector<int>& nums) {
        int n_idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[n_idx++] = nums[i];
            }
        }
        for (int j = n_idx; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }

    // 空间最优
    void moveZeroes3(vector<int>& nums) {
        int slow = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                int temp = nums[i];
                nums[i] = nums[slow];
                nums[slow] = temp;
                slow++;
            }
        }
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
    s.moveZeroes3(nums);
    for (int n : nums) {
        cout << n << endl;
    }
}