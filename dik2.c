#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start) {

    int distance[MAX], visited[MAX], i, j, minDist, nextNode;
    for (i = 0; i < n; i++) {
        distance[i] = (graph[start][i] == 0 ? INF : graph[start][i]);
        visited[i] = 0;
    }
    distance[start] = 0;
    for (i = 0; i < n; i++) {
        minDist = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < minDist) {
                minDist = distance[j];
                nextNode = j;
            }
        }

        visited[nextNode] = 1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[nextNode][j] != 0 &&
                distance[nextNode] + graph[nextNode][j] < distance[j]) {

                distance[j] = distance[nextNode] + graph[nextNode][j];
            }
        }
    }
    printf("\nShortest distances from node %d:\n", start);
    for (i = 0; i < n; i++) {
        printf("To node %d = %d\n", i, distance[i]);
    }
}

int main() {
    int graph[MAX][MAX], n, start, i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 = no link):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
