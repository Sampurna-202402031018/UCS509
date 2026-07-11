#include <stdio.h>

int main() {
    int numbers[] = {12, 5, 7, 19, 3, 25, 7, 12, 19};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int i, j;
    int foundDuplicate = 0;

    printf("Duplicate values in the array: ");
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (numbers[i] == numbers[j]) {
                printf("%d ", numbers[i]);
                foundDuplicate = 1;
                break; // avoid printing the same duplicate multiple times
            }
        }
    }

    if (!foundDuplicate) {
        printf("None");
    }

    printf("\n");
    return 0;
}
