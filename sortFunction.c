#include <stdio.h>

int mainMerge[50] = {21, 10, 23, 15, 11};  // Global array
int arraySize = 5;  // Global array size

void sortBubble(int arr[], int size) {
    printf("\nBubble Sorted Array:\n");
    for (int pick = 0; pick < size - 1; pick++) {

        for (int i = 0; i < size - 1 - pick; i++) {

            if (arr[i] > arr[i + 1]) {  // Swap only if needed
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void sortSelection(int arr[], int size) {
    int position;

    for (int i = 0; i < size - 1; i++) {
        position = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[position] > arr[j]) {
                position = j;
            }
        }

        if (position != i) {  // Swap only if needed
            int temp = arr[i];
            arr[i] = arr[position];
            arr[position] = temp;
        }
    }

    printf("\nSelection Sorted Array:\n");

    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    
    printf("\n");
}

void sortMain() {
    int pickSort;

    printf("\nPick the type of sort (Bubble - 1 / Selection - 2): ");
    scanf("%d", &pickSort);

    if (pickSort == 1) {
        sortBubble(mainMerge, arraySize);
    } else if (pickSort == 2) {
        sortSelection(mainMerge, arraySize);
    } else {
        printf("\nInvalid Input.\n");
    }
}

int main() {
    sortMain();
    return 0;
}
