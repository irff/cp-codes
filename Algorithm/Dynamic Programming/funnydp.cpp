#include <cstdio>
#include <cstring>

char s[100],a[100];
int memo[100][100];
int len,finish;
int rek(int id, int next) {
    int hasil=0;
    if(next==finish) return 1;
    if(id==len) return 0;
    if(memo[id][next]!=-1) return memo[id][next];
    
    hasil+=rek(id+1, next);
    if(a[id]==s[next]) hasil+=rek(id+1, next+1);
    return memo[id][next]=hasil;
}

int main() {
    memset(memo,-1, sizeof memo);
    scanf("%s\n", s);
    gets(a);
    len=strlen(a),finish=strlen(s);

    int hasil=rek(0,0);
    
    printf("%d\n", hasil);
    return 0;
}
