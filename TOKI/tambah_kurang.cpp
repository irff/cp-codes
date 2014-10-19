#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


int n, target, a[50];
bool bisa = 0;
bool vis[40][75000];

void rek(int ke, int num) {
    //
    printf("%d %d\n", ke, num);
    if(vis[ke][num+36000]) return ;
    vis[ke][num+36000] = 1;
    if(ke>=n) {
        if(num==target) bisa = 1;
        return ;
    }
    rek(ke+1, num-a[ke]);
    rek(ke+1, num+a[ke]);
}

int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &a[i]);
    scanf("%d", &target);
    rek(1,a[0]);
    if(bisa) printf("ada\n");
    else printf("tidak ada\n");
    return 0;
}
