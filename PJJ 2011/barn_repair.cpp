/*
    ID: irfan1
    LANG: C++
    TASK: barn1
*/

#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int m, n, occupied, cows[300], space[300];
int main() {
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    scanf("%d%d%d", &m, &n,&occupied);
    R(i,0,occupied) scanf("%d", &cows[i]);
    
    int ctr=0;
    bool start = 0;
    sort(cows, cows+occupied);
    R(i,1,occupied) {
        if(cows[i]-cows[i-1]>1) {
            space[ctr++]=cows[i]-cows[i-1]-1;
        }
    }
    sort(space,space+ctr,greater<int>());
    int jml = 0;
    R(i,0,m-1) {
        jml+=space[i];
    }
    jml+=cows[0]-1+n-cows[occupied-1];
    printf("%d\n", n-jml);
    return 0;
}
