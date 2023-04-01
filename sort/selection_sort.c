//
// Created by lete on 2023/4/1.
//
#include "stdio.h"

void sort(int *nums, int len) {
    for (int i = 0; i < len - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < len; ++j) {
            if (nums[minIndex] > nums[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
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

