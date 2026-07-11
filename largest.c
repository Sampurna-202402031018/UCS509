#include <stdio.h>

int main() {
    int numbers[] = {12, 5, 7, 19, 3, 25};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int largest = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }

    printf("The largest number is: %d\n", largest);
    return 0;
}