#include <stdio.h>

void toh(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    toh(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    toh(n - 1, auxiliary, source, destination);
}

int main()
{
    int n = 5;

    printf("Steps to solve Tower of Hanoi with %d disks:\n\n", n);
    toh(n, 'A', 'B', 'C');

    return 0;
}