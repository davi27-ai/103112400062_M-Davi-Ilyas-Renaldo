#include <iostream>
#include <iomanip>
#include "queue.h"

using namespace std;

void createQueue(Queue *Q) {
    Q->head = -1; 
    Q->tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

bool enqueue(Queue *Q, infotype x) {
    if (isFullQueue(*Q)) {
        return false;
    }

    if (isEmptyQueue(*Q)) {
        Q->head = 0; 
        Q->tail = 0;
    } else {
        Q->tail++;
    }

    Q->info[Q->tail] = x;
    return true;
}

infotype dequeue(Queue *Q) {
    if (isEmptyQueue(*Q)) {
        return -1;
    }

    infotype dequeued_value = Q->info[Q->head]; 

    if (Q->head == Q->tail) {
        createQueue(Q); 
    } else {
        for (int i = Q->head + 1; i <= Q->tail; i++) {
            Q->info[i - 1] = Q->info[i];
        }
        
        Q->tail--;
    }

    return dequeued_value;
}

void printInfo(Queue Q) {
    cout << setw(3) << Q.head 
         << " | " << setw(3) << Q.tail 
         << " | ";

    if (isEmptyQueue(Q)) {
        cout << setw(10) << "empty queue" << endl;
    } else {
        for (int i = 0; i < MAX_QUEUE; ++i) {
            if (i <= Q.tail) {
                cout << Q.info[i];
            } else {
                cout << " ";
            }

            if (i < MAX_QUEUE - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}