#include <stdio.h>
#include <string.h>
#include <Windows.h>

#include "libFile.h"

typedef char* string;

string* lastElement[20];

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

	printf("┌");
	for (i = 0; i < (empty - flag) / 2; i++) {
		printf("─");
	}
	printf("[ %s", title);
	if (flag == 1) {
		printf(" ");
	}
	printf(" ]");
	for (i = 0; i < (empty - flag) / 2; i++) {
		printf("─");
	}
	printf("┐\n");

	for (i = 0; i < length; i++) {
		printf("│ %02d. %-42s │\n", i + 1, contents[i]);
	}
	printf("│ 00. 돌아가기                                   │\n");

	printf("└────────────────────────────────────────────────┘\n");
}

void loading(int isSuccess) {
	system("cls");
	printf("\n");
	printf("┌────────────────────────────────────────────────┐\n");
	printf("│                   Loading.                     │\n");
	printf("└────────────────────────────────────────────────┘\n");
	printf("\n");
	Sleep(1000);
	system("cls");
	printf("\n");
	printf("┌────────────────────────────────────────────────┐\n");
	printf("│                   Loading..                    │\n");
	printf("└────────────────────────────────────────────────┘\n");
	printf("\n");
	Sleep(1000);
	system("cls");
	printf("\n");
	printf("┌────────────────────────────────────────────────┐\n");
	printf("│                   Loading...                   │\n");
	printf("└────────────────────────────────────────────────┘\n");
	printf("\n");
	Sleep(1000);
	if (isSuccess == 1) {
		system("cls");
		printf("\n");
		printf("┌────────────────────────────────────────────────┐\n");
		printf("│                   Success!                     │\n");
		printf("└────────────────────────────────────────────────┘\n");
		printf("\n");
	}
	else if (isSuccess == 0) {
		system("cls");
		printf("\n");
		printf("┌────────────────────────────────────────────────┐\n");
		printf("│                   Failed..                     │\n");
		printf("└────────────────────────────────────────────────┘\n");
		printf("\n");
	}
}

char getLastValue(int num) {
	return dirDB[num].isLast;
}

int getTitle(int num, string* returnValue) {

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

	*returnValue = dirDB[result].element;
	
	return result;
}

int getContents(int num, string* returnValue) {

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
			*returnValue = dirDB[i].element;
			lastElement[count] = dirDB[i].element;
			count += 1;
			returnValue += 1;
		}
		i++;
	}

	return count;
}

int showGUI(int num) {
	string title = { 0 };
	string contents[100] = { 0 };
	int length = 0, lineNumber = 0;
	int returnValue = 0;
	char isLast = 'F';
	lineNumber = getTitle(num, &title);
	length = getContents(num, contents);
	defaultGUI(title, contents, length);

	isLast = dirDB[lineNumber].isLast;

	do {
		if (isLast == 'F') {
			printf("이동할 화면의 버튼을 선택해주세요 : ");
			scanf_s("%d", &returnValue);
		}
		else {
			printf("변경할 파라미터의 번호를 선택해주세요 : ");
			scanf_s("%d", &returnValue);
		}

		if (returnValue < 0 || returnValue > length) {
			printf("정상적인 번호를 입력해주세요.\n");
		}
	} while (returnValue < 0 || returnValue > length);

	if (isLast == 'T') {
		returnValue = -returnValue;
	}
	

	return returnValue;
}

char* sendMapElement(int number) {
	return getMapNumber(lastElement[number]);
}