#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.c" //引用自定义文件
int main()
{
int id;
while(1) {                        //循环执行
    menu();
    scanf("%d",&id);
   // getchar();   加了就不能打开文件??不加又会有字母Bug.
    while(id <1 || id > 12){
        printf("请输入正确的序号!!!\n");
        scanf("%d",&id);
    }// 防止输入越界
    switch(id) {                  //根据id选择操作
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
            OutOneNode(temp);   //打印所获节点
            if (temp != NULL) {
            printf("是否修改数据? (1.是 2.否): ");
            scanf("%d",&n);
            getchar();//避免当输入char类型时 卡死.
            while (n != 1 && n != 2) {
            printf("代号错误,请输入正确的代号: ");
            scanf("%d",&n);
            }
            if(n == 1) {Modify(temp);break;}//修改
            else {printf("好的,跳过\n");
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
            printf("插入成功!!!\n");
            system("pause");
            system("cls");
            break;
        case 7:
            Head = Delete_num(Head);
            break;
        case 8:
            Search_score(Head);
            printf("缓存已经更新,请重新录入文件信息\n");
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
            printf("没有此功能!!!\n");
            system("pause");
            system("cls");
            break;

    }
  }
 }
 /*Bug: 1.查找时 先输入字母 循环卡死
        2.修改头节点信息后,找最大值
        3.开始时输入字母,卡死.
        4.功能 8 查找后主链表改变
        */

