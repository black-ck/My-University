#include "student.h"//�����ļ�
//���뺯��
Position Input() {
  system("cls");
  Position g_head,flag,Tmpcell;
  int n,i;
  i = 1;
  g_head = (Position)malloc(sizeof(STU)); //����������
  printf("��������Ҫ¼���ѧ������: ");
  scanf("%d",&n);
  //ѭ������
  while(i <= n) {
    Tmpcell = (Position)malloc(sizeof(STU));//��ʱ��Žڵ�
    printf("******��%d��******\n",i);
    OneNode(Tmpcell);// ¼�뵥�ڵ�
    if (i == 1){
     g_head = flag = Tmpcell; //�����ͷ�ڵ� ֱ�Ӹ�ֵ
    } else {
     flag->next = Tmpcell; //�������,����β��
     flag = Tmpcell; // flag ����ƶ�
    }
    i++;
 }
  flag->next = NULL;
  system("pause");
  system("cls");
  return g_head;
}
//�������
void OutOneNode(STU* p){
  if(p == NULL) {printf("���޴���\n");return;}
  printf("name:%s\tnum:%d\tmajor:%s\t\tclass:%d\t\tEnglish:%d  Math:%d  C langaug:%d \n",p->name,p->num,p->major,p->calss,p->score[0],p->score[1],p->score[2]);
}
// �˵�����
void menu (){
printf("\t\t\t\tStudent Manager Sts   v2.0 by CK\n");
printf("\t\t\t   ************************************************\n");
printf("\t\t\t 1.*��ʼ��Ϣ¼��                                  *\n");
printf("\t\t\t 2.*��ȡ�ļ���ѧ����Ϣ                            *\n");
printf("\t\t\t 3.*��ʾ��ǰ�����е�ѧ����Ϣ                      *\n");
printf("\t\t\t 4.*��ȡ�ܳɼ����ѧ������Ϣ                      *\n");
printf("\t\t\t 5.*���Һ��޸�ѧ����Ϣ                            *\n");
printf("\t\t\t 6.*��һ��ѧ����Ϣ�������                        *\n");
printf("\t\t\t 7.*ɾ��ָ��ѧ��                                  *\n");
printf("\t\t\t 8.*����ĳ��רҵ,ĳ�ſγ̵�һ���ɼ���ѧ��         *\n");
printf("\t\t\t 9.*ɾ��ĳ���༶,ĳ�ſγ̵�һ���ɼ���ѧ��         *\n");
printf("\t\t\t10.*������º��ѧ����Ϣ                          *\n");
printf("\t\t\t11.*�Ի�������������                              *\n");
printf("\t\t\t12.*�˳�����                                      *\n");
printf("\t\t\t  ************************************************\n");
printf("\t\t\t\t*��ѡ����Ĳ���:");
}
//���̺���
void Save(Position p){
 FILE* fp;
 int i = 1;
 char filename[30];
 printf("�����뱣����ļ���:");       //��ʱ
 getchar();                           //����س�
 gets(filename);
  if((fp = fopen(filename,"wb")) == NULL) { //û������֮ǰ�޷�����,�������ź������� // ��д��ķ�ʽ���ļ�
    printf("cannot open file\n");                    //����򲻿�,����

    system("pause");
    system("cls");
    return;
  }
    while(p != NULL){
    if (fwrite(p,sizeof(STU),1,fp) != 1){         // д��,fwriteӦ��fread��Ӧʹ��,fprintf��fscanf��Ӧʹ��,��Ȼ���鷳
        printf("file write error\n");                // ������ʾ

        system("pause");
        system("cls");
        return;
     }
     p = p -> next;
    }
  printf("���ڱ���********\n");
  printf("����ɹ�!!!\n");
  fclose(fp);
  system("pause");
  system("cls");
}
//��������
 Position CreatList() {
 system("cls");
 FILE* fp;
 Position tem,g_head,flag;
 flag = g_head = NULL;
 char filename[30];
 printf("���ڶ�ȡ*******\n");
 printf("��������ļ���:");
 getchar();
 gets(filename);

 if ((fp = fopen(filename,"rb")) == NULL) { //���ļ�
    printf("file cannot open !!!\n");
    system("pause");
    system("cls");
    return 0;
 }
 tem = (Position)malloc(sizeof(STU)); //��ʱ��ŵĽڵ�
 fread(tem,sizeof(STU),1,fp);// ��ȡͷһ���ڵ�
 g_head = flag = tem;
 while (flag->next != NULL )  //֮��ڵ㿪ʼѭ������
     {
         tem = (Position)malloc(sizeof(STU));
         fread(tem,sizeof(STU),1,fp);
         flag->next = tem;
         flag = tem;

     }
 fclose(fp);
 Head = flag;
 printf("��ȡ�ɹ�!!!\n");
 system("pause");
 system("cls");
 return g_head;
}
//��ӡ����
void Output(Position p){
  system("cls");
  if (p == NULL)printf("û��ƥ�����ѡ!!!\n");
  while(p != NULL) {
    OutOneNode(p);
    p = p -> next;
  }
  system("pause");
  system("cls");
}
//�����ֵ
Position Max(STU* p) {
  system("cls");
  Position  flag;
  int maxscore;
  maxscore = (p ->score[0]) + (p->score[1]) + (p->score[2]);
  while(p != NULL) {   // ѭ���Ա�
    int sum;
    sum = p ->score[0] + p->score[1] + p->score[2];
    if (maxscore < sum) {  // maxscore ʼ�������ֵ
        maxscore = sum;
        flag = p;
    }
    p = p -> next;
  }
  return flag;

}
//������������
Position Search_num(Position p) {
 system("cls");
 int id,n;
 char m[15];
 //ѡ������
 printf("1.����������ѯ 2.����ѧ�Ų�ѯ: ");
 scanf("%d",&id);
 getchar();
 while (id != 1 && id != 2) {
    printf("���Ŵ���,��������ȷ�Ĵ���: ");

    scanf("%d",&id);
 }
 if (id == 1) {
     printf("����������:");
     scanf("%s",m);
     while(strcmp(p->name,m)!=0 && p->next != NULL){ //���������Ա�
        p = p->next;
     }
     if (strcmp(p->name,m)==0) return p;
     else return NULL;

 } else {

     printf("������ѧ��:");
     scanf("%d",&n);
     while(p->num != n && p->next != NULL){
        p = p->next;
     }
     if (p->num == n) return p;
     else return NULL;
 }
}
//�޸ĺ���
void Modify(Position p){
  if (p == NULL ) {
    printf("���޴����޷�����\n");
    system("pause");
    system("cls");
    return;
  }
    printf("��ʼ�޸���Ϣ\n");
    OneNode(p);//����¼��
    printf("�޸����!!!\n");
    system("pause");
    system("cls");
    return;
}
//���뺯��
Position InsertList(Position p){
 system("cls");
 int id;
 Position Tmpcell,flag;
 flag = p;
 Tmpcell = (Position)malloc(sizeof(STU));
 printf("��������������Ϣ:\n");
 OneNode(Tmpcell);
 if ( p->num >= Tmpcell->num) {
    Tmpcell->next = p;
    flag = Tmpcell;
    return flag;
 }
 while(p->next != NULL && p->next->num < Tmpcell->num ) {
    p = p->next;
 }
 if (p->next == NULL) {
        p->next = Tmpcell;
        Tmpcell->next = NULL;
        return flag;
 } else {
   Tmpcell->next = p->next;
   p->next = Tmpcell;
   return flag;
 }

}
//����һ���ڵ�
void OneNode(Position Tmpcell){
 int id;
 printf("������ѧ������:");
 scanf("%s",Tmpcell->name);
 getchar();
 printf("������ѧ��(>0):");
 scanf("%d",&(Tmpcell->num));
 getchar();
 printf("��ѡ��רҵ:\t1.Computer\t2.Sotfware\t3.Network:  ");
 scanf("%d",&id);
 memset(Tmpcell->major,0,10);
 switch(id) {
  case 1: strcpy(Tmpcell->major,"Computer");break;
  case 2: strcpy(Tmpcell->major,"Sotfware");break;
  case 3: strcpy(Tmpcell->major,"NetWork");break;
  default  : printf("�������,hhhh\n");
 }
 printf("������༶1 or 2 : ");
 scanf("%d",&(Tmpcell->calss));
 printf("�������Ӣ�ɼ�:\t");
 scanf("%d",&(Tmpcell->score[0]));
 printf("����������ɼ�:\t");
 scanf("%d",&(Tmpcell->score[1]));
 printf("������C���Գɼ�: ");
 scanf("%d",&(Tmpcell->score[2]));
}
//ɾ������
Position Delete_num(Position p){
 system("cls");
 int id,n;
 Position flag,f;

 flag = (Position)malloc(sizeof(STU));// !!! ֮ǰû����仰,��f->next = NULL, ��Ϊû�з����flag�ڴ�ռ�,f.
 flag->next = p;
 f = flag;
 char m[15];
 memset(m,0,15);
 printf("1.��������ɾ�� 2.����ѧ��ɾ��: ");
 scanf("%d",&id);
 getchar();//���⵱����char����ʱ ����.
 while (id != 1 && id != 2) {
    printf("���Ŵ���,��������ȷ�Ĵ���: ");
    scanf("%d",&id);
 }
 if (id == 1) {

     flag->next = p;
     printf("����������:");
     scanf("%s",m);
     while(flag->next!= NULL ) {
        if (strcmp(flag->next->name,m) == 0) {
            Position tmp;
            tmp = flag->next;
            flag->next = tmp->next;
            free(tmp);
        }
        if(flag->next == NULL) break;
        if(strcmp(flag->next->name,m) != 0)
              flag = flag->next;   // ��ɾ�����һ���ڵ�ʱԽ��
       // printf("%d    %d\n",flag,flag->next);
     }
    printf("�������,�Ѿ�ɾ��!!!\n");
    //printf("%d\n",f->next);
    printf("�����Ѿ�����!!!\n");
    system("pause");
    system("cls");
    return f->next;

 } else {

     flag->next = p;
     printf("������ѧ��:");
     scanf("%d",&n);

     while(flag->next != NULL) {
        if (flag->next->num == n) {
            Position tmp;
            tmp = flag->next;
            flag->next = tmp->next;
            free(tmp);
        }
        if(flag->next == NULL) break;
        if(flag->next->num != n)
              flag = flag->next;
     }
     //printf("%d  %d",NULL,flag->next);

     printf("�������,�Ѿ�ɾ��!!!\n");
     printf("�����Ѿ�����!!!\n");
     system("pause");
     system("cls");
     return f->next;
 }
}
//����������Χ����
void Search_score(Position p) {
 system("cls");
 int c,id,n,i,score;
 char m[15];

 Position g_head,flag,tem;
 g_head = (Position)malloc(sizeof(STU));
 g_head->next = NULL;
 flag = g_head;
 printf("��ѡ���ѯ��רҵ:1.Computer 2.Sotfware 3.Network: ");
 scanf("%d",&n);
 getchar();//���⵱����char����ʱ ����.
 while (n != 1 && n != 2 && n != 3) {
    printf("���Ŵ���,��������ȷ�Ĵ���: ");
    scanf("%d",&n);
 }
 switch(n){
   case 1: strcpy(m,"Computer");break;
   case 2: strcpy(m,"Sotfware");break;
   case 3: strcpy(m,"NetWork");break;
 }

 printf("��ѡ��γ�:1.English 2.Math 3.C langaug: ");
 scanf("%d",&i);
 getchar();//���⵱����char����ʱ ����.
 while (i != 1 && i != 2 && i != 3) {
    printf("���Ŵ���,��������ȷ�Ĵ���: ");
    scanf("%d",&i);
 }
 printf("�����������: ");
 scanf("%d",&score);
 printf("��ѡ�����: 1.���ڵ��ڷ����� 2.С�ڷ�����: ");
 scanf("%d",&id);
 getchar();//���⵱����char����ʱ ����.
 while (id != 1 && id != 2) {
    printf("���Ŵ���,��������ȷ�Ĵ���: ");
    scanf("%d",&id);
 }
printf("%s %d %d %d %d",m,c,i,score,id);
 if (id == 1) {

      while( p != NULL){
      if (p->major[0] == m[0] && p->score[i-1] >= score)
         {
           tem = (Position)malloc(sizeof(STU));
           tem = p;
           flag->next = tem;
           flag = tem;
         }
      p = p->next;

     }
     flag->next = NULL;
     Output(g_head->next);
     printf("�Ƿ񱣴�: 1.���� 2.������: ");
     scanf("%d",&id);
     if (id == 1) Save(g_head->next);
     else printf("�õ�,����\n");

     system("pause");
     system("cls");
     return;
} else {
     while( p != NULL){

     if (  p->major[0] == m[0] && (p->score[i-1]) < score)
           {
           tem = (Position)malloc(sizeof(STU));
           tem = p;
           flag->next = tem;
           flag = tem;
           }
     p = p->next;

    }
    flag->next = NULL;
    Output(g_head->next);
    printf("�Ƿ񱣴�: 1.���� 2.������: ");
    scanf("%d",&id);
    if (id == 1) Save(g_head->next);
    else printf("�õ�,����\n");

    system("pause");
    system("cls");
    return;
  }
 printf("���޴���!!!\n");
 system("pause");
 system("cls");
 return;
}
//����������Χɾ��
Position Delete_score(Position p){
 system("cls");
 Position flag,f;
 int c,id,n,i,score;
 char m[15];
 flag = (Position)malloc(sizeof(STU));// !!! ֮ǰû����仰,��f->next = NULL, ��Ϊû�з����flag�ڴ�ռ�,f.
 flag->next = p;
 f = flag;

 printf("������༶(1 or 2): ");
 scanf("%d",&c);
 getchar();//���⵱����char����ʱ ����.
 while (c != 1 && c != 2) {
    printf("���Ŵ���,��������ȷ�Ĵ���: ");
    scanf("%d",&c);
 }
 printf("��ѡ��γ�:1.English 2.Math 3.C langaug: ");
 scanf("%d",&i);
 getchar();//���⵱����char����ʱ ����.
 while (i != 1 && i != 2 && i != 3) {
    printf("���Ŵ���,��������ȷ�Ĵ���: ");
    scanf("%d",&i);
 }
 printf("�����������: ");
 scanf("%d",&score);
 printf("��ѡ�����: 1.���ڵ��ڷ����� 2.С�ڷ�����: ");
 scanf("%d",&id);
 getchar();//���⵱����char����ʱ ����.
 while (id != 1 && id != 2) {
    printf("���Ŵ���,��������ȷ�Ĵ���: ");
    scanf("%d",&id);
 }
 //printf("%s %d %d %d %d\n",m,c,i,score,id);
 if (id == 1) {

     flag->next = p;
     while(flag->next != NULL) {
      //  printf("%d %d %d %d\n",strcmp(flag->next->major,m),(flag->next->calss) == c,flag->next->score[i-1] >= score,flag);
        if (flag->next->calss == c && flag->next->score[i-1] >= score){
            //printf("1\n");
            Position tmp;
            tmp = flag->next;
            flag->next = tmp->next;
            free(tmp);

        }
        if (flag->next == NULL) break;
        if(!(flag->next->calss == c && flag->next->score[i-1] >= score))
              //printf("2\n");
              flag = flag->next;
      //  printf("%d\n",f);
     }

    printf("�������,�Ѿ�ɾ��!!!\n");
    //printf("%d\n",f->next);

    system("pause");
    system("cls");
    return f->next;

 } else {

     flag->next = p;
     while(flag->next != NULL) {
        if ( flag->next->calss == c && flag->next->score[i-1] < score){
            Position tmp;
            tmp = flag->next;
            flag->next = tmp->next;
            free(tmp);
        }
        if (flag->next == NULL) break;
        if(!(flag->next->calss == c && flag->next->score[i-1] < score))
              flag = flag->next;
     }
     printf("�������,�Ѿ�ɾ��!!!\n");

     system("pause");
     system("cls");
     return f->next;
 }
}
//������
void Order(Position p){
system("cls");
Position flag,f;
STU temp;
flag = p;
//���Ϊ��
if (p == NULL) {
    printf("��������ɶ˳��?\n");
    return;
}
//������ڵ�
if (p->next == NULL) {
    printf("ֻ��һ���ڵ㻹��ɶ˳��?\n");
    return;
}
//�������
while(flag->next != NULL) { //��ͷѭ����β���ڵ�
    f = flag->next;
    while(f != NULL) {
        if(flag->score[0] + flag->score[1] + flag->score[2] > f->score[0] + f->score[1] + f->score[2]) {//����Ⱥ���ڵ���򻥻�
            temp = *flag; //��ֵ����
            *flag = *f;
            *f = temp;
            temp.next = flag->next; //ָ�뻻��
            flag->next = f->next;
            f->next = temp.next;
        }
        f = f ->next; //�򵥱Ƚ�����
    }
    flag = flag->next;
}
printf("�������\n");
system("pause");
system("cls");
return;
}

