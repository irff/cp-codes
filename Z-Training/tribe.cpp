#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
int V,E;

vector<int> adj[50111];
bool num[50111];
set<int> se;
int bfs(int s){
     int conn=0;
     queue<int> q;
     q.push(s);
     while(!q.empty()){
         conn++;
         int u=q.front(); q.pop();
         num[u]=1;
         for(vector<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++){
             if(!num[*it]) q.push(*it);
             num[*it]=1;
         }
     
     }
     return conn;
}
int main(){
    int MAX=-1;
    scanf("%d%d", &V,&E);
    R(i,0,E){
        int v1,v2;
        scanf("%d%d", &v1,&v2);
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    R(i,0,V+1){
        if(!num[i]){
            MAX=max(MAX,bfs(i));
        }
    }
    printf("%d\n", MAX);
    return 0;
}
