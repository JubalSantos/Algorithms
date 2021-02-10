#include <math.h> 
#include <stdlib.h>
#include <stdio.h>

void printArray(int array[], int size) {
	for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("\n");
}
void swapIndex(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void partition(int array[], int low, int high) {

	int pivot = array[low];
	int lowNdx, highNdx;

	if((high-low) == 1 && array[low] > array[high]) {
		swapIndex(&array[low], &array[high]);
	}

	for(lowNdx = low+1; lowNdx <= high; lowNdx++){
		for(highNdx = high; pivot < array[highNdx];){
			--highNdx;
		}
		if(lowNdx == highNdx){
			if(array[low] > array[lowNdx]){
				swapIndex(&array[low], &array[lowNdx]);
			}
			else{
				swapIndex(&array[low], &array[--highNdx]);
			}

			partition(array, low, --highNdx);
			partition(array, lowNdx, high);
		}
		else if(lowNdx > highNdx){

			if(pivot != array[highNdx]){
				swapIndex(&array[low], &array[highNdx]);
			}

			partition(array, low, --highNdx);
			partition(array, lowNdx, high);
		}
		else{
			swapIndex(&array[lowNdx], &array[highNdx]);
		}
	}
}
int main() {
	int size;
	int *array;

	printf("Enter a size for your array:\n");
	scanf("%d",  &size);
	array = malloc(size*sizeof(int));
	printf("\n");
	printf("Enter numbers with space in between:\n");

	for(int i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	} 

	partition(array, 0, size-1);
	printf("\n");
	printf("Your array sorted:\n");
	printArray(array,size);
	free(array);
	return 0;
}
