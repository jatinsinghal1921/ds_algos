// Defining CLass Structure
class node {
public:
	int data;
	node* link;
};

// Declaring Function
void printLL(node* head);
node* insert_at_beginning(node* head, int x);
node* intersection_of_ll(node* head1, node* head2);
node* last_node_to_first(node* head);