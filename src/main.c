#include "node.h"
#include <stdio.h>

int main() {
	node *plus = newNode("+", OPERATOR, 2);
	node *one = newNode("1", TOKEN, 0);
	node *two = newNode("2", TOKEN, 0);
	plus->children[0] = one;
	plus->children[1] = two;
	printf("%s", eval(plus));
	return 0;
}
