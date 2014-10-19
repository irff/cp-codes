#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
using namespace std;

char s[15];
int len,nresult=0;
map<int,bool> mep;

void rek(int k, int prev) {
    if(k==len) {
        mep[prev]=1;
        return ;
    }
    
    int x=0; char tmp[15];
    memset(tmp,0,sizeof tmp);
    for(int i=k; i<len; i++) {
        tmp[x++]=s[i];
        int num=atoi(tmp);
        if(k!=0) rek(i+1,prev-num);
        rek(i+1,prev+num);
    }
}

int main() {
    scanf("%s", s);
    len=strlen(s);
    rek(0,0);
    for(map<int,bool>::iterator it=mep.begin(); it!=mep.end(); it++) {
        if(it->second==1) nresult++;
    }
    printf("%d\n", nresult);
    return 0;
}
