#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<deque>
#include<cstdlib>
#include<ctime>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define ull unsigned long long
#define N number
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

inline int Min(int a,int b){
	return a>b?b:a;
}

inline int Max(int a,int b){
	return a>b?a:b;
}

template <typename T> inline void read(T &x) {
	x=0; int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

template <typename T> inline void write(T x) {
	if(x < 0) x=-x,putchar('-');
	if(x > 9) write(x / 10);
	putchar(x%10+'0');
}

template <typename T> inline void writeln(T x) {
	write(x);
	puts("");
}

int n,X,last,l,r,m;

signed main(){
	read(n);read(m);read(X);
	for(int i=1;i<=n;i++){
		int x,a,b;read(x);read(a);read(b);
		if(a>=b){
			printf("NIE\n");
			return 0;
		}
		if(x>=X) break;
		r+=x-last;last=x;
		a=((x+a)*1.0/2)+1;b=((x+b-1)/2);
		r=Min(r,b);l=Max(l,a);
		if(l>r){
			printf("NIE\n");
			return 0;
		}
	}
	writeln(l);
	return 0;
}