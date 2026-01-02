#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int k, vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        return quickSelect(nums, 0, nums.size() - 1, k);
    }

    int quickSelect(vector<int> &nums, int start, int end , int k) {
        if (start == end) {
            return nums[start];
        }

        int i = start;
        int j = end;
        int pivot = nums[i + (j - i) / 2];
        while (i <= j) {
            while (i <= j && nums[i] > pivot) {
                i++;
            }

            while (i <= j && nums[j] < pivot) {
                j--;
            }

            if (i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }

        // 跳出循环时数组被分成三段 start...j..i..end。
        if (start + k -1 <= j) {
            return quickSelect(nums, start, j, k);
        }

        if (start + k - 1 >= i) {
            return quickSelect(nums, i, end, k - (i -  start));
        }

        return nums[j + 1];
    }
};

int main() {
    vector<int> nums{1,4,4,5,7,7,8,9,9,10};
    int k = 6;
    Solution solution;
    cout << "result: " << solution.kthLargestElement(k, nums) << endl;
}