#include <cstdio>
#include <cstdlib>
#include <cstring>
#define int long long//懒得一个个改于是就只好暴力一点了……

int a,b;
int ans[10010],anss=0;
int s[10010],t=0;
int least(int x,int y)//求出第一个小于x/y的单位分数的分母（优化2）
{
	for(int i=2;;i++)
	if(x*i>y)return i;
}
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int maxx(int x,int y){return x>y?x:y;}
bool dfs(int re,int x,int y)//re表示还要选re个数（也就是上面的k）
{
	if(re==1)//当只剩最后一个数时，显然最后这个数我们只能选x/y
	{
		//如果x/y是个单位分数并且它比之前的解要更加优秀
		if(x==1&&y>s[t]&&(anss==0||y<ans[anss]))
		{
			anss=++t;s[t]=y;//更新答案
			for(int i=1;i<=t;i++)
			ans[i]=s[i];
			t--;
			return true;
		}
		return false;
	}
	bool getans=false;//记录是否找到答案
	//下限，两者间取个最大值
	for(int i=maxx(s[t]+1,least(x,y));re*y>x*i;i++)//上限如上所述
	{
		int yy(y/gcd(y,i)*i);
		int xx(x*(yy/y)-yy/i);//xx/yy = x/y - 1/i
		s[++t]=i;//记录减去的分数的分母
		if(dfs(re-1,xx/gcd(xx,yy),yy/gcd(xx,yy)))getans=true;
		t--;
	}
	return getans;
}
#undef int

int main()
{
	#define int long long
	scanf("%lld %lld",&a,&b);
	int gg=gcd(a,b);
	a/=gg;b/=gg;
	if(a==1)printf("%lld",b),exit(0);
	s[0]=1;
	for(int i=2;;i++)
	{
		t=0;
		if(dfs(i,a,b))//如果找到答案就输出
		{
			for(int i=1;i<=anss;i++)
			printf("%lld ",ans[i]);
			return 0;
		}
	}
}