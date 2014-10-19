#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef multimap<int,PII> PQ;

PQ q;
int V, E, p[1200];

int find(int a) {
    if(p[a] == a) return a;
    return p[a] = find(p[a]);
}

bool same(int a, int b) {
    return find(a)==find(b);
}

void join(int a, int b) {
    p[find(a)] = find(b);
}

int main() {
    while(scanf("%d%d", &V, &E), V) {
        R(i,0,V+1) p[i] = i;
        R(i,0,E) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            q.insert(PQ::value_type(w,PII(a,b)));
        }
        bool bisa = 0;
        while(!q.empty()) {
            PQ::iterator it = q.begin();
            int x = it -> second.first, y = it -> second.second;
            if(same(x,y)) {
                if(bisa) printf(" ");
                else bisa = 1;
                printf("%d", it -> first);
            } else {
                join(x,y);
            }
            q.erase(it);
        }
        if(!bisa) printf("forest");
        printf("\n");
    }
    return 0;
}
