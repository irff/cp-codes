#include <cstdio>

int n;
bool a[120000];
int main() {
    scanf("%d", &n);
    for(int i=0; i<n-2; i++) {
        int num;
        scanf("%d", &num); a[num]=1;
    }
    for(int i=1; i<=n; i++) {
        if(!a[i]) printf("%d\n", i);
    }
    return 0;
}
