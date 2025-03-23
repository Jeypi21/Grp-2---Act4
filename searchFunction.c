#include <stdio.h>

int mergeArray[50], arraySize;

void searchLinear(int arr[], int size) {
	int findValue, pos = -1;

	printf("Enter value to search: ");
	scanf("%d", &findValue);

	for (int i = 0; i < size; i++) {
		if (findValue == arr[i]) {
			pos = i + 1;
			break;
		}
	}

	if (pos == -1) {
		printf("Value not found.\n");
	} else {
		printf("Value found at position = %d\n", pos);
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
			printf("%d is present at index %d.\n", search, middle + 1);
			return;
		} else {
			last = middle - 1;
		}
	}

	printf("Not found! %d is not present in the list.\n", search);
}

void searchMain() {
	int pickSearch, pickLinearSearch;

	printf("\n\nPick the type of search (Linear - 1 / Binary - 2): ");
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
		printf("\nBinary search requires a sorted array!\n");
		searchBinary(mergeArray, arraySize);
	} else {
		printf("\nInvalid Input.\n");
	}
}

int main() {
	printf("Enter array size: ");
	scanf("%d", &arraySize);

	printf("Enter %d elements:\n", arraySize);
	for (int i = 0; i < arraySize; i++) {
		scanf("%d", &mergeArray[i]);
	}

	searchMain();
	return 0;
}
