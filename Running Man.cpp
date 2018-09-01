#include<bits/stdc++.h>
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;
const int X=30;
const int Y=14;
char a[100][100]={"##############################",
	              "#      ## #      #      ##   #",
				  "#             #       ##    ##",
				  "#       #                    #",
				  "##           #       #       #",
				  "#   #     ##       #      ####",
				  "#  #          #    #    ##   #",
				  "#     ##                     #",
				  "#           # #   #    ##   ##",
				  "#    ##            #    #  ###",
				  "##      #      #     #       #",
				  "#    ##   ##   #  #   #   ####",
				  "###              ##          #",
				  "##############################"};
int putmap(int e,string pp)
{
	for(int i=0;i<Y;i++) puts(a[i]);
	if(pp!=" ")
	cout<<pp;
	else
	cout<<"level:"<<e;
	return 0;
}
int putsomethinginmap(int x,int y,char g)
{
	int x1,y1;
	do
	{
		srand(time(NULL));
		x1=rand()%(x-1)+1;
		srand(time(NULL));
		y1=rand()%(y-1)+1;
	}while(a[x1][y1]!=' ');
	a[x1][y1]=g;
	return 0;
}
int gameover()
{
	system("cls");
	char gf[]="Game over!";
	for(int i=0;i<strlen(gf);i++)
	{
		cout<<gf[i];
		Sleep(100);
	}
	return 0;
}
int main()
{
	system("color 0a");
	system("cls");
	int level=1;
	int x=2,y=4;
	putmap(level,"加载中……");
	putsomethinginmap(X,Y,'1');
	putsomethinginmap(X,Y,'1');
	putsomethinginmap(X,Y,'1');
	putsomethinginmap(X,Y,'1');
	putsomethinginmap(X,Y,'1');
	system("cls");
	a[x][y]='O';
	putmap(level," ");
	int angle=2;
	char n;
	while(1)
	{
		n=getch();
		if(n=='a' || n=='A') angle=3;
		else if(n=='s' || n=='S') angle=2;
		else if(n=='w' || n=='W') angle=1;
		else if(n=='D' || n=='d') angle=4;
		if(angle==1)
		{
			if(a[x-level][y]==' ')
			{
				a[x][y]=' ';
				a[x-level][y]='O';
				x-=level;
			}
			else if(a[x-level][y]=='1')
			{
				a[x][y]=' ';
				a[x-level][y]='O';
				x-=level;
				level++;
				system("cls");
				putmap(level,"加载中……");
				putsomethinginmap(X,Y,'1');
			} 
			else break;
		}
		if(angle==2)
		{
			if(a[x+level][y]==' ')
			{
				a[x][y]=' ';
				a[x+level][y]='O';
				x+=level;
			}
			else if(a[x+level][y]=='1')
			{
				a[x][y]=' ';
				a[x+level][y]='O';
				x+=level;
				level++;
				system("cls");
				putmap(level,"加载中……");
				putsomethinginmap(X,Y,'1');
			} 
			else break;
		}
		if(angle==3)
		{
			if(a[x][y-level]==' ')
			{
				a[x][y]=' ';
				a[x][y-level]='O';
				y-=level;
			}
			else if(a[x][y-level]=='1')
			{
				a[x][y]=' ';
				a[x][y-level]='O';
				y-=level;
				level++;
				system("cls");
				putmap(level,"加载中……");
				putsomethinginmap(X,Y,'1');
			} 
			else break;
		}
		if(angle==4)
		{
			if(a[x][y+level]==' ')
			{
				a[x][y]=' ';
				a[x][y+level]='O';
				y+=level;
			}
			else if(a[x][y+level]=='1')
			{
				a[x][y]=' ';
				a[x][y+level]='O';
				y+=level;
				level++;
				system("cls");
				putmap(level,"加载中……");
				putsomethinginmap(X,Y,'1');
			} 
			else break;
		}
		system("cls");
		putmap(level," ");
	}
	gameover();
	a[x][y]=' ';
	for(int i=0;i<X;i++)
	{
		for(int j=0;j<Y;j++)
		{
			if(a[i][j]=='1') a[i][j]=' ';
		}
	}
	char k;
	cout<<endl<<"是否继续？(Y/N)";
	cin>>k;
	if(k=='Y' || k=='y') main();
	return 0;
}
