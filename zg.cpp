/************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
FileName: zg.cpp
Author: yxm
Date:2018.6.29
Description: ʮ�����Ӧʮ������ // ģ������
Version: 6.0 // �汾��Ϣ
Function List: // ��Ҫ�������书��
1. add�������ְ������
2. write��������ְ������
3. read������������
4 list�������ְ������
5. del����ɾ��ְ������
6. find������������ְ������
7. modify�����޸�ְ������
8. grsds��������˰��
9.menu�����˵�����
10.main����������

-------
History: // ��ʷ�޸ļ�¼
David 201/06/29 1.0 build this moudle
***********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct worker
{
		char num[10];         //����
		char name[10];   //����
		float gwgz;        //��λ����
		float xjgz;       //н������
		float zwjt;          //ְ�����
		float jxgz;         //��Ч����
		float yfgz;        //Ӧ������ 
		float sds;           //��������˰
		float sfgz;         //ʵ������
}zggz[100];  

int n = 0;//ְ����������
int i = 0;
int flag = 0;
     
void grsds(float yfgz,int i);
/***********************************************************
Function: // add

Description: // ���ְ������

Called By: // main()

Input: // ���̼���ְ������

Output: // �����ݴ���zggz[]

***********************************************************/


void add(struct worker zggz[100])   //���
{
	n++;
	printf("������ְ���ţ�\n");
	scanf("%s",zggz[n].num);
	printf("������ְ��������\n");
	scanf("%s",zggz[n].name);
	printf("������ְ����λ���ʣ�\n");
	scanf("%f",&zggz[n].gwgz);
	printf("������ְ��н�����ʣ�\n");
	scanf("%f",&zggz[n].xjgz);
	printf("������ְ��ְ�������\n");
	scanf("%f",&zggz[n].zwjt);
	printf("������ְ����Ч���ʣ�\n");
	scanf("%f",&zggz[n].jxgz);
	zggz[n].yfgz = zggz[n].gwgz + zggz[n].xjgz + zggz[n].zwjt + zggz[n].jxgz;
	grsds(zggz[n].yfgz,n);
    zggz[n].sfgz = zggz[n].yfgz - zggz[n].sds;
	
	printf("ְ���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n"); 
	printf("%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f\n",zggz[n].num,zggz[n].name,zggz[n].gwgz,
		zggz[n].xjgz,zggz[n].zwjt,zggz[n].jxgz,zggz[n].yfgz,zggz[n].sds,zggz[n].sfgz);
	printf("��ӳɹ�\n");
	printf("���س����˳�\n");
	getchar();
	getchar();
	return ;
}
/***********************************************************
Function: // write

Description: // ����ְ���������ݺ���

Called By: // main()

Output: // ��zggz[]���ݴ��뱾���ļ�

***********************************************************/
void write(struct worker zggz[100])  //�����ļ�
{
	FILE*fp;   
	if(n > 0)
	{
		if ((fp=fopen("gx.dat","wb"))==NULL) 
		{
				printf ("�ļ���ʧ��\n");
				fclose(fp);
				exit(0);
		}
		for (i=1;i<n+1;i++) 
		{
			fprintf(fp,"%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f\n",zggz[i].num,zggz[i].name,
				zggz[i].gwgz,zggz[i].xjgz,zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].sds,zggz[i].sfgz);
		}
				
		fclose(fp);
		printf("�������ݳɹ�\n");
	}
	else
	{
		printf("��ǰû�����ݿ��Ա���\n");
	}
	printf("���س����˳�\n");
	getchar();
	getchar();
	return ;
}
/***********************************************************
Function: // read

Description: // ��ȡְ���������ݺ���,������ִ��ʱҪ���úͱ�����õĵ�һ������

Called By: // main()

Input: // �����ļ��Ķ�ȡ

Output: // �������ļ����ݴ���zggz[]

Return: // ��������ֵ��˵��
***********************************************************/
void read(struct worker zggz[100]) //��������
{
	FILE*fp;
	n = 0;
	if((fp=fopen("gx.dat","a+"))==NULL)
	{ 
			printf ("�ļ���ʧ��\n");
			fclose(fp);
			exit(0);
	}
	else
	{
		
		while(!feof(fp))
		{
			n++;
			fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",zggz[n].num,zggz[n].name,&zggz[n].gwgz,
				&zggz[n].xjgz,&zggz[n].zwjt,&zggz[n].jxgz,&zggz[n].yfgz,&zggz[n].sds,&zggz[n].sfgz);
		} 
	
		fclose(fp);
		printf("�������ݳɹ�\n");
		printf("���س����˳�\n");
		getchar();
		getchar();
		return ;
	}
}
/***********************************************************
Function: // list

Description: //���ְ���������ݺ���

Called By: // main()

Output: // ���ȫ��ְ������

***********************************************************/
void list(struct worker zggz[100])  //���
{
	printf("ְ���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n"); 
	for(i=1;i<n+1;i++)
	{
		printf("%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f\n",zggz[i].num,zggz[i].name,
			zggz[i].gwgz,zggz[i].xjgz,zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].sds,zggz[i].sfgz);
	}
     
	printf("\n���س����˳�\n");
	getchar();
	getchar();
	return ;
}
/***********************************************************
Function: // del

Description: //ɾ��ְ���������ݺ���

Called By: // main()

Input: // ���̼��빤��

Output: // �޸�zggz[]����
***********************************************************/
void del(struct worker zggz[100])   //ɾ��
{
	char gonghao[10] = {0};
	char ch[2] = {0};
	int j = 0;
	printf("������Ҫɾ����ְ����:\n");
	scanf("%s",gonghao);
	flag = 0;
	for(i=1;i<n+1;i++)
	{
		if(strcmp(gonghao,zggz[i].num) == 0)
		{  
			flag = 1;
			break;

		}
	}
	if(flag == 1)
	{
		printf("�Ƿ�ɾ����(y/n)\n");
		while(1)
		{
			scanf("%s",ch);
			if(strcmp(ch,"y") == 0)
			{
				for(j=i;j<n;j++)
				{
					strcpy(zggz[j].num,zggz[j+1].num);
					strcpy(zggz[j].name,zggz[j+1].name);
					zggz[j].gwgz=zggz[j+1].gwgz;
					zggz[j].xjgz=zggz[j+1].xjgz;
					zggz[j].zwjt=zggz[j+1].zwjt;
					zggz[j].jxgz=zggz[j+1].jxgz;
					zggz[j].yfgz=zggz[j+1].yfgz;
					zggz[j].sds=zggz[j+1].sds;
					zggz[j].sfgz=zggz[j+1].sfgz;
				}

				n--;
				break;
			}

			else if(strcmp(ch,"n") == 0)
			{
				break;
			}

			else
			{
				printf("�����������������\n");
			}
		}
	}
	else
	{
		printf("\n�Բ���,���޴���\n");
	}
		
	printf("���س����˳�\n");
	getchar();
	getchar();
	return ;
}

