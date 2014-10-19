#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
short a[15];
int main() {
    scanf("%d", &n);
    if(n<3) return 0;
    for(int i=0; i<n; i++) a[i]=i+1;
    
    while( next_permutation(a, a+n) ) {
        bool jadi=1;
        for(int i=1; i<n-1; i++) {
            if( !(a[i] > a[i-1] and a[i] > a[i+1]) and !(a[i] < a[i-1] and a[i] < a[i+1]) ){ jadi=0; break; }
        }
        if(jadi) {
            for(int i=0; i<n; i++) printf("%d ", a[i]);
            printf("\n");
        }
    }
    return 0;
}
