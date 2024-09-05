#include <stdio.h>
#include<stdlib.h>
int main() {
    int arr[100], n, choice, value, pos, i, j, temp;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {   
        scanf("%d", &arr[i]);
    }
        printf("\nMenu:\n");
        
        printf("1. Add an element\n");
        printf("2. Delete an element\n");
        printf("3. Modify an element\n");
        printf("4. Sort the array\n");
        printf("5. Simple Search\n");
        printf("6. Binary Search\n");
        printf("7. Display the array\n");
        printf("8. Exit\n");
    while (choice != 8) {
       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &value);
                printf("Enter the position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                if (pos > 0 && pos <= n + 1) {
                    for (i = n; i >= pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos - 1] = value;
                    n++;
                    printf("Element added successfully.\n");
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 2:
                printf("Enter the position of the element to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos > 0 && pos <= n) {
                    for (i = pos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Element deleted successfully.\n");
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 3:
                printf("Enter the position of the element to modify (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos > 0 && pos <= n) {
                    printf("Enter the new value: ");
                    scanf("%d", &value);
                    arr[pos - 1] = value;
                    printf("Element modified successfully.\n");
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 4:
                for (i = 0; i < n - 1; i++) {
                    for (j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Array sorted successfully.\n");
                break;

            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &value);
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Element found at position %d\n", i + 1);
                        break;
                    }
                }
                if (i == n) {
                    printf("Element not found!\n");
                }
                break;

            case 6:
                printf("Enter the element to search: ");
                scanf("%d", &value);
                int low = 0, high = n - 1, mid;
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (arr[mid] == value) {
                        printf("Element found at position %d\n", mid + 1);
                        break;
                    } else if (arr[mid] < value) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (low > high) {
                    printf("Element not found!\n");
                }
                break;

            case 7:
                printf("Array elements: \n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } 

    return 0;
}