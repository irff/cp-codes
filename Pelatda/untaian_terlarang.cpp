#include <cstdio>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;

int n;
typedef long long LLD;
typedef deque<int> DI;

deque<int> sampah, tmp, bk, x;
LLD memo[40][4][4][4];

LLD rek(int ke, DI d) {
    if(ke>=n) return 1;
    LLD result = 0;
    bk = d;
    printf("%d\n", bk.size());
    if(ke < 2) {
        d = bk; d.push_back(1);
        result += rek(ke+1, d);
        
        d = bk; d.push_back(2);
        result += rek(ke+1, d);
        
        d = bk; d.push_back(3);
        result += rek(ke+1, d);
        
        return result;
    }
    
    d = bk;
    if(ke>=2) {
        d.pop_front();
    }
    int mins = min(d[0],d[1]), maks = max(d[0], d[1]);
    
    if(mins!=2 or maks!=3) {
      d.push_back(1);
      result += rek(ke+1, d);
      d.pop_back();
    }
    
    if(mins!=1 or maks!=3) {
      d.push_back(2);
      result += rek(ke+1, d);
      d.pop_back();
    }
    if(mins!=1 or maks!=2) {
      d.push_back(3);
      result += rek(ke+1, d);
      d.pop_front();
    }
    return result;

}
    
int main() {
    //d.push_back(1); d.push_back(2);
    //bk = d; for(int i=0; i<bk.size(); i++) printf("%d\n", bk[i]);
    scanf("%d", &n);
    int hasil = rek(0,sampah);
    printf("%d\n", hasil);
    return 0;
}
