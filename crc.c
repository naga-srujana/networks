#include <stdio.h>
#include <string.h>
#define N strlen(gen)
char data[30], gen[10], rem[10];
int i, j, dl;
void xor_op() {
    for (j = 1; j < N; j++)
        rem[j] = (rem[j] == gen[j]) ? '0' : '1';}
void crc() {
    for (i = 0; i < N; i++)
        rem[i] = data[i];
    do {
        if (rem[0] == '1') xor_op();
        for (j = 0; j < N - 1; j++) rem[j] = rem[j + 1];
        rem[j] = data[i++];
    } while (i <= dl + N - 1);
}

int main() {
    printf("Enter data to be transmitted: ");
    scanf("%s", data);
    printf("Enter the Generating polynomial: ");
    scanf("%s", gen);

    dl = strlen(data);
    for (i = dl; i < dl + N - 1; i++)
        data[i] = '0';
    data[i] = '\0';
    printf("----------------------------------------\n");
    printf("Data padded with n-1 zeros : %s\n", data);
    printf("----------------------------------------\n");
    crc();
    printf("CRC or Check value is : %s\n", rem);
    printf("----------------------------------------\n");
    for (i = dl; i < dl + N - 1; i++)
        data[i] = rem[i - dl];
    printf("Final data to be sent : %s\n", data);
    printf("----------------------------------------\n");
    printf("Enter the received data: ");
    scanf("%s", data);
    printf("-----------------------------\nData received: %s\n", data);
    crc();
    for (i = 0; (i < N - 1) && rem[i] != '1'; i++);
    printf(i < N - 1 ? "Error detected\n" : "No error detected\n");
}
