#include <iostream>

#include "../common/utils.h"

using namespace std;

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        if (nums.empty()) {
            return;
        }
        // 先找到翻转点
        int pos = searchPoint(nums);
        if (pos == 0) {
            return;
        }
        cout << pos << endl;
        // 三步翻转法
        rorateNums(nums, 0, pos - 1);
        rorateNums(nums, pos, nums.size() - 1);
        rorateNums(nums, 0, nums.size() - 1);
    }

    void rorateNums(vector<int> &nums, int l, int r) {
        while (l < r) {
            int a = nums[l];
            nums[l++] = nums[r];
            nums[r--] = a;
        }
    }

    int searchPoint(vector<int> &nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[index] >= nums[i]) {
                index = i;
            }
        }
        return index;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Solution solution;
    solution.recoverRotatedSortedArray(nums);
    cout << "result: " << Utils::printVector(nums) << endl;
}
