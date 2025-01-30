#ifndef MAIN_H
#define MAIN_H
#include <stdint.h>
#include <stdbool.h>

#define TEEC_SUCCESS                       0x00000000
#define TEEC_ERROR_STORAGE_NOT_AVAILABLE   0xF0100003
#define TEEC_ERROR_GENERIC                 0xFFFF0000
#define TEEC_ERROR_ACCESS_DENIED           0xFFFF0001
#define TEEC_ERROR_CANCEL                  0xFFFF0002
#define TEEC_ERROR_ACCESS_CONFLICT         0xFFFF0003
#define TEEC_ERROR_EXCESS_DATA             0xFFFF0004
#define TEEC_ERROR_BAD_FORMAT              0xFFFF0005
#define TEEC_ERROR_BAD_PARAMETERS          0xFFFF0006
#define TEEC_ERROR_BAD_STATE               0xFFFF0007
#define TEEC_ERROR_ITEM_NOT_FOUND          0xFFFF0008
#define TEEC_ERROR_NOT_IMPLEMENTED         0xFFFF0009
#define TEEC_ERROR_NOT_SUPPORTED           0xFFFF000A
#define TEEC_ERROR_NO_DATA                 0xFFFF000B
#define TEEC_ERROR_OUT_OF_MEMORY           0xFFFF000C
#define TEEC_ERROR_BUSY                    0xFFFF000D
#define TEEC_ERROR_COMMUNICATION           0xFFFF000E
#define TEEC_ERROR_SECURITY                0xFFFF000F
#define TEEC_ERROR_SHORT_BUFFER            0xFFFF0010
#define TEE_ERROR_EXTERNAL_CANCEL          0xFFFF0011
#define TEEC_ERROR_EXTERNAL_CANCEL         0xFFFF0011
#define TEE_ERROR_OVERFLOW                 0xFFFF300F
#define TEE_ERROR_TARGET_DEAD              0xFFFF3024
#define TEEC_ERROR_TARGET_DEAD             0xFFFF3024
#define TEE_ERROR_STORAGE_NO_SPACE         0xFFFF3041
#define TEEC_ERROR_STORAGE_NO_SPACE        0xFFFF3041
#define TEE_ERROR_MAC_INVALID              0xFFFF3071
#define TEE_ERROR_SIGNATURE_INVALID        0xFFFF3072
#define TEE_ERROR_TIME_NOT_SET             0xFFFF5000
#define TEE_ERROR_TIME_NEEDS_RESET         0xFFFF5001

typedef uint32_t TEEC_Result;

typedef struct {
	/* Implementation defined */
	struct {
		int fd;
		bool reg_mem;
		bool memref_null;
	} imp;
} TEEC_Context;

TEEC_Result TEEC_InitializeContext(const char *name, TEEC_Context *context);
void TEEC_FinalizeContext(TEEC_Context *context);
TEEC_Result TEEC_InvokeCommand(int cmd);

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

#endif
