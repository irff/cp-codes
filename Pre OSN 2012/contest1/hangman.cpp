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
int teskes;

int n;
char ans[1000], guess[1000];
int main() {
    scanf("%d", &n);
    while(n!=-1) {
        scanf("%s%s", &ans, &guess);
        int lena=strlen(ans), leni=strlen(guess);
        int num = 0, state=0;
        R(i,0,leni) {
            bool ketemu = 0;
            R(j,0,lena) {
                if(ans[j]!='#' and ans[j]==guess[i]) {
                    ans[j]='#';
                    ketemu = 1;
                }
            }
            if(!ketemu) num++;
            bool solved = 1;
            R(j,0,lena) {
                if(ans[j]!='#') solved = 0;
            }
            if(solved and num<=7) { state = 0; break; }
            else if(!solved and num >=7) { state = 1; break; }
            else if(i==leni-1 and !solved and num<7) { state=2; break; }
        }
        printf("Round %d\n", n);
        if(state==0) printf("You win.\n");
        else if(state==1) printf("You lose.\n");
        else if(state==2) printf("You chickened out.\n");
        scanf("%d", &n);
    }
    return 0;
}
