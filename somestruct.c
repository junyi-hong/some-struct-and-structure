#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

char* strrev(char* str)//
{
    if(! str || !*str)
        return str;
    int i=strlen(str)-1,j=0;
    char ch;
    while(i>j)
    {
        ch=str[i];
        str[i]=str[j];
        str[j]=ch;
        i--;
        j++;
    }
    return str;
}
struct data{
        int dia;
        int mes;
        int ano;
    };

void data_print(struct data d);

void data_print(struct data d) {
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

struct Binary
{
    char str[100];
};
struct Binary to_binary(unsigned int val,int k)
{
    struct Binary ans;
    int idx=0;
    while(val>0)
    {
        int d=val%2;
        val=val/2;
        ans.str[idx]='0'+d;
        idx++;
    }
    for(int i=idx;i<k;i++)
    {
        ans.str[i]='0';
    }
    ans.str[k]=0;
    strrev(ans.str);
    return ans;
};
unsigned char RightRotate(unsigned char mask,int k)
{
    int lastk=mask & ((1<<k)-1);
    return (mask>>k)|(lastk<<(8-k));
}
struct ArrayHolder
{
    int a[100];
    int b[100];
    int sum[100];
};

struct ArrayHolder array_sum(int n)
{
    struct ArrayHolder ans;
    for(int i=0; i<n; i++)
    {
        ans.a[i]=i;
    }

    for(int i=0; i<n; i++)
    {
        ans.b[i]=i;
    }
    for(int i=0; i<n; i++)
    {
        ans.sum[i]=ans.a[i]+ans.b[i];
    }
    return ans;
}

struct ArrayHolder1
{
    int array[100];
};
struct ArrayHolder1 makeNarray(int n)
{
    struct ArrayHolder1 ans;
    for(int i=0;i<n;i++)
    {
        ans.array[i]=i+1;
    }
    return ans;
};
void array_structure(int n)
{
	struct ArrayHolder1 ans =makeNarray(n);
	for(int i=0;i<n;i++)
	{
	    printf("%d ",ans.array[i]);
	}
}

struct Result
{
    int vagfol;
    int vagshesh;
};
struct Result divide(int a,int b)
{
    return (struct Result){a/b,a%b};
};
void  multiple_maxvalue(int a,int b)
{
    int c;
    if(a==0&&a>b)
	{
		return ;
	}
	if(b==0&&b>a)
	{
		return ;
	}
    if(a>b)
    {
		c=a;
	}
	else
	{
		c=b;
	}
    struct Result result=divide(a+b,c);
    printf("%d  %d\n",result.vagfol,result.vagshesh);
}
struct Person
{
    char name[50];
    int age;
    float salary;
};
void display(struct Person p)
{
    printf("Name=%s\n",p.name);
    printf("Age=%d\n",p.age);
    printf("Salary=%.2f\n",p.salary);
}
struct Date
{
    int day;
    int month;
    int year;
};
int days_in_months[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

bool  is_valid_date(struct Date date)
{
    if((date.year%4==0&&date.year%100!=0)||(date.year%400==0))
    {
        days_in_months[date.month-1]=29;
        if(date.month>=1 && date.month<=12)
        {
            if(date.day>=1 && date.day<=days_in_months[date.month-1])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            false;
        }
    }
    else
    {
        if(date.month>=1 && date.month<=12)
        {
            if(date.day>=1 && date.day<=days_in_months[date.month-1])
            {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
}

bool getBit(unsigned int mask,int k)
{
    return (mask & (1<<k))!=0;
}

unsigned int setBit(unsigned int mask,int k)
{
    return mask | (1<<k);
}



struct points
{
    double x1;
    double x2;
    double y1;
    double y2;
    double midpoint_of_x;
    double midpoint_of_y;
};

void print_2points_mid(struct points d)
{
	d.midpoint_of_x=(double)((d.x1+d.x2)/2);
	d.midpoint_of_y=(double)((d.y1+d.y2)/2);
}

double  print_2points_dis(struct points d)
{
	double dis;
	double xdis =d.x1-d.x2;
	double ydis =d.y1-d.y2;
	dis=xdis*xdis+ydis*ydis;
	dis=sqrt(dis);
	return dis;
}

#define size 3

struct Sportteam
{
	char name[20];
	char city[20];
	int score;
};

void some_function(struct Sportteam* team)
{
	struct Sportteam t[size];
	for (int i = 0; i < size; i++)
	{
		printf("Enter the team name:\n");
		scanf("%s", t[i].name);
		printf("Enter the city:\n");
		scanf("%s", t[i].city);
		printf("Enter the team`s score:\n");
		scanf("%d", &t[i].score);
	}
	short max = 0;
	short num = 0;
	for (int i = 1; i < size; i++)
	{
		if (t[i].score > max)
		{
			max = t[i].score;
			num = i;
		}
	}
	for (short i = 0; i < size; i++)
	{
		printf("\nTeam name: %s\n", t[i].name);
		printf("\nCity: %s\n", t[i].city);
		printf("\nScore: %d\n", t[i].score);
	}
	printf("The team with the most points: %s", t[num].name);
}


struct Fraction
{
    int num;
    int denom;
};
int gcd(int a,int b)
{
    while(b>0)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
 struct Fraction reduce(struct Fraction f)
{
    int g=gcd(f.num,f.denom);
    f.num/=g;
    f.denom/=g;
    return f;
}
struct Fraction inputFraction()
{
    struct Fraction f;
    scanf("%d %d",&f.num,&f.denom);
    return f;
}
void print(struct Fraction f)
{
    printf("%d/%d",f.num,f.denom);
}

struct Fraction add(struct Fraction a,struct Fraction b)
{
    struct Fraction ans;
    ans.num=a.num*b.denom+b.num*a.denom;
    ans.denom=a.denom*b.denom;
    return ans;
};
int is_reverse_sort(int n,int a[])
{
    int count ;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            count=0;
            if(a[i]>a[j])
            {
                count++;
            }
        }
    }
    if(count==1)
        return true;
    else
        return false;
}

int swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return *a,*b;
}
void reverse_sort(int n, int a[])
{
    for(int steps=0; steps<n; steps++)
    {
        for(int i=steps+1; i<n; i++)
        {
            if(a[steps]<a[i])
            {
            swap(&a[steps],&a[i]);
            }
            printf("steps %d\n",steps);
            printf("swap %d and %d\n",i,i+1);
            for(int i=0; i<n; i++)
            {
                printf("%d ",a[i]);
            }
            printf("\n\n");

        }
        if(is_reverse_sort(n,a)==true)
        {
            printf("true\n");
            break;
        }
    }
}
unsigned int binaryToInt(char str[])
{
    unsigned int ans=0;
    int len=strlen(str);
    /**for(int i=len-1,p=1;i>=0;i--,p*=2)
    {
        int bit=str[i]-'0';
       // printf("%d %d %d\n",bit,i,p);
       if(bit==1)
       {
           ans=ans+p;
       }
    }*/
    for(int i=0;i<len;i++)
    {
        int bit=str[i]-'0';
        ans=ans*2+bit;
    }
    return ans;
}


// ����һ����ʾѧ���Ľṹ��
struct Student {
    int id;
    char name[50];
    float GPA;
};

// ����һ����ʾ�γ̵Ľṹ��
struct Course {
    int course_id;
    char title[100];
    int credits;
};

// ��������
void addStudent(struct Student students[], int *student_count);
void printStudentInfo(struct Student student);
void addCourse(struct Course courses[], int *course_count);
void printCourseInfo(struct Course course);

// ����ѧ��
void addStudent(struct Student students[], int *student_count) {
    struct Student new_student;

    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    printf("Enter student GPA: ");
    scanf("%f", &new_student.GPA);

    students[*student_count] = new_student;
    (*student_count)++;
}

// ��ӡѧ����Ϣ
void printStudentInfo(struct Student student) {
    printf("Student ID: %d\n", student.id);
    printf("Student Name: %s\n", student.name);
    printf("Student GPA: %.2f\n", student.GPA);
}

// ���ӿγ�
void addCourse(struct Course courses[], int *course_count) {
    struct Course new_course;

    printf("Enter course ID: ");
    scanf("%d", &new_course.course_id);
    printf("Enter course title: ");
    scanf("%s", new_course.title);
    printf("Enter course credits: ");
    scanf("%d", &new_course.credits);

    courses[*course_count] = new_course;
    (*course_count)++;
}

// ��ӡ�γ���Ϣ
void printCourseInfo(struct Course course) {
    printf("Course ID: %d\n", course.course_id);
    printf("Course Title: %s\n", course.title);
    printf("Course Credits: %d\n", course.credits);
}


//�ṹ�����һ�ֶ���
typedef struct {
    float length;
    float width;
} Rectangle;

float calculateArea(Rectangle *rect) {
    return rect->length * rect->width;
}

// ��ʾ���γ����ĺ���
void displayRectangleInfo(Rectangle *rect) {
    printf("length is %.2f width is %.2f", rect->length, rect->width);
}

typedef struct {
    float radius;
} Circle;

// ����Բ����ĺ���
float calcircleArea(Circle *circle) {
    return 3.1415926* circle->radius * circle->radius;
}

// ��ʾԲ�뾶�ĺ���
void displayCircleInfo(Circle *circle)
{
    printf("Բ�İ뾶Ϊ��%.2f", circle->radius);
}

//book lib
typedef struct {
    char title[50];
    char author[50];
    char publisher[50];
    float price[50];
    int stock[50];
    int n;
} Book;

void inputBookInfo(Book *book) {
	int stock;
	float price;
	char publisher;
	char title;
	char author;
	int now;
	now=book->n;
	
    book->title[now+1] =title;
    book->author[now+1]=author;
    book->publisher[now+1]=publisher;
    book->price[now+1]=price;
    book->stock[now=1]=stock;
    now++;
	book->n=now;
}

void displayBookInfo(Book *book) {
    printf("bookname��%s", book->title);
    printf("bookauthor��%s", book->author);
    printf("bookpublisher��%s", book->publisher);
    printf("price��%.2f", book->price);
    printf("stock��%d", book->stock);
}


int calculateTotalStock(Book books, int num) {
    int totalStock = 0;
    for (int i = 0; i < num; i++) {
        totalStock += books.stock[i];
    }
    return totalStock;
}


//dfs

int p,q,map[1000][1000]={0},book[1000][1000]={0},n,m;

int lujing[100]={0},lujing2[100] = {0};
int tail=0;
int head=0;
//struct note notee[100];
int stack2_tail=0;
int stack2_head=0;




struct note
{
    int x;
    int y;

};
struct note stack1[100];
struct note stack2[100];



void  dfs(int x ,int y,int step)
{
    

    //int booll=0;
    int next[4][2]={{0,1},
                  {1,0},
                  {0,-1},
                  {-1,0}};
    int i,tx,ty;
    //printf("%d %d <---",x,y);
    if(x==p&&y==q)
    {
        printf("\n");
        //printf("(%d %d)<--",x,y);
        //nodee[j].x=x;   // go stack
        //nodee[j].y=y;

        while(tail!=head)
        {
            printf("(%d,%d)<---",stack1[tail].x,stack1[tail].y);
            tail++;
        }
        tail=0;


        //j++;
        return ;
    }
    else
    {
        int i;
        for(i=0;i<4;i++)
        {
            tx = x+next[i][0];
            ty = y+next[i][1];


            if(tx<0 ||ty<0 || tx>=n ||ty>=m)
                {
                    return;
                }
            if(map[tx][ty]== 0 && book[tx][ty]==0)
            {
                book[tx][ty] = 1;
                //nodee[j].x=x;
                //nodee[j].y=y;
                //j++;

                stack1[head].x = tx;
                stack1[head].y = ty;
                head++;


                dfs(tx,ty,step+1);

                //printf("(%d %d)<---",x,y);
                book[tx][ty]=0;
                stack1[head].x=-1;
                stack1[head].y=-1;
                head--;


                //j--;
            }
            //printf("\n");
        }
    }
}
#define MAXSIZE 20

typedef struct
{
    char data[MAXSIZE];
    int top;
}Stack;

typedef struct
{
    int data[MAXSIZE];
    int top;
}NumStack;

int InitStack(Stack *S)
{
    int i;
    for(i=0 ; i<MAXSIZE ; i++)
    {
        S->data[i]=0;
        S->top = -1;
        return true;
    }
}

int Push(Stack *S , char e)
{
    if(MAXSIZE-1 == S->top)
    {
        printf("Stack already full!");
        return false;
    }
    ++(S->top);
    S->data[S->top] = e;
    return true;
}

int Pop(Stack *S, char *e)
{
    if(S->top == -1)
    {
        printf("Stack empty!");
        return false;
    }
    *e=S->data[S->top];
    --(S->top);
    return true;
}
void MidtoFin(char *Mid , char *Fin)
{
    char e;
    Stack S;
    if(InitStack(&S) != true)
    {
        printf("Init Error");

    }
    while(*Mid)
    {
        if(*Mid>='0' && *Mid<='9')
        {
            *(Fin++)=*(Mid++);
            *(Fin++)=',';
            continue;
        }
        else if(*Mid=='+'||*Mid=='-'||*Mid=='*'||*Mid=='/'||*Mid=='('||*Mid==')')
        {
            if(S.top == -1 || *Mid == '(')
           {
               Push(&S,*(Mid++));
                continue;
           }
           if(*Mid == ')')
           {
                Pop(&S,&e);

                *(Fin++)=e;
                //printf("%c ",e);
                while(Pop(&S,&e) && e!='(')
                {
                     *(Fin++) = e;
                }

                Mid++;
           }//if
        }//elseif
         Pop(&S,&e);

         if('+'==*Mid || '-'==*Mid)
         {
             if(e == '(')
             {
                Push(&S,'(');
                Push(&S,*(Mid++));
                continue;
             }
             else
             {
                 *(Fin++) = e;
                 Push(&S,*(Mid++));
                 continue;
             }
         }
         else if('*'==*Mid || '/'==*Mid)
         {
             if(e == '*' || e == '/')
             {
                 Push(&S,*(Mid++));
                 continue;
             }
             else
             {
                 Push(&S,e);
                 Push(&S,*(Mid++));
                 continue;
             }
         }
    }//while

    *Fin = '\0';
}

int operation(int number_1 , char op , int number_2)
{

    switch(op)
    {
        case '+':return number_1 + number_2;
        case '-':return number_1 - number_2;
        case '*':return number_1 * number_2;
        case '/':return number_1 / number_2;
    }
}
int IsNumber(char x)
{
    switch(x)
    {
        case '0':return 1;
        case '1':return 1;
        case '2':return 1;
        case '3':return 1;
        case '4':return 1;
        case '5':return 1;
        case '6':return 1;
        case '7':return 1;
        case '8':return 1;
        case '9':return 1;

        default:
            return(0);
    }
}
int IsOperate(char x)
{
	switch(x)
	{
		case '+':return 1;
		case '-':return 1;
		case '*':return 1;
		case '/':return 1;
		case ',':return 2;
	}
}
int SumOfFin(char *Fin)
{

    NumStack Num;
    Num.top = -1;
    int i=0;
    int number_2;
    int number_1;
    int lastnum;
    int y;
    while(Fin[i] != '\0')
    {
        if(IsNumber(Fin[i]))
        {

             Num.data[++Num.top] = atoi(&Fin[i]) ;
        }


        else
        {
        	y=IsOperate(Fin[i]);
        	switch(y)
        	{
        		case 1:{
	        			number_2=Num.data[Num.top--];
			            number_1=Num.data[Num.top--];
			            lastnum = operation(number_1,Fin[i],number_2);
			            Num.data[++Num.top] = lastnum;
						break;
						}
				case 2:break;
			}

        }

        i++;

    }
    return Num.data[Num.top];

}

typedef struct {
    double coef;
    int exp;
} polinomios;

void le_poli(int n, polinomios *p);

void sum_poli(polinomios *p1, polinomios *p2, polinomios *p3, int n1, int n2);

void sub_poli(polinomios *p1, polinomios *p2, polinomios *p3, int n1, int n2);

void print_poli(polinomios *p, int n);

void ordena_poli(polinomios *p3, int n);

void le_poli(int n, polinomios *p) {
    int i;
    for(i=0; i<n; i++) {
        scanf("%lf %d%*c", &p[i].coef, &p[i].exp);
        if(p[i].exp==32) p[i].exp=0;
    }
}

void sum_poli(polinomios *p1, polinomios *p2, polinomios *p3, int n1, int n2) {
    int i, c, r, k;
    for(i=0; i<n1; i++) {
        r=0;
        for(c=0; c<n2; c++) {
            if(p1[i].exp==p2[c].exp) {
                p3[i].coef=p1[i].coef+p2[c].coef;
                p3[i].exp=p1[i].exp;
                r++;
            }
        }
        if(r==0) {
            p3[i].coef=p1[i].coef;
            p3[i].exp=p1[i].exp;
        }
    }
    for(c=0; c<n2; c++) {
        r=0;
        for(k=0; k<n1; k++) {
            if(p2[c].exp==p1[k].exp) r++;
        }
        if(r==0) {
            p3[i].coef=p2[c].coef;
            p3[i].exp=p2[c].exp;
            i++;
        }
    }
    ordena_poli(p3, (n1+n2));
}

void sub_poli(polinomios *p1, polinomios *p2, polinomios *p3, int n1, int n2) {
    int i, c, r, k;
    for(i=0; i<n1; i++) {
        r=0;
        for(c=0; c<n2; c++) {
            if(p1[i].exp==p2[c].exp) {
                p3[i].coef=p1[i].coef-p2[c].coef;
                p3[i].exp=p1[i].exp;
                r++;
            }
        }
        if(r==0) {
            p3[i].coef=p1[i].coef;
            p3[i].exp=p1[i].exp;
        }
    }
    for(c=0; c<n2; c++) {
        r=0;
        for(k=0; k<n1; k++) {
            if(p2[c].exp==p1[k].exp) r++;
        }
        if(r==0) {
            p3[i].coef=p2[c].coef;
            p3[i].exp=p2[c].exp;
            i++;
        }
    }
    ordena_poli(p3, (n1+n2));
}

void print_poli(polinomios *p, int n) {
    int i;
    for(i=0; i<n; i++) {
        if(p[i].coef>0 && p[i].exp!=0) printf("+%.2lfX^%d", p[i].coef, p[i].exp);
        if(p[i].coef>0 && p[i].exp==0) printf("+%.2lf", p[i].coef);
        if(p[i].coef<0 && p[i].exp==0) {
            printf("%.2lf", p[i].coef);
        }
        if(p[i].coef<0 && p[i].exp!=0) {
            printf("%.2lfX^%d", p[i].coef, p[i].exp);
        }
    }
    printf("\n");
}

void ordena_poli(polinomios *p3, int n) {
    int k2, t;
    polinomios aux;
    for(k2=1; k2<n; k2++) {
        aux=p3[k2];
        for(t=k2; (t>0) && (aux.exp>p3[t-1].exp); t--) {
            p3[t]=p3[t-1];
        }
        p3[t]=aux;
    }
    
}


typedef struct {
    double r, i;
} Complex;

typedef struct {
    Complex r[2];
} RaizEq2;

RaizEq2 calc_RaizEq2(double a, double b, double c);

RaizEq2 calc_RaizEq2(double a, double b, double c) {
    RaizEq2 raiz;
    double delta;
    delta=b*b-4*a*c;
    if(delta==0) {
        raiz.r[0].r=-b/(2*a);
        raiz.r[0].i=0;
        raiz.r[1]=raiz.r[0];
        return raiz;
    }
    else if(delta<0) {
        delta=sqrt(-delta);
        raiz.r[0].r=-b/(2*a);
        raiz.r[0].i=delta/(2*a);
        raiz.r[1].r=-b/(2*a);
        raiz.r[1].i=-delta/(2*a);
        return raiz;
    }
    else {
        delta=sqrt(delta);
        raiz.r[0].r=(-b+delta)/(2*a);
        raiz.r[0].i=0;
        raiz.r[1].r=(-b-delta)/(2*a);
        raiz.r[1].i=0;
        return raiz;
    }
}