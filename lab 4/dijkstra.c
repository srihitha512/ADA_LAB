#include <stdio.h>

#define INF 999

void dijkstra(int n, int cost[n][n], int source) {
    int dist[n], visited[n];
    int i, j, u, v, min;


    for (i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;


    for (i = 0; i < n - 1; i++) {
        min = INF;


        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;


        for (v = 0; v < n; v++) {
            if (visited[v] == 0 && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }


    printf("\nShortest distances from source vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i, dist[i]);
    }
}

int main() {
    int n, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter the cost matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);


            if (i != j && cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(n, cost, source);

    return 0;
}
