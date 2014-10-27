/* md5test.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <openssl/md5.h>

/* test case */
const int INPUT_NUM = 7;
static char *input[] = {
	"",
	"a",
	"abc",
	"message digest",
	"abcdefghijklmnopqrstuvwxyz",
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
	"12345678901234567890123456789012345678901234567890123456789012345678901234567890",
	NULL,
	};

static char *expected_output[] = {
	"d41d8cd98f00b204e9800998ecf8427e",
	"0cc175b9c0f1b6a831c399e269772661",
	"900150983cd24fb0d6963f7d28e17f72",
	"f96b697d7cb7938d525a2f31aaf161d0",
	"c3fcd3d76192e4007dfb496cca67e13b",
	"d174ab98d277d9f5a5611c2c9f419d9f",
	"57edf4a22be3c955ac49da2e2107b67a",
	};

/* test program */

int main(int argc, char *argv[]);
int Test(void);
void ShowHexData(const unsigned char data[], int len, const char name[]);

int main(int argc, char *argv[])
{
	return (Test());
}

int Test(void)
{
	unsigned char actual[MD5_DIGEST_LENGTH];
	unsigned char expected[MD5_DIGEST_LENGTH];
	int i, j;
	int failed_tests;

	failed_tests = 0;
	for (i=0; i<INPUT_NUM; i++)
	{	const int DEBUG=0;
		char *s;

		printf("[Test No.%d]\n", i+1);

		if (DEBUG)
		{	memset(actual, 0x00, sizeof(actual));
		}

		MD5(input[i], strlen(input[i]), actual);
		s = expected_output[i];
		for (j=0; j<MD5_DIGEST_LENGTH; j++)
		{
			int tmp;
			sscanf(s, "%02x", &tmp);
			expected[j] = tmp & 0x00FF;
			s += 2;
		}
		if (memcmp(actual, expected, MD5_DIGEST_LENGTH) != 0)
		{	failed_tests += 1;
		}
		printf("input=\"%s\"\n", input[i]);
		printf("expeceted output=\"%s\"\n", expected_output[i]);
		ShowHexData(actual, MD5_DIGEST_LENGTH, "actual MD5 output");
	}
	printf("============\n");
	if (failed_tests > 0)
	{
		printf("Total %d tests. Failed %d\n", INPUT_NUM, failed_tests);
		return (failed_tests);
	}
	printf("All %d tests have been successfully passed!\n", INPUT_NUM);
	return (0);
}

void ShowHexData(const unsigned char data[], int len, const char name[])
{
	int i;
	printf("%s=\"", name);
	for (i=0; i<len; i++)
	{
		printf("%02x", data[i]);
	}
	printf("\"\n");
}
/**/
