/*
 * leetcode 4.Median of Two Sorted Arrays
 * 2018.1.31    16:33 -
 * Treek
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        if (len & 1) return findKth(nums1, 0, nums2, 0, len/2+1);
        return (findKth(nums1, 0, nums2, 0, len/2) + findKth(nums1, 0, nums2, 0, len/2+1))/2;
    }
    double findKth(vector<int>& nums1, int i1, vector<int>& nums2, int i2, int k) {
        if (i1 >= nums1.size()) return nums2[i2+k-1];
        if (i2 >= nums2.size()) return nums1[i1+k-1];
        if (k == 1) return min(nums1[i1], nums2[i2]);

        int key1 = i1 + k/2 - 1 >= nums1.size() ? INT_MAX: nums1[i1 + k/2 - 1];
        int key2 = i2 + k/2 - 1 >= nums2.size() ? INT_MAX: nums2[i2 + k/2 - 1];
        if (key1 < key2) return findKth(nums1, i1 + k/2, nums2, i2, k - k/2);
        else return findKth(nums1, i1, nums2, i2 + k/2, k - k/2);
    }
};

int main(void) {
    Solution s;
    int val;
    cout << "First array: " << endl;

    cout << "Size: ";
    int num1;
    cin >> num1;

    cout << "Elements: ";
    vector<int> array1;
    while (num1--) {
        cin >> val;
        array1.push_back(val);
    }

    cout << "Second array: " << endl;

    cout << "Size: ";
    int num2;
    cin >> num2;

    cout << "Elements: ";
    vector<int> array2;
    while (num2--) {
        cin >> val;
        array2.push_back(val);
    }

    cout << "Median of Two Sorted Arrays: ";
    cout << s.findMedianSortedArrays(array1, array2) << endl;
    return 0;
}
