#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <windows.h>
using namespace std;

/**ͣ��������*/
#define MAXNUM 2
#define OK 1
#define ERROR 0



SYSTEMTIME sys;
double price= 0.05;
/**ʱ��*/
typedef struct time
{
    int hour;
    int min;
} Time;

/**������Ϣ*/
typedef struct node
{
    char car_num[10];
    Time inTime;
    Time outTime;
} CarNode;

/**ͣ�����ڳ�����Ϣ*/
typedef struct node2
{
    CarNode * stack[MAXNUM +1];
    int top;
} SeqStackCar;

typedef struct car
{
    CarNode * data; //������Ϣ
    struct car * next; //ָ����һ����ָ����
} QueueNode;

typedef struct Node
{
    QueueNode * head;//ͷ��
    QueueNode * rear;//β��
} LinkQueueCar;

void StackInit (SeqStackCar * seq)
{
    seq -> top = 0;
    for(int i= 0 ; i<=MAXNUM ; i++)
    {
        seq->stack[seq->top] =NULL;
    }
}

int QueueInit(LinkQueueCar *q)
{
    q->head = (QueueNode * ) malloc(sizeof(QueueNode));
    if  (q->head !=NULL)
    {
        q->head ->next = NULL;
        q->rear = q->head;
        return OK;
    }
    else
    {
        return ERROR;
    }
}


void Print(CarNode * p, int room)
{
    int in_h, in_m,out_h,out_m;
    in_h = p->inTime.hour;
    in_m = p->inTime.min;
    GetLocalTime( &sys );
    cout<<"\n\t�뿪ʱ��Ϊ��"<<sys.wHour<<":"<<sys.wMinute<<endl;
    p->outTime.hour = sys.wHour;
    p->outTime.min =  sys.wMinute;
    cout<<"\n\t���ƺ�Ϊ:"<<p->car_num<<endl;
    cout<<"\n\t�볡ʱ��Ϊ"<<p->inTime.hour<<"ʱ"<<p->inTime.min<<"��\n";
    cout<<"\n\t����ʱ��Ϊ"<<p->outTime.hour<<"ʱ"<<p->outTime.min<<"��\n";
    out_h = p->outTime.hour;
    out_m = p->outTime.min;
    cout<<"\n\tӦ�ɷ�:"<<((out_h - in_h)*60+ (out_m - in_m))* price<<endl;
    free(p);
}
bool matchCarNum(char * incar)
{
    string firstlocation = "�����弽ԥ���ɺ�����³������Ӷ���ʽ����¼���������ش�����ʹ��";
    string regional = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string a = incar;
    if  (firstlocation.find(a.substr(0,2))<=firstlocation.length()
         &&regional.find(incar[2])<=firstlocation.length())
    {
        return true;
    }
    else
    {
        cout<<"\t���ƺŴ���"<<endl;
        return false;
    }
}
int Arrival (SeqStackCar * enter,LinkQueueCar* q)
{
    CarNode *p;
    QueueNode *t;
    p = (CarNode *)malloc(sizeof(CarNode));
    memset(p->car_num,0,10);
    while(true)
    {
    cout<<"\n\t���복�ƺ�(����³A11111):";
        cin>>p->car_num;
        if(matchCarNum(p->car_num))
            break;
    }
    if  (enter ->top<MAXNUM)
    {
        enter ->top++;
        cout<<"\n\t������ͣ������"<<enter->top<<"λ��\n";
        GetLocalTime( &sys );
        cout<<"\n\t����ʱ��Ϊ��"<<sys.wHour<<":"<<sys.wMinute<<endl;
        p->inTime.hour = sys.wHour;
        p->inTime.min =  sys.wMinute;
        enter->stack[enter->top] = p;
        return OK;
    }
    else
    {
        cout<<"\n\t����������Ҫ�ȴ�!\n";
        t = (QueueNode *) malloc(sizeof(QueueNode));
        t->data = p;
        t->next = NULL;
        q->rear->next =t;
        q->rear = t;
        return OK;
    }
}

void Leave(SeqStackCar *enter,SeqStackCar * temp,LinkQueueCar * wite)
{
    int room;
    CarNode *p,* t;
    QueueNode * q;
    //�ж��Ƿ��г�
    if  (enter ->top>0)
    {
        while(true)
        {
            cout<<"\n\t�����복�ڳ�����λ��/1--"<<enter->top<<"/";
            cin>>room;
            if(room>=1&&room<=enter->top)
            {
                break;
            }
        }
        while(enter->top>room)
        {
            temp ->top++;
            temp->stack[temp->top] = enter->stack[enter->top];
            enter->stack[enter->top]=NULL;
            enter->top--;
        }
        p=enter->stack [enter->top];
        enter ->stack[enter->top] = NULL;
        enter->top--;
        while(temp->top >= 1)
        {
            enter->top++;
            enter->stack[enter->top] = temp->stack[temp->top];
            enter->stack[temp->top]= NULL;
            temp->top--;
        }
        Print(p,room);
        if  ((wite->head!=wite->rear)&&enter->top<MAXNUM)
        {
            q= wite->head ->next;
            t = q->data;
            enter ->top++;
            cout<<"\n\t�ȴ���"<<(t->car_num)<<"�����복����"<<(enter->top)<<"λ��\n";
            GetLocalTime( &sys );
            cout<<"\n\t�볡ʱ��Ϊ��"<<sys.wHour<<":"<<sys.wMinute<<endl;
            p->inTime.hour = sys.wHour;
            p->inTime.min =  sys.wMinute;
            wite ->head ->next = q->next;
            if  (q==wite->rear)
            {
                wite ->rear = wite->head;
            }
            enter->stack[enter->top] = t;
            free(q);
        }
        else
        {
            cout<<"\nû�еȴ��еĳ���\n";
        }
    }
    else
    {
        cout<<"\n\tͣ������û�г�\n";
    }

}

