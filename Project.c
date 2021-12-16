#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define N 0


struct item_list
{
    char item[20];
    int quantity;
    double price;
    struct item_list *next;
};


struct sales_list
{
    char user[20];
    char pass[20];
    char name[20];
    char num[20];
    char email[20];
    struct sales_list *nex;
};


typedef struct item_list node;
typedef struct sales_list nod;
FILE *fp,*hp,*f1,*f2,*f3,*f4,*f5,*f6,*f7;


int menu();
void create(node *p);
void insert();
void display();
int rem();
int lessen_amount();
void load();
void refresh();
void swap(int x,char tmp[]);
void cross(char tmp[]);
void bill(char item[20],int quantity,double price);
void sales_create(nod *p);
void sale_remove();
void sale_add();
void sales_display();
int sales_menu();
void sort();


int main()
{
    node *start;
    nod *start1;
    int choice,x,choice1,n,q,r,e,f,quantity,i,a=0,c;
    double price;
    char temp[20],item[20],u[20],p[20];
    char password[10],pass1[20],newpass[20],newpass1[20];
    char username[20],buy[20];
    char user[20],pass[20],name[20],num[20],email[20];
    char ch,b;

    while(1)
    {
        n=0;
        while(1)
        {
            printf("\n\n%40s\n%38s\n\n%42s","Welcome","to","STOP & SHOP");
            printf("\n\n\n\n\n\n\t\t\tlog in as: 1.Manager\n\t\t\t\t   2.Salesman\n");
            scanf("%d",&n);
            if(n<1 || n>2)
            {
                printf("Invalid input\n");
                for(r=1; r<=3; r++)
                {
                    for(q=0; q<=100000000; q++);
                    for(q=0; q<=100000000; q++);
                    for(q=0; q<=100000000; q++);
                }
                system("cls");
            }
            else break;
            fflush(stdin);
        }

        fp=fopen("hakao.txt","w");
        fclose(fp);

        system("cls");
        if(n==1)
        {
            while(1)
            {
                i=0;
                fflush(stdin);
                printf("\n\n\n\n\n\n\n\n\n\t\t\tUsername: ");
                gets(username);
                fflush(stdin);
                printf("\n\t\t\tPassword: ");
                while( (ch=getch()) != 13)
                {
                    password[i]=ch;
                    i++;
                    printf("*");
                    fflush(stdin);
                }

                password[i]='\0';
                fp=fopen("pass.txt","r");
                fscanf(fp," %[^\n] %[^\n]",u,p);
                fclose(fp);

                if (strcmp(password,p)==0 && strcmp(username,u)==0) break;
                else
                {
                    system("cls");
                    printf("\n\tUsername or password did not match. Please try again.\n\n");
                    n=0;
                }
            }

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",177);
            }
            system("cls");

            do
            {
                printf("\n\n%40s\n%38s\n\n%42s","Welcome","to","STOP & SHOP");
                printf("\n\n\n\n\n\n\t\t\t 1.Product Management\n\t\t\t 2.Salesman Managemant\n\t\t\t 3.Change Password\n\t\t\t 4.Log Out\n\n");
                scanf("%d",&choice1);

                if(choice1<1 || choice1>4)
                {
                    printf("Invalid input\n");
                    for(r=1; r<=3; r++)
                    {
                        for(q=0; q<=100000000; q++);
                        for(q=0; q<=100000000; q++);
                        for(q=0; q<=100000000; q++);
                    }
                    system("cls");
                    fflush(stdin);
                }
                else if(choice1==1)
                {
                    while(1)
                    {
                        system("cls");
                        load();
                        sort();
                        fp=fopen("inventory.txt","r");
                        display();
                        choice=menu();

                        if(choice<1 || choice>4)
                        {
                            printf("Invalid input\n");
                            for(r=1; r<=3; r++)
                            {
                                for(q=0; q<=100000000; q++);
                                for(q=0; q<=100000000; q++);
                                for(q=0; q<=100000000; q++);
                            }
                            system("cls");
                            fflush(stdin);
                            break;
                        }
                        else if (choice==1)
                        {
                            free(start);
                            start= (node *) malloc(sizeof(node));
                            fp=fopen("inventory.txt","w");
                            create(start);
                            fclose(fp);
                            printf("\n");
                            load();
                            sort();
                            fp=fopen("inventory.txt","r");
                            display();
                        }
                        else if (choice==2)
                        {
                            insert();
                            printf("\n");
                            load();
                            sort();
                            fp=fopen("inventory.txt","r");
                            display();
                        }
                        else if (choice==3)
                        {
                            x=rem();
                            if(x==0)
                            {
                                printf("\n");
                                load();
                                sort();
                                fp=fopen("inventory.txt","r");
                                display();
                            }
                        }
                        else if(choice==4)
                        {
                            system("cls");
                            fflush(stdin);
                            break;
                        }
                        fflush(stdin);
                    }
                }
                else if(choice1==2)
                {
                    while(1)
                    {
                        system("cls");
                        refresh();

                        system("cls");
                        printf("\n\n\n\t\t\t STOP & SHOP\n\n\t\t\tEmployee List\n");
                        printf("\t\t-----------------------------\n");
                        printf("\t\t-----------------------------\n\n\n");
                        sales_display();
                        choice=sales_menu();

                        if(choice<1 || choice>4)
                        {
                            printf("Invalid input\n");
                            for(r=1; r<=3; r++)
                            {
                                for(q=0; q<=100000000; q++);
                                for(q=0; q<=100000000; q++);
                                for(q=0; q<=100000000; q++);
                            }
                            system("cls");
                            fflush(stdin);
                            break;
                        }
                        else if (choice==1)
                        {
                            free(start1);
                            start1= (nod *) malloc(sizeof(nod));
                            fp=fopen("sales.txt","w");
                            sales_create(start1);
                            fclose(fp);
                            printf("\n");
                            sales_display();
                        }
                        else if (choice==3)
                        {
                            sale_remove();
                            system("cls");
                            printf("\n");
                            sales_display();
                        }
                        else if (choice==2)
                        {
                            sale_add();
                            system("cls");
                            printf("\n");
                            sales_display();
                        }
                        else if(choice==4)
                        {
                            system("cls");
                            fflush(stdin);
                            break;
                        }
                        fflush(stdin);
                    }
                }
                else if(choice1==3)
                {
                    while(1)
                    {
                        system("cls");
                        fflush(stdin);
                        printf("\n\n\n\n\n\t\t\tEnter current password: ");
                        i=0;
                        while( (ch=getch()) != 13)
                        {
                            pass1[i]=ch;
                            i++;
                            printf("*");
                            fflush(stdin);
                        }
                        pass1[i]='\0';
                        fflush(stdin);
                        i=0;
                        printf("\n\t\t\tEnter new password: ");
                        while( (ch=getch()) != 13)
                        {
                            newpass[i]=ch;
                            i++;
                            printf("*");
                            fflush(stdin);
                        }
                        newpass[i]='\0';
                        i=0;
                        fflush(stdin);
                        printf("\n\t\t\tConfirm new password: ");
                        while( (ch=getch()) != 13)
                        {
                            newpass1[i]=ch;
                            i++;
                            printf("*");
                            fflush(stdin);
                        }
                        newpass1[i]='\0';
                        if(strcmp(pass1,password)==0 && strcmp(newpass,newpass1)==0)
                        {
                            strcpy(p,newpass);

                            fp=fopen("pass.txt","w");
                            fprintf(fp,"%s\n%s",u,p);
                            fclose(fp);

                            printf("\n\n\t\t*Your password has been changed succesfully*\n\n");
                            for(r=1; r<=5; r++)
                            {
                                for(q=0; q<=100000000; q++);
                                for(q=0; q<=100000000; q++);
                                for(q=0; q<=100000000; q++);
                            }
                            system("cls");
                            fflush(stdin);
                            break;
                        }
                        else
                        {
                            printf("\n\nSorry, Wrong password");
                            for(r=1; r<=5; r++)
                            {
                                for(q=0; q<=150000000; q++);
                                for(q=0; q<=150000000; q++);
                                for(q=0; q<=150000000; q++);
                            }
                        }
                    }
                }
                else if(choice1==4)
                {
                    system("cls");
                    printf("\n\n\n\n\n\t\t\tLogging out");
                    for(r=1; r<=5; r++)
                    {
                        for(q=0; q<=150000000; q++);
                        printf(".");
                    }
                    system("cls");
                    fflush(stdin);
                    break;
                }
                fflush(stdin);
            }
            while(1);
        }
        else if(n==2)
        {
            while(1)
            {
                i=0;
                n=0;
                fflush(stdin);
                printf("\n\n\n\n\n\n\n\n\n\t\t\tUsername: ");
                gets(username);
                fflush(stdin);
                printf("\n\t\t\tPassword: ");
                while( (ch=getch()) != 13)
                {
                    password[i]=ch;
                    i++;
                    printf("*");
                    fflush(stdin);
                }

                password[i]='\0';
                f7=fopen("sales.txt","r");
                while(fscanf(f7," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]",user,pass,name,num,email)!=EOF)
                {
                    if(strcmp(password,pass)==0 && strcmp(user,username)==0)
                    {
                        n=1;
                        break;
                    }
                }

                if(n==0)
                {
                    system("cls");
                    printf("\n\tUsername or password did not match. Please try again.\n\n");
                }
                else if(n==1) break;
            }

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",177);
            }
            system("cls");

            printf("\n\n%40s\n%38s\n\n%42s","Welcome","to","STOP & SHOP");
            printf("\n\n\n\t\t\t1.Product Management\n\t\t\t2.Log Out\n\n");
            scanf("%d",&choice1);
            fflush(stdin);

            while(1)
            {
                if(choice1<1 || choice1>2)
                {
                    printf("Invalid input\n");
                    for(r=1; r<=3; r++)
                    {
                        for(q=0; q<=100000000; q++);
                        for(q=0; q<=100000000; q++);
                        for(q=0; q<=100000000; q++);
                    }
                    system("cls");
                    fflush(stdin);
                    printf("\n\n%40s\n%38s\n\n%42s","Welcome","to","STOP & SHOP");
                    printf("\n\n\n\t\t\t1.Product Management\n\t\t\t2.Log Out\n\n");
                    scanf("%d",&choice1);
                    fflush(stdin);
                }
                else if(choice1==1)
                {
                    system("cls");
                    load();
                    sort();
                    fp=fopen("inventory.txt","r");
                    display();

                    while(1)
                    {
                        c=lessen_amount();
                        printf("\n");
                        load();
                        sort();
                        fp=fopen("inventory.txt","r");
                        display();
                        if(c==0)
                        {
                            printf("\n\n**Your item has been added to the list**\n\n");
                            a++;
                            printf("Would you like to add anything else to the list?Y/N\n\n");
                            ch=getch();
                            while(1)
                            {
                                if(ch=='N' || ch=='n' || ch=='Y' || ch=='y') break;
                                else
                                {
                                    printf("\aWrong input.Would you like to buy anything else?Y/N\n\n");
                                    ch=getch();
                                }
                            }
                            if(ch=='N' || ch=='n') break;
                        }
                    }

                    system("cls");
                    printf("Please enter the customer's name: ");
                    fflush(stdin);
                    gets(buy);
                    system("cls");
                    double sum=0;
                    refresh();

                    time_t now = time(NULL);
                    struct tm *t = localtime(&now);

                    printf("\n\n%37s","STOP & SHOP\n");
                    printf("%36s\n","-----------");
                    printf("\n\n                   *****Money Receipt*****\n\n\n");
                    printf("Buyer's Name: %s\n\n",buy);
                    printf("Date: %.2d.%.2d.%d\n",t->tm_mday, t->tm_mon+1, t->tm_year+1900);
                    printf("Time: %.2d:%.2d:%.2d\n\n",t->tm_hour,t->tm_min,t->tm_sec);

                    printf("Items\t                        Quantity\t Price\n");
                    printf("---------------------------------------------------------------\n");
                    printf("---------------------------------------------------------------\n");

                    f1=fopen("hakao.txt","r");
                    f2=fopen("new.txt","w");
                    char x[20],ch='a';
                    while(1)
                    {
                        rewind(f1);
                        while(fscanf(f1," %[^\n]%d %lf\n",item,&quantity,&price)!=EOF)
                        {
                            if(ch==item[0]) fprintf(f2,"%s\n%d\n%lf\n",item,quantity,price);
                        }
                        ch++;
                        if(ch=='z') break;
                    }
                    fclose(f1);
                    fclose(f2);
                    f1=fopen("hakao.txt","w");
                    f2=fopen("new.txt","r");
                    while(fscanf(f2," %[^\n]%d %lf\n",item,&quantity,&price)!=EOF)
                        fprintf(f1,"%s\n%d\n%lf\n",item,quantity,price);
                    fclose(f1);
                    fclose(f2);


                    hp=fopen("hakao.txt","r");
                    while(fscanf(hp," %[^\n]%d %lf",item,&quantity,&price)!=EOF)
                    {
                        printf(item);
                        f=strlen(item);
                        f=32-f;
                        for (e=0; e<f; e++)
                            printf(" ");
                        printf("%8d\t %.2lf\n",quantity,price*quantity);
                        sum=sum+price*quantity;
                    }
                    printf("\n\n---------------------------------------------------------------\n");
                    printf("Total                                            %.2lf\n",sum);
                    printf("\n\nThank you for shopping with us.\1\1\1\n");
                    fclose(hp);
                    printf("\n\nPress any key to continue\n");
                    if ((b=getch())>0) system("cls");
                    fflush(stdin);

                    printf("\n\n%40s\n%38s\n\n%42s","Welcome","to","STOP & SHOP");
                    printf("\n\n\n\t\t\t1.Product Management\n\t\t\t2.Log Out\n\n");
                    scanf("%d",&choice1);
                    fflush(stdin);
                }
                else if(choice1==2)
                {
                    system("cls");
                    printf("\n\n\n\n\n\t\t\tLogging out");
                    for(r=1; r<=5; r++)
                    {
                        for(q=0; q<=150000000; q++);
                        printf(".");
                    }
                    system("cls");
                    fflush(stdin);
                    break;
                }
                fflush(stdin);
            }
        }
    }
    return 0;
}



