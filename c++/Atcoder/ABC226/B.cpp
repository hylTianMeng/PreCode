#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N number
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

typedef vector<int> V;
set<V> S;
int n;

int main(){
    read(n);
    for(int i=1;i<=n;i++){
        int Len;read(Len);V now;now.clear();
        for(int j=1;j<=Len;j++){
            int x;read(x);now.push_back(x);
        }
        if(S.find(now)!=S.end()) continue;
        S.insert(now);
    }
    printf("%d\n",(int)S.size());
    return 0;
}