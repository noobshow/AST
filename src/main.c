#include "node.h"
#include <stdio.h>

int main() {
	node *top = newNode("-", OPERATOR, 2);
	node *three = newNode("3", TOKEN, 0);
	node *plus = newNode("+", OPERATOR, 2);
	node *one = newNode("1", TOKEN, 0);
	node *two = newNode("2", TOKEN, 0);
	top->children[0] = plus;
	top->children[1] = three;
	plus->children[0] = one;
	plus->children[1] = two;
	printf("%s", eval(top));
	return 0;
}
