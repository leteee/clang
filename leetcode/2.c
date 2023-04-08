#include "../lib/uthash/uthash.h"
#include "stdio.h"

//给你两个非空 的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0开头。
//
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head = NULL, *tail = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
        int n1, n2 = 0;
        if (l1 != NULL) {
            n1 = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            n2 = l2->val;
            l2 = l2->next;
        }
        struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        newNode->val = sum % 10;
        if (head == NULL || tail == NULL) {
            head = newNode, tail = newNode;
        } else {
            tail->next = newNode, tail = tail->next;
        }
    }
    if (carry > 0) {
        struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->val = carry;
        tail->next = newNode;
    }
    return head;
}

struct ListNode *makeListNode(int *nums, int numsSize) {
    if (numsSize < 1) {
        return NULL;
    }
    struct ListNode *head, *tail = NULL;

    for (int i = 0; i < numsSize; ++i) {
        struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->val = nums[i];
        newNode->next = NULL;
        if (head == NULL || tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

void showListNode(struct ListNode *head) {
    if (head != NULL) {
        showListNode(head->next);
        printf("%d", head->val);
    }
}

void test() {
    int nums1[] = {2, 4, 3};
    int nums2[] = {5, 6, 4};
    struct ListNode *l1 = makeListNode(nums1, sizeof(nums1) / sizeof(int));
    struct ListNode *l2 = makeListNode(nums2, sizeof(nums2) / sizeof(int));
    struct ListNode *res = addTwoNumbers(l1, l2);
    showListNode(res);
}

int main() {
    test();
    return 1;
}