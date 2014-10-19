#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
int p[100];
int main() {
    scanf("%d", &n);
    while(n!=0) {
        memset(p, 0, sizeof p);
        for(int i=2; i<=n; i++) {
            int x = i, c = 2;
            while(x>1) {
                while(x%c==0) p[c]++,x/=c;;
                c++;
            }
        }
        if(n<10) printf("  ");
        else if(n<100) printf(" ");
        printf("%d! =", n);
        int ctr = 0; bool just=0;
        for(int i=2; i<=n; i++) {
            if(p[i]) {
                if(just) printf("      "), just = 0;;
                if(p[i]<10) printf("  ");
                else if(p[i]<100) printf(" ");
                printf("%d", p[i]);
                ctr++;
                if(ctr%15==0) printf("\n"), just = 1;
            }
        }
        if(ctr%15!=0) printf("\n");
        scanf("%d", &n);
    }

    return 0;
}
