#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param a: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &a) {
        if (a.size() == 3) {
            return 1;
        }

        int start = 1;
        int end = a.size() - 2;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if ((a[start + 1] - a[start]) < 0 &&  (a[start-1] - a[start]) < 0) {
                return start;
            }
            if ((a[end + 1] - a[end]) < 0 &&  (a[end-1] - a[end]) < 0) {
                return end;
            }
            if ((a[start + 1] - a[start]) > 0 && (a[mid-1] - a[mid]) > 0 ) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if ((a[start + 1] - a[start]) < 0 &&  (a[start-1] - a[start]) < 0) {
            return start;
        }
        return end;
    }
};

int main() {
    vector<int> nums{1, 2, 3,2,1,2,1,2,1,21,1};
    Solution solution;
    cout << "result: " << solution.findPeak(nums) << endl;
}