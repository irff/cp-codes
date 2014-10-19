#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes,jolly,n,m,num;
long dp[100];
vector<int> a[100000];

int main(){
    dp[0]=1;
    for(int i=1; i<12; i++){
       dp[i]=dp[i-1]*2;
    }
    scanf("%d", &teskes);
    while(teskes--){
        a[0].clear();
        jolly=0;
        scanf("%d%d", &n,&m);
        R(i,0,dp[n]) a[n].push_back(1);
        R(i,0,m){ 
            scanf("%d", &num); a[n][num-1]=-1;
        }
        for(int i=n; i>=1; i--){
            for(int j=0; j<dp[i]; j+=2){
                if(a[i][j]==1 and a[i][j+1]==1) a[i-1].push_back(1);
                else if(a[i][j]==-1 and a[i][j+1]==-1) a[i-1].push_back(-1);
                else { a[i-1].push_back(1); jolly++; }
            }
            a[i].clear();
        }
        printf("%d\n", jolly);
    }
    return 0;
}
