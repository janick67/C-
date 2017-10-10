#include <windows.h>

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    MessageBox( NULL, "To jest wiadomość.", "Wiadomość", MB_ICONINFORMATION | MB_OKCANCEL );
    return 0;
}
