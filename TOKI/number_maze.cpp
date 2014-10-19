#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;

typedef multimap<int, PII> PQ;
int teskes, bar, kol, m[1002][1002];

PQ q;
int dist[1002][1002];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &bar, &kol);
        R(i,0,bar) {
            R(j,0,kol) {
                scanf("%d", &m[i][j]);
            }
        }
        q.insert(PQ::value_type(0,PII(0,0)));
        while(!q.empty()) {
            PQ::iterator it = q.begin();
            int a = it->second.first, b = it->second.second, w = it->first;
        }
    }
    return 0;
}