int menu()
{
    int a,q,r;
    while(1)
    {
        printf("\n\n\t\t\t");
        printf("What do you want to do?\n\t\t\t1.Create a new list\n\t\t\t2.Add an item\n\t\t\t3.Remove an item\n\t\t\t4.Go to main menu\n\n");
        scanf("%d",&a);
        if(a<1 || a>4)
        {
            printf("Invalid input\n");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                for(q=0; q<=100000000; q++);
            }
            system("cls");
            fflush(stdin);
            load();
            fp=fopen("inventory.txt","r");
            display();
        }
        else break;
    }
    return a;
}




int sales_menu()
{
    int a,q,r;
    while(1)
    {
        printf("\n\n\t\t\t");
        printf("What do you want to do?\n\t\t\t1.Create a new employee list\n\t\t\t2.Add a new employee\n\t\t\t3.Remove an employee\n\t\t\t4.Go to main menu\n\n");
        scanf("%d",&a);
        if(a<1 || a>4)
        {
            printf("Invalid input\n");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                for(q=0; q<=100000000; q++);
            }
            system("cls");
            fflush(stdin);
            printf("\n\n");
            printf("\n\n\n\t\t\t STOP & SHOP\n\n\t\t\tEmployee List\n");
            printf("\t\t-----------------------------\n");
            printf("\t\t-----------------------------\n\n\n");
            sales_display();
        }
        else break;
    }
    return a;
}




