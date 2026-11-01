#include <stdio.h>
#include <limits.h>

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

    int min = INT_MAX, max = INT_MIN;
    int umin, vmin, umax, vmax;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {   // For undirected graph
            if(graph[i][j] != 0) {
                if(graph[i][j] < min) {
                    min = graph[i][j];
                    umin = i;
                    vmin = j;
                }

                if(graph[i][j] > max) {
                    max = graph[i][j];
                    umax = i;
                    vmax = j;
                }
            }
        }
    }

    printf("\nLowest weight edge: (%d, %d) Weight = %d\n",
           umin, vmin, min);

    printf("Highest weight edge: (%d, %d) Weight = %d\n",
           umax, vmax, max);

    return 0;
}