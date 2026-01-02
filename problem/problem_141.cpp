#include <complex>
#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int start = 0;
        int end = x;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (mid > (x * 1.0f) / (mid * 1.0f)) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (end <= x / end) {
            return end;
        }
        return start;
    }
};

int main() {
    int num = 1;
    Solution solution;
    cout << "result: " << solution.sqrt(num) << endl;
}