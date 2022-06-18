#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 111
#define M 25
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct Matrix{
    int a[M][M],n,m;
    inline Matrix(){memset(a,0,sizeof(a));}
    inline Matrix operator * (const Matrix &b)const{
        Matrix c;c.n=n;c.m=b.m;
        for(int i=0;i<c.n;i++){
            for(int j=0;j<c.m;j++)
                for(int k=0;k<m;k++)
                    c.a[i][j]=(c.a[i][j]+1ll*a[i][k]*b.a[k][j]%mod)%mod;
                }
        return c;
    }
    inline void dwh(){
        assert(n==m);
        for(int i=0;i<n;i++) a[i][i]=1;
    }
    inline void Print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ",a[i][j]);
            }
            putchar('\n');
        }puts("");
    }
};

int n,m,a[N],b[N],c[N],Ans,f[N][M],C[N][N];
bool Sub2=1,Sub1=1;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);read(b[i]);
        if(a[i]>10) Sub2=0;
        if(a[i]!=1) Sub1=0;
    }
    for(int i=0;i<=100;i++)
        for(int j=0;j<=i;j++){
            if(j==0||j==i) C[i][j]=1;
            else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
}

inline void dfs(int k){
    if(k==n+1){
        int sum=0;
        for(int i=1;i<=n;i++) if(c[i]) sum+=b[i];
        if(sum%m==0) Ans++;
        return;
    }
    c[k]=1;dfs(k+1);c[k]=0;dfs(k+1);
}

inline void Dp(){
    f[0][0]=1;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            for(int k=0;k<=a[i+1];k++){
                (f[i+1][(j+k*b[i+1])%m]+=1ll*f[i][j]*C[a[i+1]][k]%mod)%=mod;
            }
        }
        printf("%d\n",f[i+1][0]);
    }
    Ans=f[n][0];
}

inline Matrix ksm(Matrix a,int b){
    Matrix now;now.m=now.n=m;now.dwh();
    while(b){if(b&1) now=now*a;a=a*a;b>>=1;}return now;
}

inline void PositiveSolution(){
    Matrix ans;ans.a[0][0]=1;ans.n=1;ans.m=m;
    for(int i=1;i<=n;i++){
        Matrix now;now.n=now.m=m;
        for(int j=0;j<=m-1;j++){
            int mo=b[i]%m;
            now.a[j][j]++;
            now.a[(m-mo+j)%m][j]++;
        }
        now.Print();
        Matrix No;No=ksm(now,a[i]);No.Print();
        ans=ans*No;
        ans.Print();
    }
    Ans=ans.a[0][0];
}

inline void Solve(){
    if(n<=10&&Sub1){
        dfs(1);printf("%d\n",Ans-1);return;
    }
    else if(Sub2){
        // printf("here\n");
        Dp();printf("%d\n",Ans-1);return;
    }
    else{
        PositiveSolution();
        printf("%d\n",Ans-1);return;
    }
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my2.out","w",stdout);
    Init();Solve();return 0;
}
/*
9 16
3 14
4 12
4 6
2 7
5 14
2 10
5 4
5 1
5 10

147488241
*/