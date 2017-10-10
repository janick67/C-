#include <windows.h>
#include <Mmsystem.h>

int main()
{
    mciSendString(("Set CDAudio Door Open"), NULL, 0, NULL);
    return(0);
}