int showWaitCar(LinkQueueCar * wite)
{
    if  ((wite->head!=wite->rear))
    {
        CarNode *t;
        QueueNode * q = wite->head->next ;
        int i  =1;
        while (q!=NULL)
        {
            t = q->data;
            cout<<"\n\t��"<<i<<"���ȴ���"<<(t->car_num)<<endl;
            q = q -> next;
            i++;
        }
        return OK;
    }
    else
    {
        cout<<"\n\tû���ڵȴ��еĳ���\n";
        return OK;
    }

}

void showinPark(SeqStackCar *S)
{
    if(S->top>0)
    {
        cout<<"\n\t����";
        cout<<"\n\tλ��   ����ʱ��   ���ƺ�\n";
        for(int i= 1 ; i <= S->top ; i++)
        {
            cout<<"\t "<<i;
            cout<<"     "<<S->stack[i]->inTime.hour<<"ʱ"<<S->stack[i]->inTime.min<<"��";
            cout<<"   "<<S->stack[i]->car_num<<endl;
        }
    }
    else
    {
        cout<<"\n\t������û�г�"<<endl;
    }
}


int findCarInfo(SeqStackCar *enter,LinkQueueCar * wite)
{
    cout<<"\n\t������Ҫ�����ĳ��ƺţ�";
    char findcarnum [10];
    cin>>findcarnum;
    for(int i= 1 ; i <= enter->top ; i++)
    {
        int result = strcmp(findcarnum,enter->stack[i]->car_num);
        if  (result==0)
        {
            cout<<"\n\t�ڳ����ҵ�����"<<findcarnum<<endl;
            cout<<"\n\t�볡ʱ��:"<<enter->stack[i]->inTime.hour<<"ʱ"<<enter->stack[i]->inTime.min<<"��\n";
            return OK;
        }
    }
    if  ((wite->head!=wite->rear))
    {
        CarNode *t;
        QueueNode * q = wite->head->next ;
        int i  =1;
        while (q!=NULL)
        {
            t = q->data;
            int result = strcmp(findcarnum,t->car_num);
            if(result==0)
            {
                cout<<"\n\t�ڵȴ��������ҵ�����"<<findcarnum<<endl;
                return OK;
            }
            q = q -> next;
            i++;
        }
    }
    cout<<"\n\t�������δ�ҵ�"<<findcarnum<<endl;
    return ERROR;
}

void Welcome()
{
    GetLocalTime( &sys );
    cout<< ("\t*******************Ŀǰͣ����״��***********************\n");
    cout<< ("\t********************************************************\n");
    cout<< ("\t---------------------��ӭ����ͣ����---------------------\n");
    cout<< ("\t*                                                      *\n");
    cout<< ("\t*                   1.ͣ����ͣ����Ϣ��ʾ               *\n");
    cout<< ("\t*                   2.�ȴ���ͣ����Ϣ��ʾ               *\n");
    cout<< ("\t*                   3.��������ͣ��������               *\n");
    cout<< ("\t*                   4.������ȥͣ��������               *\n");
    cout<< ("\t*                   5.������������                     *\n");
    cout<< ("\t*                   6.����                             *\n");
    cout<< ("\t*                   7.�˳�����ϵͳ                     *\n");
    cout<< "\t*     �շѱ�׼����ͣ��������"<<(60*price)<<"Ԫ/���ӼƷѣ�����֪!      *\n";
    cout<< "\t*                                          "<<sys.wYear<<"��"<<sys.wMonth<<"��"<<sys.wDay<<"*\n";
    cout<< "\t*------------------------------------------------------*\n";
    cout<< "\t--------------������(1/2/3/4/5/6/7)���г���-------------\n";
}

int main()
{
    SeqStackCar enter,temp;
    LinkQueueCar wait;
    int choose;
    StackInit(&enter);
    StackInit(&temp);
    QueueInit(&wait);
    while(true)
    {
        Welcome();
        while(true)
        {
            cin>>choose;
            if  (choose>=1&&choose<=7)
            {
                break;
            }
            else
            {
                cout<< "\t--------------������(1/2/3/4/5/6/7)���г���---------------\n";
            }
        }
        switch(choose)
        {
        /** 1.ͣ����ͣ����Ϣ��ʾ*/
        case 1:
            showinPark(&enter);
            break;
        /**2.�ȴ���ͣ����Ϣ��ʾ */
        case 2:
            showWaitCar(&wait);
            break;
        /**3.��������ͣ��������*/
        case 3:
            Arrival(&enter,&wait);
            break;
        /**4.������ȥͣ��������*/
        case 4:
            Leave(&enter,&temp,&wait);
            break;
        /**5.������������ */
        case 5:
            findCarInfo(&enter,&wait);
            break;
        /**6.���� */
        case 6:
            system("cls");
            break;
        /**7.�˳�ϵͳ */
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
