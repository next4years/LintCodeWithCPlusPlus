#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param a: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &a, int target) {
        if (a.empty()) {
            return -1;
        }

        int start = 0;
        int end = a.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (a[mid] >= a[start]) {
                if (a[mid] >= target && target >= a[start]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                if (a[mid] <= target && target <= a[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }

        if (a[start] == target) {
            return start;
        }
        if (a[end] == target) {
            return end;
        }
        return -1;
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    int target = 1;
    Solution solution;
    cout << "result: " << solution.search(nums, target) << endl;
}