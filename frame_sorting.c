#include <stdio.h>
struct Frame { int id; char data[50]; } f[10], t;

int main() {
    int n,i,j;
    printf("Enter number of frames: ");
    scanf("%d",&n);
    printf("enter input as id,data :");
    for(i=0;i<n;i++)
        scanf("%d %s",&f[i].id,f[i].data);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(f[i].id>f[j].id)
                { t=f[i];
            f[i]=f[j];
             f[j]=t; }

    printf("\nCorrect order:\n");
    for(i=0;i<n;i++) printf("ID:%d Data:%s\n",f[i].id,f[i].data);

    printf("\nMessage: ");
    for(i=0;i<n;i++) printf("%s ",f[i].data);
}
