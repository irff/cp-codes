#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)
#define VR(c,it) for(VP::iterator it=(c).begin(); it!=(c).end(); it++)

const int INF=2000111222;
typedef pair<int,int> PII;
typedef vector<PII> VP;

VP adj[200];
int M,E,V,S,T;

int main(){
    scanf("%d%d%d%d", &V,&S,&T,&E);
    R(i,0,E){
        int v1,v2,w;
        scanf("%d%d%d", &v1,&v2,&w);
        adj[v2].push_back(PII(v1,w));
    }
    // process (DIJK)
    vector<int> dist(V+2,INF);
    priority_queue<PII,VP,greater<PII> > pq;
    dist[S]=0;
    pq.push(PII(0,S));
    
    while(!pq.empty()){
        PII TOP=pq.top(); pq.pop();
        int d=TOP.first, u=TOP.second;
        if(d==dist[u]){
            VR(adj[u],it){
                int v=it->first,w=it->second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push(PII(dist[v],v));
                }
            }
        }
    }
    
    for(int i=1; i<=V; i++) { if(dist[i]<=T) M++; }
     printf("%d\n", M);
    return 0;
}
