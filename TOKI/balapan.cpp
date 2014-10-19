#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define VR(c,it) for(VII::iterator it=(c).begin();it!=(c).end();it++)

typedef pair<int,int> PII;
typedef vector<PII> VII;

const int INF=2000111222;

VII adj[100111];
int V,E,nstart,nfinish;
int start[300], finish[300];
int mins;
void dijk(int s) {
     vector<int> dist(V+2, INF);
     priority_queue<PII, VII, greater<PII> > pq;
     dist[s]=0;
     pq.push(PII(0,s));
     
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
     R(i, 0, nfinish) {
          mins = min( dist[finish[i]], mins );
     }
     //printf("x");
}

int main() {
    mins = INF;
    scanf("%d%d%d%d", &V, &E, &nstart, &nfinish);
    R(i,0,nstart) scanf("%d", &start[i]);
    R(i,0,nfinish) scanf("%d", &finish[i]);
    R(i,0,E){
        int a,b,c;
        scanf("%d%d%d", &a,&b,&c);
        adj[a].push_back(PII(b,c));
        adj[b].push_back(PII(a,c));         
    }
    R(i,0,nstart) {
        dijk(start[i]);              
    }
    printf("%d\n", mins);
    //printf("%d\n", E);
    
    return 0;    
}
