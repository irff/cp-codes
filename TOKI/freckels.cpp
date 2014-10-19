#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef multimap<double,PII> PQ;

int V, teskes, p[120];
double px[120], py[120];
PQ q;

double dist(int a, int b) {
    double sx = fabs(px[a]-px[b])*fabs(px[a]-px[b]);
    double sy = fabs(py[a]-py[b])*fabs(py[a]-py[b]);
    return sqrt(sx+sy);
}

int find(int a) {
    if(p[a] == a) return a;
    return p[a] = find(p[a]);
}

void join(int a, int b) {
    p[find(a)] = p[find(b)];
}

bool same(int a, int b) {
    return find(a) == find(b);
}

int main() {
    scanf("%d", &teskes);
    bool tamax=0;
    while(teskes--) {
        double mst = 0.00;
        if(tamax) printf("\n");
        else tamax = 1;
        scanf("%d", &V);
        R(i,0,V) {
            scanf("%lf%lf", &px[i], &py[i]);
            p[i] = i;
        }
        R(i,0,V) {
            R(j,i+1,V) {
                q.insert(PQ::value_type(dist(i,j),PII(i,j)));
            }
        }
        while(!q.empty()) {
            PQ::iterator it = q.begin();
            int a = it->second.first, b = it->second.second;
            if(!same(a,b)) {
                join(a,b);
                mst+=it->first;
            }
            q.erase(it);
        }
        printf("%.2lf\n", mst);
    }
    return 0;
}
