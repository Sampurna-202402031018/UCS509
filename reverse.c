#include <stdio.h>

int main() {
    int numbers[] = {12, 5, 7, 19, 3, 25};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    // Reverse the array
    for (int i = 0; i < size / 2; i++) {
        int temp = numbers[i];
        numbers[i] = numbers[size - 1 - i];
        numbers[size - 1 - i] = temp;
    }

    printf("\nReversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");
    return 0;
}