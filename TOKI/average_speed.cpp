#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[100];
double dist = 0.00, speed = 0.00;
int t = 0;
int main() {
    while(gets(s) > 0) {
        int len = strlen(s);
        int now = 3600 * ( (s[0]-'0')*10+s[1]-'0' );
        now += 60 * ( (s[3]-'0')*10 + s[4] - '0');
        now += (s[6]-'0')*10 + s[7]-'0';
        if(len > 8) {
            dist+=(double)(speed*(double)(now-t));
            speed = 0.00;
            for(int i=len-1, ten = 1; i>=9; i--, ten*=10) {
                speed+=(s[i]-'0')*ten;
            }
            speed = (double)(speed*1000)/3600;
            t = now;
        } else {
            printf("%s %.2lf km\n", s, (double)(dist+(double)((double)(now-t)*speed))/1000);
        }
    }
    return 0;
}
