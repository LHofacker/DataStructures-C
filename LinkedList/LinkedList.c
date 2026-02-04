#include<stdio.h>
#include<stdlib.h>



struct Node{

	int data;
	struct Node* next_node;
};

struct LinkedList{

	struct Node* head;
};

struct LinkedList* create_linkedlist(){

	struct LinkedList* temp_list = malloc(sizeof(*temp_list));
	
	temp_list->head = NULL;
	
	return temp_list;
}

void insert(struct LinkedList* list, int input_data){

	struct Node* current_node;

	if(list->head == NULL){

		list->head = malloc(sizeof(struct Node));
		list->head->data = input_data;
		list->head->next_node = NULL;
	}else{

		current_node = list->head;

		while(current_node->next_node != NULL){

			current_node = current_node->next_node;
		}

		current_node->next_node = malloc(sizeof(struct Node));
		current_node->next_node->data = input_data;
		current_node->next_node->next_node = NULL;
		}
}

void print_list(struct LinkedList* list){

	if(list->head != NULL){
	
		struct Node* current_node = list->head;

		while(current_node != NULL){

			printf("%i\n", current_node->data);
			current_node = current_node->next_node;
		}

	}else{

		printf("List is empty. Nothing to print\n");
	}

}

int remove_node(struct LinkedList* list, int index){
	
	if(list->head != NULL){

		struct Node* current_node = list->head;
		struct Node* auxiliar_node = NULL;
		struct Node* another_auxiliar_node = NULL;

		for(int i = 0; i < index - 1; i++){

			current_node = current_node->next_node;

			if(current_node == NULL){
				
				printf("ERROR: Index given is larger than list! Operation aborted.\n");
				return 0;
			}

		}

		auxiliar_node = current_node->next_node->next_node;
		another_auxiliar_node = current_node->next_node;

		current_node->next_node = auxiliar_node;
		free(another_auxiliar_node);
	}

	return 0;
}

int main(){

	struct LinkedList* test_list = create_linkedlist();

	insert(test_list, 12);
	insert(test_list, 10);
	insert(test_list, 34);
	insert(test_list, 5);

	print_list(test_list);

	remove_node(test_list, 6);
	
	printf("\n\n");
	print_list(test_list);
		
	return 0;
}
