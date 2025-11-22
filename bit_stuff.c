#include<stdio.h>
int main(){
    int a[20],b[30],n,i,j=0,c=0;
    printf("Enter frame length: ");
    scanf("%d",&n);
    printf("Enter bits: ");
     for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        b[j++]=a[i];
        if(a[i]==1){
             c++;
        if(c==5)
            { b[j++]=0;
        c=0;
        } }
        else c=0;
    }
    printf("After stuffing: ");
    for(i=0;i<j;i++) printf("%d",b[i]);
    return 0;
}
