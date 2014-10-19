#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
vector<int> pset(10111);
map<string,int> m;
int teskes,V,E;
string s;
priority_queue<PIII> pq;

void initset(int _size){ R(i,0,_size+1) pset[i]=i;}
int findset(int i){ return (pset[i]==i)?i:(pset[i]=findset(pset[i])); }
void join(int i, int j){ pset[findset(i)]=pset[findset(j)]; }
bool sameset(int i, int j){ return findset(i)==findset(j); }

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        m.clear();
        scanf("%d", &V);
        R(i,1,V+1){
            cin >> s;
            m[s]=i;
            scanf("%d", &E);
            R(j,0,E){
                int v1,w;
                scanf("%d%d", &v1,&w);
                pq.push(PIII(-w,PII(i,v1)));
            }
        }
        int cost=0; initset(V);
        while(!pq.empty()){
            PIII f=pq.top(); pq.pop();
            if(!sameset(f.second.first,f.second.second)){ // if no cycle
                cost+=(-f.first); // negated edge weight
                join(f.second.first,f.second.second);
            }
        }
        printf("%d\n", cost);
    }
}
