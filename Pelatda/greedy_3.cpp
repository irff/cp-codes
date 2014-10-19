#include <cstdio>
#include <algorithm>
using namespace std;

int duit, a[100], nkoin, ans=0;
int main() {
    scanf("%d %d", &nkoin, &duit);
    for(int i=0; i<nkoin; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<nkoin; i++) {
        for(int j=i+1; j<nkoin; j++)
          if(a[i] < a[j]) { int t = a[i]; a[i]=a[j]; a[j]=t; }
    }
    for(int i=0; i<nkoin; i++) {
        if(duit>=a[i]) ans+=(duit/a[i]),duit%=a[i];
    }
    printf("%d\n", ans);
    return 0;
}
