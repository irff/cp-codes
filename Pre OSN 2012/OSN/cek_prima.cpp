#include <cstdio>

bool bs[40000];
int n, num;
int main() {
    for(int i=2; i<=35000; i++) bs[i]=1;
    for(int i=2; i*i<=25000; i++)
      for(int j=i*i; j<=25000; j+=i) bs[j]=0;
    scanf("%d", &n);
    while(n--) {
       scanf("%d", &num);
       if(num < 2) printf("TIDAK\n");
       else printf("%s\n", (bs[num])?"YA":"TIDAK");
    }

}
