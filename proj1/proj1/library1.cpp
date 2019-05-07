#include<iostream>
#include "header1.h"

using namespace std;


void ll_print(node* head) 
{
	cout << "Printing The Elements of Linked List" << endl;
	while (head != 0) {
		cout << head->data << " ";
		cout << endl;
		head = head->link;
	}
}

node* ll_insert_at_beginning(node* head, int x) 
{
	node* temp = new node;
	temp->data = x;
	temp->link = head;
	head = temp;
	return head;
}

node* ll_insert_at_end(node* head,int x){
	node* temp = new node;
	temp->data = x;
	temp->link = 0;
	if(head == 0){
		return temp;
	}
	node* traverse = head;
	while(traverse->link!=0)
	{
		traverse = traverse->link;
	}
	traverse->link = temp;
	return head;
}

node* ll_insert_after_specific_node(node* head, int x, int node_value){
	node* traverse = head;
	while(traverse != 0)
	{
		if(traverse->data == node_value)
		{
			break;
		}
		traverse = traverse->link;
	}
	if(traverse == 0){
		cout<<"There is no node present with that value."<<endl;
		return head;
	}
	node* temp = new node;
	temp->data = x;
	temp->link = traverse->link;
	traverse->link = temp->link;
	return head;
}

node* ll_insert_at_specific_location(node* head, int x, int loc)
{
	if (loc < 1)
	{
		cout << "Nodes Location start from 1. So please enter a valid Location" << endl;
		return head;
	}
	node *prev = 0, *temp = head;
	int i = 1;
	while(temp!=0){
		if(i == loc){
			break;
		}
		prev = temp;
		temp = temp->link;
		i++;
	}
	if(i<loc)
	{
		cout<<"Invalid Location to add New Node"<<endl;
		return head;
	}

	node* temp1 = new node;
	temp1->data = x;

	if(prev == 0)
	{
		temp1->link = head;
		head = temp1;
	}
	else
	{
		temp1->link = temp;
		prev->link = temp1;
	}
	return head;
}

void ll_reverse_recursive(node** head, node* traverse){
	if (traverse == 0 || traverse->link == 0) {
		*head = traverse;
		return;
	}
	ll_reverse_recursive(head, traverse->link);
	traverse->link->link = traverse;
	traverse->link = 0;
}

void ll_reverse_tail_recursive(node** head) {
	ll_reverse_tail_recursive_util(head, *head, 0);
}

void ll_reverse_tail_recursive_util(node** head, node* traverse, node* prev) {
	if (traverse == 0) {
		return;
	}
	if (traverse->link == 0) {
		*head = traverse;
	}
	node* next = traverse->link;
	traverse->link = prev;
	ll_reverse_tail_recursive_util(head, next, traverse);
}

