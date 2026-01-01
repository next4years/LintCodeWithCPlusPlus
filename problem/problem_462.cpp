#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * @param a: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(vector<int> &a, int target) {
        if (a.empty()) {
            return 0;
        }

        int start = 0;
        int end = a.size() - 1;
        // 搜索起始位置
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (a[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        int left = end;
        if (a[start] == target) {
            left = start;
        }

        // 搜索结束位置
        start = 0;
        end = a.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (a[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        int right = start;
        if (a[end] == target) {
            right = end;
        }

        if (a[left] != target && a[right] != target) {
            return 0;
        }
        return right - left + 1;
    }
};

int main() {
    vector<int> nums{1, 2, 2, 4, 5, 5};
    int target = 1;
    Solution solution;
    cout << "result: " << solution.totalOccurrence(nums, target) << endl;
}