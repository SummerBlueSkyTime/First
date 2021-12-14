#include<bits/stdc++.h>
#include<iostream>
#define MAX 1000
#define SIZE 1000
using namespace std;

//��ϵ�˽ṹ��
struct person{
    char p_name[10];//���� 
    char p_address[10];//���� 
    char p_phone1[10];//�绰1 
    char p_phone2[10];//�绰2 
    char p_Email[10];//�����ʼ� 
};
//�绰���ṹ��
struct book
{
    struct person p[MAX];
    int num;
};

//�жϺ������жϸ���ϵ���Ƿ���ڣ������ش��ڵ�ַ����0��ʼ���������ڷ���-1
int exist(struct book * abs,string name){
    for(int i=0;i<abs->num;i++)
    {
        if(abs->p[i].p_name==name)//�ж��Ƿ����
        {
            return i;//���ص�ַ
        }
    }
    return -1;//�����ڵ����
}

//�����ļ����� 
void loan_file(struct book *abs)
{
	struct person tmp;//��ʱ�ṹ�� 
	FILE *fp;//�ļ�ָ�� 
	
if((fp=fopen("file_book.dat","rb+"))==NULL)//�������ļ� 
	{
		fp=fopen("file_book.dat","wb+");
		return ;
	 }//��ֻ�������ƴ��ļ� 
	
	while(fread(&tmp,sizeof(struct person),1,fp))
	{
		abs->p[abs->num]=tmp;
		abs->num++;	
	}
	
	fclose(fp);
}
//�ϴ��ṹ������
void up_file(struct book *abs) 
{
	
	FILE *fp;
	fp=fopen("file_book.dat","wb+"); 
	
	for(int i=0;i<abs->num;i++)
		fwrite(&(abs->p[i]),sizeof(struct person),1,fp);//д��p 
	
	
	
	fclose(fp);

}
//����Ϊʵ�ֹ��ܵĺ���

//�����ϵ��
void add_person(struct book * abs)
{
    char name[10];
    cout<<"����������"<<endl;
    cin>>name;
    strcpy(abs->p[abs->num].p_name,name); 
    char address[10];
    cout<<"�����뼮��"<<endl;
    cin>>address;
    strcpy(abs->p[abs->num].p_address,address);
    char phone1[10],phone2[10];
    cout<<"�������һ���绰����"<<endl;
    cin>>phone1;
    strcpy(abs->p[abs->num].p_phone1,phone1);
    cout<<"������ڶ����绰����"<<endl;
    cin>>phone2;
    strcpy(abs->p[abs->num].p_phone2,phone2);
    char Email[10];
    cout<<"����������ʼ�"<<endl;
    cin>>Email;
    strcpy(abs->p[abs->num].p_Email,Email);
    abs->num++;//num�ȳ䵱������ţ�����ͳ�ƵĹ��� 
}
 
//�޸���ϵ�� 
void change_person(struct book *abs)
{
    int exist(struct book * abs,string name);//����
    char name[10];
    cout<<"������Ҫ�޸ĵ���ϵ�˵�������";
    cin>>name;
    //�ж��Ƿ����
    int x=exist(abs,name);//��ַ
    if(x!=-1)//��ʼ�����޸� 
    {
    cout<<"����������"<<endl;
    cin>>name;
    strcpy(abs->p[x].p_name,name);
    char address[10];
    cout<<"�����뼮��"<<endl;
    cin>>address;
    strcpy(abs->p[x].p_address,address);
    char phone1[10],phone2[10];
    cout<<"�������һ���绰����"<<endl;
    cin>>phone1;
    strcpy(abs->p[x].p_phone1,phone1);
    cout<<"������ڶ����绰����"<<endl;
    cin>>phone2;
    strcpy(abs->p[x].p_phone2,phone2);
    char Email[10];
    cout<<"����������ʼ�"<<endl;
    cin>>Email;
    strcpy(abs->p[x].p_Email,Email);
    }
    else cout<<"���޴���";
    
}

