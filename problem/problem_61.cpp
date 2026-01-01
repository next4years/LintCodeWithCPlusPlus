#include <iostream>
#include "../common/utils.h"

using namespace std;

class Solution {
public:
    /**
     * @param a: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &a, int target) {
        if (a.empty()) {
            return {-1, -1};
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
            return {-1, -1};
        }
        return {left, right};
    }
};

int main() {
    vector<int> a = {3};
    int target = 5;
    Solution solution;
    cout << "result: " << Utils::printVector(solution.searchRange(a, target)) << endl;
}