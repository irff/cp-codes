#include <cstdio>
using namespace std;

int a[510000], b[510000], x[12000], y[12000];
long long ans = 0;
char s[1000];
int n;
int main() {
    gets(s);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        x[ a[i] ]++; y[ b[i] ]++;
    }
    for(int i=0; i<n; i++) {
        ans = ans + (x[ a[i] ]-1)*(y[ b[i] ]-1);
    }
    printf("%lld\n", ans);
    return 0;
}
