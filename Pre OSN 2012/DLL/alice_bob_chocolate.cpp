#include <cstdio>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, a[120000], total=0, avg=0;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%d", &a[i]);
        total+=a[i];
    }
    avg=total/2;
    int pos=1, left=a[0];
    R(i,1,n) {
        left+=a[i];
        if(left > avg) {
            //printf("%d %d %d\n", total, a[i], left);
            pos = i;
            if(left-a[i] < total-left) pos++;
            else if(total-a[i]==(left-a[i])*2) {
                pos++;
            }
            break;
        }
    }
    printf("%d %d\n", pos, n-pos);
    return 0;    
}
