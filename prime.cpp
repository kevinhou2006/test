#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull a[26],i,j,all;
int cnt;
string s;
int main()
{
	cout<<"输入一个单词："; 
	cin>>s;
	srand(time(NULL));
	i=rand()%10000+20000000;
	cout<<"如果令A~Z分别等于\n";
	for(;cnt<26;i+=rand()%10000+2000000)
	{
		bool flag=true;
		for(j=2;j<sqrt(i);j++)
			if(i%j==0)
			{
				flag=false;
				break;
			}
		if(flag && sqrt(i)*sqrt(i)!=i)
		{
			cout<<i<<endl;
			a[cnt]=i;
			cnt++;
		}
	}
	cout<<endl<<"那么"<<s<<"=";
	for(int i=0;i<s.size();i++)
		if(i==0)
			cout<<(char)toupper(s[i]);
		else
			cout<<"+"<<(char)toupper(s[i]);
	cout<<"=";
	for(i=0;i<s.size();i++)
	{
		all+=a[toupper(s[i])-'A'];
		if(i==0)
			cout<<a[toupper(s[i])-'A'];
		else
			cout<<"+"<<a[toupper(s[i])-'A'];
	}
	cout<<"="<<all;
	return 0;
}
