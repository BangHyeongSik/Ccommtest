#include <stdio.h>
#include <stdint.h>
#include <windows.h>

#include "libGUI.h"
#include "libSerial.h"

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

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

// Opens the specified serial port, configures its timeouts, and sets its
// baud rate.  Returns a handle on success, or INVALID_HANDLE_VALUE on failure.


HANDLE serialConnect() {
    char comport[6] = { 0 }, parityBit[6] = { 0 }, stop_Bits[4] = { 0 };
    int baud = 9600, dataLength = 8;
    char device[9] = { 0 };
    int parity = 0, stopbits = 0;

    char* theTest[5] = { "Comport", "BAUD Rate", "Parity", "Data Length", "Stop Bit" };
    defaultGUI("Communication Setting", theTest, 5);
    gotoxy(44, 1);
    scanf_s("%s", comport, 5);
    gotoxy(43, 2);
    scanf_s("%d", &baud);
    gotoxy(45, 3);
    scanf_s("%s", parityBit, 5);
    gotoxy(45, 4);
    printf("Bits");
    gotoxy(43, 4);
    scanf_s("%d", &dataLength);
    gotoxy(43, 5);
    printf("Bit(s)");
    gotoxy(39, 5);
    scanf_s("%s", stop_Bits, 3);

    sprintf_s(device, 9, "\\\\.\\%s", comport);
    if (parityBit) {
        if (strcmp(parityBit, "NONE") == 0) {
            parity = 0;
        }
        else if (strcmp(parityBit, "ODD") == 0) {
            parity = 1;
        }
        else if (strcmp(parityBit, "EVEN") == 0) {
            parity = 2;
        }
        else if (strcmp(parityBit, "MARK") == 0) {
            parity = 3;
        }
        else if (strcmp(parityBit, "SPACE") == 0) {
            parity = 4;
        }
    }

    if (strcmp(stop_Bits, "1") == 0) {
        stopbits = 0;
    }
    else if (strcmp(stop_Bits, "1.5") == 0) {
        stopbits = 1;
    }
    else if (strcmp(stop_Bits, "2") == 0) {
        stopbits = 2;
    }

    return open_serial_port(device, baud, parity, dataLength, stopbits);

}

int main()
{
    HANDLE port = serialConnect();
    printf("\n");

    if (port == INVALID_HANDLE_VALUE) { return 1; }
    else {
        loading(1);
    }


    uint8_t test[8] = { 0x01, 0x06, 0x00, 0x67, 0x00, 0x01, 0xF9, 0xD5 };

    int result2 = write_port(port, test, sizeof(test));
    uint8_t testbuffer[1024];

    int result3 = read_port(port, testbuffer, 1024);
    int i = 0;
    char newInt[2048];
    for (i = 0; i < result3; i++) {
        sprintf_s(newInt, 2048, "%02x", testbuffer[i]);
        printf_s("%s", newInt);
    }
    
    CloseHandle(port);
    return 0;
}