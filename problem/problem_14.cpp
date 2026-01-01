#include<iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        // write your code here
        if (nums.empty()) {
            return -1;
        }

        int start = 0;
        int end = nums.size();
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[start] == target) {
            return start;
        }

        if (nums[end] == target) {
            return end;
        }

        return -1;
    }
};

int main() {
    vector<int> nums{1,4,4,5,7,7,8,9,9,10};
    int target = 6;
    Solution solution;
    cout << "result: " << solution.binarySearch(nums, target) << endl;
}