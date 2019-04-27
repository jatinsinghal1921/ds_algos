#include<iostream>
#include "header1.h"

using namespace std;


void printLL(node* head) 
{
	while (head != 0) {
		cout << head->data << " ";
		cout << endl;
		head = head->link;
	}
}

node* insert_at_beginning(node* head, int x) 
{
	node* temp = new node;
	temp->data = x;
	temp->link = head;
	head = temp;
	return head;
}

node* intersection_of_ll(node* head1, node* head2)
{
	node *head = 0, *trav = 0;
	while(head1!=0 && head2!=0)
	{
		if(head1->data < head2->data)
		{
			head1 = head1->link;
		}
		else if(head1->data > head2->data)
		{
			head2 = head2->link;
		}
		else
		{
			node* temp = new node;
			temp->data = head1->data;
			temp->link = 0;
			if(head == 0)
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

node* last_node_to_first(node* head){
	if(head == 0 || head->link == 0)
	{
		return head;
	}
	node* temp = head;
	while(temp->link->link != 0)
	{
		temp = temp->link;
	}
	node* last = temp->link;
	temp->link = 0;
	last->link = head;
	head = last;
	return head;
}
