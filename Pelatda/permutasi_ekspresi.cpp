#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define fs first
#define sc second

typedef long long LLD;
const int INF = 2000111222;
typedef map<LLD,bool> MLB;

MLB m;
char s[100];
int hasil = 0, len = 0;

void rek(int ke, int num) {
     //printf("%d %d\n", ke, num);
     if(ke == len) m[num] = 1;
     LLD tadi = 0;
     R(i,ke,len) {
         tadi = tadi*10 + s[i]-'0';
         rek(i+1, num+tadi);
         if(ke>0) rek(i+1, num-tadi);
     }
}

int main() {
    scanf("%s", &s);
    len = strlen(s);
    rek(0,0);
    hasil = m.size();
    /*
    for(MLB::iterator it=m.begin(); it!=m.end(); it++) {
        printf("%d\n", it->first);
    }
    */
    printf("%d\n", hasil);
    return 0;
}