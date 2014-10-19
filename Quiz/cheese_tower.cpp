#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef pair<int,int> II;
typedef pair<II, int> III;
int n, target, kepeyokan;

int w[120], v[120], maks = -2000111222;
//map<III,bool> m;
bool memo[1000500][2];
void rek(int sisa, int value, bool peyok) {
    //printf("%d %d %d\n", sisa, value, peyok);
    
    if(m[III(II(sisa,value),peyok)] == 1) return ;
    m[III(II(sisa,value),peyok)] = 1;
    
    if(sisa == 0) {
        //printf("x");
        maks = max(maks,value);
        return ;
    } else if(sisa < 0) return ;
    
    R(i,0,n) {
        if(peyok) {
            if(sisa >= w[i]-(w[i]/5)) rek(sisa-(w[i]-w[i]/5), value+v[i], 1);
        } else {
            if(sisa >= w[i]) {
                if(w[i] >= kepeyokan) rek(sisa-w[i], value+v[i], 1);
                else rek(sisa-w[i], value+v[i], 0);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &target, &kepeyokan);
    R(i,0,n) scanf("%d%d", &v[i], &w[i]);
    rek(target, 0, false);
    printf("%d\n", maks);
    return 0;
}
