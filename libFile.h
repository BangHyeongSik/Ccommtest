#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DB_LENGTH 1000

struct directoryDB {
	int num;
	char element[100];
	char isLast;
};

struct mapDB {
	char element[100];
	char map[20];
};

struct directoryDB dirDB[MAX_DB_LENGTH];
struct mapDB mDB[MAX_DB_LENGTH];
int dirDB_len = 0;
int mDB_len = 0;

void getDirectory() {
	
	char buffer[1024];
	char* context = NULL;
	int num = 0;

	FILE* file;
	
	fopen_s(&file, "Directory.csv", "r");

	if (file) {
		while (fgets(buffer, sizeof(buffer), file) != NULL) {
			dirDB[num].num = atoi(strtok_s(buffer, ",", &context));
			strcpy_s(dirDB[num].element, 100, strtok_s(NULL, ",", &context));
			dirDB[num].isLast = strtok_s(NULL, "", &context)[0];

			num++;
		}
		dirDB_len = num;

		fclose(file);
	}
	
	
}

void getMap() {
	
	char buffer[1024];
	char* context = NULL;
	int num = 0;

	FILE* file;

	fopen_s(&file, "Map.csv", "r");

	if (file) {
		while (fgets(buffer, sizeof(buffer), file) != NULL) {
			strcpy_s(mDB[num].element, 100, strtok_s(buffer, ",", &context));
			strcpy_s(mDB[num].map, 20, strtok_s(NULL, ",", &context));

			num++;
		}
		mDB_len = num;

		fclose(file);
	}
}

char* getMapNumber(char* element) {
	int i;
	for (i = 0; i < mDB_len; i++) {
		if (strcmp(element, mDB[i].element) == 0) {
			return mDB[i].map;
		}
	}
}