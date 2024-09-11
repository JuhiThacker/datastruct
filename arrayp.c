#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int arr[MAX];
int size = 0;
void addElement() {
    if (size >= MAX) {
        printf("Array is full\n");
    }
    else{	                 
    int element;
    printf("Enter the element to add: ");
    scanf("%d", &element);
    
    arr[size] = element;
    size++;
    
       }
}
void deleteElement() {
    if (size == 0) {
        printf("Array is empty\n");

    }
    int element, i,j,found =0;
    printf("Enter the element to delete: ");
    scanf("%d", &element);
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = i; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--;
        printf("Element %d deleted.\n", element);
    } else {
        printf("Element %d not found.\n", element);
    }
}
void modifyElement() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    int oldElement, newElement, i, found = 0;
    printf("Enter the element to modify: ");
    scanf("%d", &oldElement);
    for (i = 0; i < size; i++) {
        if (arr[i] == oldElement) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Enter the new value: ");
        scanf("%d", &newElement);
        arr[i] = newElement;
        printf("Element %d modified to %d.\n", oldElement, newElement);
    } else {
        printf("Element %d not found.\n", oldElement);
    }
}
void sortArray() {
	int i,j;
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    for (i = 0; i < size - 1; i++) {
        for ( j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted.\n");
}
void simpleSearch() {
	int i;
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    int element, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &element);
    for ( i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element %d found at index %d.\n", element, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found.\n", element);
    }
}
void binarySearch() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    int element, low = 0, high = size - 1, mid;
    sortArray();  // Binary search requires sorted array
    printf("Enter the element to search: ");
    scanf("%d", &element);
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] < element) {
            low = mid + 1;
        } else if (arr[mid] > element) {
            high = mid - 1;
        } else {
            printf("Element %d found at index %d.\n", element, mid);
            return;
        }
    }
    printf("Element %d not found.\n", element);
}
void displayArray() {
	int i;
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current array: ");
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int choice;
        printf("\nMenu:\n");
        printf("1) Add\n");
        printf("2) Delete\n");
        printf("3) Modify\n");
        printf("4) Sort\n");
        printf("5) Simple Search\n");
        printf("6) Binary Search\n");
        printf("7) Display Array\n");
        printf("8) Exit\n");
    while (1) {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addElement();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                modifyElement();
                break;
            case 4:
                sortArray();
                break;
            case 5:
                simpleSearch();
                break;
            case 6:
                binarySearch();
                break;
            case 7:
                displayArray();
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}