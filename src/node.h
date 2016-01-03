#ifndef NODE_H_
#define NODE_H_
typedef enum node_type {
	OPERATOR, CALL, FUNCTION, CAST, CONDITIONAL, FOR, TOKEN, BLOCK
} node_type;
typedef struct node {
	enum node_type type;
	char* data;
	int len;
	struct node **children;
} node;
node* newNode(char* data, node_type type, int children);
void delete(node *top);
char* eval(node *top);
#endif
