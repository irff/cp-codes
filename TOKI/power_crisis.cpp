#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VI;
VI v;
int n, memo[120];
int main() {
    
    R(i,13,100) {
        R(m,1,2*i) {
            R(j,1,i+1) v.push_back(j);
            int pos = 0, num = -1;
            
            while(v.size() > 1) {
                num++;
                if(num%m==0) {
                    //printf("%d ", v[pos]);
                    v.erase(v.begin()+pos);
                    if(pos==v.size()) pos = 0;
                } else {
                    pos++;
                    if(pos==v.size()) pos = 0;
                }
            }
            if(v[0]==13) {
                memo[i] = m;
                break;
            }
            //printf("\n");
        }
    }
    while( scanf("%d", &n) > 0) {
        printf("%d\n", memo[n]);
    }
    return 0;
}
