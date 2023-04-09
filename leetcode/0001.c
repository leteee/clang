#include "../lib/uthash/uthash.h"
#include "stdio.h"

//给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
//输入：nums = [2,7,11,15], target = 9
//输出：[0,1]
//解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable *hashtable;

struct hashTable *find(int key) {
    struct hashTable *tmp;
    HASH_FIND_INT(hashtable, &key, tmp);
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable *it = find(ikey);
    if (it == NULL) {
        struct hashTable *tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    } else {
        it->val = ival;
    }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; ++i) {
        struct hashTable *it = find(target - nums[i]);
        if (it != NULL) {
            int *ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

void test() {
    int nums[4] = {2, 7, 11, 15};
    int returnSize;
    int *ret = twoSum(nums, sizeof(nums) / sizeof(int), 18, &returnSize);
    if (returnSize == 2)
        printf("%d\t%d", ret[0], ret[1]);
    else
        printf("Not found!");
}

int main() {
    test();
    return 1;
}