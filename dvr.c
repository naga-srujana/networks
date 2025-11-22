#include <stdio.h>

#define INF 999
#define MAX 10

struct Router {
    int dist[MAX];
    int nextHop[MAX];
} routingTable[MAX];

int main() {
    int cost[MAX][MAX];
    int n, i, j, k;
    int updated;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(i == j) cost[i][j] = 0;

            routingTable[i].dist[j] = cost[i][j];
            routingTable[i].nextHop[j] = j;
        }
    }
    do {
        updated = 0;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                for(k = 0; k < n; k++) {

                    if(routingTable[i].dist[j] > cost[i][k] + routingTable[k].dist[j]) {

                        routingTable[i].dist[j] = cost[i][k] + routingTable[k].dist[j];
                        routingTable[i].nextHop[j] = k;
                        updated = 1;
                    }
                }
            }
        }

    } while(updated);

    for(i = 0; i < n; i++) {
        printf("\nRouting Table for Node %d:\n", i + 1);
        printf("Destination\tNext Hop\tDistance\n");

        for(j = 0; j < n; j++) {
            printf("%d\t\t%d\t\t%d\n", j + 1, routingTable[i].nextHop[j] + 1, routingTable[i].dist[j]);
        }
    }

    return 0;
}
