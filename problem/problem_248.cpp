#include <iostream>

#include "../common/utils.h"

using namespace std;

class Solution {
public:
    /**
     * @param a: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &a, vector<int> &queries) {
        sort(a.begin(), a.end());
        vector<int> result;
        for (int i = 0; i < queries.size(); ++i) {
            result.push_back(findSmallerCount(a, queries[i]));
        }

        return result;
    }

    int findSmallerCount(vector<int> &a, int target) {
        if (a.empty()) {
            return 0;
        }
        int start = 0;
        int end = a.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (a[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (a[end] < target) {
            return max(0, end + 1);
        }

        if (a[start] < target) {
            return max(0, start + 1);
        }

        return 0;
    }
};

int main() {
    vector<int> a = {1, 2, 7, 8, 5};
    vector<int> queries = {1, 8, 5};
    Solution solution;
    cout << "result: " << Utils::printVector(solution.countOfSmallerNumber(a, queries)) << endl;
}
