#include<stdio.h>
#include<stdlib.h>

void main() {
    int f[10], i = 0, j, w, n;
    printf("Enter the no of frames :");
    scanf("%d", &n);

    printf("Enter the window size :");
    scanf("%d", &w);

    for (j = 0; j < n; j++) {
        printf("\nEnter the frame %d value : ", j);
        scanf("%d", &f[j]);
    }

    float loss;
    printf("\nEnter loss probability (0 to 1): ");
    scanf("%f", &loss);

    while (i < n) {
        printf("\nSending frames : ");
        for (j = i; j < w + i && j < n; j++)
            printf("%d ", f[j]);

        int resend = -1;

        for (j = i; j < i + w && j < n; j++) {

            // loss condition updated for 0–1 probability
            float r = (float)rand() / RAND_MAX;

            if (r < loss) {
                printf("\nFrame %d is lost, resending %d", f[j], f[j]);
                resend = j;
                break;
            } else {
                printf("\nFrame %d received , Ack %d sent", f[j], f[j]);
            }
        }

        if (resend == -1)
            i += w;        // slide window
        else
            i = resend;    // Go-Back-N
    }

    printf("\nALL FRAMES SENT SUCCESSFULLY\n");
}
