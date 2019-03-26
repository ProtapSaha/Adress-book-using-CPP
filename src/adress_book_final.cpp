#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct entry
{
    char name[50];
    char nick[50];
    char email[50];
    char address[50];
    char city[50];
    char cont[50];
    char pin[50];
    struct entry *ptr;
    struct entry *next;
}*temp,*node,*p,*r;

typedef struct entry *list;
int isempty();

void newentry()
{
    char a[50],b[50],f[50],g[50],c[50],d[50],e[50];
    int i,k=0;
    printf("***Enter the Datas for the New Entry***\n");
    printf("Full Name      :");
    scanf("%s",&a);
    printf("Nick name :");
    scanf("%s",&b);
    printf("E-mail ID :");
    scanf("%s",&c);
    printf("Address   :");
    scanf("%s",&d);
    printf("City      :");
    scanf("%s",&e);
    printf("Contact No:");
    scanf("%s",&f);
    printf("Post code   :");
    scanf("%s",&g);
    node=(struct entry*)malloc(sizeof(struct entry));

    for(i=0; i<50; i++)
    {
        node->name[i]=' ';
        node->nick[i]=' ';
        node->email[i]=' ';
        node->address[i]=' ';
        node->city[i]=' ';
        node->cont[i]=' ';
        node->pin[i]=' ';
    }
    for(i=0; i<50; i++)
    {
        node->name[i]=a[i];
        node->nick[i]=b[i];
        node->email[i]=c[i];
        node->address[i]=d[i];
        node->city[i]=e[i];
        node->cont[i]=f[i];
        node->pin[i]=g[i];
    }
    if(isempty())
    {
        node->ptr=node->next=NULL;
        p=r=node;
        printf("\t\tYour Entry is Added\t\t\n");
    }
    else
    {
        temp=p;
        while(temp!=NULL)
        {
            i=stricmp(node->name,temp->name);
            if(i<0)
                break;
            else if(i>0)
                temp=temp->next;
            else if(i==0)
            {
                printf("\t\tName Already Exists.Entry cannot be Added\t\t\n");
                k=1;
                break;
            }
        }
        if(k!=1)
        {
            if(temp==p)
            {
                node->ptr=NULL;
                node->next=p;
                p->ptr=node;
                p=node;
                printf("\t\tYour Entry is Added\t\t\n");
            }
            else if(temp==NULL)
            {
                node->next=NULL;
                node->ptr=r;
                r->next=node;
                r=node;
                printf("\t\tYour Entry is Added\t\t\n");
            }
            else
            {
                node->next=temp;
                node->ptr=temp->ptr;
                temp->ptr=node;
                (node->ptr)->next=node;
                printf("\t\tYour Entry is Added\t\t\n");
            }
        }
    }
}

void displayall()
{
    int n=1;
    if(!isempty())
    {
        temp=p;
        while(temp!=NULL)
        {
            printf("[%d] Name:%s Nick Name :%s E-mail ID:%s address:%s City:%s Contact.No:%s Pin code:%s\n",n,temp->name,temp->nick,temp->email,temp->address,temp->city,temp->cont,temp->pin);
            temp=temp->next;
            n++;
        }
    }
    else
        printf("\t\tAddress Book is Empty\t\t");
}

void deletentry(char n[50])
{
    int i;
    if(isempty())
        printf("\t\tAddress  Book is Empty\t\t\n");
    else
    {
        temp=p;
        while(temp!=NULL)
        {
            i=stricmp(temp->name,n);
            if(i==NULL)
            {
                if(p==r)
                {
                    p=r=NULL;
                    printf("\t\tEntry deleted\t\t\n");
                    break;
                }
                else if(temp==p)
                {
                    p=p->next;
                    p->ptr=NULL;
                    printf("\t\tEntry deleted\t\t\n");
                    break;
                }
                else if(temp==r)
                {
                    r=r->ptr;
                    r->next=NULL;
                    printf("\t\tEntry deleted\t\t\n");
                    break;
                }
                else
                {
                    (temp->ptr)->next=temp->next;
                    (temp->next)->ptr=temp->ptr;
                    printf("\t\tEntry deleted\t\t\n");
                    break;
                }
            }
            temp=temp->next;

        }
        if(temp==NULL)
            printf("\t\tNot Found\t\t\n");
    }
}
int isempty()
{
    return p==NULL;
}

