//
// Created by elvis on 2023/7/31.
//
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ridx = 0;
        int bidx = nums.size() - 1;
        int i = 0;
        while (ridx < bidx) {
            switch (nums[i]) {
                case 0:
                    swap(nums, ridx++, i);
                    break;
                case 2:
                    bidx--;
                    break;
            }
            i++;
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    for (int n : nums) {
        cout << n << ",";
    }
    cout << endl;
    Solution s;
    s.sortColors(nums);
    for (int n : nums) {
        cout << n << ",";
    }
    cout << endl;
}