#include <stdio.h>

int main() {
    int p[20], f[10], n, m, i, j, k, faults = 0, hit, pos, far;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++) f[i] = -1;

    for(i = 0; i < n; i++) {
        hit = 0;

        for(j = 0; j < m; j++)
            if(f[j] == p[i]) hit = 1;

        if(!hit) {
            faults++;
            pos = -1; far = -1;

            for(j = 0; j < m; j++) {
                for(k = i + 1; k < n; k++)
                    if(f[j] == p[k]) break;

                if(k == n) { pos = j; break; }
                if(k > far) { far = k; pos = j; }
            }
            f[pos] = p[i];
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
