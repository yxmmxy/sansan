/************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
FileName: zg.cpp
Author: yanximing 
Date: 2018.06.28
Description: // 职工工资管理系统
Version: // 6.0
Function List: // 主要函数及其功能
1.-------
History: // 历史修改记录
<author> <time> <version > <desc>
David 96/10/12 1.0 build this moudle
***********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct worker
{
		char num[10];         //工号
		char name[10];   //姓名
		float gwgz;        //岗位工资
		float xjgz;       //薪级工资
		float zwjt;          //职务津贴
		float jxgz;         //绩效工资
		float yfgz;        //应发工资
		float sds;           //个人所得税
		float sfgz;         //实发工资
}zggz[100];  

int n = 0;//职工的总人数
int i = 0;
int flag = 0;
     
float grsds(float yfgz);

void add(struct worker zggz[100])   //添加
{
	n++;
	printf("请输入职工号：\n");
	scanf("%s",zggz[n].num);
	printf("请输入职工姓名：\n");
	scanf("%s",zggz[n].name);
	printf("请输入职工岗位工资：\n");
	scanf("%f",&zggz[n].gwgz);
	printf("请输入职工薪级工资：\n");
	scanf("%f",&zggz[n].xjgz);
	printf("请输入职工职务津贴：\n");
	scanf("%f",&zggz[n].zwjt);
	printf("请输入职工绩效工资：\n");
	scanf("%f",&zggz[n].jxgz);
	zggz[n].yfgz = zggz[n].gwgz + zggz[n].xjgz + zggz[n].zwjt + zggz[n].jxgz;
	zggz[n].sds = grsds(zggz[n].yfgz);
	if(zggz[n].sds == 5)
	{
		zggz[n].sfgz = (1 - zggz[n].sds/100) * zggz[n].yfgz;
	}
	else if(zggz[n].sds == 10) 
	{
		zggz[n].sfgz = (1 - zggz[n].sds/100) * (zggz[n].yfgz - 500) + 500;
	}
	else if(zggz[n].sds == 15) 
	{
		zggz[n].sfgz = (1 - zggz[n].sds/100) * (zggz[n].yfgz - 2000) + 2000;
	}
	else if(zggz[n].sds == 20) 
	{
		zggz[n].sfgz = (1 - zggz[n].sds/100) * (zggz[n].yfgz - 5000) + 5000;
	}
	else if(zggz[n].sds == 25) 
	{
		zggz[n].sfgz = (1 - zggz[n].sds/100) * (zggz[n].yfgz - 20000) + 20000;
	}
	else if(zggz[n].sds == 30) 
	{
		zggz[n].sfgz = (1 - zggz[n].sds/100) * (zggz[n].yfgz - 40000) + 40000;
	}
	else if(zggz[n].sds == 35) 
	{
		zggz[n].sfgz = (1 - zggz[n].sds/100) * (zggz[n].yfgz - 60000) + 60000;
	}
	else if(zggz[n].sds == 40) 
	{
		zggz[n].sfgz = (1 - zggz[n].sds/100) * (zggz[n].yfgz - 80000) + 80000;
	}
	else if(zggz[n].sds == 45) 
	{
		zggz[n].sfgz = (1 - zggz[n].sds/100) * (zggz[n].yfgz - 100000) + 100000;
	}
	
	printf("职工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n"); 
	printf("%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f\n",zggz[n].num,zggz[n].name,zggz[n].gwgz,zggz[n].xjgz,zggz[n].zwjt,zggz[n].jxgz,zggz[n].yfgz,zggz[n].sds,zggz[n].sfgz);
	printf("添加成功\n");
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;
}

void write(struct worker zggz[100])  //保存文件
{
	FILE*fp;   
	if(n > 0)
	{
		if ((fp=fopen("gx.dat","wb"))==NULL) 
		{
				printf ("文件打开失败\n");
				fclose(fp);
				exit(0);
		}
		for (i=1;i<n+1;i++) 
		{
			fprintf(fp,"%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjgz,zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].sds,zggz[i].sfgz);
		}
				
		fclose(fp);
		printf("保存数据成功\n");
	}
	else
	{
		printf("当前没有数据可以保存\n");
	}
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;
}

void read(struct worker zggz[100]) //导入数据
{
	FILE*fp;
	n = 0;
	if((fp=fopen("gx.dat","rb"))==NULL)
	{
			printf ("文件打开失败\n");
			fclose(fp);
			exit(0);
	}
	else
	{
		
		while(!feof(fp))
		{
			n++;
			fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",zggz[n].num,zggz[n].name,&zggz[n].gwgz,&zggz[n].xjgz,&zggz[n].zwjt,&zggz[n].jxgz,&zggz[n].yfgz,&zggz[n].sds,&zggz[n].sfgz);
		} 
	
		fclose(fp);
		printf("导入数据成功\n");
		printf("按回车键退出\n");
		getchar();
		getchar();
		return ;
	}
}

void list(struct worker zggz[100])  //浏览
{
	printf("职工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n"); 
	for(i=1;i<n+1;i++)
	{
		printf("%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f%% %2.1f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjgz,zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].sds,zggz[i].sfgz);
	}
	printf("\n按回车键退出\n");
	getchar();
	getchar();
	return ;
}

void del(struct worker zggz[100])   //删除
{
	char gonghao[10] = {0};
	char ch[2] = {0};
	int j = 0;
	printf("请输入要删除的职工号:\n");
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
		printf("是否删除：(y/n)\n");
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
				printf("输入错误，请重新输入\n");
			}
		}
	}
	else
	{
		printf("\n对不起,查无此人\n");
	}
		
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;
}


void find(struct worker zggz[100])//查找
{
	char gonghao[10] = {0};
	printf("请输入要查找的职工号:\n");
	scanf("%s",gonghao);
	flag = 0;
	for(i=1;i<n+1;i++)
	{
		if(strcmp(gonghao,zggz[i].num) == 0)
		{  
			printf("职工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n"); 
			printf("%s %s %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f%% %2.1f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjgz,zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].sds,zggz[i].sfgz);
			flag = 1;
			break;

		}
	}
	if(flag == 0)
	{		
		printf("\n对不起,查无此人\n");
	}
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;		
}


void modify(struct worker zggz[100]) //修改
{
	char gonghao[10] = {0};
	printf("请输入要修改的职工号:\n");
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
		printf("请输入职工号：\n");
		scanf("%s",zggz[i].num);
		printf("请输入职工姓名：\n");
		scanf("%s",zggz[i].name);
		printf("请输入职工岗位工资：\n");
		scanf("%f",&zggz[i].gwgz);
		printf("请输入职工薪级工资：\n");
		scanf("%f",&zggz[i].xjgz);
		printf("请输入职工职务津贴：\n");
		scanf("%f",&zggz[i].zwjt);
		printf("请输入职工绩效工资：\n");
		scanf("%f",&zggz[i].jxgz);
			zggz[i].yfgz = zggz[i].gwgz + zggz[i].xjgz + zggz[i].zwjt + zggz[i].jxgz;
		
		
		zggz[i].sds = grsds(zggz[i].yfgz);
		if(zggz[i].sds == 5)
		{
			zggz[i].sfgz = (1 - zggz[i].sds/100) * zggz[i].yfgz;
		}
		else if(zggz[i].sds == 10) 
		{
			zggz[i].sfgz = (1 - zggz[i].sds/100) * (zggz[i].yfgz - 500) + 500;
		}
		else if(zggz[i].sds == 15) 
		{
			zggz[i].sfgz = (1 - zggz[i].sds/100) * (zggz[i].yfgz - 2000) + 2000;
		}
		else if(zggz[i].sds == 20) 
		{
			zggz[i].sfgz = (1 - zggz[i].sds/100) * (zggz[i].yfgz - 5000) + 5000;
		}
		else if(zggz[i].sds == 25) 
		{
			zggz[i].sfgz = (1 - zggz[i].sds/100) * (zggz[i].yfgz - 20000) + 20000;
		}
		else if(zggz[i].sds == 30) 
		{
			zggz[i].sfgz = (1 - zggz[i].sds/100) * (zggz[i].yfgz - 40000) + 40000;
		}
		else if(zggz[i].sds == 35) 
		{
			zggz[i].sfgz = (1 - zggz[i].sds/100) * (zggz[i].yfgz - 60000) + 60000;
		}
		else if(zggz[i].sds == 40) 
		{
			zggz[i].sfgz = (1 - zggz[i].sds/100) * (zggz[i].yfgz - 80000) + 80000;
		}
		else if(zggz[i].sds == 45) 
		{
			zggz[i].sfgz = (1 - zggz[i].sds/100) * (zggz[i].yfgz - 100000) + 100000;
		}
		
		
	}
	else
	{
		printf("\n对不起,查无此人\n");
	}
		
	printf("按回车键退出\n");
	getchar();
	getchar();
	return ;
}

float grsds(float yfgz)
{
	for(i = 1; i < n+1; i++)
	{
		if(yfgz <= 500)
		{
			return 5;
		}
		else if(yfgz > 500 && yfgz <= 2000)
		{
			return 10;
		}
		else if(yfgz > 2000 && yfgz <= 5000)
		{
			return 15;
		}
		else if(yfgz > 5000 &&yfgz <= 20000)
		{
			return 20;
		}
		else if(yfgz > 20000 && yfgz <= 40000)
		{
			return 25;
		}
		else if(yfgz > 40000 && yfgz <= 60000)
		{
			return  30;
		}else if(yfgz > 60000 && yfgz <= 80000)
		{
			return 35;
		}
		else if(yfgz > 80000 && yfgz <= 100000)
		{
			return 40;
		}else 
		{
			return 45;
		}
	}
}

void menu() //菜单界面
{
		printf("***欢迎来到职工管理系统***\n\n");
		printf("  1  查询  \n");
		printf("  2  修改  \n");
		printf("  3  添加  \n");
		printf("  4  删除  \n");
		printf("  5  保存  \n");
		printf("  6  浏览  \n");
		printf("  7  退出  \n");
		printf("请选择:");
}


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
				find(zggz);
				break;
			case 2: 
				modify(zggz);
				break;
			case 3:
				add(zggz);
				break; 
			case 4:
				del(zggz);
				break;
			case 5:
				write(zggz);
				break;
			case 6:
				list(zggz);
				break;
			case 7:
				exit(0);
				break;
			default :
				break;
		}
	}
	return 0;
}

