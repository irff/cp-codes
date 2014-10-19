#include <cstdio>

int teskes,n,ctr;
int main(){
  scanf("%d", &teskes);
  while(teskes--){
    ctr=0;
    scanf("%d", &n);
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            ctr++;
            if(i*i!=n){
                ctr++;
            }
        }
    }
    printf("%s\n", ctr<=4?"YA":"TIDAK");
    
    
  }
  return 0;
}
