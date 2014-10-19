#include <cstdio>
#include <algorithm>
using namespace std;

int a[20], n;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) a[i] = i+1;
    bool bisa = 1;
    while(bisa) {
        bool tipe_a = 1, tipe_b = 1;
        for(int i=1; i<n; i++) {
            if(i%2==1 and i == n-1) {
                if(a[i] > a[i-1]) tipe_a=0;
                else tipe_b = 0;
            } else if(i%2==1) {
                if( a[i] > a[i-1] or a[i] > a[i+1]) tipe_a = 0;
                if( a[i] < a[i-1] or a[i] < a[i+1]) tipe_b = 0;
            }
        }
        if(tipe_a or tipe_b) {
            for(int i=0; i<n; i++) printf("%d",a[i]);
            printf("\n");
        }
        bisa = next_permutation(a, a+n);
    }
    scanf("\n");
    return 0;
}
