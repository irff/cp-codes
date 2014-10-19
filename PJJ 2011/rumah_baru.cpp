#include <cstdio>
#include <algorithm>
using namespace std;

bool m[300][300];
int n,a[100],b[100], hasil=0;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    for(int i=0; i<n; i++) m[ 150+a[i] ][ 150+b[i] ] = 1;
    for(int i=50; i<=250; i++) {
        for(int j=50; j<=250; j++) {
            bool atas=0, kanan=0, kiri=0, bawah=0;
            for(int k=i-1; k>=50; k--) if(m[k][j]==1) { atas=1; break; }
            for(int k=j+1; k<=250; k++) if(m[i][k]==1) { kanan=1; break; }
            for(int k=i+1; k<=250; k++) if(m[k][j]==1) { bawah=1; break; }
            for(int k=j-1; k>=50; k--) if(m[i][k]==1) { kiri=1; break; }
            if(atas and kanan and bawah and kiri) {
                hasil++;
                //printf("%d %d\n", i-150, j-150);
            }
        }
    }
    printf("%d\n", hasil);
    return 0;
}
