//
// Created by elvis on 2023/7/31.
//

#include "vector"
#include "iostream"
using namespace std;

/**
 * 移除元素
 *
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 */
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