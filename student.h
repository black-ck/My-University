#ifndef STUDENT_H
#define STUDENT_H
struct Student {
  char name[15];//����
  int num;//ѧ��
  char major[10];//רҵ:computer,network,software
  int calss;//�༶1-2
  int score[3];//���ſγɼ�
  struct Student* next;
};

typedef struct Student* Position;
typedef struct Student STU;
Position Head = NULL;
char filename1[30];
Position Input();//���ļ������n��ѧ������Ϣ
void OutOneNode(STU* p);//��p��ָ��ѧ����Ϣ��Ļ���
Position CreatList();//���ļ���¼����Ϣ
void Output(Position p);//��ʾ����ѧ����Ϣ;
void menu();//�˵�
void Save(Position p);//����
Position Max(STU* p);//�����ֵ
Position Search_num(Position p);//����
void Modify(Position p);//�޸�
Position InsertList(Position p);//����
void OneNode(Position Tmpcell);//¼�뵥���ڵ�
Position Delete_num(Position p);//ɾ��
void Search_score(Position p);//����רҵ�ɼ�����
Position Delete_score(Position p);//���ݰ༶�ɼ�ɾ��
void Order(Position p);//��С��������
#endif // STUDENT_H
