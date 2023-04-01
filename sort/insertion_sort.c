//
// Created by lete on 2023/4/1.
//
#include "stdio.h"

void sort(int *nums, int len) {
    for (int i = 1; i < len; ++i) {
        int preIndex = i - 1;
        int current = nums[i];
        while (preIndex >= 0 && nums[preIndex] > current) {
            nums[preIndex + 1] = nums[preIndex];
            preIndex--;
        }
        nums[preIndex + 1] = current;
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

