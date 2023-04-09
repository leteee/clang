#include "stdio.h"
#include "../lib/uthash/uthash.h"

//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
//
//输入: s = "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

struct hashTable {
    int key;
    int value;
    UT_hash_handle hh;
};

struct hashTable *hashtable;

struct hashTable *find(int key) {
    struct hashTable *temp;
    HASH_FIND_INT(hashtable, &key, temp);
    return temp;
}

void insert(int iKey, int iValue) {
    struct hashTable *it = find(iKey);
    if (it == NULL) {
        it = malloc(sizeof(struct hashTable));
        it->key = iKey, it->value = iValue;
        HASH_ADD_INT(hashtable, key, it);
    } else {
        it->value = iValue;
    }
}

void delete(int iKey) {
    struct hashTable *it = find(iKey);
    HASH_DEL(hashtable, it);
}

int max(int x, int y) {
    if (x > y) {
        return x;
    }
    return y;
}

int lengthOfLongestSubstring(char *s, int len) {
    int right = -1, ans = 0;
    for (int left = 0; left < len; left++) {
        if (left != 0) {
            delete(s[left - 0]);
        }
        for (; right + 1 < len && find(s[right + 1]) == NULL; right++) {
            insert(s[right + 1], s[right + 1]);
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

void test() {
    char s[] = "abcabcbb";
    int ret = lengthOfLongestSubstring(s, sizeof(s) / sizeof(char) - 1);
    printf("%d", ret);
}

int main() {
    test();
    return 1;
}