#include <stdio.h>
#define DATA_SIZE 9
int Data[DATA_SIZE] = { 6, 5, 2, 3, 8, 7, 1, 9, 4 };


void Insertion() {
	int Data[DATA_SIZE] = { 6, 5, 2, 3, 8, 7, 1, 9, 4 };
	int i, j, temp;
	for ( i = 1; i < DATA_SIZE; i++) {
		temp = Data[i];
		for (j = i - 1; j >= 0 && Data[j] > temp; j--) {
			Data[j + 1] = Data[j];
		}
		Data[j+1] = temp;
	}
	for (int k = 0; k < DATA_SIZE; k++)
		printf("%d", Data[k]);
}

void Bubble() {
	int Data[DATA_SIZE] = { 6, 5, 2, 3, 8, 7, 1, 9, 4 };
	int i, j, temp;
	for (i = DATA_SIZE - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (Data[j] > Data[j + 1]) {
				temp = Data[j];
				Data[j] = Data[j + 1];
				Data[j + 1] = temp;
			}
		}
	}
	for (int k = 0; k < DATA_SIZE; k++)
		printf("%d", Data[k]);
}

void Selection() {
	int Data[DATA_SIZE] = { 6, 5, 2, 3, 8, 7, 1, 9, 4 };
	int i, j, min, temp;
	for (i = 0; i < DATA_SIZE-1; i++) {
		min = i;
		for (j = i+1; j < DATA_SIZE; j++) {
			if (Data[min] > Data[j])
				min = j;
		}
		temp = Data[min];
		Data[min] = Data[i];
		Data[i] = temp;
	}
	for (int k = 0; k < DATA_SIZE; k++)
		printf("%d", Data[k]);
}
