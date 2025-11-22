#include <stdio.h>
int main() {
    int n, i, j, a[10][10], root;
    printf("Enter no. of nodes: "); scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    printf("Enter root node: ");
    scanf("%d",&root);
    printf("\nAdjacent nodes of %d:\n",root);
    for(j=1;j<=n;j++)
        if(a[root][j]==1 || a[j][root]==1)
         printf("%d ",j);
    printf("\nNon-adjacent nodes:\n");
    for(i=1;i<=n;i++)
    if(i!=root && a[root][i]==0 && a[i][root]==0)
    printf("%d ",i);
}
