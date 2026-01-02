#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * @param source: A source string
     * @param target: A target string
     * @return: An integer as index
     */
    int strStr2(string &source, string &target) {
        int base = 1000000;
        if (target.length() == 0) {
            return 0;
        }

        int tLen = target.length();
        int tHash = 0;
        for (int i = 0; i < tLen; i++) {
            tHash = (tHash  * 31 + target[i]) % base;
        }

        // 计算31^m
        int power =  1;
        for (int i = 0; i < tLen; i++) {
            power = (power * 31) % base;
        }

        int cHash = 0;
        for (int i = 0; i < source.length(); i++) {
            // 滑动窗口时，计算新加入的字符的hash值
            cHash = (cHash * 31 + source[i]) % base;
            if (i < tLen - 1) {
                continue;
            }
            // 滑动窗口时，减去出去的字符的hash值
            if (i >= tLen) {
                cHash = cHash - (source[i - tLen] * power) % base;
                if (cHash < 0) {
                    cHash += base;
                }
            }

            // double check
            if (tHash == cHash) {
                if (source.substr(i - tLen + 1, tLen).compare(target) == 0) {
                    return i - tLen + 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    string source = "abcdefg";
    string target = "abcd";
    Solution solution;
    cout << "result: " << solution.strStr2(source,target) << endl;
}