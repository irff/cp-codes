#include <bitset>
#include <algorithm>
using namespace std;

char s[1000];
int ans;
int main(){
    scanf("%s", &s);
    int len=strlen(s);
    reverse(s,s+len);
    for(int i=0; i<len; i++){
        ans+=((1<<i)*(s[i]-'0'));
    }
    while(ans!=0){
        printf("%d\n", ans);
        ans=0;
        memset(s,0,sizeof(s));
        scanf("%s", &s);
        int len=strlen(s);
        reverse(s,s+len);
        for(int i=0; i<len; i++){
            ans+=((1<<i)*(s[i]-'0'));
        }
    }    
    return 0;
}
