#include <stdio.h>
int main() {
    int bs, rate, n, pkt[10], i, stored=0;
    printf("Enter bucket size, output rate, no. of packets: ");
    scanf("%d%d%d", &bs, &rate, &n);
    printf("Enter packet sizes: ");
    for(i=0;i<n;i++)
        scanf("%d",&pkt[i]);

    for(i=0;i<n;i++) {
        stored += pkt[i];
        if(stored > bs){
             printf("\nBucket overflow!");
    stored = bs;
    }
        printf("\nTime %d: In=%d Sent=%d Left=%d", i+1, pkt[i],
               (stored>=rate)?rate:stored,
               (stored>=rate)?stored-rate:0
               );
        stored = (stored>=rate)?stored-rate:0;
    }
    while(stored>0){
        printf("\nSending... Sent=%d Left=%d",
               (stored>=rate)?rate:stored,
               (stored>=rate)?stored-rate:0);
        stored = (stored>=rate)?stored-rate:0;
    }
    printf("\nDone.");
}
