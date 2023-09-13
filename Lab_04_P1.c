#include<stdio.h>
#include<stdlib.h>
void insert_beg(int item);
struct linklist
{
    int info;
    struct linklist *next;

};

typedef struct linklist Node;

Node *start;
int count=1;

// **************** 1. Create node *********************
Node * create_node()
{
    Node *ptr;
    int no_node,t=0;
    printf("Enter number of nodes\n");
    scanf("%d",&no_node);

    ptr=(Node *)malloc(no_node*sizeof(Node));

    printf("Enter your element\n");
    for(int i=0;i<no_node;i++)
    { 
        scanf("%d",&t);
        insert_beg(t);
        t=0;
        
    }
    
    return ptr;
}

// ******************2. Display list *****************Nayan******
void display()
{
    Node *temp;
    if(start==NULL)
    {
        printf("Lilst is empty\n");
    }
    else{
        temp=start;
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }

}

// ***************** 3. Insert the element at beginning **************
void insert_beg(int item)
{
    Node *ptr,*temp;
    ptr=(Node *)malloc(sizeof(Node));
    ptr->info=item;
    ptr->next=NULL;
    
    if(start == NULL)
    {
        start=ptr;
    }
    else
    {
       temp=start;
       start=ptr;
       ptr->next=temp;
    }
}
// ********************* 4. Insert the element at the end ******************
void insert_end(int item)
{
    Node *ptr,*temp;
    ptr=(Node *)malloc(sizeof(Node));
    ptr->info=item;
    ptr->next=NULL;
    temp=start;

    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next=ptr;
    }
}


// ************** 5. Insert the element at specific postion ***************
void insert_spec_postion(int postion,int item)
{
    Node *ptr,*temp;
    ptr=(Node *)malloc(sizeof(Node));
    ptr->info=item;
    ptr->next=NULL;
    temp=start;

    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
        
        for(int i=0;i<postion;i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

 // ******************** 6. Delete the element from beginning ***********
 void delete1_beg()
{
    Node *temp;
    temp=start;

    if(start==NULL)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        start=temp->next;
        printf("%d \n",temp->info);
        free(temp);
    }
}


 
// *************** 7. Delete the element from the end ****Nayan ********

void delete2_end()
{
    Node *temp,*temp1;
    temp=start;
    if(start==NULL)
    {
        printf("list is empty\n");
        return;
    }
    else{
        while((temp->next)->next != NULL)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=NULL;
        free(temp1);
    }
}
// ************** 8. delete specific location ************
void delete_spec_postion(int position)
{
   Node *temp,*temp1;

   temp=start;
   if(start==NULL)
   {
     printf("List is empty\n");
     return;
   }
   else if(temp->next==NULL)
   {
    temp=start;
    start = NULL;
    printf("%d",temp->info);
    free(temp);
   }
   else
   {
    for(int i=0;i<position;i++)
    {
        temp=temp->next;
    }
    temp1=temp->next;
    temp->next=temp1->next;
    printf("%d \n",temp1->info);
    free(temp1);
   }
}
// ************* 9. count *****************
int count_node()
{
    Node *temp;
    temp=start;
    if(start==NULL)
    {
        //printf("List is empty\n");
        return 0;
    }
    else
    {
        while(temp->next!=NULL)
        {

            count++;
            temp=temp->next;
        }
    }
    //printf("%d\n",count);
    return count;
}

// ************** 10. Search element **************

int search(int ele)
{
    Node *temp;
    temp=start;
    if(start==NULL)
    {
        return 0;
    }
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->info == ele)
            {
                return 1;
            }
            temp=temp->next;
        }
    }
}


int main()
{
  int p,q,choice;
  while(1)
  {
    printf("\n");
    printf("1.Create a Node   \n");
    printf("2.Display the list\n");
    printf("3.Insert the element at beginning\n");
    printf("4.Insert the element at the end\n");
    printf("5.Insert the element at specific position\n");
    printf("6.Delete the element from the beginning\n");
    printf("7.Delete the element from the end\n");
    printf("8.Delete the element from specific position\n");
    printf("9.Count the total number of nodes\n");
    printf("10.Search an element in the linked list \n");
    printf("11.Exit \n");
    
    
    printf("Enter your choice \n");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
    case 1:
    printf("address of node is %u\n",create_node());
    break;

    case 2:
    display();
    break;

    case 3:
    printf("Enter your element\n");
    scanf("%d",&p);
    insert_beg(p);
    break;


    case 4:
    printf("Enter your element\n");
    scanf("%d",&p);
    insert_end(p);
    break;
    
    case 5:
    printf("Enter your postion and element\n");
    scanf("%d%d",&q,&p);
    insert_spec_postion(q,p);
    break;


    case 6:
     delete1_beg();
    break;

    case 7:
    delete2_end();
    break;
    
    case 8:
    printf("Enter your location\n");
    scanf("%d",&p);
    delete_spec_postion(p);
    break;

    case 9:
    printf("no of node is %d\n",count_node());
    break;

    case 10:
     printf("Enter your element\n");
    scanf("%d",&p);
    printf("%d \n",search(p));
    break;

    case 11:
    exit(0);
    break;

    default:
    printf("Invalid \n");
    break;

  }
  }
   return 0;
}
