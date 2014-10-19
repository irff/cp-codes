#include <cstdio>
#include <algorithm>
using namespace std;

int teskes, n, c[200];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int a = 0, b = 0, diff = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &c[i]);
        sort(c, c+n);
        for(int i=n-1; i>=0; i--) {
           if(a<b) a+=c[i];
           else b+=c[i];
        }
        diff = abs(a-b);
        printf("%d\n", diff);
    }
    return 0;
}
