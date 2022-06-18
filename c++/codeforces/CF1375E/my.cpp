#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
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

typedef pair<int,int> P;
int n,tail;P a[N];
vector<int> v[N];
P ans[N*N];

inline bool cmp(int i,int j){
    return a[i]<a[j];
}

int main(){
    read(n);
    for(int i=1;i<=n;i++){
        int x;read(x);a[i]=make_pair(x,i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(a[j]>a[i]) v[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end(),cmp);
    }
    for(int i=n;i>=1;i--){
        for(int j:v[i]){
            ans[++tail]=make_pair(j,i);
            swap(a[j],a[i]);
        }
    }
    printf("%d\n",tail);
    for(int i=1;i<=tail;i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}