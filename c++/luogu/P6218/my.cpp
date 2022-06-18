#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 35
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

int f[N][N][N][2][2];
int l,r,a[N],b[2];

//1 到 k
inline int Solve(int k){
    memset(f,0,sizeof(f));
    int t=0;
    while(k){
        a[++t]=(k&1);k>>=1;
    }
    f[t+1][0][0][1][1]=1;
    for(int i=t+1;i>=2;i--){
        // printf("i=%d\n",i);
        for(b[0]=0;b[0]<=t+1-i;b[0]++){
            for(b[1]=0;b[1]<=t+1-i-b[0];b[1]++){
                for(int k=0;k<=1;k++){
                    // printf("b[0]=%d b[1]=%d k=%d\n",b[0],b[1],k);
                    // printf("f[0]=%d f[1]=%d\n",f[i][b[0]][b[1]][k][0],f[i][b[0]][b[1]][k][1]);
                    if(f[i][b[0]][b[1]][k][0]){
                        int up=(k==1)?a[i-1]:1;
                        int val=f[i][b[0]][b[1]][k][0];
                        for(int j=0;j<=up;j++){
                            b[j]++;
                            f[i-1][b[0]][b[1]][k&&(j==up)][0]+=val;
                            b[j]--;
                        }
                    }
                    if(f[i][b[0]][b[1]][k][1]){
                        f[i-1][b[0]][b[1]+1][k][0]+=f[i][b[0]][b[1]][k][1];
                        f[i-1][b[0]][b[1]][0][1]+=f[i][b[0]][b[1]][k][1];
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=t;i++){
        for(int j=i;j<=t-i;j++){
            for(int k=0;k<=1;k++)
                for(int p=0;p<=1;p++){
                    ans+=f[1][j][i][k][p];
                    // printf("1 %d %d %d %d f=%d\n",j,i,k,p,f[1][j][i][k][p]);
                }
        }
    }
    return ans;
}

int main(){
    freopen("mmy.in","r",stdin);
    freopen("my.out","w",stdout);
    read(l);read(r);
    // return 0;
    // printf("%d\n",Solve(r));
    // printf("%d\n",Solve(l-1));
    printf("%d\n",Solve(r)-Solve(l-1));
    return 0;
}