#include <iostream>

#include "../common/utils.h"

using namespace std;

class Solution {
public:
    /**
     * @param a: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &a) {
        if (a.empty()) {
            return;
        }

        vector<int> temp(a.size());
        mergeSort(a, 0, a.size() - 1, temp);
    }

    void mergeSort(vector<int> &a, int start, int end, vector<int> &temp) {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;
        mergeSort(a, start, mid, temp);
        mergeSort(a, mid + 1, end, temp);
        merge(a, start, end, temp);
    }

    void merge(vector<int> &a, int start, int end, vector<int> &temp) {
        int mid = start + (end - start) / 2;
        int leftIndex = start;
        int rightIndex = mid + 1;
        int index = leftIndex;

        while (leftIndex <= mid && rightIndex <= end) {
            if (a[leftIndex] < a[rightIndex]) {
                temp[index++] = a[leftIndex++];
            } else {
                temp[index++] = a[rightIndex++];
            }
        }

        while (leftIndex <= mid) {
            temp[index++] = a[leftIndex++];
        }

        while (rightIndex <= end) {
            temp[index++] = a[rightIndex++];
        }

        for (int i = start; i <= end; i++) {
            a[i] = temp[i];
        }
    }

    void quickSort(vector<int> &a, int start, int end) {
        if (start >= end) {
            return;
        }

        int left = start;
        int right = end;
        // 1. pivot选取中心点的值
        int pivot = a[start + (end - start) / 2];
        // 2. left <= right，而不是left < right
        while (left <= right) {
            // 3. a[left] <= right，而不是 <=
            while (left <= right && a[left] < pivot) {
                left++;
            }
            while (left <= right && a[right] > pivot) {
                right--;
            }
            if (left <= right) {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                left++;
                right--;
            }
        }

        quickSort(a, start, right);
        quickSort(a, left, end);
    }
};

int main() {
    vector<int> nums{3, 2, 1, 4, 5};
    Solution solution;
    solution.sortIntegers2(nums);
    cout << "result: " << Utils::printVector(nums) << endl;
}
