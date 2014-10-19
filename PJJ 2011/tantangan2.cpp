#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<VI,PII> VPI;

int n, k, a;
bool gagal = 0;
vector<int> v, ori;

map<VI,bool> m;
queue<VPI> q;
int udah = 0, hasil=99999;
bool memo[8][8][8][8][8][8][8][8];
int s[10];
bool cek(vector<int>x) {
    for(int i = 7; i>=n; i--) x.push_back(1);
    if( memo[x[ 0 ]-1][x[ 1 ]-1][x[ 2 ]-1][x[ 3 ]-1][x[ 4 ]-1][x[ 5 ]-1][x[ 6 ]-1][x[ 7 ]-1] ) {
        return 1;
    }
    return 0;
}

void update(vector<int> x) {
    for(int i = 7; i>=n; i--) x.push_back(1);
    memo[x[ 0 ]-1][x[ 1 ]-1][x[ 2 ]-1][x[ 3 ]-1][x[ 4 ]-1][x[ 5 ]-1][x[ 6 ]-1][x[ 7 ]-1] = 1;
}

void rek(vector<int> v) {
     q.push(VPI(v, PII(0,-1)));
     while(!q.empty()) {
         if(q.front().second.second >= 100) return ;
         if(q.front().first == ori and q.front().second.second!=-1) {
             hasil = min(q.front().second.second, hasil);
             udah =1;
         }
         VPI t = q.front(); q.pop();
         
         if(t.second.second == -1) {
           for(int i=0; i<n; i++) {
               q.push(VPI(t.first, PII(i,0)));
           }
         } else if(t.second.first+k <= n) {
           vector<int> x = t.first;
           reverse(&x[t.second.first], &x[t.second.first+k]);
           if( !cek(x) ){
             update(x);
             for(int j = 0; j<=n-k+1; j++) {
               q.push(VPI(x, PII(j, t.second.second+1)));
             }
           }
         }
     }
     
}

int main() {
    scanf("%d", &n);
    R(i,0,n) { scanf("%d", &a); v.push_back(a); }
    R(i,0,n) { memset(memo, 0, sizeof memo); ori.push_back(i+1); }
    scanf("%d", &k);
    rek(v);
    if(udah) {
        printf("%d\n", hasil);
    } else {
        printf("-1\n");
    }
}
