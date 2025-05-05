#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

void initialize(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued successfully\n", value);
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initialize(&q);
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);
    
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);
    
    enqueue(&q, 4);
    display(&q);
    
    return 0;
}