#include "node.h"
#include <stdio.h>

int main() {
	node *plus = newNode("+", OPERATOR, 2);
	printf("%s", plus->data);
	return 0;
}
