#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[150];
int main() {
    n=4;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    bool can=0, segment=0;
    for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
        for(int k=j+1; k<n; k++) {
            if(a[i]+a[j] > a[k]) can=1;
            if(a[i]+a[j] == a[k]) segment=1;
        }
      }
    }
    if(can) printf("TRIANGLE\n");
    else if(segment) printf("SEGMENT\n");
    else printf("IMPOSSIBLE\n");
    return 0;
}
