#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
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

template<typename T> inline T Min(T a,T b){return a<b?a:b;}
template<typename T> inline T Max(T a,T b){return a<b?b:a;}

int f[N][N],n,m,k;
char s1[N],s2[N];

int main()
{
    read(n);read(m);
	scanf("%s%s",s1+1,s2+1);
	int maxx=Max(n,m);
	for(int i=1;i<=maxx;i++) f[0][i]=i,f[i][0]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1];
			else{
				f[i][j]=Min(f[i-1][j],Min(f[i-1][j-1],f[i][j-1]))+1;
			}
		}
	}
    if(f[n][m]>=k){
        printf("NO");return 0;
    }
    printf("YES");
}