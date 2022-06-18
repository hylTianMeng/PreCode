#include<bits/stdc++.h>
#define dd double
#define int long long
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 3010
#define M 30
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

int n,q,ans,Max[N][21],Min[N][21],a[N],b[N][N],s[N][N],Log[N];

void Prepare(){
	for(int i=1;i<=n;i++)
		Log[i]=log2(i);
	for(int j=1;j<M;j++)
		for(int i=1;i+(1ll<<j)-1<=n;i++)
			Max[i][j]=max(Max[i][j-1],Max[i+(1ll<<(j-1))][j-1]);
	for(int j=1;j<M;j++)
		for(int i=1;i+(1ll<<j)-1<=n;i++)
			Min[i][j]=min(Min[i][j-1],Min[i+(1ll<<(j-1))][j-1]);   
}
void Prepare2(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+b[i][j];
}
int Query(int sx,int sy,int tx,int ty){
    int val=s[tx][ty]-s[tx][sy-1]-s[sx-1][ty]+s[sx-1][sy-1];
    return val % mod;
}
int MAX(int l,int r){
	int k=Log[r-l+1];
	return max(Max[l][k],Max[r-(1<<k)+1][k]);
}
int MIN(int l,int r){
    int k=Log[r-l+1];
	return min(Min[l][k],Min[r-(1<<k)+1][k]);
}
signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(q);
    for(int i=1;i<=n;i++){
        read(Min[i][0]);Max[i][0]=Min[i][0];
    }
    // printf("here");
    Prepare();
    // printf("here\n");
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            int Fir=MIN(i,j);
            int Sec=MAX(i,j);
            b[i][j]=Fir*Sec;
        }
    Prepare2();
    while(q--){
        // cout<<"q="<<q<<endl;
        int sx,tx,sy,ty;
        read(sx);read(tx);read(sy);read(ty);
        // printf("here\n");
        printf("%lld\n",Query(sx,sy,tx,ty));
    }
    return 0;   
}