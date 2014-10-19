#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


int V, awal, akhir;
string s[120];
vector<int> adj[120];
int memo[20][20], now = 0, maks = 0;
bool vis[20];

int dist(string a, string b) {
    int lena = a.length(), leni = b.length();
    if(!memo[lena][leni]) {
        if(lena == 0) return memo[lena][leni] = leni;
        if(leni == 0) return memo[lena][leni] = lena;
        int ans = 2000111222;
        string x = a.substr(1), y = b.substr(1);
        if(a[0] == b[0]) return memo[lena][leni] = min(ans, dist(x, y));
        ans = min(ans, dist(x,y)+1);
        ans = min(ans, dist(a,y)+1);
        ans = min(ans, dist(x,b)+1);
        return memo[lena][leni] = ans;
    }
    return memo[lena][leni];
}

void dfs(int u) {
    now++;
    vis[u] = 1;
    int len = adj[u].size();
    R(i,0,len) {
        if(!vis[ adj[u][i] ]) {
            dfs(adj[u][i]);
        }
    }
}
int main() {
    scanf("%d%d%d", &V, &awal, &akhir);
    R(i,0,V) {
        cin >> s[i];
    }
    R(i,0,V) {
        R(j,i+1,V) {
            memset(memo, 0, sizeof memo);
            int d = dist(s[i], s[j]);
            if(d >= awal and d <= akhir) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                //printf("%d %d -> %d\n", i, j, d);
            }
            
        }
    }
    R(i,0,V) {
        if(!vis[i]) {
            now = 0;
            dfs(i);
            maks = max(maks, now);
        }
    }
    printf("%d\n", maks);
    return 0;
}
