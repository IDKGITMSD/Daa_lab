#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *node){

    while(node!= NULL ){
        printf("%d",node->data);
        node = node->next;
    }
    printf("\n");
}
void scannur(struct Node *node){
    for(int i =1;i<= 3 ;i++){
    printf("Enter %d digit : ",i );    
    scanf("%d",&node->data);
    node = node->next ;
    }
}



int main(){
    // allocating node pointers
    struct Node *head = NULL;
    struct Node *node2 = NULL;
    struct Node *node3 = NULL;
    struct Node *node4 = NULL;

// allocating node memory heap
    head = (struct Node*)malloc(sizeof(struct Node)) ;  
    node2 = (struct Node*)malloc(sizeof(struct Node)) ;  
    node3 = (struct Node*)malloc(sizeof(struct Node)) ;  
    node4 = (struct Node*)malloc(sizeof(struct Node)) ; 

// joining nodes
    head->data = 0 ;
    head-> next = node2;

    node2->data = 0;
    node2-> next = node3;

    node3 -> data = 0;
    node3 -> next = NULL;

    node4 -> data = 0;
    node4-> next = NULL;


    // second linked list 
     struct Node *ahead = NULL;
    struct Node *anode2 = NULL;
    struct Node *anode3 = NULL;
    struct Node *anode4 = NULL;


    ahead = (struct Node*)malloc(sizeof(struct Node)) ;  
    anode2 = (struct Node*)malloc(sizeof(struct Node)) ;  
    anode3 = (struct Node*)malloc(sizeof(struct Node)) ;  
    anode4 = (struct Node*)malloc(sizeof(struct Node)) ; 


    ahead->data = 0;
    ahead-> next = anode2;

    anode2->data = 0;
    anode2-> next = anode3;

    anode3 -> data = 0;
    anode3 -> next = NULL;

    anode4 -> data = 0;
    anode4-> next = NULL;
   
    scannur(head);
    scannur(ahead);

   // display(head);
   // display(ahead);
// to store first number for linked list head
    int n1 ;

   int dig3 = node3-> data;
   int dig2 = node2-> data;
   int dig1 = head->data;

   n1 = 100*dig3 + 10*dig2 + dig1 ;
   printf("\n The first three digit number is: %d",n1);

// to store second number for linked list ahead
 int n2 ;

   int adig3 = anode3-> data;
   int adig2 = anode2-> data;
   int adig1 = ahead->data;

   n2 = 100*adig3 + 10*adig2 + adig1 ;
   printf(" \n The second three digit number is: %d",n2);   

    int Sum = n1 + n2 ;
    printf(" \n The Sum of two inputted numbers is %d",Sum);

// separating digits

    int fdig1;
    int fdig2;
    int fdig3;
    int fdig4;

    fdig1 = Sum%10 ;
    fdig2 = (Sum%100-fdig1)/10;
    fdig3 = (Sum%1000-fdig2-fdig1)/100;
    fdig4 = (Sum%10000-fdig3-fdig2-fdig1)/1000;
    printf("\n the digits are 1: %d 2: %d 3: %d 4: %d",fdig4,fdig3,fdig2,fdig1);
// making a new linked list for storing Sum

 // allocating node pointers
    struct Node *fhead = NULL;
    struct Node *fnode2 = NULL;
    struct Node *fnode3 = NULL;
    struct Node *fnode4 = NULL;

// allocating node memory heap
    fhead = (struct Node*)malloc(sizeof(struct Node)) ;  
    fnode2 = (struct Node*)malloc(sizeof(struct Node)) ;  
    fnode3 = (struct Node*)malloc(sizeof(struct Node)) ;  
    fnode4 = (struct Node*)malloc(sizeof(struct Node)) ; 

// joining nodes
    fhead->data = 0 ;
    fhead-> next = fnode2;

    fnode2->data = 0;
    fnode2-> next = fnode3;

    fnode3 -> data = 0;
    fnode3 -> next = fnode4;

    fnode4 -> data = 0;
    fnode4-> next = NULL;
    
    fhead->data=fdig4;
    fnode2->data=fdig3;
    fnode3->data=fdig2;
    fnode4->data =fdig1;
    printf("\n the linked list represenatation is:");
    display(fhead);
    return 0;


}
