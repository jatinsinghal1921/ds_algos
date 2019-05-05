// Defining CLass Structure
class node {
public:
	int data;
	node* link;
};

// Declaring Function
void ll_print(node* head);
node* ll_insert_at_beginning(node* head, int x);
node* ll_intersection(node* head1, node* head2);
node* ll_last_node_to_first(node* head);
node* ll_insert_at_end(node* head,int x);
node* ll_insert_after_specific_node(node* head, int x, int node_value);
node* ll_insert_at_specific_location(node* head, int x, int loc);
void ll_reverse_recursive(node** head, node* traverse);
void ll_reverse_tail_recursive(node** head);
void ll_reverse_tail_recursive_util(node** head, node* traverse, node* prev);
void ll_reverse(node** head);
void ll_delete_at_beginning(node** head);
void ll_delete_at_end(node** head);
void ll_delete_specific_node(node** head, int x);
void ll_delete_at_specific_position(node** head, int pos);