#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行Z 字形排列。
//比如输入字符串为 "PAYPALISHIRING"行数为 3 时，排列如下：
//P   A   H   N
//A P L S I I G
//Y   I   R
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

char *convert(char *s, int numRows) {
    int n = strlen(s), r = numRows;
    if (r == 1 || r >= n) {
        return s;
    }
    char **mat = (char **) malloc(sizeof(char *) * r);
    int *columSize = (int *) malloc(sizeof(int) * r);
    for (int i = 0; i < r; ++i) {
        int size = sizeof(char) * (n + 1);
        mat[i] = (char *) malloc(size);
        memset(mat[i], 0, size);
    }
    for (int i = 0, x = 0, t = r * 2 - 2; i < n; ++i) {
        mat[x][columSize[x]++] = s[i];
        i % t < r - 1 ? ++x : --x;
    }
    int pos = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < columSize[i]; ++j) {
            s[pos++] = mat[i][j];
        }
        free(mat[i]);
    }
    free(columSize);
    free(mat);
    return s;
}


void test() {
    char s[] = "PAYPALISHIRING";
    char *ret = convert(s, 3);
    printf("%s", ret);
}

int main() {
    test();
    return 1;
}