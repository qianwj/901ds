//
// Created by elvis on 2023/7/31.
//


#include "vector"
#include "iostream"
using namespace std;

/**
 * 删除排序数组中的重复项 II
 *
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 */
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