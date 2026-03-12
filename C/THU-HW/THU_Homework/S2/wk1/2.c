#include<stdio.h>

unsigned char reverse_table[256];

void init_reverse_table(void) {
	for (int i = 0; i < 256; ++i) {
		unsigned char byte = (unsigned char)i;
		unsigned char result = 0;
		for (int j = 0; j < 8; ++j) {
			result |= ((byte >> j) & 1) << (8 - 1 - j);
		}
		reverse_table[i] = result;
	}
}

int main(void) {
	FILE* fpi = fopen("input.dat", "rb");
	FILE* fpo = fopen("output.dat", "wb");
	if (fpi == NULL) return -1;
	if (fpo == NULL) return -1;
	init_reverse_table();
	
	unsigned char buffer;
	while (!feof(fpi)) {
		if (fread(&buffer, sizeof(unsigned char), 1, fpi) != 1) break;
			buffer = reverse_table[buffer];
		fwrite(&buffer, sizeof(unsigned char), 1, fpo);
	}
	fclose(fpi);
	fclose(fpo);
}