#include"cstdio"
#include"cstring"
#include<iostream>
using namespace std;
typedef struct Node
{
    char name[8];
    char ID[11];
    float FOX;
    float C;
    float ENGLISH;
    float COUNT;
    struct Node* next;
}Node, * CLLinkList;
#define len sizeof(Node)
void InitCLLinkList(CLLinkList* head)//��ʼ��ѭ������
{
    *head = (CLLinkList)malloc(len);
    if (*head)//����ڴ�й©��������
    {
        (*head)->next = *head;
    }
}
void SearchCLLinkList1(CLLinkList head, char ID[])//����ѧ��
{
    int j = 0,flag=0; //�ó�ֵ
    Node* p;
    p = head->next;//�ó�ֵ
    while (p != head)
    {
        j++;
        if (strcmp(p->ID, ID) == 0)
        {
            flag = 1;
            cout << "************************" << endl;
            cout << "��λѧ������Ϣ���£�" << endl;
            cout << "���ڱ��е�λ��Ϊ��" << j << endl;
            cout << "������" << p->name << endl;
            cout << "ѧ�ţ�" << p->ID << endl;
            cout << "FOX�ɼ���" << p->FOX << endl;
            cout << "C�ɼ���" << p->C << endl;
            cout << "ENGLISH�ɼ���" << p->ENGLISH << endl;
            cout << "�ܷ�Ϊ��" << p->COUNT << endl;
            cout << "************************" << endl;
        }
        p = p->next;
    }
    if (flag != 1)
    {
        cout << "************************" << endl;
        cout << "��ѧ�Ų���ϵͳ�У�" << endl;
        cout << "************************" << endl;
    }
}
int SearchCLLinkList2(CLLinkList head, char name[])//��������
{
    int j = 0; //�ó�ֵ
    Node* p;
    p = head->next;//�ó�ֵ
    while (p != head)
    {
        j++;
        if (strcmp(p->name, name) == 0)
            return(j);
        p = p->next;
    }
    return(0);
}
void CreatCLLinkList(CLLinkList head)//ѭ������Ĵ���
{
    Node* rear, * s;
    char n1[8];
    char u1[11];
    float FOX;
    float C;
    float ENGLISH;
    int flag = 1;
    int a, b, n;
    rear = head;//rearָ�붯ָ̬��ǰ��β�����ʼֵָ��ͷ���   
    cout << "��������Ҫ¼���ѧ��������:\n";
    cin >> n;
    while (flag)
    {
        for (b = 0; b < n; b++)
        {
            cout << "��������Ҫ��ӵ�ѧ��������:" << "\n";
            cin >> n1;
            s = (Node*)malloc(len);
        A:
            while (1)
            {
                cout << "��������Ҫ��ӵ�ѧ����10λѧ��:" << "\n";
                cin >> u1;
                if (strlen(u1) == 10)
                {
                    for (a = 0; a < 11; a++)
                    {
                        if ((u1[a] >= '0') && (u1[a] <= '9'))
                        {
                            if (s)//����ڴ�й©��������
                            {
                                strcpy_s(s->ID, u1);
                                goto B;
                            }

                        }
                        else
                        {
                            cout << "�������";
                            strcpy_s(u1, "");//������飬����ڴ��������
                            goto A;
                        }
                    }
                }
                else
                {
                    cout << "�������";
                    strcpy_s(u1, "");//������飬����ڴ��������
                    goto A;
                }
            }
        B:
            cout << "FOX�ɼ���";
            cin >> FOX;
            cout << "C�ɼ���";
            cin >> C;
            cout << "ENGLISH�ɼ���";
            cin >> ENGLISH;
            cout << "--------------------------" << endl;
            strcpy_s(s->name, n1);
            strcpy_s(s->ID, u1);
            s->FOX=FOX;
            s->C=C;
            s->ENGLISH=ENGLISH;
            rear->next = s;
            rear = s;
        }
        flag = 0;
        rear->next = head;//���һ���ڵ��next��ָ��ͷ���
    }
}
void InCLLinkList(CLLinkList head, int i)//���
{
    Node* p, * s;
    int a, k = 0;
    int flag = 1;
    char n1[8], u1[11];
    float FOX;
    float C;
    float ENGLISH;
    p = head;
    if (i <= 0)
    {
        cout << "�����λ�ò��Ϸ�:" << "\n";
        return;
    }
    while (p->next != head && k < i - 1)
    {
        k++;
        p = p->next;
    }
    s = (Node*)malloc(len);
    cout << "��������Ҫ��ӵ�ѧ��������" << "\n";
    cin >> n1;
A:
    while (1)
    {
        cout << "��������Ҫ��ӵ�ѧ����10λѧ��:" << "\n";
        cin >> u1;
        if (strlen(u1) == 10)
        {
            for (a = 0; a < 11; a++)
            {
                if ((u1[a] >= '0') && (u1[a] <= '9'))
                {
                    if (s)//����ڴ�й©��������
                    {
                        strcpy_s(s->ID, u1);
                        goto B;
                    }

                }
                else
                {
                    cout << "�������";
                    strcpy_s(u1, "");//������飬����ڴ��������
                    goto A;
                }
            }
        }
        else
        {
            cout << "�������";
            strcpy_s(u1, "");//������飬����ڴ��������
            goto A;
        }
    }
B:
    cout << "FOX�ɼ���";
    cin >> FOX;
    cout << "C�ɼ���";
    cin >> C;
    cout << "ENGLISH�ɼ���";
    cin >> ENGLISH;
    cout << "--------------------------" << endl;
    strcpy_s(s->name, n1);
    strcpy_s(s->ID, u1);
    s->FOX = FOX;
    s->C = C;
    s->ENGLISH = ENGLISH;
    s->next = p->next;
    p->next = s;
    cout << "����ɹ���";
}
void Count_CLLinkList(CLLinkList head)//�����ܷ�
{
    Node* p;
    p = head->next;
    float COUNT=0;
    for (; p != head; p = p->next)
    {
        COUNT = p->FOX + p->C + p->ENGLISH;
        p->COUNT = COUNT;
        COUNT = 0;
    }
}
void Print_CLLinkList(CLLinkList head)//���
{
    Node* p;
    int i;
    p = head->next;
    cout << "*****ѧ���ɼ�����ϵͳ*****" << endl;
    for (i=1; p != head; p = p->next,i++)
    {
        cout << "---��" << i << "��ѧ���ĳɼ���Ϣ---" << endl;
        cout << "������" << p->name << endl;
        cout << "ѧ�ţ�" << p->ID << endl;
        cout << "FOX�ɼ���" << p->FOX << endl;
        cout << "C�ɼ���" << p->C << endl;
        cout << "ENGLISH�ɼ���" << p->ENGLISH << endl;
        cout << "�ܷ�Ϊ��" << p->COUNT << endl;
        cout << "--------------------------" << endl;
    }
}
void DeleCLLinkList(CLLinkList head, char u1[])//ɾ��
{
    Node* p, * r;
    p = head;
    while (p->next != head && strcmp((p->next)->ID, u1) != 0)
    {
        p = p->next;
    }
    if (p->next == head)
    {
        cout << "��Ҫɾ����ѧ�Ų�����!";
        return;
    }
    r = p->next;
    p->next = r->next;
    free(r);
}
void BubleSort1(CLLinkList head)//�ܷ�����
{
    Node* p,*q,*temp;
    p = head;
    q = head->next;
    if (p->next!=head) 
    {
        while (q->next!=head)
        {  
            if (q->COUNT > (q->next)->COUNT) 
            {   
                temp = p->next;
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = temp;
            }
            else
            {
                q = q->next;
            }
        }
        p = p->next;
        q = p->next;
    }
    p = head->next;
}
void BubleSort2(CLLinkList head)//ѧ������
{
    Node* p, * q, * temp;
    p = head;
    q = head->next;
    if (p->next != head)
    {
        while (q->next != head)
        {  
            if (strcmp(q->ID,(q->next)->ID)>0)
            {   
                temp = p->next;
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = temp;
            }
            else
            {
                q = q->next;
            }
        }
        p = p->next;
        q = p->next;
    }
    p = head->next;
}
int LengthCLLinkList(CLLinkList head)//��ѭ������ĳ���
{
    int i = 0;
    Node* p;
    p = head->next;
    while (p != head)
    {
        i++;
        p = p->next;
    }
    return i;
}
int main()
{
    int i;
    char n1[8];
    char u1[11];
    int select = 1;
    CLLinkList head;
    InitCLLinkList(&head);
    while (select != 0)
    {
        cout << "**ѧ���ɼ�����ϵͳ**\n"
            "  #���������ѡ��#\n"
            "   1-��ʼ¼����Ϣ\n"
            "   2-����ѧ����Ϣ\n"
            "   3-����λ�ò���\n"
            "   4-ɾ��ѧ����Ϣ\n"
            "   5-��������ܷ�\n"
            "   6-�����ܷ�����\n"
            "   7-����ѧ������\n"
            "   8-��ʾȫ����Ϣ\n"
            "   0-�������η���\n";
        cin >> select;
        switch (select)
        {
        case 1:
            CreatCLLinkList(head);
            Count_CLLinkList(head);
            Print_CLLinkList(head);
            break;
        case 2:
            cout << "\n��������Ҫ���ҵ�ѧ��:\n";
            cin >> u1;
            SearchCLLinkList1(head, u1);
            break;
        case 3:
            cout << "\n��������Ҫ������λͬѧ����������ǰ��:\n";
            cin >> n1;
            i = SearchCLLinkList2(head, n1);
            if (i == 0)
            {
                cout << "\n��λͬѧ����ϵͳ�У�\n\n";
            }
            else
            {
                InCLLinkList(head, i);
            }
            Count_CLLinkList(head);
            cout << "������ѧ������Ϊ:\n";
            Print_CLLinkList(head);
            break;
        case 4:
            cout << "\n��������Ҫɾ��ѧ����ѧ��:\n";
            cin >> u1;
            DeleCLLinkList(head, u1);
            cout << "\nɾ�����ѧ������Ϊ:\n";
            Print_CLLinkList(head);
            break;
        case 5:
            Print_CLLinkList(head);
            break;
        case 6:
            BubleSort1(head);
            Print_CLLinkList(head);
            break;
        case 7:
            BubleSort2(head);
            Print_CLLinkList(head);
            break;
        case 8:
            Print_CLLinkList(head);
            break;
        case 0:
            break;
        default:
            cout << "\n�������\n\n";
        }
    }
    cout << "\n";
    return 0;
}