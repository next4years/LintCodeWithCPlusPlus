#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param l: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &l, int k) {
        if (l.empty()) {
            return 0;
        }

        int start = 1;
        int end = l[0];
        for (int i = 0; i < l.size(); i++) {
            if (end < l[i]) {
                end = l[i];
            }
        }

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (canCutSegs(l, mid) < k) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (canCutSegs(l, end) >= k) {
            return end;
        }
        if (canCutSegs(l, start) >= k) {
            return start;
        }
        return 0;
    }

    int canCutSegs(vector<int> &l, int len) {
        int count = 0;
        for (int i = 0; i < l.size(); i++) {
            count += l[i] / len;
        }

        return count;
    }
};

int main() {
    std::vector<int> l = {232, 124, 456};
    int k = 7;
    Solution solution;
    cout << "result: " << solution.woodCut(l, k) << endl;
}