void makempty()
{
    p=r=NULL;
    printf("\t\tAddress Book is Emptied\t\t\n");
}
void display(char n[50])
{
    int i,m=1;
    if(isempty())
        printf("\t\tAddress Book is Empty\t\t\n");
    else
    {
        temp=p;
        while(temp!=NULL)
        {
            i=stricmp(temp->name,n);
            if(i==NULL)
            {
                if(m==1)
                    printf("\t\tEntry is found in %dst position\t\t\n",m);
                else if(m==2)
                    printf("\t\tEntry is found in %dnd position\t\t\n",m);
                else if (m==3)
                    printf("\t\tEntry is found in %drd position\t\t\n",m);
                else
                    printf("\t\tEntry is found in %dth position\t\t\n",m);
                printf("\tName:%s Nick Name :%s E-mail ID :%s address:%s City:%s Contact.No:%s Post code:%s\t\n",temp->name,temp->nick,temp->email,temp->address,temp->city,temp->cont,temp->pin);
                break;
            }
            temp=temp->next;
            m++;
        }
        if(temp==NULL)
            printf("\t\tEntry Not Found\t\t\n");

    }
}
void saventry()
{
    char n[50];
    int c;
    printf("Enter the Name of the Person: ");
    scanf("%s",n);
    list t;
    if(isempty())
        printf("\t\tAddress Book is Empty\t\t\n");
    else
    {
        FILE *f;
        f=fopen("entry.txt","a");
        int i;
        t=p;
        while(t!=NULL)
        {
            i=stricmp(t->name,n);
            if(i==0)
            {
                fprintf(f,"%s %s %s %s %s %s %s",t->name,t->nick,t->email,t->address,t->city,t->cont,t->pin);
                printf("\t\tYour Entry Saved\t\t\n");
                printf("\nAdd Another Entry?(1-yes/2-no) : ");
                scanf("%d",&c);
                if(c==1)
                    saventry();
                else if(c==2)
                    break;
            }
            t=t->next;

        }
        fclose(f);
        if(t==NULL)
            printf("\t\tEntry Not Found !!\t\n");
    }

}
void deleteall()
{
    FILE *f;
    f=fopen("entry.txt","w");
    fclose(f);
    printf("***all saved files were delete***");
}
int main()
{
    int p=1,m;
    char n[50];
    while(p!=8)
    {
        printf("\n********************************************************************************#------------------------SIMPLE ADDRESSBOOK------------------------------------#********************************************************************************\n");
        printf("\t\tEnter Your Choice : \n");
        printf("");
        printf("\t\t\t(1)-New Entry\n");
        printf("");
        printf("\t\t\t(2)-Display an Entry\n");
        printf("");
        printf("\t\t\t(3)-Delete an Entry\n");
        printf("");
        printf("\t\t\t(4)-Display all Entries\n");
        printf("");
        printf("\t\t\t(5)-Empty the book\n");
        printf("");
        printf("\t\t\t(6)-Save Entry\n");
        printf("");
        /*printf("\t\t\t(7)-Load Entries\n");
        printf("");*/
        printf("\t\t\t(7)-Delete All Saved Files\n");
        printf("");
        printf("\t\t\t(8)-End\n");
        printf("");
        printf("********************************************************************************");
        printf("");
        scanf("%d",&p);
        switch(p)
        {
        case 1:
            newentry();
            getch();
            break;
        case 2:
            printf("Enter the Name of the Person to Display : ");
            printf("");
            scanf("%s",&n);
            display(n);
            getch();
            break;
        case 3:
            printf("Enter the Name of the Person to Delete : ");
            printf("");
            scanf("%s",&n);
            deletentry(n);
            getch();
            break;
        case 4:
            displayall();
            getch();
            break;
        case 5:
            makempty();
            getch();
            break;
        case 6:
            saventry();
            getch();
            break;
        case 7:
            deleteall();
            getch();
            break;
        case 8:
            printf("Program Ends Here.Thank You!!!");
            printf("");
            getch();
            break;
        default:
            printf("Enter a Valid Choice from 1-8 only");
            printf("");
            getch();
            break;
        }
    }
    getch();
}
