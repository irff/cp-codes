#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, sum = 0;
int m[10];
char s[1200];

bool maen() {
    if(sum%3==0) {
        if(m[3]) {
            m[3]--;
            sum-=3;
            return 1;
        }
        return 0;
    }
    
    if(sum%3==2) {
        if(m[2]) {
            m[2]--;
            sum-=2;
            return 1;
        }
        return 0;
    }
    
    if(sum%3==1) {
        if(m[1]) {
            m[1]--;
            sum-=1;
            return 1;
        }
        return 0;
    }
}

int main() {
    scanf("%d", &teskes);
    R(j,0,teskes) {
        R(i,0,4) m[i] = 0;
        sum = 0;
        scanf("%s", &s);
        
        int len = strlen(s);
        R(i,0,len) {
            sum += (s[i]-'0'-1)%3+1;
            m[ (s[i]-'0'-1)%3+1]++;
        }
        int now = 0;
        bool bisa = maen();
        while(bisa) {
            now = 1 - now;
            bisa = maen();
        }
        printf("Case %d: %c\n", j+1, now?'S':'T');
        //R(i,1,4) printf("%d ", m[i]);
        
    }
    return 0;
}
