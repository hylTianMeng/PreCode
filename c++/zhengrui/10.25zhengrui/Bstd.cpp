#include<bits/stdc++.h>
using namespace std;
#define N 2505
#define ll long long
struct Point{
	ll x,y,z;
	bool operator < (const Point &k)const{
		if (x!=k.x)return x<k.x;
		return ((y<k.y)||(y==k.y)&&(z<k.z));
	}
	bool operator == (const Point &k)const{
		return (x==k.x)&&(y==k.y)&&(z==k.z);
	}
}a[N];
int n;
ll ans;
vector<Point>v;
ll gcd(ll x,ll y){
	if (!y)return x;
	return gcd(y,x%y);
}
Point calc(Point x,Point y){
	Point o=Point{x.y*y.z-x.z*y.y,x.z*y.x-x.x*y.z,x.x*y.y-x.y*y.x};
	ll g=gcd(gcd(abs(o.x),abs(o.y)),abs(o.z));
	if (!g)return o;
	if (o<Point{0,0,0})g=-g;
	return Point{o.x/g,o.y/g,o.z/g};
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
	ans=(ll)n*(n-1)*(n-2)/6;//C(n,3)
	for(int i=1;i<=n;i++){
		v.clear();
		for(int j=i+1;j<=n;j++)v.push_back(calc(a[i],a[j]));
		sort(v.begin(),v.end());
		for(int j=0,lst=0;j<v.size();lst=j){
			while ((j<v.size())&&(v[j]==v[lst]))j++;
			int s=j-lst;
			ans-=s*(s-1)/2;
			if (v[lst]==Point{0,0,0})ans-=s*(n-i-s);
		}
	}
	printf("%lld\n",ans);
	return 0;
}