#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define MAXSIZE 301
using namespace std;
struct Athlete
{
int school;            //ѧУ���
char name[10];       //����
int item;             //��Ŀ���
int rank;            //����
int score;           //���ζ�Ӧ�ĵ÷�
char sex;           // �Ա� 
};
 
struct Seqlist         //�ṹ������
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
	cout<<"����������ѧУ��ţ�ѧ��������ѧ���Ա���Ŀ���,ѧ������"<<endl;
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
	cout<<"��ӡ�ɼ�����"<<endl;
	for(j=1;j<=n;j++)
	{
		w=0;m=0;s=0;
		for(i=1;i<=num;i++)
		
			if(j==L.s[i].school){
				cout<<"ѧУ���"<<L.s[i].school<<" ";
				cout<<"ѧ������"<<L.s[i].name<<" ";
				cout<<"ѧ���Ա�"<<L.s[i].sex<<" ";
				cout<<"��Ŀ���"<<L.s[i].item<<" ";
				cout<<"ѧ������"<<L.s[i].rank<<" ";
				cout<<"ѧ���÷�"<<L.s[i].score<<endl;
				if(L.s[i].sex=='w')
				w+=L.s[i].score;
				if(L.s[i].sex=='m')
					m+=L.s[i].score;
					s=w+m;
				
			}
			cout<<j<<"�����ܷ�"<<s<<endl;
			cout<<j<<"Ů�������ܷ�"<<w<<endl;
			cout<<j<<"���������ܷ�"<<m<<endl;
			cout<<endl;
	
	}
}
int main(){
	Seqlist se;
	int al,sc;
	cout<<"������ѧУ�������˶�Ա����"<<endl;
	cin>>sc>>al;
	intput(se,al);
	display(se,al,sc);
	
	return 0;
}


