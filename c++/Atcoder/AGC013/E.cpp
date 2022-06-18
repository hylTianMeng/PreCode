#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
#define M number
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
    int a[4][4],n,m;
    inline void Clear(){memset(a,0,sizeof(a));}
    inline Matrix operator * (const Matrix &b)const{
        Matrix c;c.Clear();
        c.n=n;c.m=b.m;
        for(int i=1;i<=c.n;i++)
            for(int j=1;j<=c.m;j++)
                for(int k=1;k<=m;k++) c.a[i][j]=(c.a[i][j]+1ll*a[i][k]*b.a[k][j]%mod)%mod;
        return c;
    }
    inline void Print(){
        printf("%d %d\n",n,m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
            puts("");
        }
        puts("");
    }
}I,A,B,C;

inline Matrix ksm(Matrix a,int b){
    Matrix res=I;
    while(b){if(b&1) res=res*a;a=a*a;b>>=1;}return res;
}

int n,m,a[N];

inline void PreWork(){
    read(n);read(m);
    for(int i=1;i<=3;i++) I.a[i][i]=1;
    I.n=I.m=3;
    for(int i=1;i<=m;i++) read(a[i]);
    A.n=1;A.m=3;
    A.a[1][1]=1;A.a[1][2]=1;A.a[1][3]=1;
    B.n=3;B.m=3;
    B.a[1][1]=2;B.a[1][2]=1;B.a[1][3]=1;
    B.a[2][1]=2;B.a[2][2]=1;B.a[2][3]=0;
    B.a[3][1]=1;B.a[3][2]=1;B.a[3][3]=1;
    C.n=3;C.m=3;
    C.a[1][1]=1;C.a[1][2]=0;C.a[1][3]=0;
    C.a[2][1]=2;C.a[2][2]=1;C.a[2][3]=0;
    C.a[3][1]=1;C.a[3][2]=1;C.a[3][3]=1;
}

inline void Solve(){
    if(a[m]!=n){
        a[++m]=n;
    }
    int last=1;
    for(int i=1;i<=m;i++){
        int len=a[i]-last;
        Matrix trans=ksm(B,len);
        A=A*trans;
        if(i!=m) A=A*C; 
        last=a[i]+1;
    }
    printf("%d\n",A.a[1][1]);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork();
    Solve();
    return 0;
}