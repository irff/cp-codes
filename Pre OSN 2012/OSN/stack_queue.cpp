#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

int n, num;
char in[100];

deque<int> d;
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%s", &in);
        if(strcmp(in,"push_back")==0) {
            scanf("%d", &num); d.push_back(num);
        }
        if(strcmp(in,"pop_back")==0) {
            d.pop_back();
        }
        if(strcmp(in,"push_front")==0) {
            scanf("%d", &num); d.push_front(num);
        }
        if(strcmp(in,"pop_front")==0) {
            d.pop_front();
        }
    }
    int len = d.size();
    for(int i=0; i<len; i++) printf("%d\n", d[i]);
    return 0;
}
