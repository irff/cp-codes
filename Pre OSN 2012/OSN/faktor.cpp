#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;
int main() {
    scanf("%d", &n);
    for(int i=1; i*i<=n; i++) {
        if(n%i==0) {
            v.push_back(i);
            if(i*i!=n) v.push_back(n/i);
        }
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) printf("%d\n", v[i]);
    return 0;
}
