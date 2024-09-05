#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int value) {
    if (top1 >= MAX - 1) {
        printf("Stack 1 Overflow!\n");
    } else {
        stack1[++top1] = value;
    }
}

void push2(int value) {
    if (top2 >= MAX - 1) {
        printf("Stack 2 Overflow!\n");
    } else {
        stack2[++top2] = value;
    }
}

int pop1() {
    if (top1 < 0) {
        printf("Stack 1 Underflow!\n");
        return -1;
    } else {
        return stack1[top1--];
    }
}

int pop2() {
    if (top2 < 0) {
        printf("Stack 2 Underflow!\n");
        return -1;
    } else {
        return stack2[top2--];
    }
}

int peep1(int index) {
    if (top1 - index + 1 < 0) {
        printf("Invalid Position in Stack 1!\n");
        return -1;
    } else {
        return stack1[top1 - index + 1];
    }
}

int peep2(int index) {
    if (top2 - index + 1 < 0) {
        printf("Invalid Position in Stack 2!\n");
        return -1;
    } else {
        return stack2[top2 - index + 1];
    }
}

void modify1(int index, int value) {
    if (top1 - index + 1 < 0) {
        printf("Invalid Position in Stack 1!\n");
    } else {
        stack1[top1 - index + 1] = value;
    }
}

void modify2(int index, int value) {
    if (top2 - index + 1 < 0) {
        printf("Invalid Position in Stack 2!\n");
    } else {
        stack2[top2 - index + 1] = value;
    }
}

void display1() {
    if (top1 < 0) {
        printf("Stack 1 is Empty!\n");
    } else {
        printf("Stack 1: ");
        for (int i = 0; i <= top1; i++) {
            printf("%d ", stack1[i]);
        }
        printf("\n");
    }
}

void display2() {
    if (top2 < 0) {
        printf("Stack 2 is Empty!\n");
    } else {
        printf("Stack 2: ");
        for (int i = 0; i <= top2; i++) {
            printf("%d ", stack2[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value, index;
    
    while (1) {
        printf("\nDouble Stack Operations Menu:\n");
        printf("1. Push in Stack 1\n");
        printf("2. Push in Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Peep in Stack 1\n");
        printf("6. Peep in Stack 2\n");
        printf("7. Modify Stack 1\n");
        printf("8. Modify Stack 2\n");
        printf("9. Display Stack 1\n");
        printf("10. Display Stack 2\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push in Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter value to push in Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                value = pop1();
                if (value != -1) {
                    printf("Popped from Stack 1: %d\n", value);
                }
                break;
            case 4:
                value = pop2();
                if (value != -1) {
                    printf("Popped from Stack 2: %d\n", value);
                }
                break;
            case 5:
                printf("Enter index to peep in Stack 1: ");
                scanf("%d", &index);
                value = peep1(index);
                if (value != -1) {
                    printf("Value at index %d in Stack 1: %d\n", index, value);
                }
                break;
            case 6:
                printf("Enter index to peep in Stack 2: ");
                scanf("%d", &index);
                value = peep2(index);
                if (value != -1) {
                    printf("Value at index %d in Stack 2: %d\n", index, value);
                }
                break;
            case 7:
                printf("Enter index to modify in Stack 1: ");
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
                modify1(index, value);
                break;
            case 8:
                printf("Enter index to modify in Stack 2: ");
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
                modify2(index, value);
                break;
            case 9:
                display1();
                break;
            case 10:
                display2();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}