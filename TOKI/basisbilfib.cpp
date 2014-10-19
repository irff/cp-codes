#include <cstdio>
using namespace std;


long long f[100],data[2000500];
int teskes;
int main(){
    f[0]=0;f[1]=1;
    data[0]=1;
    for(int i=2; f[i-1]<=10000000000LL; i++) f[i]=f[i-1]+f[i-2];
    int n=0;
    for(n=0; n<100; n++) {if(f[n]>2000002) break; }
    n--;
        //---------------------------------------------
    for(int i=1; i<=n; i++)
      for(long long j=2000002; j>=f[i]; j--){
          data[j]=data[j]+data[j-f[i]];
    }
    data[0]=1;
    long long maks;
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%lld", &maks);
        printf("%lld\n", data[maks]);
    }
    return 0;
}
