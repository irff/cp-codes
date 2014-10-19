#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const long long INF = 2000111222333444555LL;

vector<int> v[30][120];

int bar, kol;
long long a[40][200];

int main() {
    while(scanf("%d%d", &bar, &kol) > 0) {
        R(i,0,bar) {
            R(j,0,kol) {
                scanf("%d", &a[i][j]);
                a[bar+i][j] = a[i][j];
            }
        }
        int mod = bar;
        bar*=2;
        R(i,0,bar) v[i][0].clear();
        R(i,0,bar) v[i][0].push_back(i);
        R(j,1,kol) {
            R(i,0,bar) {
                long long mins = INF;
                int path = 0;
                
                if( i > 0 and mins > a[i-1][j-1] ) { path = -1; mins = a[i-1][j-1]; }
                if( mins > a[i][j-1] ) { path = 0; mins = a[i][j-1]; }
                if( i < bar-1 and mins > a[i+1][j-1]) { path = 1; mins = a[i+1][j-1]; }
                
                v[i][j] = v[i+path][j-1];
                v[i][j].push_back(i);
                a[i][j] += mins;
            }
        }
        long long ans = INF;
        int pos = 0;
        R(i,0,bar) {
            if( ans > a[i][kol-1]) {
                ans = a[i][kol-1];
                pos = i;
            }
        }
        R(i,0,v[pos][kol-1].size()) {
            printf("%d", v[pos][kol-1][i]%mod+1);
            if(v[pos][kol-1].size()-1!=i) printf(" ");
            else printf("\n");
        }
        printf("%lld\n", ans);
    }
    return 0;
}
