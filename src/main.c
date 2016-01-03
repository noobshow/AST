#include "node.h"
#include <stdio.h>

int main() {
	FILE *out = fopen("out.c", "w");
	if(out) {
		node *assign = newNode("int x", ASSIGN, 1);
		node *value = newNode("0", TOKEN, 0);
		assign->children[0] = value;
		fprintf(out, "int main() { %s; return x; }", eval(assign));
	} else {
		printf("File system error.");
	}
	return 0;
}
