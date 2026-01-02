#include <iostream>
#include <stdnoreturn.h>

using namespace std;
class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        if (pages.empty()) {
            return 0;
        }

        int start = pages[0];
        int end = 0;
        for (int i = 0; i < pages.size(); i++) {
            start = max(start, pages[i]);
            end += pages[i];
        }

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (howManyK(pages, mid) > k) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (howManyK(pages, end) == k) {
            return end;
        }
        return start;
    }

    int howManyK(vector<int> &pages, int maxPages) {
        int k = 0;
        int pagesNum = 0;
        for (int i = 0; i < pages.size(); i++) {
            if (pagesNum + pages[i] > maxPages) {
                k++;
                pagesNum = 0;
            }
            pagesNum += pages[i];
        }

        if (pagesNum <= maxPages) {
            k++;
        }
        return k;
    }
};

int main() {
    vector<int> pages{3};
    int k = 2;
    Solution solution;
    cout << "result: " << solution.copyBooks(pages, k) << endl;
}