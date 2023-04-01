//
// Created by lete on 2023/4/1.
//
#include "stdio.h"

void sort(int *nums, int len) {


    for (int gap = len / 2; gap > 0; gap = gap / 2) {
        /**
         * 是简单插入排序的改进版
         */
        for (int i = gap; i < len; i++) {
            int preIndex = i - gap;
            int current = nums[i];
            while (preIndex >= 0 && nums[preIndex] > current) {
                nums[preIndex + 1] = nums[preIndex];
                preIndex = preIndex - gap;
            }
            nums[preIndex + 1] = current;
        }
    }
}

int main() {
    int nums[10] = {2, 16, 7, 1, 11, 8, 5, 10, 17, 23};
    int len = sizeof(nums) / sizeof(int);
    sort(nums, len);
    for (int i = 0; i < len; ++i) {
        printf("%d\t", nums[i]);
    }
    printf("\nhello world");
}

