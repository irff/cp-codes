#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define x first
#define y second

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

vector<int> pset(1000);

int mindist,teskes,n;
char s[600][5];
void initset(int _size) { R(i,0,_size+1) pset[i]=i; }
int findset(int i) { return (pset[i]==i)?i:(pset[i]=findset(pset[i])); }
void join(int i, int j) { pset[findset(i)]=pset[findset(j)]; }
bool sameset(int i, int j) { return findset(i)==findset(j); }

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        mindist=2000111222;
        scanf("%d", &n);
        R(i,0,n) {
            scanf("%s", s[i]);
        }
        vector<PIII> edges;
        R(i,0,n) {
            R(j,i+1,n) {
                int d=0;
                for(int k=0; k<4; k++) {
                    int na=s[i][k]-'0', nb=s[j][k]-'0';
                    d+=min( (na-nb+10)%10, (nb-na+10)%10);
                }
                edges.push_back( PIII(d, PII(i,j)) );
            }
            int disttozero=0;
            R(j,0,4) disttozero+=min( (s[i][j]-'0'+10)%10, ('0'-s[i][j]+10)%10);
            mindist=min(mindist, disttozero);
        }
        sort(edges.begin(), edges.end());
        int cost=0; initset(n);
        int nedge=edges.size();
        R(i,0,nedge) {
            PIII f=edges[i];
            if(!sameset(f.y.x, f.y.y) ) {
                cost+=f.x;
                join(f.y.x, f.y.y);
            }
        }
        printf("%d\n", cost+mindist);
    }
    return 0;
}
