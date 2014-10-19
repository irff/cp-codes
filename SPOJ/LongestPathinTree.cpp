#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define PII pair<int,int>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

vector<int> adj[9000];
int uda[10000];
int V;
int v1,v2,w;

PII bfs(int a,int b){
    int maks=-1,miks;
    queue<int> q; map<int,int> dist;
    q.push(a); dist[a]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(vector<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++){
                if( !dist.count(*it)){
                    dist[*it]=dist[u]+1;
                    if(maks<dist[*it]) maks=dist[*it],miks=*it;
                    q.push(*it);
                }
            }
        }
    return PII(maks,miks);
}

int main(){
    int maks=-1;
    scanf("%d", &V);
    R(i,0,V-1){
             scanf("%d%d", &v1,&v2);
             adj[v1].push_back(v2);
             adj[v2].push_back(v1);
    }
    PII s2=bfs(1,0);
    PII s3=bfs(s2.second,0);
    printf("%d\n", s3.first);
    scanf("\n");
    return 0;
}
