#include<bits/stdc++.h>
#define dd double
#define int long long
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 4010
#define M number
using namespace std;

const int INF=1e18;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int f[N][N],P[N],W[N],n,m,Sum[N][N],Sum2[N],a[N][N],Ans;
void E(long long &x, long long y) { x ^= y; x ^= x >> 12; x ^= x << 25; x ^= x >> 27; }

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
		read(P[i]);read(W[i]);a[i][P[i]]=W[i];
    }
}

inline void GetPre(){
	Sum[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			Sum2[j]=Sum2[j-1]+a[i][j];
			Sum[i][j]=Sum[i-1][j]+Sum2[j];
		}
}

inline void Dp(){
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int Now=-INF;
			for(int k=1;k<i;k++)
				for(int l=1;l<j;l++) Now=max(Now,f[k][l]+Sum[k][l]-Sum[k][j]-Sum[i][l]);
			Now=max(Now,0ll);Now+=Sum[i][j];
			f[i][j]=Now;E(Ans,Now);
		}
	printf("%lld",Ans);
}

signed main(){
	Init();GetPre();Dp();return 0;
}