void create(node *p)
{
    char s[15];
    fflush(stdin);
    printf("\n\t\t\t*(Type 'end' to finish)*\n");
    printf("Enter item name: ");
    gets(p->item);
    if (strcmp(p->item,"end")==0) p->next=N;
    else
    {
        fflush(stdin);
        printf("Enter quantity: ");
        scanf("%d",&p->quantity);
        fflush(stdin);
        printf("Enter price: ");
        scanf("%lf",&p->price);
        fprintf(fp,"%s\n%d\n%lf\n",p->item,p->quantity,p->price);
        p->next=(node *) malloc(sizeof(node));
        create(p->next);
    }
    system("cls");
    return;
}



void display()
{
    int a,i,quantity;
    char item[20];
    double price;
    while(fscanf(fp," %[^\n]%d %lf",item,&quantity,&price)!=EOF)
    {
        a=strlen(item);
        a=32-a;
        printf(item);
        for (i=0; i<a; i++)
            printf(" ");
        printf("%8d\t %.2lf\n",quantity,price);
    }
    fclose(fp);
}



void insert()
{
    int x;
    double y;
    char newitem[20];

    fflush(stdin);
    printf("Enter the new item: ");
    gets(newitem);
    fflush(stdin);
    printf("Enter quantity: ");
    scanf("%d",&x);
    printf("Enter price: ");
    scanf("%lf",&y);
    fflush(stdin);

    f5=fopen("inventory.txt","a");
    fprintf(f5,"%s\n%d\n%lf\n",newitem,x,y);
    fclose(f5);
    system("cls");
    refresh();
}




