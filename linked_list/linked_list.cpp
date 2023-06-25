//
// Created by elvis on 2023/6/25.
//
#include <iostream>

using namespace std;


typedef struct SingleListNode {
  int data;
  SingleListNode *next;
} SingleListNode, *SingleLinkedList;

typedef struct DuplicateListNode {
    int data;
    DuplicateListNode *prev, *next;
} DuplicateListNode, *DuplicateLinkedList;

// 初始化一个单链表，带头结点
bool init_single_linked_list(SingleLinkedList &l) {
    l = (SingleListNode *) malloc(sizeof(SingleListNode));
    if (l == NULL) {
        return false;
    }
    l->data = -1;
    l->next = NULL;
    return true;
}

bool init_headless_single_linked_list(SingleLinkedList &l) {
    l == NULL;
    return true;
}

bool is_empty(SingleLinkedList &l) {
    if (l == NULL) {
        return true;
    }
    return false;
}

