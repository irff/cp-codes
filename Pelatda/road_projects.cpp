#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef pair<int,PII> PIE;
typedef long long LLD;

PIE edges[201000];

int V,E,X;
LLD ans = 0;
int parent[101000];

int findparent(int n) {
    return (parent[n]==n)?n:parent[n] = findparent(parent[n]);
}

int main() {
    scanf("%d%d%d", &V, &E, &X);
    R(i,0,E) {
        int va, vb, cost;
        scanf("%d%d%d", &va, &vb, &cost);
        va--; vb--;
        edges[i] = PIE(cost,PII(va,vb));
    }
    sort(edges, edges+E);
    for(int i=0; i<V+2; i++) parent[i]=i;
    register int va, vi, pa, pi, c;
    register PIE now;
    register int i = 0;
    
    for(i = 0; i<E; i++) {
        now = edges[i];
        va  = now.second.first, vi = now.second.second;
        c   = now.first;
        pa  = findparent(va), pi = findparent(vi);
        if(pa == pi) {
            if(X > c) ans += (X-c);
        } else {
            parent[pa]=parent[pi];
            ans += (X-c);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
