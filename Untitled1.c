#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* hard_code[]={"books","dairymilk","kit-kat","dairymilksilk","snikers","perk","milkybar","barone","galaxy","ferrorochaer","bournville","temptation","kurkurechips","bingochips","MTRchips","cheetoschips","nachoschips","layschips","laysmaxcrunchchips","bakedchips","puffcorn","doublechocochips","pillsburreychocochips","pillsburreychococookiecakechocochips","dominoscookiechocochips","hideandseekcookiechocochips ","apisbakersfactoryoatsandrasinscookiechocochips","nabiscooreominichocochips ","sunfeastdarkfantasychocochips","britanialitleheartschocochips","baurbounchocochips","appleChillifruits","appleDeliciousfruits","bananaChandrafruits","chainBerryfruits","chicco[Sapota]fruits","grapesBloreBluefruits","grapesFlamefruits ","guavafruits","indianblackglobegrapesfruits","mangoalphansfruits","mangoBadamifruits","Mosambi fruits","Orange fruits","Papaya Nati fruits","Pineapple  fruits","Pomegranate Bhagav fruits","Straw Berry  fruits","Watermellon fruits","Kitchen Scissors - Vegetable and Meat Cutter, Black stationary","Carbons  (Pencil)       Kores stationary","Spring Files stationary","Cello tape  stationary","Binding Roll stationary","Foarm Tape (Small) stationary","White Tape stationary","4 Line Books stationary","100 Pg Ruled book stationary","Squire Book stationary","Full scape sheets stationary","Graph Book (Full scape) stationary","Project Book stationary","Drawing Book  stationary","Practicle sheet stationary","Diary stationary","World Map stationary","Colouring Book stationary","CD Cover stationary","Long Book Prime v","Pen ( stationary","Permanent Marker stationary","Gel Pen Renolds stationary","Clay Packets stationary","Rangeela Colours stationary","Nataraj Pencil stationary","Camline Compass stationary","Flair Glitter Pen stationary","Fevicol Stips stationary","Class Mate Book stationary","Hightligther stationary","Crayons stationary","Curry leave vegetables","Drumstik  vegetables","Garlic vegetables",};

