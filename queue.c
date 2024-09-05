#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insert(int value) {
    if (rear >= MAX - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (front == -1) {
            front = 0;  // Initializing front when first element is inserted
        }
        queue[++rear] = value;
    }
}

int delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return -1;
    } else {
        int value = queue[front++];
        if (front > rear) {
            // Reset the queue after the last element is deleted
            front = rear = -1;
        }
        return value;
    }
}

void modify(int position, int newValue) {
    if (front == -1 || position < 1 || position > rear - front + 1) {
        printf("Invalid Position!\n");
    } else {
        queue[front + position - 1] = newValue;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value, position;
    
    while (1) {
        printf("\nQueue Operations Menu:\n");
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