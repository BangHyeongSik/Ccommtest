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
	
	printf("忙");
	for (i = 0; i < (empty - flag) / 2; i++) {
		printf("式");
	}
	printf("[ %s", title);
	if (flag == 1) {
		printf(" ");
	}
	printf(" ]");
	for (i = 0; i < (empty - flag) / 2; i++) {
		printf("式");
	}
	printf("忖\n");

	for (i = 0; i < length; i++) {
		printf("弛 %02d. %-42s 弛\n", i + 1, contents[i]);
	}

	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
}

void loading(int isSuccess) {
	system("cls");
	printf("\n");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                   Loading.                     弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("\n");
	Sleep(1000);
	system("cls");
	printf("\n");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                   Loading..                    弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("\n");
	Sleep(1000);
	system("cls");
	printf("\n");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                   Loading...                   弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("\n");
	Sleep(1000);
	if (isSuccess == 1) {
		system("cls");
		printf("\n");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                    Success!                    弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("\n");
	}
	else if (isSuccess == 0) {
		system("cls");
		printf("\n");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                    Failed..                    弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("\n");
	}
}