int found(char product_name[])
{
	//printf("came here\n");
	int flag=0;
	int p=0;
	for(;p<(sizeof(hard_code)/sizeof(hard_code[0])) ; p++)
	{
		//printf("came here2\n");
		if(strcmp(product_name,hard_code[p])==0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

struct node
{
   char product_name[30];
   int price;
   int no_of_quantities;
   //int sl_no;
   struct node *link;
};
typedef struct node node;
struct list
{
node *head;
};
typedef struct list s_list;
void list_initialize(s_list*);
void list_insert_front(s_list*,int,int,char[]);
void list_insert_At(s_list*,int ,int,char[],int);
void list_insert_end(s_list*,int,int,char[]);
void list_delete_front(s_list*);
void list_delete_end(s_list*);
void delete_element(s_list*,int );
void list_print(s_list*);
void generate_bill(s_list*);

int main()
{
	printf("\n################WELCOME TO  CITRALIT###############\n\n\n");
	char customers_name[10];
	printf("enter the customer's name\n");
	scanf("%s",customers_name);
	int  op;
	char product_name[30];
	int price;
	int no_of_quantities;
	int position;
	//int price_of_individual;
	s_list list;
	list_initialize(&list);
	while(1)
	{
		printf("1. Insert beginning of the list \n");
		printf("2. Insert at the position \n");
		printf("3. Insert at the end \n");
		printf("4. Delete beginning \n");
		printf("5. Delete at  the end\n");
		printf("6. Delete at the position\n");
		printf("7. Display the products\n");
		printf("8. Generate Bill\n");
		printf("0. Exit\n");
		printf("Enter your option \n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:printf("Enter the productname,price,no.of quantities  to be inserted\n");
		         		scanf("%s %d %d",product_name,&price,&no_of_quantities);
		         		list_insert_front(&list,price,no_of_quantities,product_name);
		        		  break;
			case 2: printf("\nEnter the  productname,price,no.of quantities and position to be inserted\n");
				scanf("%s %d %d %d",product_name,&price,&no_of_quantities,&position);
			 	list_insert_At(&list,price,no_of_quantities,product_name,position);
				break;
			case 3: printf("\nEnter the productname,price,no.of quantities to be inserted\n");
				scanf("%s %d %d",product_name,&price,&no_of_quantities);
				list_insert_end(&list,price,no_of_quantities,product_name);
				break;
			case 4: list_delete_front(&list);
				break;
			case 5: list_delete_end(&list);
				break;
			case 6: printf("\nEnter the element position to be deleted\n");
				scanf("%d",&position);
				delete_element(&list, position);
 				break;
			case 7: list_print(&list);
				break;
			case 8: generate_bill(&list);
				break;

			default: exit(0);
       	}
	}
}


void list_initialize(s_list *list)
{
    list->head=NULL;
}

node* create_Node(char product_name[],int price,int no_of_quantities, node* link)
{

	node *temp = (node*)malloc(sizeof(node));
	strcpy(temp->product_name, product_name);
	temp->price=price;
	temp->no_of_quantities=no_of_quantities;
	temp->link = link;
	return temp;

}

void list_insert_front(s_list *list,int price,int no_of_quantities,char product_name[])
{
	if(found(product_name)==1)
	{
    	 node* newnode=create_Node(product_name,price,no_of_quantities,NULL);
   	 if(list->head==NULL)
   	 {
        	list->head=newnode;
		printf("\nProduct Added Succesfully at Front\n");
   	 }
    	else
    	{
       		 newnode->link=list->head;
       		 list->head=newnode;
		printf("\nProduct Added Succesfully at Front\n");
   	    }

	}
	//price_of individual=(temp->price)*(temp->no_of_quantities);
	//printf("individual price: "&price_of_individual);
	else
	{
		printf("Product not available\n");
		//return list;
	}
}

void list_insert_At(s_list *list,int price,int no_of_quantities,char product_name[],int position)
{
	if(found(product_name)==1)
	{
	node *newnode=create_Node(product_name,price,no_of_quantities,NULL);
    	node *q;
    	node *prev=NULL;
    	q=list->head;
    	int i=1;
    	if(position<=0){
        	printf("\nError: Position can't be less than 0\n");
		}
	else if(position==1){
		list_insert_front(list,price,no_of_quantities,product_name);
	}
	else{
    		while((q!=NULL)&&(i<position))
    		{
      		 i++;
       		 prev=q;
       		 q=q->link;
   		}
        	newnode->link=q;
        	prev->link=newnode;
		printf("\nProduct Added Successfully at %d Position\n", position);
	}
	}
		else
	{
		printf("Product not available\n");
		//return list;
	}

}

void list_insert_end(s_list *list,int price,int no_of_quantities,char product_name[])
{
	if(found(product_name)==1)
	{
    	node *newnode=create_Node(product_name, price, no_of_quantities, NULL);
    	if(list->head==NULL)
    	{
       		list->head=newnode;
		printf("\nProduct Added Succesfully at End\n");
   	}
   	else
    	{
		node *temp=list->head;

        	while(temp->link!=NULL)
       		{
           		temp=temp->link;
        	}
        	temp->link=newnode;
		printf("\nProduct Added Succesfully at end\n");
    	}
	}
	else
	{
		printf("Product not available\n");
		//return list;
	}
}
void list_print(s_list*list)
{
    	node *temp;
    	temp=list->head;
   	if(temp==NULL)
    	{
       		 printf("\nThere are no products in the List\n");
    	}
    	else
    	{

       	while(temp!=NULL)
       	{
		printf("\nProductName\tPrice\tQuantity\n");
            	printf("%s\t\t%d\t%d\n",temp->product_name,temp->price,temp->no_of_quantities);
            	temp=temp->link;
       	}
       	printf("\n");
   	}
}





void list_delete_front(s_list *list)
{

   	node *s=list->head;
    	if(list->head==NULL)
    	{
       		 printf("\nThere are no products in the List to delete\n");
   	 }
   	 else
   	 {
       	 	list->head=s->link;
        	free(s);
		printf("\nProduct Deleted Succesfully at Front\n");
   	 }
}




void list_delete_end(s_list *list)
{

    	node *q , *prev;
    	q=list->head;
    	prev=NULL;
    	if(list->head==NULL)
    	{

        	printf("\nThere are no products in the List to delete\n");
   	 }
    	while(q->link!=NULL)
    	{

        	prev=q;
        	q=q->link;
    	}
    	if(prev==NULL)
    	{

        	list->head=NULL;
		free(q);
		printf("\nProduct deleted Succesfully at End\n");
   	}
    	else
   	 {
       		 prev->link=NULL;
        		free(q);
			printf("\nProduct Deleted Succesfully at End\n");
   	 }
}


void delete_element(s_list *list,int position)
{
    	node* temp=list->head;
	node* prev=NULL;
    	int i=1;

    	if(position<=0){
        	printf("\nError: Position can't be less than 0\n");
	}
	else if(position==1){
		 list_delete_front(list);
	}
	else{
    		while((temp!=NULL)&&(i<position))
    		{
      		  i++;
       		 prev=temp;
       		 temp=temp->link;
   		}
       		if(i==position)
		{
            			temp=temp->link;
			free(temp);
			printf("\nProduct Deleted Successfully at %d Position\n", position);
   		}
   		else
    		{
			prev->link=temp->link;
			free(temp);
			printf("\nProduct Deleted Successfully at %d Position\n", position);
   		}
	}
}

void generate_bill(s_list* list)
{
	node *temp;
    temp=list->head;
	int total_amount;
	int price_of_individual;
	char ch[1];
	list_print(list);
	printf("Do u want to procees for billing [y/N]:\n");
	scanf("%s",ch);
	if(ch[0]=='y')
	{
		printf("came here\n");
		price_of_individual=(temp->price)*(temp->no_of_quantities);
		printf("individual price",&price_of_individual);
		total_amount+=price_of_individual;
		//printf("bill is generated");
	}
	else
	{
		//break;
	}
}











