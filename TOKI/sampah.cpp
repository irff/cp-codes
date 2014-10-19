#include <cstdio>
#include <functional>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LLD;

int n, len;
LLD ans, a[100];
char s[100];  

void rek(int ke, LLD x) {
    if(ke>=n) {
        if(ans < x) ans = x;
    } else {
        rek(ke+1, a[ke]^x);
        rek(ke+1, x);
    }
}
 
int main() {
    scanf("%d%d", &n, &len);
    gets(s);
    for(int i=0; i<n; i++) {
        gets(s);
        a[i] = 0;
        for(int j=0,k=len-1; j<len; j++,k--) {
            if(s[j]=='1') a[i]+=((LLD)1<<k);
        }
    }
    sort(a, a+n, greater<LLD>());
    ans = 0;
    LLD dua = 1;
    while(dua <= a[0]) dua*=2;
    //printf("%lld\n", dua);
    dua/=2;
    
    for(int st = 0; dua>=1; dua/=2) {
        int i = st;
        //nyari yang digit ke-i  = 1
        while(i<n &&(a[i]&dua)==0) i++;
        if(i>=n) continue;
        
        // kalo nemu
        swap(a[st], a[i]);
        
        
        for(int j=0; j<n; j++)
            if(j!=st and (a[j]&dua)!=0)
                a[j] ^= a[st];
        st++;
    }
    
    for(int i=0; i<n; i++)  ans^=a[i];
    
    for(int i=len-1; i>=0; i--) {
        if(ans&((LLD)1<<i)) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}
