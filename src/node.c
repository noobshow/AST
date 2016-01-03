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
	char *result;
	switch(top->type) {
	case OPERATOR:
		if(top->len == 1) {
			char *parameter = eval(top->children[0]);
			int length = strlen(top->data) + strlen(parameter);
			result = string(length);
			strcat(result, top->data);
			strcat(result, parameter);
		} else {
			char *param1, *param2;
			param1 = eval(top->children[0]);
			param2 = eval(top->children[1]);
			int length = strlen(top->data) + strlen(param1) + strlen(param2);
			result = string(length);
			strcat(result, param1);
			strcat(result, top->data);
			strcat(result, param2);
		}
		break;
	case TOKEN:
		result = top->data;
		break;
	default:
		result = "";
		break;
	}
	return result;
}
