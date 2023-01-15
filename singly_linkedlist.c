include<stdio.h>
#include<stdlib.h>   
   struct node{
    int data;
    struct node *next;
    };
   struct node *newnode,*newnode1,*newnode2,*newnode3,*head,*ptr,*temp,*temp2,*temp3,*temp4,*temp5,*temp6;
void insert_beg()
{
 newnode1=(struct node*) malloc(sizeof(struct node));
  printf("\n enter the data u want to insert\t:");
   scanf("%d",&newnode1->data);
newnode1->next=head;
head=newnode1;
printf("the data after insertion \n");
temp2=head;
  while(temp2!=0)
  {
   printf("\t%d",temp2->data);
   temp2=temp2->next;
  }
}
void insert_pos()
{
int pos,i=1;
newnode2=(struct node*) malloc(sizeof(struct node));
  printf("\n enter the data u want to insert\t:");
   scanf("%d",&newnode2->data);
printf("enter the position u want  insert data after that : ");
scanf("%d",&pos);
temp3=head;
temp4=head;
while(i<pos)
{
temp3=temp3->next;
i++;
}
newnode2->next=temp3->next;
temp3->next=newnode2;
printf("the data after insertion \n");
temp4=head;
  while(temp4!=0)
  {
   printf("\t%d",temp4->data);
   temp4=temp4->next;
  }

}
void insert_end()
{
 newnode3=(struct node*) malloc(sizeof(struct node));
  printf("\n enter the data u want to insert\t:");
   scanf("%d",&newnode3->data);
temp5=head;
while(temp5->next!=NULL)
{
  temp5=temp5->next;
}
temp5->next=newnode3;
newnode3->next=NULL;
printf("the data after insertion \n");
temp5=head;
  while(temp5!=0)
  {
   printf("\t%d",temp5->data);
   temp5=temp5->next;
  }
}
void delete_beg()
{
  if(head==NULL)
{
 printf("the list has no elements  \n ");
}
else
{
 temp6=head;
head=head->next;
}

printf("the data after insertion \n");
temp2=head;
  while(temp2!=0)
  {
   printf("\t%d",temp2->data);
   temp2=temp2->next;
  }
}
void delete_pos()
{
int pos,i=1;
printf("enter the position u want delete : ");
scanf("%d",&pos);
temp4=head;
ptr=temp4;
while(i<pos)
{ ptr=temp4;
temp4=temp4->next;
i++;
}
ptr->next=temp4->next;

printf("the data after insertion \n");
temp4=head;
  while(temp4!=0)
  {
   printf("\t%d",temp4->data);
   temp4=temp4->next;
  }

}
void delete_end()
{
temp5=head;
while(temp5->next!=NULL)
{
ptr=temp5;
temp5=temp5->next;
}
ptr->next=NULL;
printf("the data after insertion \n");
temp5=head;
  while(temp5!=0)
  {
   printf("\t%d",temp5->data);
   temp5=temp5->next;
  }
}
void search()
{
 int pos=0, data,i=1;
  printf("enter the searching element  :  ");
  scanf("%d",&data);
 ptr=head;
while(ptr!=NULL)
{
 if(data==ptr->data)
{
 pos=1;
printf("the %d found at position %d\n\n ",data,i);
break;
}
else
{
ptr=ptr->next;
}
i++;
}
if(pos==0)
{
printf("\nthe data is not found\n");
}
}

void main()
{
    

   head=NULL; int choice;
while(choice){
   newnode=(struct node*) malloc(sizeof(struct node));
   printf("enter the data\t:");
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   if(head==NULL)
   {
     head=newnode;
     temp=newnode ;
 }
   else
   {
     temp->next=newnode;
     temp=newnode;
   }
   printf("do you want to continue: ");
   scanf("%d",&choice);
}
   temp=head;
printf("the data is \n");
  while(temp!=0)
  {

   printf("\t%d",temp->data);
   temp=temp->next;
  }
int s;
   do{ printf("\n\nChoose\n1.insertion at begining\n2.insertion at positon\n3.insertion at end\n4.deletion at bigining\n5.deleting at position\n6.delete at end\n7.searching\nEneter: ");
    scanf("%d",&s);
    switch(s)
    {
        case 1:insert_beg();
        break;
        case 2:insert_pos();
        break;
        case 3:insert_end();
        break;
        case 4:delete_beg();
        break;
        case 5:delete_pos();
        break;
        case 6:delete_end();
        break; 
        case 7:search();
        break;



     }
}while(s!=0);


}
