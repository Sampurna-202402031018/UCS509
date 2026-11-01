#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];

int dfs(int v, int parent, int n)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i])
        {
            if(!visited[i])
            {
                if(dfs(i, v, n))
                    return 1;
            }
            else if(i != parent)
            {
                return 1; // Cycle found
            }
        }
    }
    return 0;
}

int hasCycle(int n)
{
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1, n))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    if(hasCycle(n))
        printf("Graph contains a cycle.\n");
    else
        printf("Graph does not contain a cycle.\n");

    return 0;
}