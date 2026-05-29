#include <stdio.h>

int main() {
    int b[10], p[10], alloc[10], nb, np;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter block sizes: ");
    for(int i=0;i<nb;i++) scanf("%d",&b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter process sizes: ");
    for(int i=0;i<np;i++){ scanf("%d",&p[i]); alloc[i]=-1; }

    // Best-Fit allocation
    for(int i=0;i<np;i++){
        int best=-1;
        for(int j=0;j<nb;j++)
            if(b[j]>=p[i] && (best==-1 || b[j]<b[best])) best=j;
        if(best!=-1){ alloc[i]=best; b[best]-=p[i]; }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(int i=0;i<np;i++)
        if(alloc[i]==-1) printf("%d\t%d\tNot Allocated\n", i+1, p[i]);
        else printf("%d\t%d\t%d\n", i+1, p[i], alloc[i]+1);
}
