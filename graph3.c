#include <stdio.h>

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int maxDegree = -1, minDegree = n + 1;
    int maxVertex, minVertex;

    for(int i = 0; i < n; i++) {
        int degree = 0;

        for(int j = 0; j < n; j++) {
            if(graph[i][j] != 0)
                degree++;
        }

        if(degree > maxDegree) {
            maxDegree = degree;
            maxVertex = i;
        }

        if(degree < minDegree) {
            minDegree = degree;
            minVertex = i;
        }
    }

    printf("\nVertex with highest degree: %d\n", maxVertex);
    printf("Number of connected edges: %d\n", maxDegree);

    printf("\nVertex with lowest degree: %d\n", minVertex);
    printf("Number of connected edges: %d\n", minDegree);

    return 0;
}