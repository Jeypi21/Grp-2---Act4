#include <stdio.h>

int arrayN[5], arrayB[5], mergeArray[10], tryAgain, 
    arraySize = 0;

//This is for Merge Array Function
int isUnique (int arrVar){
    for (int i = 0; i < arraySize; i++){
        if (mergeArray[i] == arrVar){
            return 0;
        }
    }

    return 1;
}

void mainMerge(int arr[], int size){
    for (int i = 0; i < 5; i++){
        if (isUnique(arrayN[i])){
            mergeArray[arraySize] = arrayN[i];
            arraySize++;
        }
    }

    for (int i = 0; i < 5; i++){
        if (isUnique(arrayB[i])){
            mergeArray[arraySize] = arrayB[i];
            arraySize++;
        }
    }

    printf("\nMerged Array: \n");

    for (int i = 0; i < arraySize; i++){
        printf("%d  ", mergeArray[i]);
    }
}
//End of Merge Array Function
//--------------------------------------------------------
//This is for Search Array Function
void searchLinear(int arr[], int size) {
	int findValue, pos = -1, i;

    printf("\nMerged Array: \n");
    for(int i = 0; i < size; i++){
        printf("%d  ", arr[i]);
    }

	printf("\n\nEnter value to search: ");
	scanf("%d", &findValue);

	for (int i = 0; i < size; i++) {
		if (findValue == arr[i]) {
			pos = i + 1;
			break;
		}
	}

	if (pos == -1) {
		printf("\nNot found! %d is not present in the list.\n", findValue);
	} else {
		printf("\n%d can be found at position %d.\n", findValue, pos);
	}

    //sort to get the maximum and minimum values
    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {  
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nThe minimum value found in the array is: %d", arr[0]);
    printf("\nThe maximum value found in the array is: %d\n", arr[size - 1]);
}

void searchBinary(int arr[], int size) {
	int search, first, middle, last;
    char sortConfirm;

    printf("\nBinary search requires a sorted array!\n");

        printf("\nDo you want to sort it?(y/n): ");
        scanf(" %c", &sortConfirm);

        if (sortConfirm == 'y' || sortConfirm == 'Y'){
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - 1 - i; j++) {
                    if (arr[j] > arr[j + 1]) {  // Swap only if needed
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            printf("\nSorted Array: \n");

            for (int i = 0; i < size; i++){
                printf("%d  ", arr[i]);
            }

            printf("\n\nEnter the value to search: ");
	        scanf("%d", &search);

            first = 0;
            last = size - 1;

            while (first <= last) {
                middle = (first + last) / 2;

                if (arr[middle] < search) {
                    first = middle + 1;
                } else if (arr[middle] == search) {
                    printf("\n%d can be found at index %d.\n", search, middle);
                    printf("and found at position %d.\n", middle + 1);
                    return;
                } else {
                    last = middle - 1;
                }
            }

	        printf("\nNot found! %d is not present in the list.\n", search);
        } else if (sortConfirm == 'n' || sortConfirm == 'N'){
            printf("\nUse the linear search instead.\n");
        } else {
            printf("Invalid Input!");
        }
}

void searchMain(int arr[], int size) {
	int pickSearch, pickLinearSearch;

	printf("\nPick the type of search (Linear - 1 | Binary - 2): ");
	scanf("%d", &pickSearch);

	if (pickSearch == 1) {
		searchLinear(mergeArray, arraySize);
	} else if (pickSearch == 2) {
		searchBinary(mergeArray, arraySize);
	} else {
		printf("\nInvalid Input.\n");
	}
}
//End of Search Array Function
//--------------------------------------------------------
//This is for Sort Array Function
void sortBubbleAscend(int arr[], int size) {
    printf("\nBubble Sorted Array:\n");
    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {  // Swap only if needed
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void sortBubbleDescend(int arr[], int size) {
    printf("\nBubble Sorted Array:\n");
    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - 1 - i; j++) {

            if (arr[j] < arr[j + 1]) {  // Swap only if needed
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void sortSelectionAscend(int arr[], int size) {
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

void sortSelectionDescend(int arr[], int size) {
    int position;

    for (int i = 0; i < size - 1; i++) {
        position = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[position] < arr[j]) {
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

void sortMain(int arr[], int size) {
    int pickSort, whatSort;

    printf("\nPick the type of sort (Bubble - 1 | Selection - 2): ");
    scanf("%d", &pickSort);

    if (pickSort == 1) {
        printf("\nHow do you wanted it to be sorted? (Ascending - 1 | Descending - 2): ");
        scanf("%d", &whatSort);

        if (whatSort == 1){
            sortBubbleAscend(mergeArray, arraySize);
        } else if (whatSort == 2){
            sortBubbleDescend(mergeArray, arraySize);
        } else {
            printf("\nInvalid Input.\n");
        }
    } else if (pickSort == 2) {
        printf("\nHow do you wanted it to be sorted? (Ascending - 1 | Descending - 2): ");
        scanf("%d", &whatSort);

        if (whatSort == 1){
            sortSelectionAscend(mergeArray, arraySize);
        } else if (whatSort == 2){
            sortSelectionDescend(mergeArray, arraySize);
        } else {
            printf("\nInvalid Input.\n");
        }
    } else {
        printf("\nInvalid Input.\n");
    }
}
//--------------------------------------------------------
//End of Sort Array Function
//--------------------------------------------------------
//Main Function
int main() {
    int seSo, useOldValues = 0;
    char tryAgain, keepArr;

    do {
        if (!useOldValues) {
            printf("\nEnter values for Array N:\n");
            for (int i = 0; i < 5; i++) {
                scanf("%d", &arrayN[i]);
            }

            printf("\nEnter values for Array B:\n");
            for (int i = 0; i < 5; i++) {
                scanf("%d", &arrayB[i]);
            }

            // Merge arrays before searching/sorting
            mainMerge(mergeArray, arraySize);
        }

        printf("\n---------------------------------------------------------------------");
        printf("\nPick whether to SEARCH or SORT the array (SEARCH - 1 | SORT - 2): ");
        scanf("%d", &seSo);

        if (seSo == 1) {
            searchMain(mergeArray, arraySize);
        } else if (seSo == 2) {
            sortMain(mergeArray, arraySize);
        } else {
            printf("Invalid Input.");
        }

        printf("\nDo you want to try again?(Y/N): ");
        scanf(" %c", &tryAgain);

        if (tryAgain == 'Y' || tryAgain == 'y') {
            printf("Do you want to reuse the existing arrays?(Y/N): ");
            scanf(" %c", &keepArr);

            if(keepArr == 'Y' || keepArr == 'y'){
                useOldValues = 1;
            } else {
                useOldValues = 0;
            }   
        } else {                                                         
            break;
        }

    } while (1);

    printf("\nThank you for using our program!\n");
    return 0;
}