#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
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

template<typename T> inline T Min(T a,T b){return a<b?a:b;}

vector<int> v[3][3][3];
int Bian[3][3],l[N],r[N];
char s[N];
int n,len,cnt;

inline int Next(int x){return l[x];}
inline int Last(int x){return r[x];}
inline void Delete(int x){r[l[x]]=r[x];l[r[x]]=l[x];}

inline int ID(char c){
    if(c=='B') return 0;else if(c=='R') return 1;return 2;
}

inline void Insert(int id,int l,int r){
    if(ID(s[l])>ID(s[r])) swap(l,r);
    // printf("Insert:%d %d %d id=%d\n",ID(s[id]),ID(s[l]),ID(s[r]),id);
    v[ID(s[id])][ID(s[l])][ID(s[r])].push_back(id);
}

inline void Delete2(int id,int l,int r){
    if(ID(s[l])>ID(s[r])) swap(l,r);
    // printf("Delete:%d %d %d id=%d\n",ID(s[id]),ID(s[l]),ID(s[r]),id);
    v[ID(s[id])][ID(s[l])][ID(s[r])].pop_back();
}

inline void Add(int l,int r){
    if(ID(s[l])>ID(s[r])) swap(l,r);
    // printf("Add:%d %d\n",ID(s[l]),ID(s[r]));
    Bian[ID(s[l])][ID(s[r])]++;
}

inline void Write(int X){
	if(X<0) {X=~(X-1); putchar('-');}
	if(X>9) Write(X/10);
	putchar(X%10+'0');
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);scanf("%s",s);len=strlen(s);
    for(int i=0;i<len;i++){
        l[i]=i-1;r[i]=i+1;
    }
    r[len-1]=0;l[0]=len-1;
    for(int i=0;i<len;i++){
        int l=Last(i),r=Next(i);
        Insert(i,l,r);Add(i,Next(i));
    }
    // printf("here\n");
    while(cnt<n-3){
        cnt++;
        // printf("cnt=%d\n",cnt);
        int minn=INF;
        minn=Min(Bian[0][1],Min(Bian[1][2],Bian[0][2]));
        if(minn==Bian[0][1]){
            int now=v[2][0][1][v[2][0][1].size()-1];
            v[2][0][1].pop_back();
            Bian[0][1]++;Bian[1][2]--;Bian[0][2]--;
            int l=Last(now),r=Next(now);
            Delete2(l,Last(l),Next(l));Delete2(r,Last(r),Next(r));
            Delete(now);
            // printf("%d %d\n",l+1,r+1);
            Write(l+1);putchar(' ');Write(r+1);putchar('\n');
            Insert(l,Last(l),Next(r));Insert(r,Last(r),Next(r));
        }
        else if(minn==Bian[1][2]){
            int now=v[0][1][2][v[0][1][2].size()-1];
            v[0][1][2].pop_back();
            Bian[1][2]++;Bian[0][1]--;Bian[0][2]--;
            int l=Last(now),r=Next(now);
            Delete2(l,Last(l),Next(l));Delete2(r,Last(r),Next(r));
            Delete(now);
            // printf("%d %d\n",l+1,r+1);
            Write(l+1);putchar(' ');Write(r+1);putchar('\n');
            Insert(l,Last(l),Next(r));Insert(r,Last(r),Next(r));
        }
        else if(minn==Bian[0][2]){
            int now=v[1][0][2][v[1][0][2].size()-1];
            v[1][0][2].pop_back();
            Bian[0][2]++;Bian[1][2]--;Bian[0][2]--;
            int l=Last(now),r=Next(now);
            Delete2(l,Last(l),Next(l));Delete2(r,Last(r),Next(r));
            Delete(now);
            // printf("%d %d\n",l+1,r+1);
            Write(l+1);putchar(' ');Write(r+1);putchar('\n');
            Insert(Last(l),l,Next(r));Insert(Last(r),r,Next(r));
        }
    }
    return 0;
}