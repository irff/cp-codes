#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;
typedef pair<int,int> PII;
typedef multimap<double,PII> PQ;

PQ q;
int px[1200], py[1200];
int kasus = 0, teskes, V, p[1200];
double threshold;
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

double dist(int a, int b) {
    double sx = (px[a]-px[b])*(px[a]-px[b]), sy = (py[a]-py[b])*(py[a]-py[b]);
    return sqrt(sx+sy);
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int com = 1;
        double road = 0, rail = 0;
        scanf("%d%lf", &V, &threshold);
        R(i,0,V) {
            scanf("%d%d", &px[i], &py[i]);
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
            double w = it->first;
            if(!same(a,b)) {
                join(a,b);
                if(w > threshold) {
                    com++;
                    rail+=w;
                } else road+=w;
            }
            q.erase(it);
        }
        printf("Case #%d: %d %.lf %.lf\n", ++kasus, com, road, rail);
    }
    return 0;
}
