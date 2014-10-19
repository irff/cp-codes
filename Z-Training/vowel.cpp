#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int len,hasil;
char s[2000];
int main(){
    scanf("%d%s", &len,&s);
    R(i,0,len) if(s[i]=='a' or s[i]=='i' or s[i]=='u' or s[i]=='e' or s[i]=='o') hasil++;
    printf("%d\n", hasil);
    scanf("\n");
    return 0;
}
