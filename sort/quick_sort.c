//
// Created by lete on 2023/4/1.
//
#include "stdio.h"

void sort(int *, int, int);  //函数声明, 快速排序


int main() {
    int nums[10] = {2, 16, 7, 1, 11, 8, 5, 10, 17, 23};
    int len = sizeof(nums) / sizeof(int);
    sort(nums, 0, len - 1);
    for (int i = 0; i < len; ++i) {
        printf("%d\t", nums[i]);
    }
    printf("\nhello world");
}

void sort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left, j = right, temp = nums[left];
    while (i < j) {
        while (nums[j] > temp && i < j) {
            j--;
        }
        nums[i] = nums[j];
        while (nums[i] < temp && i < j) {
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = temp;
    sort(nums, left, i - 1);
    sort(nums, j + 1, right);
}