void load()
{
    printf("\n\n");
    printf("%35s","STOP & SHOP\n\n");
    printf("                  *****Inventory*****\n\n\n");
    printf("Items\t                        Quantity\t Price\n");
    printf("---------------------------------------------------------------\n");
    printf("---------------------------------------------------------------\n");
}




int lessen_amount()
{
    void cross(char tmp[]);
    int a,q,r,quantity,b=0,d=1;
    double c,price;
    char temp[20],item[20];
    f5=fopen("inventory.txt","r");


    printf("\n\nWhich item would you like to buy?\n\n");
    fflush(stdin);
    printf("Enter item name: ");
    gets(temp);
    fflush(stdin);
    while(fscanf(f5," %[^\n] %d %lf",item,&quantity,&price)!=EOF)
    {
        if(strcmp(temp,item)==0)
        {
            d=0;
            break;
        }
    }

    if(d==1)
    {
        printf("\n\n\n\t\t\tSorry, the item is not on the list\n");
        for(r=1; r<=3; r++)
        {
            for(q=0; q<=100000000; q++);
            for(q=0; q<=100000000; q++);
            for(q=0; q<=100000000; q++);
        }

        refresh();
        system("cls");
        fclose(f5);
        b=1;
    }
    else if(d==0)
    {
        printf("Enter total amount: ");
        scanf("%d",&a);
        fflush(stdin);


        rewind(f5);
        while(fscanf(f5," %[^\n] %d %lf",item,&quantity,&price)!=EOF)
        {
            if(strcmp(item,temp)==0)
            {
                if(a>quantity)
                {
                    b=1;
                    printf("Sorry,the store didn't have that much in the first place\n");
                    for(r=1; r<=20; r++)
                    {
                        for(q=0; q<=50000000; q++);
                    }
                    system("cls");
                }
                else if (a==quantity)
                {
                    cross(temp);
                    bill(item,a,price);
                    break;
                }
                else
                {
                    quantity=quantity-a;
                    bill(item,a,price);
                    swap(quantity,temp);
                    break;
                }
            }
        }
        fclose(f5);
        system("cls");
        refresh();
    }
    return b;
}




