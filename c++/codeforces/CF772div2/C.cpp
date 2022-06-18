#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200100
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

int t,n,a[N];

typedef pair<int,int> P;
pair<P,int> ans[N];

int tail;

int main(){
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        tail=0;
        read(n);for(int i=1;i<=n;i++) read(a[i]);
        if(a[n-1]>a[n]){puts("-1");continue;}
        bool op=0;
        for(int i=1;i<=n-1;i++){
            if(a[i]>a[i+1]){op=1;break;}
        }
        if(!op){puts("0");continue;}
        if(a[n]<0){puts("-1");continue;}
        for(int i=n-2;i>=1;i--){
            a[i]=a[n-1]-a[n];
            ans[++tail]=make_pair(make_pair(i,n-1),n);
        }
        printf("%d\n",tail);
        for(int i=1;i<=tail;i++){
            printf("%d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second);
        }
    }
    return 0;
}