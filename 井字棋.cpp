#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
char ctmap[20][20]={"       ",
					"-------",
                    "| | | |",
				   	"-------",
				   	"| | | |",
				    "-------",
				    "| | | |",
				    "-------"};
int itgmap[4][4],cnt;
#define putmap for(int i=0;i<=7;i++) cout<<ctmap[i]<<endl;
bool check()
{
	if((itgmap[1][1]==2 && itgmap[1][2]==2 && itgmap[1][3]==2) || (itgmap[2][1]==2 && itgmap[2][2]==2 && itgmap[2][3]==2 )|| (itgmap[3][1]==2 && itgmap[3][2]==2 && itgmap[3][3]==2))
	{
		system("cls");
		cout<<"player2 win!"<<endl;
		putmap
		exit(0);
	}
	else if((itgmap[1][1]==1 && itgmap[1][2]==1 && itgmap[1][3]==1) || (itgmap[2][1]==1 && itgmap[2][2]==1 && itgmap[2][3]==1 )|| (itgmap[3][1]==1 && itgmap[3][2]==1 && itgmap[3][3]==1))
	{
		system("cls");
		cout<<"player1 win!"<<endl;
		putmap
		exit(0);
	}
	else if((itgmap[1][1]==1 && itgmap[2][2]==1 && itgmap[3][3]==1) || (itgmap[1][3]==1 && itgmap[2][2]==1 && itgmap[3][1]==1))
	{
		system("cls");
		cout<<"player1 win!"<<endl;
		putmap
		exit(0);
	}
	else if((itgmap[1][1]==2 && itgmap[2][2]==2 && itgmap[3][3]==2) || (itgmap[1][3]==2 && itgmap[2][2]==2 && itgmap[3][1]==2))
	{
		system("cls");
		cout<<"player2 win!"<<endl;
		putmap
		exit(0);
	}
	else if(cnt==9)
	{
		system("cls");
		cout<<"draw!"<<endl;
		putmap
		exit(0);
	}
	return true;
}
int main()
{
	cout<<"--------------------------------------"<<endl;
	cout<<"          欢迎来到井字棋小游戏。      "<<endl;
	cout<<"游戏规则：两名玩家交替落子，谁的棋子先"<<endl;
	cout<<"连成直线即获胜。请按任意键以开始游戏..."<<endl;
	getch();
	cout<<"--------------------------------------"<<endl;
	int first;
	do
	{
		cout<<"谁先下？(1=player1,2=player2)";
		cin>>first;
	}while(!(first==1 || first==2));
	char play1,play2;
	cout<<"--------------------------------------"<<endl;
	if(first==1)
		cout<<"player1 (O)\nplayer2 (X)\n",play1='O',play2='X';
	else
		cout<<"player1 (X)\nplayer2 (O)\n",play1='X',play2='O';
	cout<<"--------------------------------------"<<endl;
	do
	{
		putmap
		int x,y;
		do
		{
			if(first==1)
				cout<<"Enter player1::x and y：";
			else
				cout<<"Enter player2::x and y：";
			cin>>x>>y;
		}while(itgmap[x][y] || x>3 || y>3);
		cnt++;
		itgmap[x][y]=first;
		ctmap[x*2][y*2-1]=first==1?play1:play2;
		system("cls");
		first=first==1?2:1;
	}while(check());
	return 0;
}
