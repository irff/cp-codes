#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VI;

VI adj[3000];
int sex[3000];
bool homo;
int teskes,nbug,ninter;
int main(){
    scanf("%d", &teskes);
    R(x,0,teskes){
        printf("Scenario #%d:\n", x+1);
        homo=0;
        memset(sex,0,sizeof sex);
        memset(adj,0,sizeof adj);
        
        scanf("%d%d", &nbug,&ninter);
        
        R(i,0,ninter){
            int a,b;
            scanf("%d%d", &a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        sex[1]=1;
        R(i,1,nbug+1){
            for(VI::iterator it=adj[i].begin();it!=adj[i].end();it++){
                if(sex[i]==1){
                    if(sex[*it]==1) { homo=1; break; }
                    else sex[*it]=2;
                } 
                else if(sex[i]==2){
                    if(sex[*it]==2) { homo=1; break; }
                    else sex[*it]=1;
                }
                else {
                    if(sex[*it]==1) sex[i]=2;
                    else sex[i]=1;
                }
            }
            if(homo) break;
        }
        //R(i,1,nbug+1) printf("S- %d %d\n", i, sex[i]);
        if(homo) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
    }
    return 0;
}
