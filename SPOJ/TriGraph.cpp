#include <cstdio>
#include <algorithm>
using namespace std;

int n,m[100111][3],kasus=1;
int main(){
    scanf("%d", &n);
    while(n!=0){
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                scanf("%d", &m[i][j]);
            }
        }
        m[n-1][0]=m[n-1][0]+m[n-1][1];
        for(int i=n-2; i>=0; i--){
            m[i][2]=m[i][2]+min(m[i+1][1],m[i+1][2]);    
            m[i][1]=m[i][1]+min(m[i+1][0],min(m[i+1][1],min(m[i+1][2],m[i][2])));
            m[i][0]=m[i][0]+min(m[i+1][0],min(m[i+1][1],m[i][1]));
        }
        printf("%d. %d\n", kasus,m[0][1]);
        kasus++;
        scanf("%d", &n);
    }
}
