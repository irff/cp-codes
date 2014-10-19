#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[120000];
int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    reverse(a, a+n);
    for(int i=0; i<m; i++) {
        for(int j=n; j>=0; j--) {
            if(j==n) {
                a[j]=0;
            } else {
                a[j]=a[j+1]^a[j];
            }
        }
        n++;
    }
    for(int i=n-1; i>=0; i--) printf("%d\n", a[i]);
    return 0;
}
