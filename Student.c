/*���Ǻ��������ļ�*/
#include"Student.h"
//�˵�
void menu (){
printf("\t\t\t\tStudent Manager Sts   v1.0 by CK\n");
printf("\t\t\t  ************************************************\n");
printf("\t\t\t1.*��ʼ��Ϣ¼��                                  *\n");
printf("\t\t\t2.*��ȡ�ļ���ѧ����Ϣ                            *\n");
printf("\t\t\t3.*��ʾ��ǰ�����е�ѧ����Ϣ                      *\n");
printf("\t\t\t4.*��ȡ��n��ѧ������Ϣ                           *\n");
printf("\t\t\t5.*����༶�ͳɼ�����                            *\n");
printf("\t\t\t6.*����ѧ��ĳ�ſε���߷ֺ�ѧ������              *\n");
printf("\t\t\t7.*������ѧ����ƽ���ɼ��ӵ͵�������              *\n");
printf("\t\t\t8.*��ĳ��רҵѧ����ĳ�ſγɼ��ɸߵ��ͽ�������    *\n");
printf("\t\t\t9.*������º��ѧ����Ϣ                          *\n");
printf("\t\t\t10*��ĳ��רҵ��ѧ��ĳ�ſΰ��ɼ��Ӹߵ�������      *\n");
printf("\t\t\t0.*�˳�����                                      *\n");
printf("\t\t\t  ************************************************\n");
printf("\t\t\t\t*��ѡ����Ĳ���:");
}
//���뺯��
void Input(STU* p) {
    system("cls");                   //����
    int i = 1;
    int n;
//    printf("������¼���ѧ����Ŀ n :"); //������һ�����ƵĹ���
//    scanf("%d",&n);
    n = N;                                // û������,��ʱ����д
    while(i <= n) {                       //ѭ������
    int id;
    printf("******��%d��******\n",i);
    printf("������ѧ������:\t");
    getchar();
    scanf("%s",p->name);
    getchar();
    printf("������ѧ��(1- 20):\t");
    scanf("%s",p->num);
    printf("��ѡ��רҵ:\t1.Computer\t2.Sotfware\t3.Network:\t");
    scanf("%d",&id);
    switch(id) {
       case 1: strcpy(p->major,"Computer");break;
       case 2: strcpy(p->major,"Sotfware");break;
       case 3: strcpy(p->major,"NetWork");break;
       default  : printf("�������,�޷�����,���ֵ� �����Ҷ�ѧԺ \n");  //һ��С�ʵ�
                   strcpy(p->major,"Gryffindor");break;
    }
    printf("������༶1 or 2:\t");
    scanf("%d",&(p->calss));
    printf("�������Ӣ�ɼ�:\t");
    scanf("%d",&(p->score[0]));
    printf("����������ɼ�:\t");
    scanf("%d",&(p->score[1]));
    printf("������C���Գɼ�: ");
    scanf("%d",&(p->score[2]));
    p++;
    i++;
      }
    printf("�������!!!\n");
    system("pause"); //��ͣ
    system("cls");    //����
}
//����,ÿ�α���Ḳ���ϴε�����
void Save(STU* p,int n){
 FILE* fp;
 int i = 1;
 char filename[30];
 printf("�����뱣����ļ���:");       //��ʱ
 getchar();                           //����س�
 gets(filename);
  if((fp = fopen(filename,"wb")) == NULL) { //û������֮ǰ�޷�����,�������ź������� // ��д��ķ�ʽ���ļ�
    printf("cannot open file\n");                    //����򲻿�,����
    return;
  }
    while(i++ <= n){
    if (fwrite(p++,sizeof(STU),1,fp) != 1){         // д��,fwriteӦ��fread��Ӧʹ��,fprintf��fscanf��Ӧʹ��,��Ȼ���鷳
        printf("file write error\n");                // ������ʾ
        return;
     }
    }
  printf("���ڱ���********\n");
  printf("����ɹ�!!!\n");
  fclose(fp);
  system("pause");
  system("cls");
}
// �������
void Output(STU* p){
  if (p == NULL) return;
  printf("name:%s\t\tnum:%s\t\tmajor:%s\t\tclass:%d\t\tEnglish:%d  Math:%d  C langaug:%d  \n",p->name,p->num,p->major,p->calss,p->score[0],p->score[1],p->score[2]);
}
//��ȡ����
void Loadstudent(STU* p,int n) {
 system("cls");
 FILE* fp;
 char filename[30];
 printf("���ڶ�ȡ*******\n");
 printf("��������ļ���:");       //��ʱ
 getchar();                          //����س�
 gets(filename);
 //strcpy(filename,"studentInit.dat"); // û������,��ʱ
 if ((fp = fopen(filename,"rb")) == NULL) {
    printf("file cannot open !!!");
    return;
 }
 for(int i = 1;i <= n;i++)
     {
        // fscanf(fp,"name:%s\tnum:%s\tmajor:%s\tclass:%d\tEnglish:%d  Math:%d  C langaug:%d  \n",p->name,p->num,p->major,&p->calss,&p->score[0],&p->score[1],&p->score[2]);;
         fread(p++,sizeof(STU),1,fp);

     }
 fclose(fp);
 printf("��ȡ�ɹ�!!!\n");
 system("pause");
 system("cls");
}
//���ҵ�n��ѧ��
void FindnStudent(){
  system("cls");
  int i;
  printf("������n: ");
  getchar();
  scanf("%d",&i);
  if (i > N) {          // ������Χ����ʾ
    printf("���볬����Χ\n");
    system("pause");
    system("cls");
    return;
  }
  Output(&(Head[i-1])); //- 1����
  system("pause");
  system("cls");
}
void Findscore(){
  system("cls");
  int Class,score,id,sum = 0; //sum �Ǽ�¼����ĸ���
  printf("��ѡ����Ҫ��ѯ�Ŀ�Ŀ 1.��Ӣ 2.���� 3.C����: ");
  scanf("%d",&id);
  id--;
  printf("������༶�ͳɼ�,�Կո���: ");
  scanf("%d %d",&Class,&score);
  printf("1.���ڵ�������ɼ�\t2.С������ɼ�: ");
  scanf("%d",&id);
  switch(id) {   //ͨ��id����ѡ����һ������
    case 1:      // ������ڵĳɼ�
          for (int i = 0;i < N;i ++) {
              if (Head[i].calss == Class)
                if (Head[i].score[id] >= score)
                     {
                      Output(&(Head[i]));
                      sum++;
                     }
          }
          break;
     case 2:      //���С�ڵĳɼ�
          for (int i = 0;i < N;i ++) {
              if (Head[i].calss == Class)
                if (Head[i].score[id] < score)
                    {
                     Output(&(Head[i]));
                     sum++;
                    }
          }
          break;

  }
  if(!sum)   // �鲻��
       printf("���޴���\n");
  system("pause");
  system("cls");
}
//��ʾ���л������Ϣ
void Show() {
 system("cls");
 for (int i = 0;i < N;i ++) {
    Output(Head+i);
  }
  system("pause");
  system("cls");
}
//�ȽϷ�������ɼ�
void Maxscore() {
  system("cls");
  int id,max = -1,n;
  printf("��ѡ����Ҫ��ѯ�Ŀ�Ŀ 1.��Ӣ 2.���� 3.C����: ");
  scanf("%d",&id);
  id--;
  for(int i = 0;i < N;i++) {
    if (max < Head[i].score[id]) {
            max = Head[i].score[id];
            n = i;
      }
  }
  Output(&(Head[n]));
  system("pause");
  system("cls");
}
//ѡ������
void Choosesort(){
 system("cls");
 for (int i = 0;i < N;i++) {
    for (int j = i+1;j < N;j ++) {
        if (Head[i].score[0] + Head[i].score[1] + Head[i].score[2] > Head[j].score[0] + Head[j].score[1] + Head[j].score[2])
        {
            STU tmp;
            tmp = Head[i];
            Head[i] = Head[j];
            Head[j] = tmp;
        }
    }
 }
 printf("����ѧ���Ѱ���ƽ���ɼ���С������������!!!\n");
 system("pause");
 system("cls");
}
//ð������
void Bubblesort(){
 system("cls");
 int id;
 printf("��ѡ����Ҫ��ѯ�Ŀ�Ŀ 1.��Ӣ 2.���� 3.C����: ");
 scanf("%d",&id);
 id--;
for (int i = 0;i < N;i ++) {
    int flag = 0;
    for (int j = 0;j <N - i - 1;j ++)
        if( Head[j].score[id] < Head[j+1].score[id]) {
            STU tmp;
            tmp = Head[j];
            Head[j] = Head[j+1];
            Head[j+1] = tmp;
            flag = 1;
        }
    if (!flag) break;
}
printf("���������!!!\n");
system("pause");
system("cls");

}
//��������
void Insertsort(){
system("cls");
int id,sum = 0,n;//sum ����ͳ�Ƹ�רҵѧ����
char m[15];      //ԭ������ָ��,��֪��Ϊʲô����,����.
STU Tmp[10];
printf("��ѡ��רҵ:\t1.Computer\t2.Sotfware\t3.Network:\t");     //ѡ��רҵ
    scanf("%d",&id);
    switch(id) {
       case 1: strcpy(m,"Computer");break;
       case 2: strcpy(m,"Sotfware");break;
       case 3: strcpy(m,"NetWork");break;
       default  : printf("�����Ҷ�ѧԺ !!!\n");  //һ��С�ʵ�
                   strcpy(m,"Gryffindor");break;
    }
printf("��ѡ����Ҫ��ѯ�Ŀ�Ŀ 1.��Ӣ 2.���� 3.C����: ");
scanf("%d",&n);
n--;
for (int i = 0;i < N;i ++) {
    if ( !strcmp(Head[i].major,m)) {
        Tmp[sum++] = Head[i];
    }
}
for (int i = 1;i < sum;i++) {
   int value = Tmp[i].score[n];
   STU tem = Tmp[i];
   int j = i - 1;
   for (;j >= 0;--j) {
    if (Tmp[j].score[n] < value) {
        Tmp[j+1] = Tmp[j];         //�ƶ�����
    } else {
      break;
    }
   }
   Tmp[j+1] = tem;    // ����
  }
for (int i = 0;i < sum;i ++) Output(&Tmp[i]);
system("pause");
system("cls");
}



