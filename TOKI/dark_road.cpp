#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef multimap<int,PII> PQ;

int V, E, p[200111];
PQ q;

int find(int a) {
    if(p[a] == a) return a;
    return p[a] = find(p[a]);
}

void join(int a, int b) {
    p[find(a)] = p[find(b)];
}

bool same(int a, int b) {
    return find(a)==find(b);
}

int main() {
    while(scanf("%d%d", &V, &E), V) {
        R(i,0,V) p[i] = i;
        R(i,0,E) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            q.insert(PQ::value_type(w,PII(a,b)));
        }
        int saved = 0;
        while(!q.empty()) {
            PQ::iterator it = q.begin();
            int a = it->second.first, b = it->second.second;
            if(same(a,b)) {
                saved+=it->first;
            } else join(a,b);
            q.erase(it);
        }
        printf("%d\n", saved);
    }
    return 0;
}
