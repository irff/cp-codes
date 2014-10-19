#include <cstdio>

int n,total,hasil,kantong[10100];
int main() {
    while(scanf("%d", &n) and n!=-1) {
        total=0,hasil=0;
        for(int i=0; i<n; i++) {
            scanf("%d", &kantong[i]);
            total+=kantong[i];
        }
        if(total%n!=0) printf("-1\n");
        else {
            total/=n;
            for(int i=0; i<n; i++) {
                if(kantong[i] > total) hasil+=kantong[i]-total;
            }
            printf("%d\n", hasil);
        }
    }
    return 0;
}
