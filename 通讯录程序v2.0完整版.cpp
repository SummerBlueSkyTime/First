#include<bits/stdc++.h>
#include<iostream>
#define MAX 1000
#define SIZE 1000
using namespace std;


struct person{
    char p_name[10];//姓名 
    char p_address[10];//籍贯 
    char p_phone1[10];//电话1 
    char p_phone2[10];//电话2 
    char p_Email[10];//电子邮件 
};

struct book
{
    struct person p[MAX];
    int num;
};

//判断函数，判断该联系人是否存在，并返回存在地址（从0开始），不存在返回-1
int exist(struct book * abs,string name){
    for(int i=0;i<abs->num;i++)
    {
        if(abs->p[i].p_name==name)//判断是否存在
        {
            return i;//返回地址
        }
    }
    return -1;//不存在的情况
}

//加载文件内容 
void loan_file(struct book *abs)
{
	struct person tmp;//临时结构体 
	FILE *fp;//文件指针 
	
if((fp=fopen("file_book.dat","rb+"))==NULL)//打开输入文件 
	{
		fp=fopen("file_book.dat","wb+");
		return ;
	 }//用只读二进制打开文件 
	
	while(fread(&tmp,sizeof(struct person),1,fp))
	{
		abs->p[abs->num]=tmp;
		abs->num++;	
	}
	
	fclose(fp);
}
//上传结构体内容
void up_file(struct book *abs) 
{
	
	FILE *fp;
	fp=fopen("file_book.dat","wb+"); 
	
	for(int i=0;i<abs->num;i++)
		fwrite(&(abs->p[i]),sizeof(struct person),1,fp);//写入p 
	
	
	
	fclose(fp);

}
//以下为实现功能的函数

//添加联系人
void add_person(struct book * abs)
{
    char name[10];
    cout<<"请输入姓名"<<endl;
    cin>>name;
    strcpy(abs->p[abs->num].p_name,name); 
    char address[10];
    cout<<"请输入籍贯"<<endl;
    cin>>address;
    strcpy(abs->p[abs->num].p_address,address);
    char phone1[10],phone2[10];
    cout<<"请输入第一个电话号码"<<endl;
    cin>>phone1;
    strcpy(abs->p[abs->num].p_phone1,phone1);
    cout<<"请输入第二个电话号码"<<endl;
    cin>>phone2;
    strcpy(abs->p[abs->num].p_phone2,phone2);
    char Email[10];
    cout<<"请输入电子邮件"<<endl;
    cin>>Email;
    strcpy(abs->p[abs->num].p_Email,Email);
    abs->num++;//num既充当了数组号，又有统计的功能 
}
 
//修改联系人 
void change_person(struct book *abs)
{
    int exist(struct book * abs,string name);//声明
    char name[10];
    cout<<"请输入要修改的联系人的姓名：";
    cin>>name;
    //判断是否存在
    int x=exist(abs,name);//地址
    if(x!=-1)//开始进行修改 
    {
    cout<<"请输入姓名"<<endl;
    cin>>name;
    strcpy(abs->p[x].p_name,name);
    char address[10];
    cout<<"请输入籍贯"<<endl;
    cin>>address;
    strcpy(abs->p[x].p_address,address);
    char phone1[10],phone2[10];
    cout<<"请输入第一个电话号码"<<endl;
    cin>>phone1;
    strcpy(abs->p[x].p_phone1,phone1);
    cout<<"请输入第二个电话号码"<<endl;
    cin>>phone2;
    strcpy(abs->p[x].p_phone2,phone2);
    char Email[10];
    cout<<"请输入电子邮件"<<endl;
    cin>>Email;
    strcpy(abs->p[x].p_Email,Email);
    }
    else cout<<"查无此人";
    
}

//删除联系人
void delete_person(struct book *abs)
{
    int exist(struct book * abs,string name);//声明
    string name;
    cout<<"请输入要删除人的名字：";
    cin>>name;//判断是否存在
    int x=exist(abs,name);//地址
    if(x!=-1)//将后一项值赋给前一项，并只赋值到倒数第一个赋值给倒数第二个，以防出现两个最后一个数 
    {
        for(int i=x;i<abs->num;i++)
        {
            abs->p[i]=abs->p[i+1];
            abs->num--;
        }
    }
    else 
    cout <<"查无此人"<<endl;

}

//菜单功能 
void menu()
{
    cout<<"******************************"<<endl;
    cout<<"1、添加联系人"<<"  2、查看通讯录"<<endl;
    cout<<"3、查找联系人"<<"  4、删除联系人"<<endl;
    cout<<"5、修改联系人"<<"  6、退出该系统"<<endl;
    cout<<"******************************"<<endl;
}

//查看联系人 
void check_book(struct book * abs)
{
	if(abs->num==0)//检查通讯录里的人数，如果为0，提示为空 
	cout<<"通讯录为空"<<endl;
	else//依次输出通讯录里的人员信息 
	{
		for(int i=0;i<abs->num;i++)
		{
			cout<<"姓名："<<abs->p[i].p_name<<endl;
			cout<<"籍贯："<<abs->p[i].p_address<<endl;
			cout<<"电话1："<<abs->p[i].p_phone1<<endl;
			cout<<"电话2："<<abs->p[i].p_phone2<<endl;
			cout<<"电子邮箱："<<abs->p[i].p_Email<<endl;
			cout<<" "<<endl;
			
		}
	 } 
}

//查找联系人 
void cheak_person(struct book * abs,string name)

{
	
	int r= exist(abs,name);//先判断是否存在此人，如不存在，提示为无 
	if(r!=-1)//找到人后依次输出 
	{
		cout<<"姓名："<<abs->p[r].p_name<<endl;
		cout<<"籍贯："<<abs->p[r].p_address<<endl;
		cout<<"电话1："<<abs->p[r].p_phone1<<endl;
		cout<<"电话2："<<abs->p[r].p_phone2<<endl;
		cout<<"电子邮件："<<abs->p[r].p_Email<<endl;
		 
	}
	else//未找到人 
	cout<<"未找到联系人"<<endl; 
	  
}
   
    

 //主函数
 int main()
{

    int s;
    struct book abs;//通讯录结构体变量
    abs.num=0;
  	loan_file(&abs);
    while(1)//无限循环，确保能一直执行命令 
    {
    
       menu();
       cin>>s;
       switch(s)
       {
        case 1://1、添加联系人(完成)
           {
           	
               add_person(&abs);
               up_file(&abs);
                system("pause") ;
                system("cls");
           }
            break;
        case 2://2、查看通讯录(完成) 
        {
		    check_book(&abs); 
		    system("pause");
		    system("cls");
		
		}
            break;
        case 3://3、查找联系人(完成) 
		{
			string name;
		cout<<"请输入姓名"<<endl;
	    cin>>name;
	    cheak_person(&abs,name);
	    system("pause");
	    system("cls");
		}
            break;
        case 4://4、删除联系人(完成)
        {
            delete_person(&abs);
            system("pause");
            system("cls");
        }
            break;
        case 5://5、修改联系人
        {
            change_person(&abs);
            system("pause") ;
            system("cls");
        }
            break;
        case 6://6、退出该系统（完成）
        {
        	cout<<"已保存 "; 
            cout<<"欢迎您下次使用"<<endl;
            up_file(&abs);
            return 0;
        }
            
            break;  
           }
        
    }
    return 0;
}

