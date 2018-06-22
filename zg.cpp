#include <stdio.h>
#include <string.h>
#define N 100
struct worker
{
	char gh;//*工号
	char name;//*姓名
	float gw;//*岗位工资
	float xj;//*薪级工资
	float zw;//*职务津贴
	float jx;//*绩效工资
	float yf;//*应发工资
	float gr;//*个人所得税
	float sf;//*实发工资
}
int main()
{   
	int input(struct worker work[],int a );//输入函数，输入职工的信息
	void read(struct worker work[10],int a);//*保存职工信息
	void write(struct worker work[10],int a);//*保存职工信息
    void find(struct worker work[10],int a);//*查询职工信息
    void list(struct worker work[10],int a);//*浏览职工信息
    void modify(struct worker work[10],int a);//*修改职工信息
    void del(struct worker work[10],int a);//*删除职工信息
    void add(struct worker work[10],int a);//*添加职工信息
    void grsds(struct worker work[10],int a);//*计算个人所得
	struct worker work[N],*p=work;
	int a=N,select;
	/*
	printf("请输入职工人数:");
	scanf ("%d",&a);
	*/
	printf("您是首次登陆本系统，请输入员工信息：\n") ;
	a=input(p,a);
	do
	{
		printf("\n **********职工工资管理系统********** \n");
		printf("\n 1.读取职工工资 \n");
		printf("\n 2.保存职工工资 \n");
		printf("\n 3.查询职工工资 \n");
		printf("\n 4.浏览职工工资 \n");
		printf("\n 5.修改职工信息 \n");
        printf("\n 6.删除职工信息 \n");
		printf("\n 7.添加职工信息 \n");
		printf("\n 8.计算个人所得 \n");
		printf("\n 9.退出    系统 \n");
		printf("\n ************************************ \n");
		printf("\n 请输入您的选择 \n");
		scanf("%d",&select);
		switch(select)
		{
		case 0:
			printf("系统已有该职工信息，再次输入将覆盖记录，是否确定（请输入'y'或'n'）");
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
		    printf("要继续吗？请输入‘y’或者‘n’：");
		}

		getchar();
		     ((getchar()=='y')||(getchar()=='Y'));
				a=input(p,a);
				break;



		}
	
	while(1);
	printf("结束！\n");
	return 0;
}

int input(struct worker work[],int a)
{
	int i;
	printf("输入职工信息");
	scanf("%d",&a);
	printf("输入格式为：\工号，姓名\n岗位工资，薪级工资，职务津贴，绩效工资，应发工资，个人所得税，实发工资\n");
	for(i=0;i<a;i++){
	   
	scanf("%d,&s",& work[i].gh,work[i].name);
	scanf("%f,%f,%f,%f,%f,%f,%f,%f",work[i].gw,work[i].xj,work[i].zw,work[i].jx,work[i].yf,work[i].gr,work[i].sf);
	}
return a;

}


void read(struct worker work[10],int a)//*读取职工信息
{
	

}
void write(struct worker work[10],int a)//*保存职工信息
{
}
void find(struct worker work[10],int a)//*查询职工信息
{
}
void list(struct worker work[10],int a)//*浏览职工信息
{
}
void modify(struct worker work[10],int a)//*修改职工信息
{
}
void del(struct worker work[10],int a)//*删除职工信息
{
}
void add(struct worker work[10],int a)//*添加职工信息
{
}
void grsds(struct worker work[10],int a)//*计算个人所得
{
}
