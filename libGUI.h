#include <stdio.h>
#include <string.h>
#include <Windows.h>

#include "libFile.h"

void print_error(const char* context)
{
	DWORD error_code = GetLastError();
	char buffer[256];
	DWORD size = FormatMessageA(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_MAX_WIDTH_MASK,
		NULL, error_code, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
		buffer, sizeof(buffer), NULL);
	if (size == 0) { buffer[0] = 0; }
	fprintf(stderr, "%s: %s\n", context, buffer);
}

void defaultGUI(char* title, char** contents, int length) {
	int i, empty = 44 - strlen(title), flag = empty % 2;
	
	
	printf("��");
	for (i = 0; i < (empty - flag) / 2; i++) {
		printf("��");
	}
	printf("[ %s", title);
	if (flag == 1) {
		printf(" ");
	}
	printf(" ]");
	for (i = 0; i < (empty - flag) / 2; i++) {
		printf("��");
	}
	printf("��\n");

	for (i = 0; i < length; i++) {
		printf("�� %02d. %-42s ��\n", i + 1, contents[i]);
	}

	printf("����������������������������������������������������������������������������������������������������\n");
}

void loading(int isSuccess) {
	system("cls");
	printf("\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("��                   Loading.                     ��\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("\n");
	Sleep(1000);
	system("cls");
	printf("\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("��                   Loading..                    ��\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("\n");
	Sleep(1000);
	system("cls");
	printf("\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("��                   Loading...                   ��\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("\n");
	Sleep(1000);
	if (isSuccess == 1) {
		system("cls");
		printf("\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("��                   Success!                     ��\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("\n");
	}
	else if (isSuccess == 0) {
		system("cls");
		printf("\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("��                   Failed..                     ��\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("\n");
	}
}

char getLastValue(int num) {
	return dirDB[num].isLast;
}

char* getTitle(int num) {
	int stair = 0, result = 0;
	int i = 0;
	int point;
	while (num != 0) {
		point = num % 10;
		num /= 10;
		for (; i < dirDB_len; i++) {
			if (dirDB[i].num == stair) {
				point -= 1;
				if (point == 0) {
					result = i;
					break;
				}
			}
		}
		stair += 1;
	}
	printf("%s -- %d", dirDB[result].element, stair);

	
	return dirDB[result].element;
}

char** getContents(int num) {
	int stair = 0, result = 0;
	int i = 0, count = 0;
	int point;
	
	while (num != 0) {
		point = num % 10;
		num /= 10;
		for (; i < dirDB_len; i++) {
			if (dirDB[i].num == stair) {
				point -= 1;
				if (point == 0) {
					result = i;
					break;
				}
			}
		}
		stair += 1;
	}

	result += 1;
	i = result;
	while (stair <= dirDB[i].num && i < dirDB_len) {
		if (stair == dirDB[i].num) {
			printf("%d, %s, %c\n", dirDB[i].num, dirDB[i].element, dirDB[i].isLast);
		}
		i++;
	}

}

void showGUI(int num) {
	getTitle(num);
	getContents(num);
}