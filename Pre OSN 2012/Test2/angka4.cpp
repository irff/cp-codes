#include <cstdio>
#include <cstring>
using namespace std;

char a[10000];
int awal, akhir;
int main() {
    memset(a,1,sizeof a);
    
    for(int i=2; i*i<=10000; i++)
      for(int j=i*i; j<=10000; j+=i) a[j]=0;
    
    scanf("%d%d", &awal, &akhir);
    int has = 0;
    for(int i=awal; i<=akhir; i++) if(!a[i]) has++;
    printf("%d\n", has);
    return 0;
}
