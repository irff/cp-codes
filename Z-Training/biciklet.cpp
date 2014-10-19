#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define PII pair<int,int>
#define PIII pair<int,PII>
#define VPII vector<PII>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

VPII adj[9000];
int uda[10000];
int V;
int v1,v2,w;

PII bfs(int a,int b){
    int maks=-1,miks;
    queue<int> q; map<int,int> dist;
    q.push(a); dist[a]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(VPII::iterator it=adj[u].begin(); it!=adj[u].end(); it++){
                if( !dist.count(it->first)){
                    dist[it->first]=dist[u]+it->second;
                    if(maks<dist[it->first]) maks=dist[it->first],miks=it->first;
                    q.push(it->first);
                }
            }
        }
    return PII(maks,miks);
}

int main(){
    int maks=-1;
    int tipu=0,tupai=-1;
    scanf("%d", &V);
    R(i,0,V-1){
             scanf("%d%d%d", &v1,&v2,&w);
             adj[v1].push_back(PII(v2,w));
             adj[v2].push_back(PII(v1,w));
    }
    PII s2=bfs(1,0);
    PII s3=bfs(s2.second,0);
    printf("%d\n", s3.first);
   
    return 0;
}
