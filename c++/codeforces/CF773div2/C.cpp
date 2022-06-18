#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
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

int t,n,a[N],b[N];
map<int,int> Map;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        int x;
        read(n);read(x);
        for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
        sort(a+1,a+n+1);sort(b+1,b+n+1);
        int len=unique(b+1,b+n+1)-b-1;
        int ans=0;
        for(int i=1;i<=n;i++){
            Map[a[i]]++;
        }
        for(int i=1;i<=len;i++){ 
            while(Map[b[i]]){
                Map[b[i]]--;
                if(Map[b[i]*x]) Map[b[i]*x]--;
                else ans++;
            }
        }
        printf("%lld\n",ans);
        Map.clear();
    }
    return 0;
}