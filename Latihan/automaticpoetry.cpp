#include <cstdio>
#include <cstring>

int teskes;
char sa[1000],sb[1000],sc[4][100];
int main() {
    scanf("%d\n", &teskes);
    while(teskes--) {
        memset(sc,0, sizeof sc);
        gets(sa); gets(sb);
        int lena=strlen(sa),lenb=strlen(sb);
        for(int i=0; i<lena; i++)
            if(sa[i]!='<' and sa[i]!='>') putchar(sa[i]);
        printf("\n");
        int ke=0,state=-1;
        
        for(int i=0; i<lena; i++) {
            if(sa[i]=='<' and state==1) state=2,ke=0;
            else if(sa[i]=='>' and state==2) state=3,ke=0;
            else if(sa[i]=='<') state=0,ke=0;
            else if(sa[i]=='>') state=1,ke=0;
            else if(state!=-1 and sa[i]!=' ') {
                sc[state][ke++]=sa[i];
            }
        }
        for(int i=0; i<lenb; i++) {
            if(sb[i]=='.' and sb[i+1]=='.' and sb[i+2]=='.') break;
            else putchar(sb[i]);
        }
        printf("%s%s %s%s\n", sc[2],sc[1],sc[0],sc[3]);
    }
    return 0;
}
