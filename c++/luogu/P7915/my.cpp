#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000110
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

int t,n,a[N],ans[N],tail,posi1,posi2,b[N],li,ri;
bool op=0,flag=0;

inline void Print(){
    for(int i=1;i<=n;i++)if(ans[i]==-1) putchar('L');else if(ans[i]==1) putchar('R');puts("");
}

inline void Ly(int &l,int &r,int &z,int &y){
    while(1){
        op=0;
        while(l<z-1&&a[l]==a[z-1]){
            l++;z--;ans[++tail]=-1;op=1;flag=1;
        }
        while(y<r&&a[l]==a[y+1]){
            l++;y++;ans[++tail]=-1;op=1;flag=1;
        }
        if(!op) return;
    }
}

inline bool Check(int l,int r,int z,int y){
    while(y-z+1<(n>>1)){
        flag=0;
        Ly(l,r,z,y);
        if(l<z&&a[r]==a[z-1]){
            r--;z--;ans[++tail]=1;flag=1;
        }
        Ly(l,r,z,y);
        if(y+1<r&&a[r]==a[y+1]){
            r--;y++;ans[++tail]=1;flag=1;
        }
        Ly(l,r,z,y);
        // Print();
        if(!flag){return 0;}
    }
    return 1;
}

inline void Init(){
    read(n);n<<=1;
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=2;i<=n;i++) if(a[1]==a[i]) posi1=i;
    for(int i=1;i<=n-1;i++) if(a[i]==a[n]) posi2=i;
}

inline void GetAns(){
    li=1;ri=n;
    for(int i=1;i<=tail;i++){
        if(ans[i]==1) b[i]=a[ri--];
        else b[i]=a[li++];
    }
    for(int i=tail;i>=1;i--){
        if(a[li]==b[i]){li++;ans[2*tail-i+1]=-1;}
        else{ri--;ans[2*tail-i+1]=1;} 
    }
}

inline void Solve(){
    tail=0;ans[++tail]=-1;
    if(Check(2,n,posi1,posi1)){
        GetAns();Print();return;
    }
    tail=0;ans[++tail]=1;
    if(Check(1,n-1,posi2,posi2)){
        GetAns();Print();return;
    }
    tail=0;puts("-1");
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();Solve();
    }
    return 0;
}