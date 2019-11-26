#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define MAXSIZE 301
using namespace std;
struct Athlete
{
int school;            //学校编号
char name[10];       //姓名
int item;             //项目编号
int rank;            //名次
int score;           //名次对应的得分
char sex;           // 性别 
};
 
struct Seqlist         //结构体数组
{
Athlete s[MAXSIZE];
int last;
};
 void change(Athlete* e)
{
if(e->item%2==0)
{
switch(e->rank)
{
case 1:
e->score=5;
break;
case 2:
e->score=3;
break;
case 3:
e->score=2;
break;
}
}
if(e->item%2==1)
{
    switch(e->rank)
    {
        case 1:
        e->score=7;
        break;
        case 2:
        e->score=5;
        break;
        case 3:
        e->score=3;
        break;
        case 4:
        e->score=2;
        break;
        case 5:
        e->score=1;
        break;
}
}
}
void intput(Seqlist&list,int n){
	int i=1;
	list.last=0;
	cout<<"请依次输入学校编号，学生姓名，学生性别，项目编号,学生名次"<<endl;
	while(n>0){
		cin>>list.s[i].school>>list.s[i].name>>
		list.s[i].sex>>list.s[i].item
		>>list.s[i].rank;
		change(&list.s[i]);
		i++;
		list.last++;
		n--;
	}
}
void display(Seqlist L,int num,int n)//althletenum,school
{
	int j,i;
	int s=0,m=0,w=0;
	cout<<"打印成绩报表"<<endl;
	for(j=1;j<=n;j++)
	{
		w=0;m=0;s=0;
		for(i=1;i<=num;i++)
		
			if(j==L.s[i].school){
				cout<<"学校编号"<<L.s[i].school<<" ";
				cout<<"学生姓名"<<L.s[i].name<<" ";
				cout<<"学生性别"<<L.s[i].sex<<" ";
				cout<<"项目编号"<<L.s[i].item<<" ";
				cout<<"学生名次"<<L.s[i].rank<<" ";
				cout<<"学生得分"<<L.s[i].score<<endl;
				if(L.s[i].sex=='w')
				w+=L.s[i].score;
				if(L.s[i].sex=='m')
					m+=L.s[i].score;
					s=w+m;
				
			}
			cout<<j<<"团体总分"<<s<<endl;
			cout<<j<<"女子团体总分"<<w<<endl;
			cout<<j<<"男子团体总分"<<m<<endl;
			cout<<endl;
	
	}
}
int main(){
	Seqlist se;
	int al,sc;
	cout<<"请输入学校数量和运动员数量"<<endl;
	cin>>sc>>al;
	intput(se,al);
	display(se,al,sc);
	
	return 0;
}


