// BFS (Basic Form)
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define VI vector<int> 
#define MI map<int,int>
#define QI queue<int>
#define R(i,a,b) for(int i=int(a); i<int(b); i++) // Simple Loop Macro
#define RV(v,it) for(VI::iterator (it)=v.begin(); (it)!=v.end(); (it)++) // Vector Loop Macro
VI adj[10000];
MI dist;
QI q;
int n,source,num1,num2;
void bfs(int s){
     q.push(s);  dist[s]=0; // Start from source
     
     while(!q.empty()){
         int u = q.front(); q.pop(); // Queue Layer by layer
         printf("Visit %d. Layer %d\n", u, dist[u]);
         RV(adj[u],v)
             if(!dist.count(*v)){
                 dist[*v]=dist[u]+1;
                 q.push(*v);
             }
     }
}

int main(){
    scanf("%d", &n); // Number of Edges
    R(i,0,n){
        scanf("%d %d", &num1, &num2);
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }
    scanf("%d", &source);
    bfs(source);
    return 0;
}
