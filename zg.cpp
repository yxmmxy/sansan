#include <stdio.h>
#include <string.h>
#define N 100
struct worker
{
	char gh;//*����
	char name;//*����
	float gw;//*��λ����
	float xj;//*н������
	float zw;//*ְ�����
	float jx;//*��Ч����
	float yf;//*Ӧ������
	float gr;//*��������˰
	float sf;//*ʵ������
}
int main()
{   
	int input(struct worker work[],int a );//���뺯��������ְ������Ϣ
	void read(struct worker work[10],int a);//*����ְ����Ϣ
	void write(struct worker work[10],int a);//*����ְ����Ϣ
    void find(struct worker work[10],int a);//*��ѯְ����Ϣ
    void list(struct worker work[10],int a);//*���ְ����Ϣ
    void modify(struct worker work[10],int a);//*�޸�ְ����Ϣ
    void del(struct worker work[10],int a);//*ɾ��ְ����Ϣ
    void add(struct worker work[10],int a);//*���ְ����Ϣ
    void grsds(struct worker work[10],int a);//*�����������
	struct worker work[N],*p=work;
	int a=N,select;
	/*
	printf("������ְ������:");
	scanf ("%d",&a);
	*/
	printf("�����״ε�½��ϵͳ��������Ա����Ϣ��\n") ;
	a=input(p,a);
	do
	{
		printf("\n **********ְ�����ʹ���ϵͳ********** \n");
		printf("\n 1.��ȡְ������ \n");
		printf("\n 2.����ְ������ \n");
		printf("\n 3.��ѯְ������ \n");
		printf("\n 4.���ְ������ \n");
		printf("\n 5.�޸�ְ����Ϣ \n");
        printf("\n 6.ɾ��ְ����Ϣ \n");
		printf("\n 7.���ְ����Ϣ \n");
		printf("\n 8.����������� \n");
		printf("\n 9.�˳�    ϵͳ \n");
		printf("\n ************************************ \n");
		printf("\n ����������ѡ�� \n");
		scanf("%d",&select);
		switch(select)
		{
		case 0:
			printf("ϵͳ���и�ְ����Ϣ���ٴ����뽫���Ǽ�¼���Ƿ�ȷ����������'y'��'n'��");
				getchar();
			if((getchar()=='y')||(getchar()=='Y'));
				a=input(p,a);
		case 1:
			read(p,a);
			break;
		case 2:
			write(p,a);
			break;
		case 3:
			find(p,a);
			break;
		case 4:
			list(p,a);
			break;
		case 5:
			modify(p,a);
			break;
		case 6:
			del(p,a);
			break;
		case 7:
			add(p,a);
			break;
		case 8:
			grsds(p,a);
			break;
		case 9:
		    printf("Ҫ�����������롮y�����ߡ�n����");
		}

		getchar();
		     ((getchar()=='y')||(getchar()=='Y'));
				a=input(p,a);
				break;



		}
	
	while(1);
	printf("������\n");
	return 0;
}

int input(struct worker work[],int a)
{
	int i;
	printf("����ְ����Ϣ");
	scanf("%d",&a);
	printf("�����ʽΪ��\���ţ�����\n��λ���ʣ�н�����ʣ�ְ���������Ч���ʣ�Ӧ�����ʣ���������˰��ʵ������\n");
	for(i=0;i<a;i++){
	   
	scanf("%d,&s",& work[i].gh,work[i].name);
	scanf("%f,%f,%f,%f,%f,%f,%f,%f",work[i].gw,work[i].xj,work[i].zw,work[i].jx,work[i].yf,work[i].gr,work[i].sf);
	}
return a;

}


void read(struct worker work[10],int a)//*��ȡְ����Ϣ
{
	

}
void write(struct worker work[10],int a)//*����ְ����Ϣ
{
}
void find(struct worker work[10],int a)//*��ѯְ����Ϣ
{
}
void list(struct worker work[10],int a)//*���ְ����Ϣ
{
}
void modify(struct worker work[10],int a)//*�޸�ְ����Ϣ
{
}
void del(struct worker work[10],int a)//*ɾ��ְ����Ϣ
{
}
void add(struct worker work[10],int a)//*���ְ����Ϣ
{
}
void grsds(struct worker work[10],int a)//*�����������
{
}
