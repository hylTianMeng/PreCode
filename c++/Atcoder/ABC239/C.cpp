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

typedef pair<int,int> P;
map<P,int> Map;

P a,b;

const int fx[]={0,1,2,2,1,-1,-2,-2,-1};
const int fy[]={0,2,1,-1,-2,-2,-1,1,2};

int main(){
    read(a.first);read(a.second);read(b.first);read(b.second);
    for(int i=1;i<=8;i++){
        P now;
        now.first=a.first+fx[i];
        now.second=a.second+fy[i];
        Map[now]=1;
        // printf("%d %d\n",now.first,now.second);
    }
    // printf("______\n");
    for(int i=1;i<=8;i++){
        P now;
        now.first=b.first+fx[i];
        now.second=b.second+fy[i];
        // printf("%d %d\n",now.first,now.second);
        // printf("%d %d\n",fx[i],fy[i]);
        if(Map.count(now)){
            puts("Yes");return 0;
        }
    }
    puts("No");
    return 0;
}