void refresh()
{
    int q,r;
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\tRefreshing");
    for(r=1; r<=3; r++)
    {
        for(q=0; q<=100000000; q++);
        printf(".");
    }
    printf("\n\t\t\t");
    for(r=1; r<=14; r++)
    {
        for(q=0; q<=50000000; q++);
        printf("%c",177);
    }
    system("cls");
}



int rem()
{
    void cross(char tmp[]);
    int a,q,r,quantity,b=0,d=1;
    double c,price;
    char temp[20],item[20];
    f5=fopen("inventory.txt","r");


    printf("\n\nWhich item would you like to remove?\n\n");
    fflush(stdin);
    printf("Enter item name: ");
    gets(temp);
    fflush(stdin);
    while(fscanf(f5," %[^\n] %d %lf",item,&quantity,&price)!=EOF)
    {
        if(strcmp(temp,item)==0)
        {
            d=0;
            break;
        }
    }

    if(d==1)
    {
        printf("\n\n\n\t\t\tSorry, the item is not on the list\n");
        for(r=1; r<=3; r++)
        {
            for(q=0; q<=100000000; q++);
            for(q=0; q<=100000000; q++);
            for(q=0; q<=100000000; q++);
        }

        refresh();
        system("cls");
        fclose(f5);
        b=1;
    }
    else if(d==0)
    {
        printf("Enter total amount: ");
        scanf("%d",&a);
        fflush(stdin);


        rewind(f5);
        while(fscanf(f5," %[^\n] %d %lf",item,&quantity,&price)!=EOF)
        {
            if(strcmp(item,temp)==0)
            {
                if(a>quantity)
                {
                    b=1;
                    printf("Sorry,the store didn't have that much in the first place\n");
                    for(r=1; r<=20; r++)
                    {
                        for(q=0; q<=50000000; q++);
                    }
                    system("cls");
                }
                else if (a==quantity)
                {
                    cross(temp);
                    bill(item,a,price);
                    break;
                }
                else
                {
                    quantity=quantity-a;
                    bill(item,a,price);
                    swap(quantity,temp);
                    break;
                }
            }
        }
        fclose(f5);
        system("cls");
        refresh();
    }
    return b;
}



