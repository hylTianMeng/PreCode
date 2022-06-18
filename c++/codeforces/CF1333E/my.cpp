#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 510
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N][N],tot=1;;

int main(){
    read(n);
    if(n<=2){puts("-1");return 0;}
    for(int i=n;i>=4;i--){
        if(i&1){
            for(int j=1;j<=i;j++){
                a[i][j]=tot;tot++;
            }
            for(int j=i-1;j>=1;j--){
                a[j][i]=tot;tot++;
            }
        }
        else{
            for(int j=1;j<=i;j++){
                a[j][i]=tot;tot++;
            }
            for(int j=i-1;j>=1;j--){
                a[i][j]=tot;tot++;
            }
        }
    }
    tot--;
    a[1][1]=9+tot;a[1][2]=2+tot;a[1][3]=7+tot;
    a[2][1]=4+tot;a[2][2]=5+tot;a[2][3]=8+tot;
    a[3][1]=1+tot;a[3][2]=3+tot;a[3][3]=6+tot;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d ",a[i][j]);
        puts("");
    }
}