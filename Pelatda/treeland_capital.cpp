#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int j=int(_a);i>=int(_b);i--)

const int INF = 2000111222;

typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef map<PII, int> MIE;

int V;
MIE memo;
bool vis[201000];
VI adj[201000], inv[201000];

int rek(int a, int b) {
  if(!vis[b]) {
    vis[b] = 1;
    
    if(memo.find(PII(a,b)) == memo.end()) {
        int ans = 0;
        int len_out = adj[b].size();
        R(i,0,len_out) {
            ans+=rek(b,adj[b][i]);
        }
    
        int len_in = inv[b].size();
        R(i,0,len_in) {
            if(inv[b][i]!=a) ans+=rek(b,inv[b][i])+1;
        }
        return memo[PII(a,b)] = ans;
    }
    return memo[PII(a,b)];
  
  }
  return 0;
}

int main() {
    scanf("%d", &V);
    R(i,0,V-1) {
        int va, vi;
        scanf("%d%d", &va, &vi);
        va--; vi--;
        adj[va].push_back(vi);
        inv[vi].push_back(va);
    }
    int mins = INF;
    /*
    int now = rek(-1,3);
    printf("%d\n", now);
    */
    R(i,0,V) {
        int now = rek(-1, i);
        //printf("%d ", now);
        mins = min(now, mins);
    }
    
    //printf("\n");
    printf("%d\n", mins);
    R(i,0,V) {
        if(memo[PII(-1,i)]==mins) printf("%d ", i+1);
    }
    return 0;
}
