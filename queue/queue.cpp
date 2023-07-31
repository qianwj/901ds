//
// Created by elvis on 2023/7/15.
//

typedef struct {
    int data[10];
    int front, rear;
} SeqQueue;

void init_queue(SeqQueue &q) {
    q.rear = q.front = 0;
}

bool is_empty(SeqQueue &q) {
    return q.rear == q.front;
}

bool enqueue(SeqQueue &q, int x) {
    if ((q.rear + 1) % 10 == q.front) { // 牺牲一个单元判满
        return false;
    }
    q.data[q.rear] = x;
    q.rear = (q.rear + 1) % 10;
    return true;
}

int dequeue(SeqQueue &q) {
    if (is_empty(q)) {
        return -1;
    }
    int result = q.data[q.front];
    q.front = (q.front + 1) % 10;
    return result;
}
