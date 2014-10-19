#include <cstdio>
#include <cstdlib>

int i,n,lok[100000],mak[100000],tmp,tukar,satu,dua;

int main() {
    scanf("%d",&n);
    for (i=1 ; i<=n ; i++) {
        scanf("%d",&mak[i]);
        lok[mak[i]] = i;
    }
    
    for (i=1 ; i<=n ; i++) if (mak[i] != i) {
        tukar++;
        satu = i;
        dua = lok[i];
        
        tmp = mak[satu];
        mak[satu] = mak[dua];
        mak[dua] = tmp;
        
        lok[i] = i;
        lok[mak[dua]] = dua;
    }
    
    printf("%d\n",tukar);
}
