#include <cstdio>
#include <deque>
using namespace std;

int n, a[1500999], teskes;
int magic = 0;
bool leading = 0;
int main() {
  a[1]=1;
  a[2]=2;
  deque<int> v,m;
  v.push_back(1); v.push_back(2);
  for(int i=3; i<=1500000; i++) {
        a[i] = a[i-1]+a[i-2];
        a[i]%=1000000;
  }
  scanf("%d", &teskes);
  while(teskes--) {
    scanf("%d", &n);
    if(n<30) printf("%d\n", a[n]);
    else {
        n=(n-1)%1500000+1;
        if(a[n] < 10) printf("00000");
        else if(a[n] < 100) printf("0000");
        else if(a[n] < 1000) printf("000");
        else if(a[n] < 10000) printf("00");
        else if(a[n] < 100000) printf("0");
        printf("%d\n", a[n]);
    }
  }
    return 0;
}
