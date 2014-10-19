#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

struct edges {
    bool edge[5][5];
};
edges bm;
vector<int> v;
int adj[5][4];

void rek(int now, int e, edges bm, vector<int> v) {
    v.push_back(now);
    
    if(e==8) {
        R(i,0,9) printf("%d ", v[i]+1);
        printf("\n");
        return ;
    }
    R(i,0,4) {
        if(adj[now][i]!=-1 and !bm.edge[now][ adj[now][i] ] and !bm.edge[ adj[now][i] ][now]) {
            edges tmp=bm;
            tmp.edge[now][adj[now][i]]=1;
            tmp.edge[adj[now][i]][now]=1;
            rek(adj[now][i],e+1,tmp,v);
        }
    }
}

int main() {
    adj={ {1,2,4,-1}, {0,2,4,-1}, {0,1,3,4}, {2,4,-1,-1}, {0,1,2,3} };
    
    R(i,0,5) {
        rek(i,0,bm,v);
    }
    return 0;
}
