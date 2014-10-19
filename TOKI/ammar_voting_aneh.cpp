#include <cstdio>
#include <cstdlib>
#include <cmath>

int n,m,x,ctr,i,pos,sisa;
int a[10000];

int main() {
    scanf("%d%d%d",&n,&m,&x);
    
    for (i=0 ; i<n ; i++) a[i] = i+1;
    sisa = n;
    pos = 0;
    
    while (sisa != 1) {
        
        ctr = x % ((sisa-1)*m+1);
        if (ctr == 0) ctr = (sisa-1)*m+1;
        
        if (ctr == 1) ctr = 0; else ctr = (ctr + m - 2) / m;
        
        pos = (pos + ctr) % sisa;
        sisa--;
        for (i=pos ; i<sisa ; i++) a[i] = a[i+1];
        
        pos = pos % sisa;
    }
    printf("%d\n",a[0]);

    scanf("\n");
    return 0;
}
