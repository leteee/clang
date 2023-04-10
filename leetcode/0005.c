#include "stdio.h"
#include "string.h"

//给你一个字符串 s，找到 s 中最长的回文子串。
//如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
//
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。

int *expandAroundCenter(char *s, int left, int right) {
    while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
        left--;
        right++;
    }
    int ret[2] = {left, right};
    return ret;
}

char *longestPalindrome(char *s) {
    if (s == NULL || s[0] == '\0') {
        return "";
    }
    int start = 0, len = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        int left = i, right = i;
        while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > len) {
            start = left + 1;
            len = right - left - 1;
        }
        left = i, right = i + 1;
        while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > len) {
            start = left + 1;
            len = right - left - 1;
        }
    }
    if (len > 1) {
        s[start + len] = '\0';
        return s + start;
    } else {
        return "";
    }
}

void test() {
    char s[] = "babad";
    char *ret = longestPalindrome(s);
    printf("%s", ret);
}

int main() {
    test();
    return 1;
}