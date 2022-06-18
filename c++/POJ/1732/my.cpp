#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 50010
#define M 52
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int Num[]={2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0};
// int Num[]={1,1,1,2,2,2,3,3,3,4,4,4,5,5,6,6,6,7,7,7,8,8,8,9,9,9};
char num[N],s[N][M];
int n,f[M<<1],g[M<<1],len,lens,Lens;
bool op=0;

inline void Init(){
    scanf("%s",num+1);read(n);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    len=strlen(num+1);
}

inline void Print(int k){
    if(!k) return;
    Lens=strlen(s[g[k]]+1);
    Print(k-Lens);
    printf("%s",s[g[k]]+1);
    if(k!=len) putchar(' ');
}

inline void Solve(){
    fill(f,f+len+1,INF);f[0]=0;
    for(int i=1;i<=len;i++){
        // printf("i=%d\n",i);
        for(int j=1;j<=n;j++){
            // printf("j=%d\n",j);
            lens=strlen(s[j]+1);
            if(lens>i||f[i-lens]==INF) continue;
            op=1;
            for(int k=lens;k>=1;k--){
                if(Num[s[j][k]-'a']!=num[i-lens+k]-'0'){op=0;break;}
            }
            // printf("op=%d\n",op);
            if(!op) continue;
            if(f[i]>f[i-lens]+1){
                f[i]=f[i-lens]+1;g[i]=j;
            }
        }
        // printf("f[%d]=%d\n",i,f[i]);
    }
    if(f[len]==INF) return(void)puts("No solution.");
    Print(len);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}