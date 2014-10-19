#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef pair<int,PII> PIE;

vector<PIE> q;

int N, E, m[400][400];
long long ans = 0;
int parent[400];
int findparent(int v) {
    return (parent[v]==v)? v : parent[v] = findparent(parent[v]);
}
int main() {
    scanf("%d", &N);
    R(i,0,N) {
        scanf("%d", &m[N][i]);
        m[i][N] = m[N][i];
    }
    R(i,0,N) R(j,0,N) scanf("%d", &m[i][j]);
    N++;
    R(i,0,N) {
        R(j,i+1,N) {
            q.push_back(PIE(m[i][j],PII(i,j)));
        }
    }
    /*
    R(i,0,N) {
        R(j,0,N) printf("%d%c", m[i][j], j==N-1?'\n':' ');
    }
    */
    int E = q.size();
    sort(q.begin(), q.end());
    R(i,0,N+2) parent[i] = i;
    int va, vi, c, pa, pi;
    
    R(i,0,E) {
        va = q[i].second.first, vi = q[i].second.second, c = q[i].first;
        //printf("%d %d %d\n", va, vi, c);
        pa = findparent(va); pi = findparent(vi);
        if(pa!=pi) {
            ans += c;
            parent[pa] = parent[pi];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
