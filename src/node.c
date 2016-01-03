#include "node.h"
#include "stdlib.h"
#include "mem.h"

node* newNode(char* data, node_type type, int children) {
	node *current = new(current);
	current->data = data;
	current->type = type;
	current->len = children;
	current->children = array(current->children, current->len);
	return current;
}
void delete(node *top) {
	if(top) {
		node **children = top->children;
		for(int i = 0; i < top->len; i++) {
			delete(children[i]);
		}
		free(top->children);
		free(top);
	}
}
char* eval(node *top) {

}