void swap(int x,char tmp[])
{
    char item[20];
    int quantity;
    double price;
    hp=fopen("inventory.txt","r");
    f1=fopen("temp.txt","w");
    while(fscanf(hp," %[^\n]%d %lf\n",item,&quantity,&price)!=EOF)
    {
        if(strcmp(tmp,item)==0) fprintf(f1,"%s\n%d\n%lf\n",item,x,price);
        else fprintf(f1,"%s\n%d\n%lf\n",item,quantity,price);
    }
    fclose(hp);
    fclose(f1);
    hp=fopen("inventory.txt","w");
    f1=fopen("temp.txt","r");
    while(fscanf(f1," %[^\n]%d %lf\n",item,&quantity,&price)!=EOF)
        fprintf(hp,"%s\n%d\n%lf\n",item,quantity,price);
    fclose(f1);
    fclose(hp);
}



void cross(char tmp[])
{
    char item[20];
    int quantity;
    double price;
    hp=fopen("inventory.txt","r");
    f1=fopen("temp.txt","w");
    while(fscanf(hp," %[^\n]%d %lf\n",item,&quantity,&price)!=EOF)
        if(strcmp(tmp,item)!=0) fprintf(f1,"%s\n%d\n%lf\n",item,quantity,price);
    fclose(hp);
    fclose(f1);
    hp=fopen("inventory.txt","w");
    f1=fopen("temp.txt","r");
    while(fscanf(f1," %[^\n] %d %lf\n",item,&quantity,&price)!=EOF)
        fprintf(hp,"%s\n%d\n%lf\n",item,quantity,price);
    fclose(f1);
    fclose(hp);
}


void bill(char item[20],int quantity,double price)
{
    f6=fopen("hakao.txt","a");
    fprintf(f6,"%s\n%d %.2lf\n",item,quantity,price);
    fclose(f6);
}




