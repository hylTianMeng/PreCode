#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
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

int t,n,a[N],cnt[N],ans[N],tail;

inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        tail=0;
        for(int i=0;i<=30;i++) cnt[i]=0;
        Init();
        bool op=1;
        for(int i=1;i<=n;i++) if(a[i]!=0) op=0;
        if(op){
            for(int i=1;i<=n;i++) printf("%d ",i);puts("");continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=30;j>=0;j--){
                if((a[i]>>j)&1) cnt[j]++;
            }
        }
        int g=-1;
        for(int i=30;i>=0;i--){
            if(!cnt[i]) continue;
            if(g==-1) g=cnt[i];
            else g=gcd(g,cnt[i]);
        }
        int i;
        for(i=1;i*i<g;i++){
            if(g%i==0){
                ans[++tail]=i;ans[++tail]=g/i;
            }
        }
        if(g==i*i) ans[++tail]=i;
        sort(ans+1,ans+tail+1);
        for(int i=1;i<=tail;i++) printf("%d ",ans[i]);
        puts("");
    }
}