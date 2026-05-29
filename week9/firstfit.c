#include <stdio.h>

int main() {
    int nb, np;
    printf("Blocks: "); scanf("%d", &nb);
    int b[nb];
    for(int i=0;i<nb;i++){ printf("B%d: ",i+1); scanf("%d",&b[i]); }

    printf("Processes: "); scanf("%d", &np);
    int p[np], a[np];
    for(int i=0;i<np;i++){ printf("P%d: ",i+1); scanf("%d",&p[i]); a[i]=-1; }

    for(int i=0;i<np;i++)
        for(int j=0;j<nb;j++)
            if(b[j]>=p[i]){ a[i]=j; b[j]-=p[i]; break; }

    printf("\nProc\tSize\tBlock\n");
    for(int i=0;i<np;i++)
        if(a[i]!=-1) printf("%d\t%d\t%d\n",i+1,p[i],a[i]+1);
        else printf("%d\t%d\tNA\n",i+1,p[i]);
}
