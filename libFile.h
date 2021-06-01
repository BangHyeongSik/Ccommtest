#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** openDirectory() {
	char* buffer;
	int size;
	int count;

	FILE* file = fopen("Directory.csv", "r");

	fseek(file, 0, SEEK_END);
	size = ftell(file);
	
	buffer = (char*)malloc(size + 1);
	
	if (buffer) {
		memset(buffer, 0, size + 1);

		fseek(file, 0, SEEK_SET);
		count = fread(buffer, size, 1, file);

		fclose(file);

		free(buffer);
	}
	

}