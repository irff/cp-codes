#include <cstdio>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char board[10][10];
int main() {
    R(i,0,8) scanf("%s", &board[i]);
    int datar=0, turun=0;
    R(i,0,8) {
      bool jadi = 1;
      R(j,0,8) {
          if(board[i][j]=='W') jadi=0;
      }
      if(jadi) datar++;
    }
    R(j,0,8) {
      bool jadi = 1;
      R(i,0,8) {
          if(board[i][j]=='W') jadi=0;
      }
      if(jadi) turun++;
    }
    if(turun == 8 and datar == 8) printf("8\n");
    else printf("%d\n", turun+datar);

    return 0;
}
