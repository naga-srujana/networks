#include <stdio.h>
#include <string.h>
void main() {
 int i = 0, j = 0, n, pos;
 char a[20], b[50], ch;
 printf("Enter string:\n");
 scanf("%s", a);
 n = strlen(a);
 printf("Enter position:\n");
 scanf("%d", &pos);
 while (pos > n || pos < 1) {
 printf("Invalid position, enter again: ");
 scanf("%d", &pos);
 }
 printf("Enter the character to stuff:\n");
 scanf(" %c", &ch);

 b[0] = 'd';
 b[1] = 'l';
 b[2] = 'e';
b[3] = 's';
 b[4] = 't';
 b[5] = 'x';
 j = 6;

 while (i < n) {

 if (i == pos - 1) {
 b[j++] = 'd';
 b[j++] = 'l';
 b[j++] = 'e';
 b[j++] = ch;
 b[j++] = 'd';
 b[j++] = 'l';
 b[j++] = 'e';
 }

 if (i + 2 < n && a[i] == 'd' && a[i + 1] == 'l' && a[i + 2] == 'e') {
 b[j++] = 'd';
 b[j++] = 'l';
 b[j++] = 'e';
 }

 b[j++] = a[i++];
 }

 b[j++] = 'd';
 b[j++] = 'l';
 b[j++] = 'e';
 b[j++] = 'e';
 b[j++] = 't';
 b[j++] = 'x';
 b[j] = '\0';
 printf("\nFrame after stuffing:\n%s\n", b);
}
