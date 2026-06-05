#include <stdio.h>

int main() {
    int p[20], f[10], t[10], n, m, i, j, k, pos, faults = 0;

    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++) scanf("%d", &p[i]);

    for(i = 0; i < m; i++) f[i] = -1;

    for(i = 0; i < n; i++) {
        int hit = 0;
        for(j = 0; j < m; j++)
            if(f[j] == p[i]) { t[j] = i; hit = 1; }

        if(!hit) {
            pos = 0;
            for(j = 1; j < m; j++)
                if(f[j] == -1 || t[j] < t[pos]) pos = j;

            f[pos] = p[i];
            t[pos] = i;
            faults++;
        }
    }

    printf("Page Faults = %d", faults);
    return 0;
}
