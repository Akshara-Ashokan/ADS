#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_position();
void display();
void search();
void main ()
{
int x;
  printf("\n Enter the number of elements in the list:");
  scanf("%d",&x);
  for(int i=0;i<x;i++)
  {
    insertion_last();
  }


int choice =0;
    while(choice != 8)
    {
        printf("\nChoose one option from the following list ...\n");
        printf("\n1.Display\n2Insertion in biginning\n3.Insert at end\n4.Insertion at position\n5.Deletion at Beginning\n6.Deletion  at last\n7.Deletion at position\n8.Search\n9.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            display();
            break;
            case 2:
            insertion_beginning();
            break;
            case 3:
            insertion_last();
            break;
            case 4:
            insertion_specified();
            break;
            case 5:
            deletion_beginning();
            break;
            case 6:
            deletion_last();
            break;
            case 7:
            deletion_position();
            break;
            case 8:
            search();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf("Please enter valid choice..");
        }
    }
}

void display()
{
    int count=0;
    struct node *ptr;
    printf("\n List ELements\n");
    ptr = head;
    while(ptr != NULL)
    {
        printf("list[%d]:%d\n",count,ptr->data);
        ptr=ptr->next;
        count++;
    }
}

void insertion_beginning()
{
   struct node *ptr;
   int item;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\nOVERFLOW");
   }
   else
   {
    printf("\nEnter Element:");
    scanf("%d",&item);

   if(head==NULL)
   {
       ptr->next = NULL;
       ptr->prev=NULL;
       ptr->data=item;
       head=ptr;
  }
   else
   {
       ptr->data=item;
       ptr->prev=NULL;
       ptr->next = head;
//       head->prev=ptr;
       head=ptr;
   }
}
}

void insertion_last()
{
   struct node *ptr,*temp;
   int item;
   ptr = (struct node *) malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\nOVERFLOW");
   }
   else
   {
       printf("\nEnter value:");
       scanf("%d",&item);
        ptr->data=item;
       if(head == NULL)
       {
           ptr->next = NULL;
           ptr->prev = NULL;
           head = ptr;
       }
       else
       {
          temp = head;
          while(temp->next!=NULL)
          {
              temp = temp->next;
          }
           temp->next = ptr;
          ptr ->prev=temp;
          ptr->next = NULL;
          }
       }
    }


void insertion_specified()
{
   struct node *ptr,*temp;
   int item,loc,i;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\n OVERFLOW");
   }
   else
   {
       temp=head;
       printf("Enter the location:");
       scanf("%d",&loc);
       for(i=1;i<loc;i++)
       {
           temp = temp->next;
           if(temp == NULL)

{
               printf("\n There are less than %d elements", loc);
               return;
           }
       }
       printf("Enter value:");
       scanf("%d",&item);
       ptr->data = item;
       ptr->next = temp->next;
       ptr -> prev = temp;
        temp->next=ptr;

       temp->next->prev=ptr;

       printf("\nnode inserted in %d\n",loc);
   }
}

void deletion_beginning(){
        struct node *ptr;
        int item;
        ptr=(struct node *)malloc(sizeof(struct node));
        if(ptr == NULL){
        printf("underflow");
          }
        else
        {
        ptr=head;
        head=head->next;
        head->prev=NULL;
        free(ptr);
        printf("Element Deleted from Begininng");
        }
}

void deletion_last(){
        struct node *ptr,*temp;
        temp=head;
        ptr=(struct node *)malloc(sizeof(struct node));
        if(ptr == NULL){
        printf("underflow");
          }
        else
        {

        while(temp->next!=NULL)
        {
        temp=temp->next;
        }        
        temp->prev->next=NULL;
          free(temp);
        }

}
void deletion_position(){
        int loc,i;
        struct node *ptr,*temp;
        temp=head;
        ptr=(struct node *)malloc(sizeof(struct node));
        if(ptr == NULL){
        printf("underflow");
          }
        else
        {
          printf("Enter the location:");
       scanf("%d",&loc);
       for(i=1;i<loc;i++)
       {
           temp = temp->next;

       }        
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        }

}
void search()
{
 int pos=0, data,i=1;
struct node *ptr,*temp;
ptr=(struct node *)malloc(sizeof(struct node));
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
