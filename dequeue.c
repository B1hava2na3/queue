#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Dequeue;

// Initialize Dequeue
void initDequeue(Dequeue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if Dequeue is full
int isFull(Dequeue *dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

// Check if Dequeue is empty
int isEmpty(Dequeue *dq) {
    return (dq->front == -1);
}

// Insert at rear
void insertRear(Dequeue *dq, int x) {
    if (isFull(dq)) {
        printf("Overflow! Cannot insert %d at rear\n", x);
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->arr[dq->rear] = x;
    printf("%d inserted at rear\n", x);
}

// Insert at front
void insertFront(Dequeue *dq, int x) {
    if (isFull(dq)) {
        printf("Overflow! Cannot insert %d at front\n", x);
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = x;
    printf("%d inserted at front\n", x);
}

// Delete from front
void deleteFront(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Underflow! Cannot delete from front\n");
        return;
    }

    printf("Deleted from front: %d\n", dq->arr[dq->front]);

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

// Delete from rear
void deleteRear(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Underflow! Cannot delete from rear\n");
        return;
    }

    printf("Deleted from rear: %d\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

// Display the Dequeue
void display(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty\n");
        return;
    }

    printf("Dequeue elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Dequeue dq;
    initDequeue(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 3);
    display(&dq);

    deleteRear(&dq);
    deleteFront(&dq);
    display(&dq);

    return 0;
}