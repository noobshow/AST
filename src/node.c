#include "node.h"
#include <stdlib.h>
#include "mem.h"
#include <string.h>
#include <stdio.h>

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
	char* result;
	switch(top->type) {
	case OPERATOR:
		if(top->len == 1) {
			int length = strlen(top->data) + strlen(top->children[0]->data);
			result = string(length);
			strcat(result, top->data);
			strcat(result, top->children[0]->data);
		}
		break;
	default:
		result = "";
		break;
	}
	return result;
}
