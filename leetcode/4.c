#include "stdio.h"
#include<limits.h>
#include "util.c"


// 给定两个大小分别为 m 和 n 的正序（从小到大）数组nums1 和nums2。请你找出并返回这两个正序数组的 中位数 。
// 算法的时间复杂度应该为 O(log (m+n)) 。
//
// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    const int m = nums1Size, n = nums2Size;
    int left = 0, right = m;
    int medianIdx = (m + n + 1) >> 1;
    while (left < right) {
        int i = (left + right + 1) >> 1;
        int j = medianIdx - i;
        int nums_im1 = nums1[i - 1];
        int nums_j = nums2[j];
        if (nums_im1 < nums_j) {
            left = i ;
        } else {
            right = i - 1;
        }
    }
    int i = left, j = medianIdx - left;
    int median = max(i == 0 ? INT_MIN : nums1[i - 1], nums2[j - 1]);
    if ((m + n + 1) % 2 == 0) {
        int median2 = min(i == m ? INT_MAX : nums1[i], nums2[j]);
        return (median + median2) / 2;
    } else {
        return median;
    }
}

void test() {
/*    int nums1[] = {1, 2, 3};
    int nums2[] = {3, 7, 9, 11};
    double result = findMedianSortedArrays(nums2, 4, nums1, 3);*/

    int nums1[] = {1, 2};
    int nums2[] = {3, 7, 9, 11};
    double result = findMedianSortedArrays(nums2, 4, nums1, 2);
    printf("中位数：%.2f", result);
}

int main() {
    test();
    return 1;
}