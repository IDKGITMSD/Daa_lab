#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    char cityname[50];
    int  coorx;
    int  coory;
    struct node *next;
};

void insert(struct node**head, char newname[],int abcissa,int oordinate){
   
        if(head==NULL){
        struct node *head = (struct node*)malloc(sizeof(struct node));
        strcpy(head->cityname,newname);
        head->coorx=abcissa;
        head->coory=oordinate;
        head->next=NULL;
        }
        else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        strcpy(temp->cityname,newname);
        temp->coorx=abcissa;
        temp->coory=oordinate;
        temp->next=*head;
        *head=temp;
        }
   
}

void display(struct node*head){
    struct node* trav = head;
    while(trav!=NULL){
        printf("the data stored is : cityname- %s x cordinate- %d y cordinate- %d  \n",trav->cityname,trav->coorx,trav->coory);
        trav=trav->next;
    }
}

void searchname(char key[],struct node*head){
        struct node* trav = head;
        int temp = strcmp(trav->cityname,key);
       while(trav!=NULL){ 
        if(temp==0){
            printf("Match found its x coordinate is: %d and y coordinate is: %d ", trav->coorx, trav->coory);
            return ;
        }
        else{
            trav=trav->next;
        }
       }
       printf("Match not found!!");
}

void searchcoor(struct node*head, int keyx,int keyy){
        struct node* trav =head;
        while(trav!=NULL){
            if(keyx==trav->coorx && trav->coory==keyy){
                printf("The name of the City is: %s", trav->cityname);
                return;
            }
            else{
                trav=trav->next;
            }
        }
        printf("Match not found!!");
}

struct node* delname(char key[],struct node*head){
    struct node* trav = head;
    struct node*nexxt = trav->next;
        int temp = strcmp(nexxt->cityname,key);
       while(nexxt!=NULL){ 
        if(temp==0){
            //delete node
           trav->next=nexxt->next;
           free(nexxt);
            return head;
        }
        else{
            trav=trav->next;
            nexxt=nexxt->next;
        }
       }
       printf("Match not found!!");}

struct node * delcoor(struct node*head, int keyx, int keyy){
     struct node* trav =head;
     struct node* nexxt= trav->next;
        while(nexxt!=NULL){
            if(nexxt->coorx==keyx && nexxt->coory==keyy){
                //delete node
                trav->next=nexxt->next;
                free(nexxt);
                return head;
            }
            else{
                trav=trav->next;
                nexxt=nexxt->next;
            }
        }
        printf("Match not found!!");

}

void rad(struct node* head, int X, int Y, int Z){

    struct node* trav= head;
    int a =X-Z;
    int b =Y-Z;
    int c=X+Z;
    int d=Y+Z;
    while(trav!=NULL){
        if(a<=trav->coorx && c>=trav->coorx && b<=trav->coory && d>=trav->coory){
            printf("%s , \t",trav->cityname);
            trav=trav->next;
           }
        else{
           printf("match not found");
        }   
         }
          
    

}


void main(){
    struct node *databs ;
    char srch[50];
    char gname[50];
    int gx,gy,m,usr,srcx,srcy,rx,ry,z;
   
    //prompt user to enter details for new data
    printf("Total number of data entries you wish to do: ");
    scanf("%d", &m);
    for(int i=0;i<m;i++){
    printf("Enter the name of city: ");
    scanf("%s", &gname);
    printf("Enter x-coordinate: ");
    scanf("%d", &gx);
    printf("Enter y-coordinate: ");
    scanf("%d", &gy);
    insert(&databs,gname,gx,gy);
    }
    display(databs);
    printf("Now that the Database is created you can search by name of city or by x,y coordinates \n To search by City name enter 1 \n to search by coordinates enter 2 \n press any other key to skip searching:  ");
    scanf("%d", &usr);
    if(usr==1){
        //search by cityname
        printf("Enter City name: ");
        scanf("%s", &srch);
        searchname(srch,databs);
    }
    else if(usr==2){

        //search by coordinates
        printf("Enter x coordinates: ");
        scanf("%d", &srcx);
        printf("Enter y coordinates: ");
        scanf("%d", &srcy);
        searchcoor(databs,srcx,srcy);
        }
    else{
        
    }
    //delteprompt
    printf("Now that you've searched the database you can delete data by name of city or by x,y coordinates \n To delete by City name enter 1 \n to delete by coordinates enter 2 \n press any other key to skip deleting:  ");
    scanf("%d", &usr);
    if(usr==1){
        //delete by cityname
        printf("Enter City name: ");
        scanf("%s", &srch);
        delname(srch,databs);
    }
    else if(usr==2){

        //delete by coordinates
        printf("Enter x coordinates: ");
        scanf("%d", &srcx);
        printf("Enter y coordinates: ");
        scanf("%d", &srcy);
        delcoor(databs,srcx,srcy);
        }
    else{
        
    }    
    printf("thus after deleting node the database is : \n");
    display(databs);
    printf("To find number of cities in giver radius from a certain point: \n");
    printf("Enter x coordinate: \n ");
    scanf("%d",&rx);
    printf("Enter y coordinate: \n ");
    scanf("%d",&ry);
    printf("Enter distance from them to display all cities in given radius: \n ");
    scanf("%d",&z);
    rad(databs,rx,ry,z);

}