#include<iostream>
#include "header1.h"

using namespace std;

int main() {
	node* head = 0;
	head = ll_insert_at_beginning(head, 9);
	head = ll_insert_at_beginning(head, 5);
	head = ll_insert_at_beginning(head, 6);
	head = ll_insert_at_beginning(head, 4);
	head = ll_insert_at_beginning(head, 2);
	ll_print(head);
	head =  ll_segregate_even_odd_nodes(head);
	ll_print(head);
}

