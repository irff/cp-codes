#include <cstdio>
#include <algorithm>
using namespace std;


int a[1200], lisa[1200], lisi[1200], n;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) lisa[i]=1,lisi[i]=1;
    for(int i=1; i<n; i++) {
      for(int j=0; j<i; j++) {
          if(a[i] > a[j]) lisa[i] = max(lisa[i], lisa[j]+1);
      }
    }
    
    for(int i=n-2; i>=0; i--) {
      for(int j=i+1; j<n; j++) {
          if(a[i] > a[j]) lisi[i] = max(lisi[i], lisi[j]+1);
      }
    }
    
    int maks = -1, pos=0;
    for(int i=0; i<n; i++) {
        if(lisa[i]+lisi[i]-1>maks) maks=lisa[i]+lisi[i]-1,pos=i;
    }
    printf("%d %d\n", pos+1, maks);

    return 0;
}
