#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

TEEC_Result TEEC_InitializeContext(const char *name, TEEC_Context *context) {
	return strcmp(name, "good") == 0 ? TEEC_SUCCESS : TEEC_ERROR_GENERIC;
}

void TEEC_FinalizeContext(TEEC_Context *context) {
	// Do nothing
}

TEEC_Result TEEC_InvokeCommand(int cmd) {
	switch (cmd) {
	case 0:
		return 1;
	case 1:
		return 2;
	case 2:
		sleep(2);
		return 3;
	case 3:
		return 3;
	default:
		return TEEC_ERROR_GENERIC;
	}
}

#if NO_TEST
int main(int argc, char *argv[])
{
	int a = 2;
	int b = 2;
	printf("Add: %d\n", add(a, b));
	printf("Subtract: %d\n", subtract(a, b));
	printf("Multiply: %d\n", multiply(a, b));
	return 0;
}
#endif
