#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[100];
int len;
map<long long, bool> ada;
map<long long, bool> udah[15];

void rek(int a, int num, int minus) {
    if(a == len-1) {
        ada[num]=1;
        return ;
    }
    if(minus==0) {
        rek(a+1, num+s[a]-'0', 0);
    } else if(minus) {
        rek(a+1, num-s[a]-'0', 1);
        rek(a+1, num*10+s[a]-'0',0);
    }
    
}
int main() {
    scanf("%s", &s);
    len = strlen(s);
    rek(,0,0,0);
    int hasil=0;
    for(map<long long,bool>::iterator it=ada.begin(); it!=ada.end(); it++) {
        //printf("%d\n", it->first);
        hasil++;
    }
    printf("%d\n", hasil);
    return 0;
}
