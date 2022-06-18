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
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int f[N],g[N],n;
int main(){
    read(n);
	int b=sqrt(n);
	f[0]=g[0]=1;
	for(int i=1,p;i<=b;i++){
		p=i*i;
		for(int tt=1;tt<=2;tt++)
		for(int j=i;j+p<=n;j++)
        f[j]=(f[j]+f[j-i])%mod;
		for(int j=p;j<=n;j++)
        g[j]=(g[j]+f[j-p])%mod;
	}
	for(int i=1;i<=n;i++)cout<<g[i]<<"\n";
	return 0;
}
