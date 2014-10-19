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

char sa[20], si[20];
char key[25][20];
string k[25];
int main() {
    k[0] = "123456";
    k[1] = "143265";
    k[2] = "625413";
    k[3] = "645231";
    k[4] = "321465";
    k[5] = "341256";
    k[6] = "526431";
    k[7] = "546213";
    k[8] = "432165";
    k[9] = "412356";
    k[10] = "234156";
    k[11] = "214365";
    
    k[12] = "153642";
    k[13] = "163524";
    k[14] = "635124";
    k[15] = "615342";
    k[16] = "351624";
    k[17] = "361542";
    k[18] = "516324";
    k[19] = "536142";
    k[20] = "264531";
    k[21] = "254613";
    k[22] = "452631";
    k[23] = "462513";
    while(scanf("%s", &sa)>0) {
        R(i,0,6) si[i]=sa[i+6];
        bool ketemu=0;
        R(i,0,24) {
            R(j,0,6) {
                //key[i][j]=sa[ k[i][j]-'0'-1' ];
                key[i][j] = sa[ k[i][j]-'0'-1];
            }
            if(strcmp(si, key[i])==0) ketemu=1;
        }
        printf("%s\n", ketemu?"TRUE":"FALSE");
    }
    return 0;
}













