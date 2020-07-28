#ifndef STUDENT_H
#define STUDENT_H
struct Student {
  char name[15];//名字
  int num;//学号
  char major[10];//专业:computer,network,software
  int calss;//班级1-2
  int score[3];//三门课成绩
  struct Student* next;
};

typedef struct Student* Position;
typedef struct Student STU;
Position Head = NULL;
char filename1[30];
Position Input();//从文件中输出n个学生的信息
void OutOneNode(STU* p);//讲p所指的学生信息屏幕输出
Position CreatList();//从文件中录入信息
void Output(Position p);//显示所有学生信息;
void menu();//菜单
void Save(Position p);//存盘
Position Max(STU* p);//求最大值
Position Search_num(Position p);//查找
void Modify(Position p);//修改
Position InsertList(Position p);//插入
void OneNode(Position Tmpcell);//录入单个节点
Position Delete_num(Position p);//删除
void Search_score(Position p);//根据专业成绩查找
Position Delete_score(Position p);//根据班级成绩删除
void Order(Position p);//从小到大排序
#endif // STUDENT_H
