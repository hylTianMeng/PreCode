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

int n,a[N],top,ans;

typedef pair<int,int> P;
P Stack[N];

inline void Insert(int x){
    if(Stack[top].first!=x){
        Stack[++top].first=x;Stack[top].second=1;
        ans++;
        return;
    }
    Stack[top].second++;ans++;
    if(Stack[top].first==Stack[top].second){
        ans-=Stack[top].second;top--;
    }
}

int main(){
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++){
        Insert(a[i]);
        printf("%d\n",ans);
    }
    return 0;
}