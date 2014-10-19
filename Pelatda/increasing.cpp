#include <cstdio>


int n, d, x, step=0, pre,selisih;
int main() {
    scanf("%d%d", &n, &d);
    for(int i=0; i<n; i++) {
        int num; scanf("%d", &num);
        if(i==0) {
            pre=num;
        } else {
            if(num <= pre) {
                if(num==pre) {
                  selisih = pre-num+d;
                } else selisih = pre-num;
                
                  int now = 0;
                  if(selisih%d==0) now+=selisih/d;
                  else now+=(selisih+d)/d;
                
                  pre = num+now*d;
                  step += now;
                  
                
            } else pre=num;
        }
        printf("%d %d %d\n", pre, selisih, step);
    }
    printf("%d\n", step);
    return 0;
}
