#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
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

int n,s,a[N],jie[N];

inline void Init(){
    read(n);read(s);
    jie[0]=1;for(int i=1;i<=10;i++) jie[i]=jie[i-1]*i;
}

inline bool Check(){
    int sum=0;
    for(int i=1;i<=n;i++) sum+=i%a[i];
    return sum==s;
}

inline void Print(){
    for(int i=1;i<=n;i++) printf("%lld\n",a[i]);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    if(n<=10){
        for(int i=1;i<=n;i++) a[i]=i;
        if(Check()){
            Print();return 0;
        }
        for(int i=1;i<=jie[n]-1;i++){
            next_permutation(a+1,a+n+1);
            if(Check()){
                Print();return 0;
            }
        }
        puts("SPFA is dead!");
        return 0;
    }
    if(s<=2){
        if(s==0){
            for(int i=1;i<=n;i++) a[i]=i;
        } 
        else if(s==1){
            if(n<2){puts("SPFA is dead!");return 0;}
            a[1]=2;a[2]=1;for(int i=3;i<=n;i++) a[i]=i;
        }
        else if(s==2){
            if(n<3){puts("SPFA is dead!");return 0;}
            a[1]=3;a[2]=1;a[3]=2;for(int i=4;i<=n;i++) a[i]=i;
        }
        Print();
        return 0;
    }
    if(s>n*(n-1)/2){
        puts("SPFA is dead!");return 0;
    }
    int shengxia=n*(n-1)/2-s;
    // printf("shengxia=%d\n",shengxia);
    for(int i=1;i<n;i++) a[i]=i+1;a[n]=1;
    if(shengxia==1){
        if(n%2==1){
            a[1]=3;a[2]=1;a[n]=2;
        }
        else if(n%2==0) swap(a[1],a[n]);
        Print();return 0;
    }
    for(int i=n-1;i>=1;i--){
        if(shengxia>=i){
            shengxia-=i;swap(a[i],a[i-1]);
        }
    }
    Print();
    return 0;
}