void sales_create(nod *p)
{
    char s[15];
    fflush(stdin);
    printf("\n\t\t\t*(Type 'end' to finish)*\n");
    printf("Enter user name: ");
    gets(p->user);
    if (strcmp(p->user,"end")==0) p->nex=N;
    else
    {
        fflush(stdin);
        printf("Enter Password: ");
        gets(p->pass);
        fflush(stdin);
        fflush(stdin);
        printf("Enter Name: ");
        gets(p->name);
        fflush(stdin);
        printf("Enter Mobile Number: ");
        gets(p->num);
        fflush(stdin);
        printf("Enter E-mail adress: ");
        gets(p->email);
        fflush(stdin);
        fprintf(fp,"%s\n%s\n%s\n%s\n%s\n",p->user,p->pass,p->name,p->num,p->email);
        p->nex=(nod *) malloc(sizeof(nod));
        sales_create(p->nex);
    }
    system("cls");
    return;
}




void sale_remove()
{
    char s[20],user[20],pass[20],name[20],num[20],email[20];
    fflush(stdin);
    printf("Enter the username of the salesman you want to remove: ");
    gets(s);
    fflush(stdin);
    fp=fopen("sales.txt","r");
    f5=fopen("salestmp.txt","w");
    while(fscanf(fp," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]",user,pass,name,num,email)!=EOF)
    {
        if(strcmp(user,s)!=0) fprintf(f5,"%s\n%s\n%s\n%s\n%s\n",user,pass,name,num,email);
    }
    fclose(f5);
    fclose(fp);
    fp=fopen("sales.txt","w");
    f5=fopen("salestmp.txt","r");
    while(fscanf(f5," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]",user,pass,name,num,email)!=EOF)
    {
        fprintf(fp,"%s\n%s\n%s\n%s\n%s\n",user,pass,name,num,email);
    }
    fclose(f5);
    fclose(fp);
    system("cls");
}




void sale_add()
{
    char user[20],pass[20],name[20],num[20],email[20];

    fflush(stdin);
    printf("Enter the name: ");
    gets(name);
    fflush(stdin);
    printf("Enter username: ");
    gets(user);
    fflush(stdin);
    printf("Enter Password: ");
    gets(pass);
    fflush(stdin);
    printf("Enter Mobile Number: ");
    gets(num);
    fflush(stdin);
    printf("Enter E-mail adress: ");
    gets(email);
    fflush(stdin);

    fp=fopen("sales.txt","a");
    fprintf(fp,"%s\n%s\n%s\n%s\n%s\n",user,pass,name,num,email);
    fclose(fp);
    system("cls");
}




void sales_display()
{
    char user[20],pass[20],name[20],num[20],email[20];
    fp=fopen("sales.txt","r");
    while(fscanf(fp," %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]",user,pass,name,num,email)!=EOF)
    {
        printf("Name: %s\n",name);
        printf("Username: %s\n",user);
        printf("Password: %s\n",pass);
        printf("Mobile: %s\n",num);
        printf("Email: %s\n",email);
        printf("\n\n");
    }
    fclose(fp);
}




void sort()
{
    char item[20];
    int quantity;
    double price;
    f1=fopen("inventory.txt","r");
    f2=fopen("new.txt","w");
    char x[20],ch='A';
    while(1)
    {
        rewind(f1);
        while(fscanf(f1," %[^\n]%d %lf\n",item,&quantity,&price)!=EOF)
        {
            if(ch==item[0]) fprintf(f2,"%s\n%d\n%lf\n",item,quantity,price);
        }
        ch++;
        if(ch=='Z') break;
    }
    fclose(f1);
    fclose(f2);
    f1=fopen("inventory.txt","w");
    f2=fopen("new.txt","r");
    while(fscanf(f2," %[^\n]%d %lf\n",item,&quantity,&price)!=EOF)
        fprintf(f1,"%s\n%d\n%lf\n",item,quantity,price);
    fclose(f1);
    fclose(f2);
}
