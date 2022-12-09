#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <windows.h>
using namespace std;

/**停车场容量*/
#define MAXNUM 2
#define OK 1
#define ERROR 0



SYSTEMTIME sys;
double price= 0.05;
/**时间*/
typedef struct time
{
    int hour;
    int min;
} Time;

/**车辆信息*/
typedef struct node
{
    char car_num[10];
    Time inTime;
    Time outTime;
} CarNode;

/**停车场内车辆信息*/
typedef struct node2
{
    CarNode * stack[MAXNUM +1];
    int top;
} SeqStackCar;

typedef struct car
{
    CarNode * data; //车辆信息
    struct car * next; //指向下一个的指针域
} QueueNode;

typedef struct Node
{
    QueueNode * head;//头车
    QueueNode * rear;//尾车
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
    cout<<"\n\t离开时间为："<<sys.wHour<<":"<<sys.wMinute<<endl;
    p->outTime.hour = sys.wHour;
    p->outTime.min =  sys.wMinute;
    cout<<"\n\t车牌号为:"<<p->car_num<<endl;
    cout<<"\n\t入场时间为"<<p->inTime.hour<<"时"<<p->inTime.min<<"分\n";
    cout<<"\n\t出场时间为"<<p->outTime.hour<<"时"<<p->outTime.min<<"分\n";
    out_h = p->outTime.hour;
    out_m = p->outTime.min;
    cout<<"\n\t应缴费:"<<((out_h - in_h)*60+ (out_m - in_m))* price<<endl;
    free(p);
}
bool matchCarNum(char * incar)
{
    string firstlocation = "京津沪渝冀豫云辽黑湘皖鲁新苏浙赣鄂桂甘晋蒙陕吉闽贵粤青藏川宁琼使领";
    string regional = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string a = incar;
    if  (firstlocation.find(a.substr(0,2))<=firstlocation.length()
         &&regional.find(incar[2])<=firstlocation.length())
    {
        return true;
    }
    else
    {
        cout<<"\t车牌号错误"<<endl;
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
    cout<<"\n\t输入车牌号(例：鲁A11111):";
        cin>>p->car_num;
        if(matchCarNum(p->car_num))
            break;
    }
    if  (enter ->top<MAXNUM)
    {
        enter ->top++;
        cout<<"\n\t车辆在停车场第"<<enter->top<<"位置\n";
        GetLocalTime( &sys );
        cout<<"\n\t到达时间为："<<sys.wHour<<":"<<sys.wMinute<<endl;
        p->inTime.hour = sys.wHour;
        p->inTime.min =  sys.wMinute;
        enter->stack[enter->top] = p;
        return OK;
    }
    else
    {
        cout<<"\n\t车场已满需要等待!\n";
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
    //判断是否有车
    if  (enter ->top>0)
    {
        while(true)
        {
            cout<<"\n\t请输入车在车场的位置/1--"<<enter->top<<"/";
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
            cout<<"\n\t等待的"<<(t->car_num)<<"车进入车场第"<<(enter->top)<<"位置\n";
            GetLocalTime( &sys );
            cout<<"\n\t入场时间为："<<sys.wHour<<":"<<sys.wMinute<<endl;
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
            cout<<"\n没有等待中的车辆\n";
        }
    }
    else
    {
        cout<<"\n\t停车场里没有车\n";
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
            cout<<"\n\t第"<<i<<"辆等待的"<<(t->car_num)<<endl;
            q = q -> next;
            i++;
        }
        return OK;
    }
    else
    {
        cout<<"\n\t没有在等待中的车辆\n";
        return OK;
    }

}

void showinPark(SeqStackCar *S)
{
    if(S->top>0)
    {
        cout<<"\n\t车场";
        cout<<"\n\t位置   到达时间   车牌号\n";
        for(int i= 1 ; i <= S->top ; i++)
        {
            cout<<"\t "<<i;
            cout<<"     "<<S->stack[i]->inTime.hour<<"时"<<S->stack[i]->inTime.min<<"分";
            cout<<"   "<<S->stack[i]->car_num<<endl;
        }
    }
    else
    {
        cout<<"\n\t车场里没有车"<<endl;
    }
}


int findCarInfo(SeqStackCar *enter,LinkQueueCar * wite)
{
    cout<<"\n\t请输入要搜索的车牌号：";
    char findcarnum [10];
    cin>>findcarnum;
    for(int i= 1 ; i <= enter->top ; i++)
    {
        int result = strcmp(findcarnum,enter->stack[i]->car_num);
        if  (result==0)
        {
            cout<<"\n\t在场内找到车辆"<<findcarnum<<endl;
            cout<<"\n\t入场时间:"<<enter->stack[i]->inTime.hour<<"时"<<enter->stack[i]->inTime.min<<"分\n";
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
                cout<<"\n\t在等待队列中找到车辆"<<findcarnum<<endl;
                return OK;
            }
            q = q -> next;
            i++;
        }
    }
    cout<<"\n\t查找完成未找到"<<findcarnum<<endl;
    return ERROR;
}

void Welcome()
{
    GetLocalTime( &sys );
    cout<< ("\t*******************目前停车场状况***********************\n");
    cout<< ("\t********************************************************\n");
    cout<< ("\t---------------------欢迎来到停车场---------------------\n");
    cout<< ("\t*                                                      *\n");
    cout<< ("\t*                   1.停车场停车信息显示               *\n");
    cout<< ("\t*                   2.等待中停车信息显示               *\n");
    cout<< ("\t*                   3.汽车到达停车场操作               *\n");
    cout<< ("\t*                   4.汽车离去停车场操作               *\n");
    cout<< ("\t*                   5.查找汽车功能                     *\n");
    cout<< ("\t*                   6.清屏                             *\n");
    cout<< ("\t*                   7.退出管理系统                     *\n");
    cout<< "\t*     收费标准：本停车场按照"<<(60*price)<<"元/分钟计费，望周知!      *\n";
    cout<< "\t*                                          "<<sys.wYear<<"年"<<sys.wMonth<<"月"<<sys.wDay<<"*\n";
    cout<< "\t*------------------------------------------------------*\n";
    cout<< "\t--------------请输入(1/2/3/4/5/6/7)运行程序-------------\n";
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
                cout<< "\t--------------请输入(1/2/3/4/5/6/7)运行程序---------------\n";
            }
        }
        switch(choose)
        {
        /** 1.停车场停车信息显示*/
        case 1:
            showinPark(&enter);
            break;
        /**2.等待中停车信息显示 */
        case 2:
            showWaitCar(&wait);
            break;
        /**3.汽车到达停车场操作*/
        case 3:
            Arrival(&enter,&wait);
            break;
        /**4.汽车离去停车场操作*/
        case 4:
            Leave(&enter,&temp,&wait);
            break;
        /**5.查找汽车功能 */
        case 5:
            findCarInfo(&enter,&wait);
            break;
        /**6.清屏 */
        case 6:
            system("cls");
            break;
        /**7.退出系统 */
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
