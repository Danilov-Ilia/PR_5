#include <windows.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    HANDLE hEvent = OpenEvent(EVENT_MODIFY_STATE, FALSE, TEXT("EventSync")); // открываем событие для синхронизации между процессами
    if (hEvent == NULL) { // проверяем на ошибку открытия
        printf("Error opening the event: %d\n", GetLastError());
        return 1;
    }

    printf("SLAVE: Started\n");

    char c;
    while (1) { // бесконечный цикл для ввода символов и установки события
        c = _getch(); // считываем с клавиатуры символ без вывода на экран

        printf("%c+ * +", c); // выводим на экран полученный с клавиатуры символ

        SetEvent(hEvent); // устанавливаем событие

        fflush(stdout); // принудительно очищаем буфер вывода

    }

    CloseHandle(hEvent); // закрываем дескриптор события

    return 0;
}