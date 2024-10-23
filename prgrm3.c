#include <stdio.h>
#define max 5
int queue[max];
int front =-1,rear=-1;
void insert(int value){
if(rear==max-1)
{
    printf("Queue overflow !! can't insert %d\n",value);
    return;
}
if(front==-1)
{
    front=0;
}
rear++;
queue[rear]=value;
printf("%d inserted into queue\n",value);

}
void delete()
{
    if(front==-1||front>rear)
    {
        printf("queue underflow  ! can't delete");
        return;

    }
    printf("%d deleted frm queue \n",queue[front]);
    front++;

    if(front>rear)
    {
        front=rear=-1;
    }
}
void display(){
    if(front==-1){
        printf("queue is empty \n");
        return;
    }
    printf("queue elements: \n ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d",queue[i]);
    }
    printf("\n");




}
int main()
{
    int choice,value;
    while(1)
    {
        printf("\n queue operations\n");
        printf("1. insert \n");
        printf("2. delete\n");
        printf("3.display\n");
        printf("4. exit\n");
        printf("enter you choice : ");
        scanf("%d",&choice);
    
    switch (choice)
    {
    case 1:
            printf("enter value to insert : ");
            scanf("%d",&value);
            insert(value);      
            break;
    case 2:
            delete();
            break;
    case 3:
            display();
            break;
    
    case 4:
            printf("exiting ...\n");
            return 0;
    default:
            printf("invalid choice !\n");
    }

}
}
