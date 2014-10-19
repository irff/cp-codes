#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;

typedef struct {
    int x,y,w;
} edges;

int teskes, V, E, tree[120], p[120];
PII pq[12000];
edges e[12000];

int find(int a) {
    if(p[a] == a) return a;
    return p[a] = find(p[a]);
}

bool same(int a, int b) {
    return find(a)==find(b);
}

void join(int a, int b) {
    p[find(a)] = p[find(b)];
}

void refresh() {
    R(i,0,V) p[i] = find(i);
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int mst = 0, second_best = 2000111222;
        scanf("%d%d", &V, &E);
        R(i,0,V) p[i] = i;
        R(i,0,E) {
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
            e[i].x--, e[i].y--;
            pq[i] = PII(e[i].w,i);
        }
        sort(pq, pq+E);
        int ctr = 0;
        R(i,0,E) {
            edges a = e[ pq[i].second ];
            if(!same(a.x, a.y)) {
                mst+=a.w;
                join(a.x,a.y);
                tree[ctr++] = pq[i].second;
            }
        }
        R(i,0,ctr) {
            int now = 0;
            R(j,0,V) p[j] = j;
            R(j,0,E) {
                int black = tree[i];
                if(pq[j].second != black) {
                    edges a = e[ pq[j].second ];
                    if(!same(a.x, a.y)) {
                        now+=a.w;
                        join(a.x, a.y);
                    }
                }
            }
            int dewe = 0;
            refresh();
            R(j,0,V) if(p[j]==j) dewe++;
            if(dewe==1) second_best = min(second_best, now);
        }
        printf("%d %d\n", mst, second_best);
    }


    return 0;
}
