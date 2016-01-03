#include "node.h"
#include <stdio.h>

int main() {
	node *print = newNode("printf", CALL, 2);
	node *fmtString = newNode("\"%f\"", TOKEN, 0);
	node *cast = newNode("float", CAST, 1);
	node *plus = newNode("+", OPERATOR, 2);
	node *op1 = newNode("12", TOKEN, 0);
	node* op2 = newNode("4", TOKEN, 0);
	cast->children[0] = plus;
	plus->children[0] = op1;
	plus->children[1] = op2;
	print->children[0] = fmtString;
	print->children[1] = cast;
	printf("%s", eval(print));
	return 0;
}
