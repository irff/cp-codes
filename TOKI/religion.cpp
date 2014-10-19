#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int p[51000];
bool m[51000];
int V, E;
int num_set = 0, kasus = 1;
int find(int a) {
    return (p[a]==a) ? a : (p[a] = find(p[a]));
}

void join(int a, int b) {
    p[find(a)] = find(b);
}

void refresh() {
    R(i,1,V+1) p[i] = find(i);
}

int main() {
    while(scanf("%d%d", &V, &E), V, E) {
        R(i,0,V+2) p[i] = i, m[i] = 0;
        R(i,0,E) {
            int a, b; scanf("%d%d", &a, &b);
            join(a,b);
        }
        refresh();
        num_set = 0;
        R(i,1,V+1) m[p[i]]=1;
        R(i,1,V+1) if(m[i]) num_set++;
        printf("Case %d: %d\n", kasus++, num_set);
    }
    return 0;
}
