#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int a,b,c;
int main(){
    scanf("%d%d%d", &a, &b, &c);
    printf("%.0lf\n", ceil((double)(c-a)/(a-b))+1);
    scanf("\n");
    return 0;
}
