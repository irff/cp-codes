#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define fs first
#define sc second

typedef map<int,int> MII;
typedef pair<int,int> PII;
typedef long long LLD;

char s[10][10];
char seq[12000];
int a, b, ronde = 1;

bool move(char ch) {
    if(ch != 'A' and ch != 'R' and ch != 'B' and ch != 'L') return 0;
    if(ch=='A') {
        if(a == 0) return 0;
        s[a][b]=s[a-1][b];
        s[a-1][b]=' ';
        a--;
    }
    if(ch=='R') {
        if(b == 4) return 0;
        s[a][b]=s[a][b+1];
        s[a][b+1]=' ';
        b++;
    }
    if(ch=='B') {
        if(a == 4) return 0;
        s[a][b]=s[a+1][b];
        s[a+1][b]=' ';
        a++;
    }
    if(ch=='L') {
        if(b == 0) return 0;
        s[a][b]=s[a][b-1];
        s[a][b-1]=' ';
        b--;
    }
    return 1;
}

int main() {
    gets(s[0]);
    bool baru = 1;
    while(strlen(s[0])==5) {
        if(!baru) printf("\n");
        bool bisa = 1;
        R(i,1,5) gets(s[i]);
        R(i,0,5) {
            R(j,0,5) if(s[i][j]==' ') a=i,b=j;
        }
        char ch;
        int ctr=0;
        scanf("%c", &ch);
        while(ch!='0') {
            if(ch>='A' and ch <='Z') seq[ctr++]=ch;
            scanf("%c", &ch);
        }
        
        int les = ctr;
        R(i,0,les) {
            bisa = move(seq[i]);
            if(!bisa) break;
        }
        printf("Puzzle #%d:\n", ronde);
        if(bisa) {
            R(i,0,5) {
                R(j,0,5) {
                    printf("%c", s[i][j]);
                    if(j!=4) printf(" ");
                }
                printf("\n");
            }
        } else {
            printf("This puzzle has no final configuration.\n");
        }
        baru=0;
        ronde++;
        gets(s[0]);
        if(s[0][0]==0) gets(s[0]);
    }
    return 0;
}
