//
// Created by elvis on 2023/6/23.
//
#include <malloc.h>

#define MAX_SIZE 100
#define INIT_SIZE 10

typedef struct StaticArraySequenceList {
    int data[MAX_SIZE];
    int length;
} StaticArraySequenceList;

typedef struct DynamicArraySequenceList {
    int *data;
    int length;
} DynamicArraySequenceList;

//void init_sasl(StaticArraySequenceList &l) {
//    for (int i = 0; i < MAX_SIZE; i++) {
//        l.data[i] = 0;
//    }
//    l.length = 0;
//}
//
//void init_dynamic_array_sequence_list(DynamicArraySequenceList &l) {
//    l.data = (int *)malloc(INIT_SIZE * sizeof(int));
//    l.length = 0;
//}

//int main() {
//    StaticArraySequenceList sl;
//    init_static_array_sequence_list(sl);
//    DynamicArraySequenceList dl;
//    init_dynamic_array_sequence_list(dl);
//}

