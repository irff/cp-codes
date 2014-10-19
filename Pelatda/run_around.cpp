/*
    ID: irfan1
    LANG: C++
    TASK: runround
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int num;
char s[1000];
bool visited[100];
int uniq[15];
bool cek( int n ) {
    memset(visited, 0, sizeof visited);
    memset(uniq, 0, sizeof uniq);
    
    int x = n,ctr=0;
    while(x>0) { uniq[x%10]++; s[ctr++]=x%10+'0'; x/=10; }
    
    bool bisa=1;
    for(int i=0; i<10; i++) if(uniq[i]>1) bisa=0;
    //printf("%d\n", bisa);
    if(!bisa) return 0;
    
    reverse(s,s+ctr);
    int now = 0, num=0,step=0;
    //printf("%s %d\n", s, ctr);
    while(step <= ctr) {
        num=s[now]-'0';
        //printf("%d_\n", num);
        int i=now,j=0;
        for(; j<num; j++) {
            i++;
            if(i==ctr) i=0;
        }
        visited[i]=1;
        now=i;
        step++;
    }
    bool jadi = 1;
    for(int i=0; i<ctr; i++) {
        //printf("%d", visited[i]);
        if(visited[i]==0) jadi=0;
    }
    //printf("\n");
    return jadi;
}

int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    scanf("%d", &num);
    //printf("%d\n", cek(num));
    bool ketemu=0;
    for(int i=num+1; !ketemu; i++) {
        if(cek(i)) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
