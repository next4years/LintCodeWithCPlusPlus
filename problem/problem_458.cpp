#include<iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        if (nums.empty()) {
            return -1;
        }

        int start = 0;
        int end = nums.size();
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[end] == target) {
            return end;
        }

        if (nums[start] == target) {
            return start;
        }

        return -1;
    }
};

int main() {
    vector<int> nums{1, 2, 2, 4, 5, 5};
    int target = 2;
    Solution solution;
    cout << "result: " << solution.lastPosition(nums, target) << endl;
}