/***********************************************************
Function: // find

Description: // ��ѯְ���������ݺ���

Called By: // main()

Input: // ���̼��빤��

Output: // ����ض�ְ������

***********************************************************/
void find(struct worker zggz[100])//����
{
	char gonghao[10] = {0};
	printf("������Ҫ���ҵ�ְ����:\n");
	scanf("%s",gonghao);
	flag = 0;
	for(i=1;i<n+1;i++)
	{
		if(strcmp(gonghao,zggz[i].num) == 0)
		{  
			printf("ְ���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n"); 
			printf("%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f%% %2.1f\n",zggz[i].num,zggz[i].name,
				zggz[i].gwgz,zggz[i].xjgz,zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].sds,zggz[i].sfgz);
			flag = 1;
			break;

		}
	}
	if(flag == 0)
	{		
		printf("\n�Բ���,���޴���\n");
	}
	printf("���س����˳�\n");
	getchar();
	getchar();
	return ;		
}
/***********************************************************
Function: //modify

Description: 	// �޸�ְ���������ݺ���

Called By: // main()

Input: // ���̼��빤��


***********************************************************/

void modify(struct worker zggz[100]) //�޸�
{
    char gonghao[10] = {0};
	printf("������Ҫ�޸ĵ�ְ����:\n");
	scanf("%s",gonghao);
	flag = 0;
	for(i=1;i<n+1;i++)
	{
		if(strcmp(gonghao,zggz[i].num) == 0)
		{  
			flag = 1;
			break;

		}
	}
	if(flag == 1)
	{
		printf("������ְ���ţ�\n");
		scanf("%s",zggz[i].num);
		printf("������ְ��������\n");
		scanf("%s",zggz[i].name);
		printf("������ְ����λ���ʣ�\n");
		scanf("%f",&zggz[i].gwgz);
		printf("������ְ��н�����ʣ�\n");
		scanf("%f",&zggz[i].xjgz);
		printf("������ְ��ְ�������\n");
		scanf("%f",&zggz[i].zwjt);
		printf("������ְ����Ч���ʣ�\n");
		scanf("%f",&zggz[i].jxgz);
		zggz[i].yfgz = zggz[i].gwgz + zggz[i].xjgz + zggz[i].zwjt + zggz[i].jxgz;	
        zggz[i].sfgz = zggz[i].yfgz - zggz[i].sds;
	
	
		
		
		
	}
	else
	{
		printf("\n�Բ���,���޴���\n");
	}
		
	printf("���س����˳�\n");
	getchar();
	getchar();
	return ;

}
/***********************************************************
Function: // grsds

Description: // ��������˰����
Called By: // modify(), add()
***********************************************************/
void grsds(float yfgz,int i)
{    
     

	if (yfgz > 3500)
	{
		if(yfgz <= 4000)
		{
			zggz[i].sds = 0.05*(yfgz-3500);
		}
		else if(yfgz > 4000 && yfgz <= 6000)
		{
			zggz[i].sds = 0.05*(yfgz-3500)+0.1*(yfgz-4000);
		}
		else if(yfgz >6000 && yfgz <= 9000)
		{
		    zggz[i].sds = 0.05*500+0.1*2000+0.15*(yfgz-6000);
		}

		else if(yfgz > 9000 && yfgz <= 21000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*(yfgz-9000);
		}
		else if(yfgz > 21000 && yfgz <= 41000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*(yfgz-21000);
		}
		else if(yfgz > 41000 && yfgz <= 61000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*20000+0.30*(yfgz-41000);
		}else if(yfgz > 61000 && yfgz <= 81000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*20000+0.30*20000+0.35*(yfgz-61000);
		}
		else if(yfgz > 81000 && yfgz <= 101000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*15000+0.30*20000+0.35*20000+0.40*(yfgz-81000);
		}else if(yfgz > 101000)
		{
			zggz[i].sds = 0.05*500+0.1*2000+0.15*3000+0.20*15000+0.25*15000+0.30*20000+0.35*20000+0.40*20000+0.45*(yfgz-101000);
		}
	}
	
     
	else
	{
		zggz[i].sds=0;
	}

}
/***********************************************************
 ***********************************************************/
