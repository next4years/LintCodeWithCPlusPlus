#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        if (nums.size() == 1) {
            return nums[0];
        }

        int start = 0;
        int end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (mid - 1 >= 0 && nums[mid] > nums[mid - 1]) {
                start = mid;
            } else if (mid - 1 > 0 && nums[mid] < nums[mid - 1]) {
                end  = mid;
            } else {
                return max(nums[start], nums[end]);
            }
        }

        return max(nums[start], nums[end]);
    }
};

int main() {
    vector<int> nums{1,2};
    Solution solution;
    cout << "result: " << solution.mountainSequence(nums) << endl;
}