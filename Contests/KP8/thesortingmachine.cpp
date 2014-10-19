#include <cstdio>
#include <algorithm>
using namespace std;

int teskes,n;
int a[120];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        sort(a,a+n);
        for(int i=0; i<n; i++) { 
            printf("%d", a[i]);
            if(i!=n-1) printf(" ");
        }
        printf("\n\n");
    }
    return 0;
}
