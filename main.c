#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.c" //�����Զ����ļ�
int main()
{
int id;
while(1) {                        //ѭ��ִ��
    menu();
    scanf("%d",&id);
   // getchar();   ���˾Ͳ��ܴ��ļ�??�����ֻ�����ĸBug.
    while(id <1 || id > 12){
        printf("��������ȷ�����!!!\n");
        scanf("%d",&id);
    }// ��ֹ����Խ��
    switch(id) {                  //����idѡ�����
        case 1:
            Head = Input();
            break;
        case 2:
            Head = CreatList();
            break;
        case 3:
            //if (Head == NULL) printf("0");
            Output(Head);
            break;
        case 4:
            OutOneNode(Max(Head));
            system("pause");
            system("cls");
            break;
        case 5:
            {
            Position temp;
            int n;
            temp = Search_num(Head);
            OutOneNode(temp);   //��ӡ����ڵ�
            if (temp != NULL) {
            printf("�Ƿ��޸�����? (1.�� 2.��): ");
            scanf("%d",&n);
            getchar();//���⵱����char����ʱ ����.
            while (n != 1 && n != 2) {
            printf("���Ŵ���,��������ȷ�Ĵ���: ");
            scanf("%d",&n);
            }
            if(n == 1) {Modify(temp);break;}//�޸�
            else {printf("�õ�,����\n");
            system("pause");
            system("cls");
            break;
                }
             }
            system("pause");
            system("cls");
            break;
            }
        case 6:
            Head = InsertList(Head);
            printf("����ɹ�!!!\n");
            system("pause");
            system("cls");
            break;
        case 7:
            Head = Delete_num(Head);
            break;
        case 8:
            Search_score(Head);
            printf("�����Ѿ�����,������¼���ļ���Ϣ\n");
            break;
        case 9:
            {

             Position tem;
             Head = Delete_score(Head);

             Output(Head);
             break;
            }
        case 10:
            Save(Head);
            break;
        case 11:
            Order(Head);
            break;
        case 12:
            return;
        default:
            printf("û�д˹���!!!\n");
            system("pause");
            system("cls");
            break;

    }
  }
 }
 /*Bug: 1.����ʱ ��������ĸ ѭ������
        2.�޸�ͷ�ڵ���Ϣ��,�����ֵ
        3.��ʼʱ������ĸ,����.
        4.���� 8 ���Һ�������ı�
        */