void ll_reverse(node** head) {
	node *prev = 0, *curr = *head, *next = *head;
	while (curr != 0) {
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void ll_delete_at_beginning(node** head) {
	if (*head == 0) {
		return;
	}
	node* temp = *head;
	*head = (*head)->link;
	delete temp;
}

void ll_delete_at_end(node** head) {
	if (*head == 0 || (*head)->link == 0) {
		*head = 0;
		return;
	}
	node* traverse = *head;
	while (traverse->link->link != 0) {
		traverse = traverse->link;
	}
	node* temp = traverse->link;
	traverse->link = temp->link;
	delete temp;
}

void ll_delete_specific_node(node** head, int x) {
	if (*head == 0) {
		cout << "List is already empty" << endl;
		return;
	}
	node *prev = 0,*curr = *head;
	while (curr != 0) {
		if (curr->data == x) {
			break;
		}
		prev = curr;
		curr = curr->link;
	}
	if (curr == 0) {
		cout << "Specified Element Doesn't exist in Linked List" << endl;
		return;
	}
	if (prev == 0) {
		ll_delete_at_beginning(head);
	}
	else {
		prev->link = curr->link;
		delete curr;
	}

}

void ll_delete_at_specific_position(node** head, int pos) {
	if (*head == 0 || pos<=0) {
		return;
	}
	int i = 1;
	node *prev = 0, *curr = *head;
	while (curr != 0) {
		if (i == pos) {
			break;
		}
		i++;
		prev = curr;
		curr = curr->link;
	}
	if (curr == 0) {
		cout << "Invalid Position to Delete an element" << endl;
		return;
	}
	if (i == 1) {
		ll_delete_at_beginning(head);
	}
	else {
		prev->link = curr->link;
		delete curr;
	}
}

node* ll_intersection(node* head1, node* head2)
{
	node *head = 0, *trav = 0;
	while (head1 != 0 && head2 != 0)
	{
		if (head1->data < head2->data)
		{
			head1 = head1->link;
		}
		else if (head1->data > head2->data)
		{
			head2 = head2->link;
		}
		else
		{
			node* temp = new node;
			temp->data = head1->data;
			temp->link = 0;
			if (head == 0)
			{
				head = temp;
			}
			else
			{
				trav->link = temp;
			}
			trav = temp;
			head1 = head1->link;
			head2 = head2->link;
		}
	}
	return head;
}

node* ll_last_node_to_first(node* head) {
	if (head == 0 || head->link == 0)
	{
		return head;
	}
	node* temp = head;
	while (temp->link->link != 0)
	{
		temp = temp->link;
	}
	node* last = temp->link;
	temp->link = 0;
	last->link = head;
	head = last;
	return head;
}

int ll_length(node* head) {
	int count = 0;
	while (head != 0) {
		count = count + 1;
		head = head->link;
	}
	return count;
}

int ll_length_tail_recursive(node* head) {
	int count = 0;
	return ll_length_tail_recursive_util(head,count);
}

int ll_length_tail_recursive_util(node* head, int count) {
	if (head == 0) {
		return count;
	}
	count = count + 1;
	return ll_length_tail_recursive_util(head->link, count);
}

bool ll_search_an_element(node* head, int x) {
	while (head != 0) {
		if (head->data == x) {
			return true;
		}
		head = head->link;
	}
	return false;
}

bool ll_search_an_element_tail_recursive(node* head, int x) {
	if (head == 0) {
		return false;
	}
	if (head->data == x) {
		return true;
	}
	return ll_search_an_element_tail_recursive(head->link, x);
}

int ll_nth_node_from_start(node* head, int n) {
	if (head == 0) {
		cout << "List is Empty" << endl;
		return -1;
	}
	if (n < 0) {
		cout << " You have entered an invalid position" << endl;
		return -1;
	}
	while (head != 0) {
		if (n == 0) {
			return head->data;
		}
		n--;
		head = head->link;
	}
	cout << "You have entered invalid position" << endl;
	return -1;
}

int ll_nth_node_from_start_tail_recursive(node* head, int n) {
	if (head == 0 || n < 0) {
		cout << "Entered Position is invalid" << endl;
		return -1;
	}
	if (n == 0) {
		return head->data;
	}
	n--;
	return ll_nth_node_from_start_tail_recursive(head->link, n);
}

int ll_nth_node_from_last(node* head, int n) {
	if (head == 0) {
		cout << "Linked List is Empty" << endl;
		return -1;
	}
	if (n <= 0) {
		cout << "Entered position is invalid" << endl;
		return -1;
	}
	node *fast = head, *slow = head;
	while (fast != 0 && n != 1)
	{
		n--;
		fast = fast->link;
	}
	if (fast == 0) {
		cout << "Entered Position is Invalid" << endl;
		return -1;
	}
	while (fast->link != 0) {
		slow = slow->link;
		fast = fast->link;
	}
	return slow->data;
}

node* ll_segregate_even_odd_nodes(node* head) {
	node *prev = 0, *curr = head, *last_even = 0, *temp;
	while (curr != 0) {
		if ((curr->data % 2) != 0) {
			prev = curr;
			curr = curr->link;
		}
		else {
			if (prev == 0 || ((prev->data % 2) == 0)) {
				prev = curr;
				last_even = curr;
				curr = curr->link;
			}
			else {
				prev->link = curr->link;
				temp = curr;
				curr = curr->link;

				if (last_even == 0) {
					temp->link = head;
					head = temp;
					last_even = head;
				}
				else {
					temp->link = last_even->link;
					last_even->link = temp;
					last_even = temp;
				}
			}
		}
	}
	return head;
}