#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 8010
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

int n,a[N],cnt,b[N];
vector<int> v;

inline void Init(){
    read(n);for(int i=1;i<=n;i++) v.push_back(i);
    for(int i=1;i<=n-1;i++) read(a[i]);
}

vector<int>::iterator it;

inline void Solve(){
    for(int i=n-1;i>=1;i--){
        for(it=v.begin(),cnt=1;it!=v.end();it++,cnt++){
            if(cnt==a[i]+1){
                b[i+1]=(*it);v.erase(it);break;
            }
        }
    }
    b[1]=(*v.begin());
    for(int i=1;i<=n;i++) printf("%d\n",b[i]);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}