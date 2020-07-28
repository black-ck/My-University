#include "student.h"//引用文件
//输入函数
Position Input() {
  system("cls");
  Position g_head,flag,Tmpcell;
  int n,i;
  i = 1;
  g_head = (Position)malloc(sizeof(STU)); //开辟新链表
  printf("请输入您要录入的学生数量: ");
  scanf("%d",&n);
  //循环输入
  while(i <= n) {
    Tmpcell = (Position)malloc(sizeof(STU));//临时存放节点
    printf("******第%d个******\n",i);
    OneNode(Tmpcell);// 录入单节点
    if (i == 1){
     g_head = flag = Tmpcell; //如果是头节点 直接赋值
    } else {
     flag->next = Tmpcell; //如果不是,插入尾部
     flag = Tmpcell; // flag 标记移动
    }
    i++;
 }
  flag->next = NULL;
  system("pause");
  system("cls");
  return g_head;
}
//输出函数
void OutOneNode(STU* p){
  if(p == NULL) {printf("查无此人\n");return;}
  printf("name:%s\tnum:%d\tmajor:%s\t\tclass:%d\t\tEnglish:%d  Math:%d  C langaug:%d \n",p->name,p->num,p->major,p->calss,p->score[0],p->score[1],p->score[2]);
}
// 菜单函数
void menu (){
printf("\t\t\t\tStudent Manager Sts   v2.0 by CK\n");
printf("\t\t\t   ************************************************\n");
printf("\t\t\t 1.*初始信息录入                                  *\n");
printf("\t\t\t 2.*读取文件中学生信息                            *\n");
printf("\t\t\t 3.*显示当前缓存中的学生信息                      *\n");
printf("\t\t\t 4.*读取总成绩最高学生的信息                      *\n");
printf("\t\t\t 5.*查找和修改学生信息                            *\n");
printf("\t\t\t 6.*将一个学生信息有序插入                        *\n");
printf("\t\t\t 7.*删除指定学生                                  *\n");
printf("\t\t\t 8.*查找某个专业,某门课程的一定成绩的学生         *\n");
printf("\t\t\t 9.*删除某个班级,某门课程的一定成绩的学生         *\n");
printf("\t\t\t10.*储存更新后的学生信息                          *\n");
printf("\t\t\t11.*对缓存中链表排序                              *\n");
printf("\t\t\t12.*退出程序                                      *\n");
printf("\t\t\t  ************************************************\n");
printf("\t\t\t\t*请选择你的操作:");
}
//存盘函数
void Save(Position p){
 FILE* fp;
 int i = 1;
 char filename[30];
 printf("请输入保存的文件名:");       //暂时
 getchar();                           //清除回车
 gets(filename);
  if((fp = fopen(filename,"wb")) == NULL) { //没加括号之前无法保存,加了括号后问题解决 // 以写入的方式打开文件
    printf("cannot open file\n");                    //如果打不开,报错

    system("pause");
    system("cls");
    return;
  }
    while(p != NULL){
    if (fwrite(p,sizeof(STU),1,fp) != 1){         // 写入,fwrite应与fread对应使用,fprintf与fscanf对应使用,不然很麻烦
        printf("file write error\n");                // 错误提示

        system("pause");
        system("cls");
        return;
     }
     p = p -> next;
    }
  printf("正在保存********\n");
  printf("保存成功!!!\n");
  fclose(fp);
  system("pause");
  system("cls");
}
//创建链表
 Position CreatList() {
 system("cls");
 FILE* fp;
 Position tem,g_head,flag;
 flag = g_head = NULL;
 char filename[30];
 printf("正在读取*******\n");
 printf("请输入打开文件名:");
 getchar();
 gets(filename);

 if ((fp = fopen(filename,"rb")) == NULL) { //打开文件
    printf("file cannot open !!!\n");
    system("pause");
    system("cls");
    return 0;
 }
 tem = (Position)malloc(sizeof(STU)); //临时存放的节点
 fread(tem,sizeof(STU),1,fp);// 读取头一个节点
 g_head = flag = tem;
 while (flag->next != NULL )  //之后节点开始循环插入
     {
         tem = (Position)malloc(sizeof(STU));
         fread(tem,sizeof(STU),1,fp);
         flag->next = tem;
         flag = tem;

     }
 fclose(fp);
 Head = flag;
 printf("读取成功!!!\n");
 system("pause");
 system("cls");
 return g_head;
}
//打印链表
void Output(Position p){
  system("cls");
  if (p == NULL)printf("没有匹配的人选!!!\n");
  while(p != NULL) {
    OutOneNode(p);
    p = p -> next;
  }
  system("pause");
  system("cls");
}
//找最大值
Position Max(STU* p) {
  system("cls");
  Position  flag;
  int maxscore;
  maxscore = (p ->score[0]) + (p->score[1]) + (p->score[2]);
  while(p != NULL) {   // 循环对比
    int sum;
    sum = p ->score[0] + p->score[1] + p->score[2];
    if (maxscore < sum) {  // maxscore 始终是最大值
        maxscore = sum;
        flag = p;
    }
    p = p -> next;
  }
  return flag;

}
//根据条件查找
Position Search_num(Position p) {
 system("cls");
 int id,n;
 char m[15];
 //选择条件
 printf("1.根据姓名查询 2.根据学号查询: ");
 scanf("%d",&id);
 getchar();
 while (id != 1 && id != 2) {
    printf("代号错误,请输入正确的代号: ");

    scanf("%d",&id);
 }
 if (id == 1) {
     printf("请输入姓名:");
     scanf("%s",m);
     while(strcmp(p->name,m)!=0 && p->next != NULL){ //根据姓名对比
        p = p->next;
     }
     if (strcmp(p->name,m)==0) return p;
     else return NULL;

 } else {

     printf("请输入学号:");
     scanf("%d",&n);
     while(p->num != n && p->next != NULL){
        p = p->next;
     }
     if (p->num == n) return p;
     else return NULL;
 }
}
//修改函数
void Modify(Position p){
  if (p == NULL ) {
    printf("查无此人无法操作\n");
    system("pause");
    system("cls");
    return;
  }
    printf("开始修改信息\n");
    OneNode(p);//重新录入
    printf("修改完成!!!\n");
    system("pause");
    system("cls");
    return;
}
//插入函数
Position InsertList(Position p){
 system("cls");
 int id;
 Position Tmpcell,flag;
 flag = p;
 Tmpcell = (Position)malloc(sizeof(STU));
 printf("下面输入插入的信息:\n");
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
//输入一个节点
void OneNode(Position Tmpcell){
 int id;
 printf("请输入学生姓名:");
 scanf("%s",Tmpcell->name);
 getchar();
 printf("请输入学号(>0):");
 scanf("%d",&(Tmpcell->num));
 getchar();
 printf("请选择专业:\t1.Computer\t2.Sotfware\t3.Network:  ");
 scanf("%d",&id);
 memset(Tmpcell->major,0,10);
 switch(id) {
  case 1: strcpy(Tmpcell->major,"Computer");break;
  case 2: strcpy(Tmpcell->major,"Sotfware");break;
  case 3: strcpy(Tmpcell->major,"NetWork");break;
  default  : printf("输入错误,hhhh\n");
 }
 printf("请输入班级1 or 2 : ");
 scanf("%d",&(Tmpcell->calss));
 printf("请输入大英成绩:\t");
 scanf("%d",&(Tmpcell->score[0]));
 printf("请输入高数成绩:\t");
 scanf("%d",&(Tmpcell->score[1]));
 printf("请输入C语言成绩: ");
 scanf("%d",&(Tmpcell->score[2]));
}
//删除函数
Position Delete_num(Position p){
 system("cls");
 int id,n;
 Position flag,f;

 flag = (Position)malloc(sizeof(STU));// !!! 之前没有这句话,则f->next = NULL, 因为没有分配给flag内存空间,f.
 flag->next = p;
 f = flag;
 char m[15];
 memset(m,0,15);
 printf("1.根据姓名删除 2.根据学号删除: ");
 scanf("%d",&id);
 getchar();//避免当输入char类型时 卡死.
 while (id != 1 && id != 2) {
    printf("代号错误,请输入正确的代号: ");
    scanf("%d",&id);
 }
 if (id == 1) {

     flag->next = p;
     printf("请输入姓名:");
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
              flag = flag->next;   // 当删除最后一个节点时越界
       // printf("%d    %d\n",flag,flag->next);
     }
    printf("操作完毕,已经删除!!!\n");
    //printf("%d\n",f->next);
    printf("缓存已经更新!!!\n");
    system("pause");
    system("cls");
    return f->next;

 } else {

     flag->next = p;
     printf("请输入学号:");
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

     printf("操作完毕,已经删除!!!\n");
     printf("缓存已经更新!!!\n");
     system("pause");
     system("cls");
     return f->next;
 }
}
//根据条件范围查找
void Search_score(Position p) {
 system("cls");
 int c,id,n,i,score;
 char m[15];

 Position g_head,flag,tem;
 g_head = (Position)malloc(sizeof(STU));
 g_head->next = NULL;
 flag = g_head;
 printf("请选择查询的专业:1.Computer 2.Sotfware 3.Network: ");
 scanf("%d",&n);
 getchar();//避免当输入char类型时 卡死.
 while (n != 1 && n != 2 && n != 3) {
    printf("代号错误,请输入正确的代号: ");
    scanf("%d",&n);
 }
 switch(n){
   case 1: strcpy(m,"Computer");break;
   case 2: strcpy(m,"Sotfware");break;
   case 3: strcpy(m,"NetWork");break;
 }

 printf("请选择课程:1.English 2.Math 3.C langaug: ");
 scanf("%d",&i);
 getchar();//避免当输入char类型时 卡死.
 while (i != 1 && i != 2 && i != 3) {
    printf("代号错误,请输入正确的代号: ");
    scanf("%d",&i);
 }
 printf("请输入分数线: ");
 scanf("%d",&score);
 printf("请选择操作: 1.大于等于分数线 2.小于分数线: ");
 scanf("%d",&id);
 getchar();//避免当输入char类型时 卡死.
 while (id != 1 && id != 2) {
    printf("代号错误,请输入正确的代号: ");
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
     printf("是否保存: 1.保存 2.不保存: ");
     scanf("%d",&id);
     if (id == 1) Save(g_head->next);
     else printf("好的,跳过\n");

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
    printf("是否保存: 1.保存 2.不保存: ");
    scanf("%d",&id);
    if (id == 1) Save(g_head->next);
    else printf("好的,跳过\n");

    system("pause");
    system("cls");
    return;
  }
 printf("查无此人!!!\n");
 system("pause");
 system("cls");
 return;
}
//根据条件范围删除
Position Delete_score(Position p){
 system("cls");
 Position flag,f;
 int c,id,n,i,score;
 char m[15];
 flag = (Position)malloc(sizeof(STU));// !!! 之前没有这句话,则f->next = NULL, 因为没有分配给flag内存空间,f.
 flag->next = p;
 f = flag;

 printf("请输入班级(1 or 2): ");
 scanf("%d",&c);
 getchar();//避免当输入char类型时 卡死.
 while (c != 1 && c != 2) {
    printf("代号错误,请输入正确的代号: ");
    scanf("%d",&c);
 }
 printf("请选择课程:1.English 2.Math 3.C langaug: ");
 scanf("%d",&i);
 getchar();//避免当输入char类型时 卡死.
 while (i != 1 && i != 2 && i != 3) {
    printf("代号错误,请输入正确的代号: ");
    scanf("%d",&i);
 }
 printf("请输入分数线: ");
 scanf("%d",&score);
 printf("请选择操作: 1.大于等于分数线 2.小于分数线: ");
 scanf("%d",&id);
 getchar();//避免当输入char类型时 卡死.
 while (id != 1 && id != 2) {
    printf("代号错误,请输入正确的代号: ");
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

    printf("操作完毕,已经删除!!!\n");
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
     printf("操作完毕,已经删除!!!\n");

     system("pause");
     system("cls");
     return f->next;
 }
}
//排序函数
void Order(Position p){
system("cls");
Position flag,f;
STU temp;
flag = p;
//如果为空
if (p == NULL) {
    printf("空链表还排啥顺序?\n");
    return;
}
//如果单节点
if (p->next == NULL) {
    printf("只有一个节点还排啥顺序?\n");
    return;
}
//正常情况
while(flag->next != NULL) { //从头循环到尾部节点
    f = flag->next;
    while(f != NULL) {
        if(flag->score[0] + flag->score[1] + flag->score[2] > f->score[0] + f->score[1] + f->score[2]) {//如果比后面节点大则互换
            temp = *flag; //把值交换
            *flag = *f;
            *f = temp;
            temp.next = flag->next; //指针换回
            flag->next = f->next;
            f->next = temp.next;
        }
        f = f ->next; //简单比较排序
    }
    flag = flag->next;
}
printf("排序完成\n");
system("pause");
system("cls");
return;
}

