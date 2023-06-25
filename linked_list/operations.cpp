//
// Created by elvis on 2023/6/25.
//
#include <iostream>
#include "linked_list.cpp"

using namespace std;

// 在第i个位置插入e（带头结点）
bool single_list_insert(SingleLinkedList &l, int i, int e) {
    if (i < 1) return false;
    SingleListNode *temp = l;
    int idx = 0;
    while (temp != NULL && idx <= i - 1) {
        if (idx == i - 1) {
            SingleListNode *new_node = new SingleListNode;
            new_node->next = temp->next;
            new_node->data = e;
            temp->next = new_node;
            return true;
        }
        temp = temp->next;
        idx++;
    }
    return false;
}

bool single_node_append(SingleListNode *p, int e) {
    if (p == NULL) {
        return false;
    }
    SingleListNode *new_node = new SingleListNode;
    new_node->data = e;
    new_node->next = p->next;
    p->next = new_node;
    return true;
}

void single_list_append(SingleLinkedList &l, int e) {
    SingleListNode *temp = l;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new SingleListNode;
    temp->next->data = e;
}

void single_list_delete(SingleLinkedList &l, int i, int e) {

}

void print_single_linked_list(SingleLinkedList &l) {
    SingleListNode *temp = l;
    while (temp != NULL) {
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << "\r\n";
}

int main() {
    SingleLinkedList l;
    init_single_linked_list(l);
    print_single_linked_list(l);
    single_list_append(l, 1);
    single_list_append(l, 3);
    single_list_insert(l, 1, 2);
    print_single_linked_list(l);
    return 0;
}
