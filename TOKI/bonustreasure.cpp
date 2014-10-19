#include <cstdio>
using namespace std;
 
int teskes,n,m,k;
 
char F(int i,int n){
    if(i == 1) return '(';
    if(i == (1<<n)) return ')';
    char ret;
    for(int j=1; j<=n; j++)
        if( i <= (1 << j)-1)
        { 
            ret=F(i- (1 << j-1) +1, j-1);
            break;
        }
    return ret;
}
 
int main(){

    while(scanf("%d%d%d", &n,&m,&k) and n or m or k){
        k++;
        for(int i=m+1; i<m+k; i++){
            printf("%c",F(i,n));
        }
        puts("");
    }
}
