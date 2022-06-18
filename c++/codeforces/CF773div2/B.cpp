#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300100
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

int t,n,a[N],b[N],cnt[N];

int main(){
    read(t);
    while(t--){
        read(n);for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
        sort(b+1,b+n+1);
        int len=unique(b+1,b+n+1)-b-1;
        for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+len+1,a[i])-b;
        int tot=0;
        for(int i=1;i<=n;i++){
            if(!cnt[a[i]]) tot++;
            cnt[a[i]]++;
        }
        for(int i=1;i<=n;i++) if(i<=tot) printf("%d ",tot);
        else printf("%d ",i);puts("");
        for(int i=1;i<=n;i++) cnt[a[i]]=0;
    }
    return 0;
}