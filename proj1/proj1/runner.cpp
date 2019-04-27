#include<iostream>
#include "header1.h"

using namespace std;

int main() {
	node* head = 0;
	head = insert_at_beginning(head, 5);
	head = insert_at_beginning(head, 4);
	head = insert_at_beginning(head, 3);
	head = insert_at_beginning(head, 2);
	head = insert_at_beginning(head, 1);
	printLL(head);
	head = last_node_to_first(head);
	printLL(head);
}

