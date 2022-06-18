#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 50
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

int cnt[10],n;
char s[N];

vector<int> v[10];

inline void PreWork(){
    v[2].push_back(2);v[3].push_back(3);
    v[4].push_back(2);v[4].push_back(2);v[5].push_back(5);
    v[6].push_back(5);v[6].push_back(3);v[7].push_back(7);
    v[8].push_back(7);v[8].push_back(2);v[8].push_back(2);
    v[8].push_back(2);v[9].push_back(7);v[9].push_back(3);
    v[9].push_back(3);v[4].push_back(3);v[9].push_back(2);
}

int main(){
    freopen("david.in","r",stdin);
    freopen("david.out","w",stdout);
    PreWork();
    read(n);scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(v[s[i]-'0'].empty()) continue;
        for(int j:v[s[i]-'0']){
            cnt[j]++;
        }
    }
    for(int i=9;i>=2;i--){
        for(int j=1;j<=cnt[i];j++) putchar(i+'0');
    }
    return 0;
}