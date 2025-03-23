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
	int findValue, pos = -1;

	printf("\nEnter value to search: ");
	scanf("%d", &findValue);

	for (int i = 0; i < size; i++) {
		if (findValue == arr[i]) {
			pos = i + 1;
			break;
		}
	}

	if (pos == -1) {
		printf("\nValue not found.\n");
	} else {
		printf("\nValue found at position: %d\n", pos);
	}
}

void searchBinary(int arr[], int size) {
	int search, first, middle, last;

	printf("Enter the value to search: ");
	scanf("%d", &search);

	first = 0;
	last = size - 1;

	while (first <= last) {
		middle = (first + last) / 2;

		if (arr[middle] < search) {
			first = middle + 1;
		} else if (arr[middle] == search) {
			printf("%d is present at index %d.\n", search, middle);
			return;
		} else {
			last = middle - 1;
		}
	}

	printf("Not found! %d is not present in the list.\n", search);
}

void searchMain(int arr[], int size) {
	int pickSearch, pickLinearSearch;

	printf("\nPick the type of search (Linear - 1 / Binary - 2): ");
	scanf("%d", &pickSearch);

	if (pickSearch == 1) {
		searchLinear(mergeArray, arraySize);

		printf("\nPick the type of linear search (Min. - 1 / Max. - 2): ");
		scanf("%d", &pickLinearSearch);

		if (pickLinearSearch == 1) {
			// Implement minimum search here
		} else if (pickLinearSearch == 2) {
			// Implement maximum search here
		} else {
			printf("\nInvalid Input.\n");
		}
	} else if (pickSearch == 2) {
		// Ensure the array is sorted before binary search
		printf("\n\nBinary search requires a sorted array!\n");
		searchBinary(mergeArray, arraySize);
	} else {
		printf("\nInvalid Input.\n");
	}
}
//End of Search Array Function
//--------------------------------------------------------
//This is for Sort Array Function
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

void sortMain(int arr[], int size) {
    int pickSort;

    printf("\nPick the type of sort (Bubble - 1 / Selection - 2): ");
    scanf("%d", &pickSort);

    if (pickSort == 1) {
        sortBubble(mergeArray, arraySize);
    } else if (pickSort == 2) {
        sortSelection(mergeArray, arraySize);
    } else {
        printf("\nInvalid Input.\n");
    }
}
//--------------------------------------------------------
//End of Sort Array Function
//--------------------------------------------------------
//Main Function
int main() {
    int seSo;
    char tryAgain;

    do {
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

        printf("\n\nPick whether to SEARCH or SORT the array (SEARCH - 1 / SORT - 2): ");
        scanf("%d", &seSo);

        if (seSo == 1) {
            searchMain(mergeArray, arraySize);  // Assuming searchMain() operates on mainMerge
        } else if (seSo == 2) {
            sortMain(mergeArray, arraySize);
        } else {
            printf("Invalid Input.");
        }

        printf("\nDo you want to try again? (Y/N): ");
        scanf(" %c", &tryAgain);
    } while (tryAgain == 'Y' || tryAgain == 'y');

    printf("\nCongrats!\n");

    return 0;
}