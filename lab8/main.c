#include <stdio.h>

#define MAX 10

int main() {

    int n, graph[MAX][MAX];
    int indegree[MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    // Read adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Calculate indegree of each vertex
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    printf("Topological Order:\n");

    // Process all vertices
    for (int count = 0; count < n; count++) {

        int found = -1;

        // Find vertex with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0 && !visited[i]) {
                found = i;
                break;
            }
        }

        // If no such vertex exists -> cycle
        if (found == -1) {
            printf("Graph contains a cycle\n");
            return 0;
        }

        // Print vertex
        printf("%d ", found);

        visited[found] = 1;

        // Remove outgoing edges
        for (int j = 0; j < n; j++) {
            if (graph[found][j] == 1) {
                indegree[j]--;
            }
        }
    }

    printf("\n");

    return 0;
}
