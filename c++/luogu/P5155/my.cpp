#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 100100
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


int top;
int n,a[N];

typedef pair<int,int> P;
P b[N];
P Stack[N];

inline int operator ^ (const P &c,const P &d){
    // printf("%d %d %d %d\n",c.first,c.second,d.first,d.second);
    return d.second*c.first-d.first*c.second;
}

inline P operator - (const P &c,const P &d){
    return make_pair(c.first-d.first,c.second-d.second);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) b[i]=make_pair(i,a[i]*100000); 
    int nn=n+1;
    b[++n]=make_pair(0,0);b[++n]=make_pair(nn,0);
    sort(b+1,b+n+1);
    Stack[++top]=b[1];Stack[++top]=b[2];
    for(int i=3;i<=n;i++){
        while((((Stack[top-1]-Stack[top])^(b[i]-Stack[top]))<=0)&&top>=2) top--;
        // printf("top=%d\n",top);
        Stack[++top]=b[i];
    }
    // for(int i=1;i<=top;i++){
    //     printf("%d %d\n",Stack[i].first,Stack[i].second);
    // }
    for(int i=1;i<=n-2;i++){
        P now=make_pair(i,-INF);
        int R=upper_bound(Stack+1,Stack+top+1,now)-Stack;
        int L=R-1;
        printf("%lld\n",(Stack[R].second*(i-Stack[L].first)+Stack[L].second*(Stack[R].first-i))/(Stack[R].first-Stack[L].first));
    }
    return 0;
}