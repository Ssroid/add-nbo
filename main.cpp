#include <stdlib.h>
#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>

uint32_t bin_read(char *argv) {
	uint32_t buf;
	FILE *fp = fopen(argv, "rb");

	if(fp == NULL) {
		printf("Unable to open the file. Check the name of the file\n");
		exit(1);
	}

	size_t result = fread(&buf, sizeof(uint32_t), 1, fp);
	if(result != 1) {
		printf("The file is smaller than 4 bytes in size\n");
		fclose(fp);
		exit(1);
	}

	uint32_t a = ntohl(buf);
	fclose(fp);
	return a;
}

int main(int argc, char **argv) {
	if(argc != 3) {
		printf("Please write 2 files in the argv\n");
		return 1;
	}
	
	uint32_t a = bin_read(argv[1]);
	uint32_t b = bin_read(argv[2]);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);
}
