#include "windows.h"
#include "xinput.h"
#include "stdio.h"
int main(void){
  HINSTANCE hXInputDLL = LoadLibraryA("XInput1_3.dll");
   if (hXInputDLL == NULL){
       printf("Controle nao encontrado");
       return 1;
   }
   for (short i = 0; i < 4; ++i){
         typedef DWORD(WINAPI * XInputPowerOffController_t)(DWORD i);
         XInputPowerOffController_t realXInputPowerOffController = (XInputPowerOffController_t)GetProcAddress(hXInputDLL, (LPCSTR)103);
         realXInputPowerOffController(i);
   }

  FreeLibrary(hXInputDLL);
  printf("DESLIGOU TUDO");
  TerminateProcess(OpenProcess(SYNCHRONIZE | PROCESS_TERMINATE, TRUE, GetCurrentProcessId()), 0);
  return 0;
}
