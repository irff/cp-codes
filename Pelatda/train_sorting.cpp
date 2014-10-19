#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> II;
typedef pair<II,int> III;
//typedef map<III,int> MI;
typedef map<II,int> MI;

int memo[3000][3000];

int teskes, n, a[2100];

int rek(int depan, int belakang, int i) {
    if(i >= n) return 0;
    if(memo[II(depan,belakang)]==0) {
      int ans = rek(depan,belakang,i+1);
      
      if(depan!=-1 and a[i] > a[depan])      ans = max(ans, rek(i ,belakang,i+1)+1);
      else if(depan==-1) ans = max(ans, rek(i,i,i+1)+1);
    
      if(belakang!=-1 and a[i] < a[belakang])   ans = max(ans, rek(depan,    i,i+1)+1);
      else if(depan==-1) ans = max(ans, rek(i,i,i+1)+1);
      
      return memo[II(depan,belakang)] = ans;
    }
    return memo[II(depan,belakang)];
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        int ans = rek(-1,-1,0);
        printf("%d\n", ans);
    }
    return 0;
}
