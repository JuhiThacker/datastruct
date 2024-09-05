#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % MAX == front);
}

int isEmpty() {
    return (front == -1);
}

void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow!\n");
    } else {
        if (isEmpty()) {
            front = 0;  
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }
}

int delete() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        return value;
    }
}

void modify(int position, int newValue) {
    if (isEmpty() || position < 1 || position > ((rear - front + MAX) % MAX + 1)) {
        printf("Invalid Position!\n");
    } else {
        int index = (front + position - 1) % MAX;
        queue[index] = newValue;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                value = delete();
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                printf("Enter position to modify: ");
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &value);
                modify(position, value);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}