#include<iostream>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // 先确定行
        int start = 0;
        int end = matrix.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid][0] < target) {
                start = mid;
            } else if (matrix[mid][0] == target) {
                return true;
            } else {
                end = mid;
            }
        }

        int colmnIndex = start;
        if (matrix[end][0] <= target) {
            colmnIndex = end;
        }

        // 再确定列
        start = 0;
        end = matrix[0].size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (matrix[colmnIndex][mid] < target) {
                start = mid;
            } else if (matrix[colmnIndex][mid] == target) {
                return true;
            } else {
                end = mid;
            }
        }

        if (matrix[colmnIndex][start] == target || matrix[colmnIndex][end] == target) {
            return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 5},
        {6, 7, 8}
    };
    int target = 6;
    Solution solution;
    cout << "result: " << solution.searchMatrix(matrix, target) << endl;
}
