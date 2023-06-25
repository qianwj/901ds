//
// Created by elvis on 2023/6/23.
//
#include <iostream>
#include "sequence_list.cpp"

using namespace std;

int get(StaticArraySequenceList l, int i) {
    if (i < 1 || i > l.length) {
        exit(-1);
    }
    return l.data[i - 1];
}

int location(StaticArraySequenceList l, int elem) {
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] == elem) {
            return i + 1;
        }
    }
    return -1;
}

bool insert(StaticArraySequenceList &l, int i, int elem) {
    if (i < 1 || i > l.length) {
        return false;
    }
    if (l.length >= MAX_SIZE) {
        return false;
    }
    for (int j = l.length; j >= i; j--) {
        l.data[j] = l.data[j - 1];
    }
    l.data[i-1] = elem;
    l.length++;
    return true;
}

bool del(StaticArraySequenceList &l, int i, int &deleted) {
    if (i < 1 || i > l.length) {
        return false;
    }
    deleted = l.data[i - 1];
    for (int j = i; j < l.length; j++) {
        l.data[i - 1] = l.data[i];
    }
    l.length--;
    return true;
}

void reverse(StaticArraySequenceList &l) {
    int mid = l.length / 2;
    for (int i = 0; i < mid; i++) {
        int temp = l.data[i];
        l.data[i] = l.data[l.length - i - 1];
        l.data[l.length - i - 1] = temp;
    }
}


// 顺序表递增有序，插入元素x，仍递增有序
void insert_ordered_list(StaticArraySequenceList &l, int x) {
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] > x) {
            insert(l, i, x);
        }
    }
}

// 用顺序表最后一个元素覆盖整个顺序表中最小元素，并返回该最小元素
int cover_min(StaticArraySequenceList &l) {
    int min = l.data[0];
    int idx = 0;
    for (int i = 1; i < l.length; i++) {
        if (min > l.data[i]) {
            min = l.data[i];
            idx = i;
        }
    }
    l.data[idx] = l.data[l.length - 1];
    return min;
}

void reverse_partition(StaticArraySequenceList &l, int m, int n) {
    int mid = (m + n) / 2;
    for (int i = m, j = 0; i <= mid; i++, j++) {
        int temp = l.data[i];
        l.data[i] = l.data[n - j];
        l.data[n - j] = temp;
    }
}

void reverse_partitions(StaticArraySequenceList &l, int m, int n) {
    reverse_partition(l, 0, m + n - 1);
    reverse_partition(l, 0, n - 1);
    reverse_partition(l, n, m + n -1);
}

// 刪除顺序表中所有值为x 的元素
void del_x(StaticArraySequenceList &l, int x) {
    int k = 0;
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] == x) {
            ++k;
        } else {
            l.data[i - k] = l.data[i];
        }
    }
    l.length -= k;
}

// 从顺序表中删除所有值重复的元素(顺序表递增)
void del_duplicate(StaticArraySequenceList &l) {
    int k = 0;
    for (int i = 0; i < l.length - 1; i++) {
        if (l.data[i] != l.data[i + 1]) {
            l.data[k++] = l.data[i];
        }
    }
    if (l.data[l.length] != l.data[k - 1]) {
        l.data[k++] = l.data[l.length - 1];
    }
    l.length = k;
}

// 两个递增有序表合并成一个递增有序表
void merge(StaticArraySequenceList a, StaticArraySequenceList b, StaticArraySequenceList &result) {
    int i = 0, j = 0;
    int k = 0;
    while (i < a.length && j < b.length) {
        if (a.data[i] < b.data[j]) {
            result.data[k++] = a.data[i++];
        } else {
            result.data[k++] = b.data[j++];
        }
    }
    while (i < a.length) {
        result.data[k++] = a.data[i++];
    }
    while (j < b.length) {
        result.data[k++] = b.data[j++];
    }
    result.length = k;
}

// 设计一个时间上尽可能高效的算法，找出数组中未出现的最小正整数
int find_not_exist_minimum_num(int a[], int n) {
    int *idx = new int[n];
    for (int i = 0; i < n; i++) {
        idx[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] <= n) {
            idx[a[i] - 1] += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (idx[i] == 0) {
            return i + 1;
        }
    }
    return n + 1;
}

void print(StaticArraySequenceList l) {
    for (int i = 0; i < l.length; i++)
        cout << l.data[i] << ", ";
    cout << "\n";
}

int main() {
    StaticArraySequenceList l = {
            { 1,2,3,4,5,6,7,8,9,10 },
            10,
    };
    reverse_partitions(l, 5, 4);
    print(l);
    StaticArraySequenceList l2 = {
            { 1,2,3,3,5,6,7,3,9,10 },
            10,
    };
    del_x(l2, 3);
    print(l2);
    StaticArraySequenceList l3 = {
            { 1,2,2,4,5,5,5,8,9,10 },
            10,
    };
    del_duplicate(l3);
    print(l3);
    StaticArraySequenceList a = {
            { 1,2,2,4,5,5,5,8,9,10 },
            10,
    };
    StaticArraySequenceList b = {
            { 2,10 },
            2,
    };
    StaticArraySequenceList result = {{}, 0};
    merge(a, b, result);
    print(result);
    int test1[4] = {-5,1,2,5};
    int min = find_not_exist_minimum_num(test1, 4);
    cout << min << "\n";
    return 0;
}