#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

map<string,int> m;
char ch;
char s[1001][1001],tmp[1000];
int main(){
    int state=0,ct=0,x=0;
    while(scanf("%c", &ch)>0){
        if(state==0 and ((ch>='a' and ch <='z') or (ch>='A' and ch<='Z') )){
            ct=0;
            if(ch>='A' and ch<='Z') ch=ch-'A'+'a';
            tmp[ct++]=ch; state=1;
        }
        else if(state==1 and ( (ch>='a' and ch <='z') or (ch>='A' and ch<='Z')) ){
            if(ch>='A' and ch<='Z') ch=ch-'A'+'a';
            tmp[ct++]=ch;
        }
        else if(ct>0){
            ct=0;
            state=0;
            strcpy(s[x],tmp);
            memset(tmp,0,sizeof tmp);
            x++;
        }
    }
    strcpy(s[x],tmp);
    string str;
    for(int i=0; i<=x; i++){
        str.clear();
        str=s[i];
        m[str]++;
    }
    string ma; int mb=0;
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++){
        if(mb<it->second) mb=it->second,ma=it->first;
    }
    printf("%s %d\n", ma.c_str(),mb);
    scanf("\n");
    return 0;
}
