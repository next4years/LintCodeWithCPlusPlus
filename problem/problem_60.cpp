#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param a: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &a, int target) {
        if (a.empty()) {
            return 0;
        }

        int left = 0;
        int right = a.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (a[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (a[right] == target) {
            return right;
        }
        if (a[left] == target) {
            return left;
        }
        if (a[left] > target) {
            return left;
        }
        if (a[right] < target) {
            return right + 1;
        }
        return left + 1;
    }
};

int main() {
    vector<int> nums = {1};
    int target = 0;
    Solution solution;
    cout << "result: " << solution.searchInsert(nums, target) << endl;
}
