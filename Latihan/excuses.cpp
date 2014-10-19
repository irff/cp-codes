#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int ke,npisuhan,nmisuh,jumlah[30],maks;
string pisuhan,kata;
char s[30][256],sampah[256];
map<string, bool> m;
int main() {
    
    while( scanf("%d%d", &npisuhan, &nmisuh) > 0 ) {
        memset(jumlah,0,sizeof jumlah);
        m.clear();
        maks=-1;
        ke++;
        R(i,0,npisuhan) cin >> pisuhan,m[pisuhan]=1;
        scanf("\n");
        R(i,0,nmisuh) {
            gets(sampah);
            strcpy(s[i],sampah);
            // cari pisuhan;
            char *result=NULL;
            char delims[] = " !@#$%^&*()~`1234567890-_=+\\|\'\";:/?.>,<";
            result=strtok(sampah, delims);
            while(result!=NULL) {
                int len=strlen(result);
                R(j,0,len) if(isupper(result[j])) result[j]=result[j]-'A'+'a';
                kata.assign(result);
                if(m[kata]) {
                   jumlah[i]++;
                }
                result=strtok(NULL, delims);
            }
            maks=max(maks,jumlah[i]);
        }
        
        printf("Excuse Set #%d\n", ke);
        printf("maks=%d\n", maks);
        R(i,0,nmisuh) if(jumlah[i]==maks) printf("%s\n", s[i]);
    }
    return 0;
}
