#include <iostream>

#include "../common/utils.h"

using namespace std;

class Solution {
public:
    /**
     * @param s: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(vector<char> &s, int offset) {
        if (s.empty()) {
            return;
        }

        offset = offset % s.size();

        // 1. 旋转整体
        rorateStr(s, 0, s.size() - 1);
        // 2. 再旋转各部分
        rorateStr(s, 0, offset - 1);
        rorateStr(s, offset, s.size() - 1);
    }

    void rorateStr(vector<char> &s, int l, int r) {
        if (l >= r) {
            return;
        }

        while (l < r) {
            char tmp = s[l];
            s[l++] = s[r];
            s[r--] = tmp;
        }
    }
};

int main() {
    int offset = 10;
    vector<char> s = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    Solution solution;
    solution.rotateString(s, offset);
    cout << "result: " << Utils::printVector(s) << endl;
}
