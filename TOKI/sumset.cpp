#include <cstdio>
#include <functional>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
int a[1200];
map<int,int> m;
int main() {
    while(scanf("%d", &n), n) {
        m.clear();
        R(i,0,n) scanf("%d", &a[i]);
        sort(a,a+n,greater<int>());
        R(i,0,n) m[a[i]]=i+1;
        
        bool bisa = 0;
        R(i,0,n) {
            R(j,i+1,n) {
                R(k,j+1,n) {
                    int x = a[i]-(a[j]+a[k]);
                    int no = m[x];
                    if(no and no-1!=i and no-1!=j and no-1!=k) {
                        printf("%d\n", a[i]);
                        bisa = 1;
                    }
                    if(bisa) break;
                }
                if(bisa) break;
            }
            if(bisa) break;
        }
        if(!bisa) printf("no solution\n");
    }

    return 0;
}
