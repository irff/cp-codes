#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI ans;

int kube[8000111];
int main() {
    R(i,1,201) kube[i*i*i] = i;
    R(i,2,201) {
        R(j,i,201) {
            R(k,j,201) {
                int x = i*i*i+j*j*j+k*k*k;
                if(x<=8000000 and kube[x]) {
                    VI v; v.push_back(kube[x]); v.push_back(i); v.push_back(j); v.push_back(k);
                    ans.push_back(v);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    int len = ans.size();
    R(i,0,len) {
        printf("Cube = %d, Triple = (%d,%d,%d)\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    }
    return 0;
}
