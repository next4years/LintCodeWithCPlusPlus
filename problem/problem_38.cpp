#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        // 根据矩阵的特性，从左下角开始搜索
        int row = matrix.size() - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col <= matrix[0].size() - 1) {
            // 当前值大于等于target时，向上走
            if (matrix[row][col] > target) {
                row--;
            } else if (matrix[row][col] == target) {
                count++;
                row--;
            } else {
                // 当前值小于target时，向右走
                col++;
            }
        }

        return count;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {2, 4, 7, 8},
        {3, 5, 9, 10}
    };
    int target = 10;
    Solution solution;
    cout << "result: " << solution.searchMatrix(matrix, target) << endl;
}