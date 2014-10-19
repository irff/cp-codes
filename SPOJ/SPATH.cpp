#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
#define PII pair<int,int>
#define VII vector<PII>
#define MI map<int,int>
#define INF 2000111222
#define RV(c,it) for(VII::iterator it=(c).begin(); it!=(c).end(); it++)
VII adj[10111];
int teskes,E,CITY,QUERY;
int memo[10111][10111];
map<string,int> m;
string s;

int dijk(int s, int b){
    vector<int> dist(CITY+1,INF);
    dist[s]=0;
    priority_queue<PII,VII,greater<PII> > pq;
    pq.push(PII(0,s));
    while(!pq.empty()){
        PII TOP=pq.top(); pq.pop();
        int d=TOP.first, u=TOP.second;
        if(d==dist[u]){
            RV(adj[u],it){
                int v=it->first,w=it->second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push(PII(dist[v],v));
                }
            }
        }
    }
    for(int i=1; i<=CITY; i++) memo[s][i]=dist[i];
    return dist[b];
}


int main(){
    memset(memo,-1,sizeof memo);
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &CITY);
        for(int i=0; i<CITY; i++){
            cin >> s;
            m[s]=i+1;
            scanf("%d", &E);
            for(int j=0; j<E; j++){
                int num1,num2;
                scanf("%d%d",&num1,&num2);
                adj[i+1].push_back(PII(num1,num2));
                adj[num1].push_back(PII(i+1,num2));
            }
        }
        scanf("%d",&QUERY);
        for(int i=0; i<QUERY; i++){
            string sa,sb;
            cin>> sa >> sb;
            int x=m[sa],y=m[sb];
            if(memo[x][y]==-1 and memo[y][x]==-1) printf("%d\n", dijk(x,y));
            else if(memo[x][y]==-1) printf("%d\n", memo[y][x]);
            else printf("%d\n", memo[x][y]);
        }
        
    }
    return 0;    
}
