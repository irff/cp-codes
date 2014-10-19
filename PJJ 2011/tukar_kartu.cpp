#include <algorithm>
#include <cstdio>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a[1000],n,ntukar=0;
int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j],a[j+1]);
                ntukar++;
            }
        }
    }
    printf("%d\n", ntukar);

    return 0;
}
