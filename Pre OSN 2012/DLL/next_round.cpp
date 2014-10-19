#include <cstdio>

int n, k, a[200];

int main() {
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    while(k < n and a[k] == a[k-1] and a[k-1]!=0) {
        k++;
    }
    if(a[k-1]==0) printf("0\n");
    printf("%d\n", k);
    return 0;
}
