#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef map<string,int> MSI;
typedef vector<int> VI;

MSI m;
string in[200];
bool vis[200];
bool adj[200][200];
int ingoing[200];
int V, E, kasus = 0;

int main() {
    while(scanf("%d", &V) > 0) {
        m.clear(); kasus++; 
        memset(adj, 0, sizeof adj);
        memset(ingoing, 0, sizeof ingoing);
        memset(vis, 0, sizeof vis);
        R(i,0,V) {
            cin >> in[i];
            m[ in[i] ] = i;
        }
        scanf("%d", &E);
        R(i,0,E) {
            string a, b;
            cin >> a >> b;
            int va = m[a], vi = m[b];
            if(!adj[va][vi]) {
                adj[va][vi] = 1;
                ingoing[vi]++;
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:", kasus);
        bool done = 0;
        while(!done) {
            done = 1;
            R(i,0,V) {
                if(!vis[i] and ingoing[i] == 0) {
                    done = 0;
                    vis[i] = 1;
                    cout << " " << in[i];
                    R(j,0,V) {
                        if(adj[i][j]) ingoing[j]--;
                    }
                    i = -1;
                }
                
            }
        }
        printf(".\n\n");
    }
    return 0;
}
