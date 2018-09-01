#include<bits/stdc++.h>
using namespace std;
struct Defnes
{
	string _first,_second;
}defne[50];
struct Varbles
{
	string _name,_kind;
}all_varble[1000];
string code[1000],incld[30];
int codenum,incldnum,defnenum,all_varblenum;
int main()
{
	cout<<"Enter your code:\n";
	printf("\n1   | ");
	getline(cin,code[0]);
	while(code[codenum]!=" " && codenum<1000)
	{
		string nowcod=code[codenum];
		if(nowcod[0]=='#')
		{
			if(nowcod.size()>10 && nowcod[1]=='i' && nowcod[2]=='n' && nowcod[3]=='c' && nowcod[4]=='l' && nowcod[5]=='u' && nowcod[6]=='d' && nowcod[7]=='e')
			{
				int pa=nowcod.find(">");
				incld[incldnum++]=nowcod.substr(9,pa-9);
			}
			else if(nowcod.size()>10 && nowcod[1]=='d' && nowcod[2]=='e' && nowcod[3]=='f' && nowcod[4]=='i' && nowcod[5]=='n' && nowcod[6]=='e')
			{
				int first32=nowcod.find(" ");
				int second32=nowcod.find(" ",first32+1);
				if(first32!=string::npos && second32!=string::npos)
				{
					defne[defnenum]._first=nowcod.substr(first32+1,second32-first32-1);
					defne[defnenum++]._second=nowcod.substr(second32+1,nowcod.size()-second32-1);
				}
			}
		}
		else if(nowcod.size()>10 && nowcod[0]=='t' && nowcod[1]=='y' && nowcod[2]=='p' && nowcod[3]=='e' && nowcod[4]=='d' && nowcod[5]=='e' && nowcod[6]=='f')
		{
			string p=nowcod;
			int i;
			for(i=p.size()-1;i>=0;i--)
				if(p[i]==' ') break;
			defne[defnenum]._second=p.substr(8,i-8);
			defne[defnenum++]._first=p.substr(i+1,p.size()-i-2);
		}
		codenum++;
		int sum=0,p=codenum+1;
		printf("%d",codenum+1);
		while(p)
			sum++,p/=10;
		for(int i=0;i<4-sum;i++)
			printf(" ");
		printf("| ");
		getline(cin,code[codenum]);
	}
	for(int i=0;i<codenum;i++)
	{
		string p=code[i];
		string name="",kind;
		int ppp;
		int ppos=p.find("int ");
		if(ppos==string::npos)
		{
			ppos=p.find("double ");
			if(ppos==string::npos)
			{
				ppos=p.find("float ");
				if(ppos==string::npos)
				{
					ppos=p.find("long long ");	
					if(ppos==string::npos)
					{
						ppos=p.find("unsigned long long ");	
						if(ppos==string::npos)
						{
							ppos=p.find("char");
							if(ppos==string::npos)
							{
								ppos=p.find("string ");
								if(ppos==string::npos)
								{
									continue;
								}
								else kind="string",ppp=7+ppos;
							}
							else kind="char",ppp=5+ppos;	
						}
						else kind="unsigned long long",ppp=19+ppos;
					}
					else kind="long long",ppp=10+ppos;
				}
				else kind="float",ppp=6+ppos;
			}
			else kind="double",ppp=7+ppos;
		}
		else kind="int",ppp=4+ppos;
		while(p[ppp]!=';')
		{
			name="";
			while(ppp<p.size() && p[ppp]!=',' && p[ppp]!='=' && p[ppp]!=';' )
				name+=p[ppp],ppp++;
			if(p[ppp]==',') ppp++;
			if(name.find(")")!=string::npos || p.find("for")!=string::npos || p.find("#define")!=string::npos || p.find("typedef")!=string::npos) break;
			int leftnum=0,rightnum=0;
			bool flag=true;
			for(int i=1;i<name.size();i++)
			{
				if(!isalpha(name[i]) && !isdigit(name[i]) && name[i]!='_' && name[i]!='*' && name[i]!=' ' && name[i]!='[' && name[i]!=']')
				{
					flag=false;
					break;
				}
			}
			if(!flag && name[name.size()-1]!=' ' || name==" " || name=="  ")
			{
				ppp++;
				if(ppp==p.size()) break;
				continue;
			}
			flag=false;
			for(int j=i;j>=0;j--)
			{
				if(code[j].find("{")!=string::npos)
				{
					flag=true;
					break;
				}
				if(code[j].find("}")!=string::npos)
					break;
			}
			if(flag) break;
			flag=true;
			for(int i=0;i<name.size();i++)
			{
				if(name[i]!=' ')
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				ppp+=name.size();
				if(ppp==p.size()) break;
				continue;
			}
			for(int j=i;j>=0;j--)
			{
				int pp=code[j].find("{");
				if(pp!=string::npos)
					if(pp==0 || pp==code[j].size()-1 || (code[j][pp-1]!=(char)123 && code[j][pp+1]!=(char)123) || (code[j][pp-1]!=(char)125 && code[j][pp+1]!=(char)125))
						leftnum++;
				pp=code[j].find("}");
				if(pp!=string::npos)
					if(pp==0 || pp==code[j].size()-1 || (code[j][pp-1]!=(char)123 && code[j][pp+1]!=(char)123) || (code[j][pp-1]!=(char)125 && code[j][pp+1]!=(char)125))
						rightnum++;
			}
			if((leftnum+rightnum)%2==0 && leftnum==rightnum)
				all_varble[all_varblenum]._name=name,all_varble[all_varblenum++]._kind=kind;
			if(p[ppp]=='=')
				while(ppp<p.size() && p[ppp]!=',' && p[ppp]!=';' )
					ppp++;
		}
	}
	cout<<"--------------------------------\n";
	cout<<incldnum<<" includes£º\n";
	for(int i=0;i<incldnum;i++)
		cout<<incld[i]<<endl;
	cout<<"--------------------------------\n";
	cout<<defnenum<<" defines & typedefs£º\n";
	for(int i=0;i<defnenum;i++)
		cout<<defne[i]._first<<" -> "<<defne[i]._second<<endl;
	cout<<"--------------------------------\n";
	cout<<all_varblenum<<" global variables£º\n";
	for(int i=0;i<all_varblenum;i++)
		cout<<all_varble[i]._kind<<" : "<<all_varble[i]._name<<endl;
	return 0;
}
