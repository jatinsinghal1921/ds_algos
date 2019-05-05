#include<iostream>
#include "header1.h"

using namespace std;

int main() {
	node* head = 0;
	head = ll_insert_at_beginning(head, 5);
	head = ll_insert_at_beginning(head, 4);
	head = ll_insert_at_beginning(head, 3);
	head = ll_insert_at_beginning(head, 2);
	head = ll_insert_at_beginning(head, 1);
	ll_print(head);
	ll_delete_at_specific_position(&head, 1);
	ll_print(head);
}

