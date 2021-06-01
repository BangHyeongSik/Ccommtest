#include <stdio.h>
#include <string.h>
#include <Windows.h>

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
		printf("��                    Success!                    ��\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("\n");
	}
	else if (isSuccess == 0) {
		system("cls");
		printf("\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("��                    Failed..                    ��\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("\n");
	}
}