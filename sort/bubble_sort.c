//
// Created by lete on 2023/4/1.
//
#include "stdio.h"

void sort(int *nums, int len) {

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
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
