#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int nlady, lady[60000];
int nquery, num, mid;

int binary(int a, int b) {
    mid = (a+b)/2;
    if( a >= b) return a;
    //printf("%d %d %d\n", a, b, mid);
    if( lady[mid] < num)  {
        a = mid+1;
    } else if( lady[mid] > num) {
        b = mid - 1;
    } else {
        return mid;
    }
    return binary(a,b);
}

int main() {
    scanf("%d", &nlady);
    int ctr=0;
    R(i,0,nlady) {
        int num; scanf("%d", &num);
        if(i==0) lady[i]=num,ctr++;
        else {
            if(num!=lady[ctr-1]) {
                lady[ctr]=num;
                ctr++;
            }
        }
    }
    nlady = ctr;
    //R(i,0,nlady) printf("%d ", lady[i]);
    scanf("%d", &nquery);
    R(i,0,nquery) {
        scanf("%d", &num);
        int pos = binary(0,nlady);
        if(lady[pos]==num) {
            if( pos != 0 and pos != nlady-1) printf("%d %d\n", lady[pos-1],lady[pos+1]);
            else if(pos == 0 and pos != nlady-1) printf("X %d\n", lady[pos+1]);
            else if(pos != 0 and pos == nlady-1) printf("%d X\n", lady[pos-1]);
            else printf("X X\n");
        } else {
            //printf("pos = %d num = %d\n", pos, lady[pos]);
            if(pos >= nlady) printf("%d X\n", lady[pos-1]);
            else if(lady[pos] < num) {
                if(pos==nlady-1) printf("%d X\n", lady[pos]);
                else printf("%d %d\n", lady[pos], lady[pos+1]);
            } if(lady[pos] > num) {
                if(pos==0) printf("X %d\n", lady[pos]);
                else printf("%d %d\n", lady[pos-1], lady[pos]);
            }
        }
    }
    return 0;
    }
