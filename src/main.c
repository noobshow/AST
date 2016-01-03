#include "node.h"
#include <stdio.h>

int main() {
	node *plus = newNode("+", OPERATOR, 1);
	node *one = newNode("1", TOKEN, 0);
	plus->children[0] = one;
	printf("%s", eval(plus));
	return 0;
}
