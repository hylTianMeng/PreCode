#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 5000100
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

int n,m,A,a[N];
int b[N],c[N],tail,head;
typedef pair<int,int> P;
P q[N];
int nowans,Ans=-INF;

inline void PreWork(){
    for(int i=1;i<=m;i++){
        while(q[tail].first<=a[i]&&tail) tail--;
        q[++tail]=make_pair(a[i],i);
    }
    b[1]=q[1].first;
    for(int i=2;i<=n-m+1;i++){
        while(head<tail&&q[head+1].second<i) head++;
        while(head<tail&&q[tail].first<=a[i+m-1]) tail--;
        q[++tail]=make_pair(a[i+m-1],i+m-1);b[i]=q[head+1].first;
    }
    head=tail=0;m--;
    for(int i=1;i<=m;i++){
        while(q[tail].first<=a[i]&&tail) tail--;
        q[++tail]=make_pair(a[i],i);
    }
    c[1]=q[1].first;
    for(int i=2;i<=n-m+1;i++){
        while(head<tail&&q[head+1].second<i) head++;
        while(head<tail&&q[tail].first<=a[i+m-1]) tail--;
        q[++tail]=make_pair(a[i+m-1],i+m-1);c[i]=q[head+1].first;
    }m++;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);read(A);
    for(int i=1;i<=n;i++) read(a[i]);
    PreWork();
    // for(int i=1;i<=n;i++) printf("%d ",b[i]);puts("");
    // for(int i=1;i<=n;i++) printf("%d ",c[i]);puts("");
    nowans=max(A,c[1]);
    for(int i=1;i<=n-m+1;i++) nowans+=b[i];Ans=nowans;
    // printf("%d\n",Ans);
    for(int i=1;i<=n;i++){
        int n1=i-m+1,n2=i+1;
        // printf("n1=%d n2=%d\n",n1,n2);
        if(n1>=1){
            nowans-=max(c[n1],A);
            nowans+=(b[n1]);
        }
        if(n2<=n-m+2){
            nowans-=b[n2-1];
            nowans+=max(A,c[n2]);
        }
        Ans=max(Ans,nowans);
        // printf("%d\n",nowans);
    }
    printf("%lld\n",Ans);
    return 0;
}