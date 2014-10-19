#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(x) push_back(x)
typedef vector<int> VI;
typedef map<int,int> MI;

MI rep, v;
VI adj[100111], ans;
bool vis[100111];
int ctr = 0, E, deg[100111];


void dfs(int x) {
    stack<int> q;
    q.push(x);
    vis[x] = 1;
    while(!q.empty()) {
      int u = q.top(); q.pop();
      ans.push_back(v[u]);
      int len = adj[u].size();
      R(i,0,len) {
          if(!vis[ adj[u][i] ]) {
              vis[ adj[u][i] ] = 1;
              q.push(adj[u][i]);
          }
      }
    }
}

int main() {
    scanf("%d", &E);
    int ctr = 1, a=0, b =0;
    R(i,0,E-1) {
        scanf("%d%d", &a, &b);
        if(!rep.count(a)) {
            v[ctr] = a;
            rep[a] = ctr;
            ctr++;
        }
        if(!rep.count(b)) {
            v[ctr] = b;
            rep[b] = ctr;
            ctr++;
        }
        adj[rep[a]].pb(rep[b]);
        adj[rep[b]].pb(rep[a]);
        deg[rep[a]]++;
        deg[rep[b]]++;
        
    }
    int to = -1, from = -1, start = 2000111222;
    
    R(i,0,ctr) {
        if(deg[i]%2) {
            if(start > v[i]) {
                start = v[i];
                to = i;
            }
        }
    }
    
    dfs(to);
    bool tamax = 0;
    int len = ans.size();
    R(i,0,len) {
        if(tamax) cout << " ";
        else tamax=1;
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
