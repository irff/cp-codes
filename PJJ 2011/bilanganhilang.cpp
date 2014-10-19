#include <cstdio>

bool a[100200];
int n,num;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n-2; i++) {
        scanf("%d", &num);
        a[num]=1;
    }
    for(int i=1; i<=n; i++) if(a[i]==0) printf("%d\n", i);
    return 0;
}
