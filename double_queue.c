#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
    } else {
        if (front == -1) { 
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        deque[front] = value;
    }
}

void insertRear(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
    } else {
        if (front == -1) {  
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
    }
}

int deleteFront() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return -1;
    } else {
        int value = deque[front];
        if (front == rear) {  
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
        return value;
    }
}

int deleteRear() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return -1;
    } else {
        int value = deque[rear];
        if (front == rear) {  
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
        return value;
    }
}

void modify(int position, int newValue) {
    if (front == -1 || position < 1 || position > (rear >= front ? rear - front + 1 : MAX - front + rear + 1)) {
        printf("Invalid Position!\n");
    } else {
        int index = (front + position - 1) % MAX;
        deque[index] = newValue;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is Empty!\n");
    } else {
        printf("Deque: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice, value, position;
    
    while (1) {
        printf("\nDouble-Ended Queue Operations Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Modify\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                value = deleteFront();
                if (value != -1) {
                    printf("Deleted from front: %d\n", value);
                }
                break;
            case 4:
                value = deleteRear();
                if (value != -1) {
                    printf("Deleted from rear: %d\n", value);
                }
                break;
            case 5:
                printf("Enter position to modify: ");
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &value);
                modify(position, value);
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}