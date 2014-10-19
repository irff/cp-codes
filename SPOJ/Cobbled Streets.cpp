#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int teskes,V,E,perm,cost;
priority_queue<PIII> pq;
vector<int> pset(1222);
void initset(int _size){ R(i,0,_size+1) pset[i]=i;}
int findset(int i){ return (pset[i]==i)?i:(pset[i]=findset(pset[i])); }
void join(int i, int j){ pset[findset(i)]=pset[findset(j)]; }
bool sameset(int i, int j){ return findset(i)==findset(j); }

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &perm);
        scanf("%d%d", &V,&E);
        R(i,0,E){
            int v1,v2,w;
            scanf("%d%d%d", &v1,&v2,&w);
            pq.push(PIII(-w,PII(v1,v2)));
        }
        cost=0; initset(V);
        while(!pq.empty()){
            PIII f=pq.top(); pq.pop();
            if(!sameset(f.second.first,f.second.second)){ // if no cycle
                cost+=(-f.first); // negated edge weight
                join(f.second.first,f.second.second);
            }
        }
        printf("%d\n", cost*perm);
    }
    return 0;
}
