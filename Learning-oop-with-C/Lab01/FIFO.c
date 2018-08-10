#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* TO-DOs
1. Modificar el push para que agregue en orden de carnet
2. Modificar el eliminar para que elimine por carnet
*/
typedef struct node {
        char  nombre[20];
   		int  carnet;
   		int  nota;
   		struct node * next;
    } Alumno;

Alumno * head = NULL;

void push(Alumno * head, int carnet,char* nombre,int nota) {
		Alumno * current = head;
		while (current->next != NULL) {
        current = current->next;
    	}
	    /* now we can add a new variable */
	    current->next = malloc(sizeof(Alumno));
	    
	    current->next->carnet=carnet;
	    strcpy(current->next->nombre, nombre);
	    current->next->nota=nota;
	    
	    current->next->next = NULL;
}

void print_list(Alumno * head) {
	printf("***Listado de alumnos:\n");
    Alumno * current = head;
    while (current != NULL) {
        printf("%s\n", current->nombre);
        current = current->next;
    }
}

void init(int carnet,char* nombre,int nota) {
	head = malloc(sizeof(Alumno));
	
	head->carnet=carnet;
	strcpy( head->nombre, nombre);
	head->nota = nota;
	
	head->next = NULL;
}

int pop(Alumno ** head) {
	    char retval[20];
	    Alumno * next_node = NULL;
	
	    if (*head == NULL) {
	        return -1;
	    }
	
	    next_node = (*head)->next;
	    strcpy(retval, (*head)->nombre);
	    free(*head);
	    *head = next_node;
	
	    printf("Alumno eliminado: %s \n",retval);
	    return 0;
	}
	
int remove_by_index(Alumno ** head, int n) {
	    int i = 0;
	    int retval = -1;
	    Alumno * current = *head;
	    Alumno * temp_node = NULL;
	
	    if (n == 0) {
	        return pop(head);
	    }
	
	    for (i = 0; i < n-1; i++) {
	        if (current->next == NULL) {
	            return -1;
	        }
	        current = current->next;
	    }
	
	    temp_node = current->next;
	    retval = temp_node->carnet;
	    current->next = temp_node->next;
	    free(temp_node);
	
	    return retval;
	}

int remove_by_value(Alumno ** head, int carnet){
		int i = 0;
	    char retval[20];
	    Alumno * current = *head;
	    Alumno * temp_node = NULL;
	    
	    if (current->carnet == carnet) {
	        return pop(head);
	    }
	    while (current->next->carnet != carnet) {
	    	if (current->next == NULL) {
	            return -1;
	        }
	        current = current->next;
    	}
    	
    	temp_node = current->next;
	    strcpy(retval, temp_node->nombre);
	    current->next = temp_node->next;
	    free(temp_node);
	
	    printf("Alumno eliminado: %s \n",retval);
	    return 0;
	}

int remove_last(Alumno * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->carnet;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    Alumno * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->carnet;
    free(current->next);
    current->next = NULL;
    return retval;

}

int main() {
	/*init(1,"Victor",90);
	push(head,2,"Andres",80);
	push(head,3,"Gaby",80);
	print_list(head);
	remove_by_value(&head,1);
	print_list(head);
	remove_by_value(&head,3);
	print_list(head);*/
	
	for (;;) {
		int choice;
		printf("Para agregar un alumno ingrese 1. Para eliminar un alumno ingrese 2:\n");
		scanf(" %d", &choice);
		if (choice==1) {
			int carnet;
			printf("Ingrese el carnet: \n");
			scanf("%d", &carnet);
			
			char nombre[20];
			printf("Ingrese el nombre: \n");
			scanf("%s", &nombre);
			
			int nota;
			printf("Ingrese la nota: \n");
			scanf("%d", &nota);
			
			if (head==NULL){
				init(carnet,nombre,nota);
			} else {
				push(head,carnet,nombre,nota);
			}
		}
		if (choice==2) {
			/*int carnet;
			printf("Ingrese el carnet que desea eliminar: \n");
			scanf("%d", &carnet);*/
			pop(&head);
		}
		print_list(head);
	}
	return 0;
}
