
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int insert_start(int data);
int insert_end(int data);
int delete_start();
int delete_end();
int print_list();
int num_elements = 0;


struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int print_list() 
{
    if (num_elements > 0)
    {
        struct node *ptr = head;
        printf("\n");

        for(int i=0; i < num_elements; i++) 
        {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
        }	
        printf("NULL");
    }
    else{
        printf("There are no elements in list to print .");
    }
    return 0;
}

int insert_start(int data) 
{

    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    num_elements += 1;
    printf("Element entered .");
    return 0;
}

int insert_end(int data)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node *p = head;
    temp->data = data;
    temp->next = NULL;
    while (p->next != NULL)
    {
      p = p->next;
    }
    p->next = temp;
    num_elements += 1;
    printf("Element entered .");
    return 0;
}

int delete_start()
{
    //print_list();
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Element deleted .");
    num_elements -=1;
    print_list();
    return 0;
}

int delete_end()
{
    struct node *temp1 = head;
    struct node *temp2;

    while (temp1->next != NULL){
        temp1 = temp1->next;
        temp2 = temp1;
    }

    free(temp1);
    temp2->next = NULL;

    printf("Element deleted");
    num_elements -= 1;
    print_list();

    return 0;
}

int main() {

    int choice = 0, data, run = 1;
    //print_list();
    //printf("%d", get_num_elements());

    printf("\n\n");
    printf("  ,-.            .       ,          ,          .   ,          .   \n");
    printf(" (   ` o         |       |    o     |         |    |    o     |   \n");//shimrod font
    printf("  `-.  . ;-. ,-: | ,-.   |    . ;-. | , ,-. ,-|    |    . ,-. |-  \n");
    printf(" .   ) | | | | | | |-'   |    | | | |<  |-' | |    |    | `-. |   \n");
    printf("  `-'  ' ' ' `-| ' `-'   `--' ' ' ' ' ` `-' `-'    `--' ' `-' `-' \n");
    printf("             `-'         \n\n");

    while (run == 1){
                                        
        printf("\nPress 0 to print linked list .");
        printf("\nPress 1 to insert node at start of linked list .");
        printf("\nPress 2 to insert node at end of linked list .");
        printf("\nPress 3 to delete node from start of linked list .");
        printf("\nPress 4 to delete node from end of linked list .");
        printf("\nPress 5 to get number of elements of linked list .");
        printf("\nPress 6 to Exit .\n\n");
        
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch (choice)
        {
            case 0 :
                print_list();
                break;

            case 1 :
                printf("Enter data :");
                scanf("%d",&data);
                insert_start(data);
                break;
                
            case 2 :
                printf("Enter data :");
                scanf("%d",&data);               
                if (num_elements == 0)
                {

                insert_start(data);
                }
                else{
                    insert_start(data);
                }
                break;


            case 3 :
                if (num_elements != 0)
                {
                    delete_start();
                    break;
                }
                else{
                    printf("Enter atleast one element in list .\n");
                    break;
                }

            case 4 :
                if (num_elements != 0)
                {
                    delete_end();
                    break;
                }
                else{
                    printf("Enter atleast one element in list .\n");
                    break;
                }

            case 5 :
                printf("Total number of elements in list = %d\n",num_elements);
                break;

            case 6 :
                printf("Good Bye :)\n");
                break;
    }
    printf("\nDo you want to continue ? (Press 1 for yes) :");
    scanf("%d",&run);
}
    getch();
    return 0;
}