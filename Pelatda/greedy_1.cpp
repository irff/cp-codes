#include <cstdio>

int n, cap, a[1000], ans = 0;
int main() {
    scanf("%d%d", &n, &cap);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) if(a[i] < a[j]) { 
            int tmp=a[i]; a[i]=a[j]; a[j]=tmp;
        }
    }
    for(int i=0; i<n; i++) {
        if(a[i] <= cap) cap-=a[i], ans+=a[i];
    }
    printf("%d\n", ans);
    return 0;
}
