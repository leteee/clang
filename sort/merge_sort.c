//
// Created by lete on 2023/4/1.
//
#include "stdio.h"
#include "stdlib.h"


void merge(int *nums, int start, int mid, int end) {
    int *temp = (int *) malloc((end - start - 1) * sizeof(int));

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= end) {
        temp[k++] = nums[j++];
    }

    for (int i = 0; i < k; ++i) {
        nums[start + i] = temp[i];
    }
    free(temp);
}

void sort(int *nums, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    sort(nums, start, mid);
    sort(nums, mid + 1, end);
    merge(nums, start, mid, end);
}


int main() {
    int nums[10] = {2, 16, 7, 1, 11, 8, 5, 10, 17, 23};
    int len = sizeof(nums) / sizeof(int);
    sort(nums, 0, len - 1);
    for (int i = 0; i < len; ++i) {
        printf("%d\t", nums[i]);
    }
    printf("\nhello world");
}

