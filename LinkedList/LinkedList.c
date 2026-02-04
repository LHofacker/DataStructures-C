#include<stdio.h>
#include<stdlib.h>

struct Node{

	void* data;
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

int main(){

	//struct LinkedList* test_list = create_linkedlist();




		
	return 0;
}
