/*��������ͷ�ļ�*/
#ifndef STUDENT_H        // ����ͷ�ļ�,�����ظ�����
#define STUDENT_H
#define N 10             // �궨������ѧ����Ŀ
struct Student {         // ѧ������Ϣ
  char name[8];//����
  char num[15];//ѧ��
  char major[10];//רҵ:computer,network,software
  int calss;//�༶1-2
  int score[3];//���ſγɼ�
};
typedef struct Student STU;
STU Head [N+1];          // ����һ�����������ʱ�����Ϣ,N+1�Ƿ�Խ��
void menu();             //�˵�
void Input(STU* p);      // ���뺯��
void Save (STU* p,int n);  // ���溯��
void Output(STU* p);       // �������
void Loadstudent(STU* p,int n); // ��ȡ����
void FindnStudent();         // ��ѯ��n��ѧ���ĺ���
void Findscore();                // ��ѯ��Ӧ�ɼ�
void Maxscore();             // ���ɼ�
void Show();//��ʾ��n��m��ѧ����Ϣ
void Choosesort();//ѡ������
void Bubblesort();//ð������
void Insertsort();//��������
#endif // STUDENT_H
