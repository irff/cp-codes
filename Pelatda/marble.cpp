#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, q, kasus = 0, mid = 0, que=0;
int a[12000], b[12000], c[12000];

int binary(int ki, int ka) {
    mid = (ki+ka)/2;
    if(ki >= ka) return ki;
    if(b[mid] < que) {
        ki = mid+1;
    } else if(b[mid] > que) {
        ka = mid-1;
    } else if(b[mid] == que) {
        return mid;
    }
    return binary(ki, ka);
}

int main() {
    scanf("%d%d", &n, &q);
    while(n!=0 or q!=0) {
        kasus++;
        memset(b, 0, sizeof b);
        R(i,0,n) scanf("%d", &a[i]);
        sort(a,a+n);
        int ctr = 0;
        R(i,0,n) {
            if(i==0) b[0]=a[0],ctr++;
            else {
                if(b[ctr-1]!=a[i]) {
                    b[ctr]=a[i];
                    c[ctr]=i;
                    ctr++;
                }
            }
        }
        
        printf("CASE# %d:\n", kasus);
        R(i,0,q) {
            scanf("%d", &que);
            binary(0,ctr);
            if(b[mid]==que) printf("%d found at %d\n", que, c[mid]+1);
            else printf("%d not found\n", que);
        }
        scanf("%d%d", &n, &q);
    }
    return 0;
}
