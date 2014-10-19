#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef unsigned long long LLD;
const LLD MOD = 1000000007;

typedef struct {
    LLD m[3][3];
} matrix;

matrix x, y, id;

matrix mul(matrix a, matrix b) {
    matrix c;
    R(i,0,3) {
        R(j,0,3) {
            c.m[i][j] = 0;
            R(k,0,3) {
                c.m[i][j]+=(LLD)(a.m[i][k]*b.m[k][j])%MOD;
            }
            c.m[i][j] %= MOD;
        }
    }
    return c;
}

matrix pow(matrix a, LLD num) {
    if(num==0) return id;
    matrix c = pow(a,num/2);
    matrix d = mul(c,c);
    if(num%2) {
        d = mul(a,d);
        return d;
    } else {
        return d;
    }
}

void print(matrix a) {
    R(i,0,3) {
        R(j,0,3) printf("%lld ", a.m[i][j]);
        printf("\n");
    }
    printf("\n");
}

LLD n;
int main() {
    scanf("%d%d%d", &y.m[0][2], &y.m[0][1], &y.m[0][0]);
    scanf("%lld", &n);
    if(n<=3) {
        if(n==1) printf("%d\n", y.m[0][2]);
        else if(n==2) printf("%d\n", y.m[0][1]);
        else printf("%d\n", y.m[0][0]);
        return 0;
    }
    x.m[0][0] = 1; x.m[0][1] = 1;
    x.m[1][0] = 1; x.m[1][2] = 1;
    x.m[2][0] = 1;
    id.m[0][0] = 1; id.m[1][1] = 1; id.m[2][2] = 1;
    //print(y);
    //print(x);
    matrix has = pow(x,n-3);
    //print(has);
    has = mul(y,has);
    printf("%llu\n", has.m[0][0]);
    
    return 0;
}
