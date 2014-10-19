#include <cstdio>
#include <bitset>
using namespace std;
bitset<100111> cc;
int main(){
    int MAX,n;
    int a[150];
    scanf("%d%d", &n, &MAX);
    while(n or MAX){
        cc.set(); cc[0]=1;
        int jum=0;
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) scanf("%
        sort(a,a+n);
        for(int i=0; i<n; i++)
         for(int j=MAX; j-a[i]>=0; j++)
          if(cc[j-a[i]]) cc[j]=1;
        for(int i=0; i<=MAX; i++) if(cc[i]) jum++;
        printf("%d\n", jum);
        scanf("%d%d", &n,&MAX);
    }

    return 0;
}