//ɾ����ϵ��
void delete_person(struct book *abs)
{
    int exist(struct book * abs,string name);//����
    string name;
    cout<<"������Ҫɾ���˵����֣�";
    cin>>name;//�ж��Ƿ����
    int x=exist(abs,name);//��ַ
    if(x!=-1)//����һ��ֵ����ǰһ���ֻ��ֵ��������һ����ֵ�������ڶ������Է������������һ���� 
    {
        for(int i=x;i<abs->num;i++)
        {
            abs->p[i]=abs->p[i+1];
            abs->num--;
        }
    }
    else 
    cout <<"���޴���"<<endl;

}

//�˵����� 
void menu()
{
    cout<<"******************************"<<endl;
    cout<<"1�������ϵ��"<<"  2���鿴ͨѶ¼"<<endl;
    cout<<"3��������ϵ��"<<"  4��ɾ����ϵ��"<<endl;
    cout<<"5���޸���ϵ��"<<"  6���˳���ϵͳ"<<endl;
    cout<<"******************************"<<endl;
}

//�鿴��ϵ�� 
void check_book(struct book * abs)
{
	if(abs->num==0)//���ͨѶ¼������������Ϊ0����ʾΪ�� 
	cout<<"ͨѶ¼Ϊ��"<<endl;
	else//�������ͨѶ¼�����Ա��Ϣ 
	{
		for(int i=0;i<abs->num;i++)
		{
			cout<<"������"<<abs->p[i].p_name<<endl;
			cout<<"���᣺"<<abs->p[i].p_address<<endl;
			cout<<"�绰1��"<<abs->p[i].p_phone1<<endl;
			cout<<"�绰2��"<<abs->p[i].p_phone2<<endl;
			cout<<"�������䣺"<<abs->p[i].p_Email<<endl;
			cout<<" "<<endl;
			
		}
	 } 
}

//������ϵ�� 
void cheak_person(struct book * abs,string name)

{
	
	int r= exist(abs,name);//���ж��Ƿ���ڴ��ˣ��粻���ڣ���ʾΪ�� 
	if(r!=-1)//�ҵ��˺�������� 
	{
		cout<<"������"<<abs->p[r].p_name<<endl;
		cout<<"���᣺"<<abs->p[r].p_address<<endl;
		cout<<"�绰1��"<<abs->p[r].p_phone1<<endl;
		cout<<"�绰2��"<<abs->p[r].p_phone2<<endl;
		cout<<"�����ʼ���"<<abs->p[r].p_Email<<endl;
		 
	}
	else//δ�ҵ��� 
	cout<<"δ�ҵ���ϵ��"<<endl; 
	  
}
   
    

 //������
 int main()
{

    int s;
    struct book abs;//ͨѶ¼�ṹ�����
    abs.num=0;
  	loan_file(&abs);
    while(1)//����ѭ����ȷ����һֱִ������ 
    {
    
       menu();
       cin>>s;
       switch(s)
       {
        case 1://1�������ϵ��(���)
           {
           	
               add_person(&abs);
               up_file(&abs);
                system("pause") ;
                system("cls");
           }
            break;
        case 2://2���鿴ͨѶ¼(���) 
        {
		    check_book(&abs); 
		    system("pause");
		    system("cls");
		
		}
            break;
        case 3://3��������ϵ��(���) 
		{
			string name;
		cout<<"����������"<<endl;
	    cin>>name;
	    cheak_person(&abs,name);
	    system("pause");
	    system("cls");
		}
            break;
        case 4://4��ɾ����ϵ��(���)
        {
            delete_person(&abs);
            system("pause");
            system("cls");
        }
            break;
        case 5://5���޸���ϵ��
        {
            change_person(&abs);
            system("pause") ;
            system("cls");
        }
            break;
        case 6://6���˳���ϵͳ����ɣ�
        {
        	cout<<"�ѱ��� "; 
            cout<<"��ӭ���´�ʹ��"<<endl;
            up_file(&abs);
            return 0;
        }
            
            break;  
           }
        
    }
    return 0;
}