void menu() //�˵�����
{
		printf("  ###��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ###  \n\n\n");
        printf("  ��ѡ��<1-7>:  \n");
        printf("  ============================================================ \n");
        printf("  |               1  ��ѯְ�����ʼ�¼                        | \n");
		printf("  |               2  �޸�ְ�����ʼ�¼                        | \n");
		printf("  |               3  ���ְ�����ʼ�¼                        | \n");
		printf("  |               4  ɾ��ְ�����ʼ�¼                        | \n");
		printf("  |               5  �������ݵ��ļ�                          | \n");
		printf("  |               6  ���ְ����¼                            | \n");
		printf("  |               7  �˳�ϵͳ                                | \n");
        printf("  ============================================================ \n");
		printf("    ���ѡ����:");
}

/***********************************************************
***********************************************************/
int main()
{   
	int choice = 0;
	read(zggz);
	while(1)
	{
		menu();
		scanf("%d",&choice);
		switch(choice)
		{	
			case 1: 
                system("cls");
				find(zggz);
				break;
              
			case 2: 
                system("cls");
				modify(zggz);
				break;
			case 3:
                 system("cls");
				add(zggz);
				break; 
			case 4:
				del(zggz);
				break;
			case 5:
                system("cls"); 
				write(zggz);
				break;
			case 6:
                 system("cls");
				list(zggz);
				break;
			case 7:
                system("cls");
				exit(0);
				break;
			default :
				break;
		}
	}
	return 0;
}

