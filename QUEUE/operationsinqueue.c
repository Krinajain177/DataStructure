#include <stdio.h>
#define size 5
void enqueue();
void dequeue();
void display();
int arr[size];
int rear=-1;
int front=-1;
int main(){
    int ch;
    printf("Practical 2.1\n");
    printf("ENROLL NO.:230130107052\n");
    printf("Krina Jain\n");
    while(1)
    {
        printf("1.Enqueue operation\n");
        printf("2.Dequeue operation\n");
        printf("3.Display queue\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: printf("END OF PROGRAM\n");
            return 0;
            defult:
            printf("Incorrect choice\n");
        }
    }
}
void enqueue(){
    int insert_item;
    if(rear== size-1)
    printf("Overflow\n");
    else{
        if(front== -1)
        front=0;
        printf("Element to be inserted in the queue:");
        scanf("%d",&insert_item);
        rear=rear+1;
        arr[rear]=insert_item;
    }
}
void dequeue(){
    if(front== -1 ||front>rear){
    printf("Underflow\n");
    return;
    }
    else  
    printf("Element deleted from thr queue:%d\n",arr[front]);
    front=front+1;
}
void display(){
    if(front==-1){
    printf("empty queue\n");
    }
    else
    printf("Queue:\n");
    for(int i=front;i<=rear;i++)
    printf("%d",arr[i]);
    printf("\n");
}
