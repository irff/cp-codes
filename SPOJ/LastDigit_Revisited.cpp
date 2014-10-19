#include <cstdio>
#include <cstring>

char s[2000];
typedef long long LLD;
int main(){
    int teskes;
    scanf("%d", &teskes);
    while(teskes--){
      memset(s,0,sizeof s);
      int a,b,digit;
      scanf("%s", &s);
      scanf("%I64d", &b);
      a=s[strlen(s)-1]-'0';
      if(b%4==0 and b!=0) b=4;
      else if(b!=0) b%=4;
      digit=1;
      int n=b;
      for(int i=0; i<n; i++){
        digit=(digit*a)%10;
      }
      printf("%d\n", digit);
    }
    return 0;
}
