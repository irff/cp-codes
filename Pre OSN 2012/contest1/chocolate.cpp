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

int a, b;
int main() {
    while(scanf("%d%d", &a, &b)>0) {
        int x=0, y=0;
        if(a==1) printf("%d\n", b-1);
        else if(b==1) printf("%d\n", a-1);
        else {
            printf("%d\n", (a-1)+(a)*(b-1));
        }
    }
    return 0;
}
