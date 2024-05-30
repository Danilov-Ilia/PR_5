#include <windows.h>
#include <stdio.h>

int main()
{
    HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("EventSync")); // создаем событие для синхронизации между процессами
    if (hEvent == NULL) { // проверяем на ошибку открытия
        printf("Error creating the event: %d\n", GetLastError());
        return 1;
    }

    printf("MASTER: Started\n");

    while (1) {  // бесконечный цикл для ожидания установки события и вывода "*"
        WaitForSingleObject(hEvent, INFINITE); // ожидаем установку события

        printf("*");

        fflush(stdout); // принудительно очищаем буфер вывода

        ResetEvent(hEvent); // сбрасываем событие после его использования

    }

    CloseHandle(hEvent); // закрываем дескриптор события

    return 0;
}