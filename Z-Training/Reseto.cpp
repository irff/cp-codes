#include <cstdio>
using namespace std;

bool bs[2000];
int n,k,ctr,num;
int main(){
    for(int i=0; i<=1000; i++) bs[i]=1;
    scanf("%d%d", &n,&k);
    //k--;
    for(int i=2; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            if(bs[j]){
                //printf("%d ", j);
                ctr++; 
                if(ctr==k) {
                    printf("%d\n", j);
                    break;
                }
                bs[j]=0;
            }
        }
        if(ctr==k) break;
    }
    scanf("\n");
    return 0;
}
