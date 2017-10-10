#include <windows.h>
#include<io.h>
#include<stdio.h>
#include<winsock2.h>


LPSTR NazwaKlasy = "Klasa Okienka";
HWND g_buton[9] ;
MSG Komunikat;


     WSADATA wsa;
    SOCKET s , new_socket;
    struct sockaddr_in server , client;
    fd_set read_fds;
   // const timeval tv={0,0};
    int c,j=0;
    char message[10];
   // timeval tv;

    int odbierz()
{
   //   tv.tv_sec=0;
   //tv.tv_usec=0;
    printf("select %d:)\n",select( new_socket+1, & read_fds, NULL, NULL, NULL));
    if( FD_ISSET( new_socket, & read_fds ) ){
            printf("mamy go!\n");
    if(( recv( new_socket, message, sizeof( message ), 0 ) ) > 0 ) {
        int i=static_cast < int > (message[0])-48;
        if (i >-1 && i<9) SetWindowText(g_buton[i],"O");
        printf("%d",i);
        }}

    return 0;
    }

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

    // WYPE£NIANIE STRUKTURY
    WNDCLASSEX wc;

    wc.cbSize = sizeof( WNDCLASSEX );
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );

    // REJESTROWANIE KLASY OKNA
    if( !RegisterClassEx( & wc ) )
    {
        MessageBox( NULL, "Wysoka Komisja odmawia rejestracji tego okna!", "Niestety...",
        MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }

    // TWORZENIE OKNA
    HWND hwnd;

    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "Oto okienko", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 235, 255, NULL, NULL, hInstance, NULL );
int i, x=0, y=0;;
for (i=0; i<9; i++)
{
g_buton[i] = CreateWindowEx( 0, "BUTTON", "", WS_CHILD | WS_VISIBLE, 20+x, 20+y, 50, 50, hwnd, NULL, hInstance, NULL );
 x+=60;
 if (i==2 || i==5){
    x=0;
    y+=60;
 }
 printf("x=%d y=%d\n",x,y);
}

    if( hwnd == NULL )
    {
        MessageBox( NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION );
        return 1;
    }

    ShowWindow( hwnd, nCmdShow ); // Poka¿ okienko...
    UpdateWindow( hwnd );





    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 1234 );

    //Bind
    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    puts("Bind done");

    //Listen to incoming connections
    listen(s , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);

    new_socket = accept(s , (struct sockaddr *)&client, &c);
        puts("Connection accepted");
        FD_SET( new_socket, & read_fds );

    if (new_socket == INVALID_SOCKET)
    {
        printf("accept failed with error code : %d" , WSAGetLastError());
        return 1;
    }











    // Pêtla komunikatów
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        odbierz();
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }

    closesocket(s);
    WSACleanup();
    return Komunikat.wParam;
}


// OBS£UGA ZDARZEÑ
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    int i;
    switch( msg )
    {
    case WM_COMMAND:
        for (i=0; i<9; i++)
        {
            if(( HWND ) lParam == g_buton[i] )
            {
            SetWindowText(g_buton[i],"X");
            message[0] = static_cast<char> (i)+48;
            send(new_socket ,&message[0] , 1 , 0);
/*switch (i)
{
 case 0:
 send(new_socket ,"0" , 1 , 0);
 break;
 case 1:
 send(new_socket ,"1" , 1 , 0);
 break;
 case 2:
 send(new_socket ,"2" , 1 , 0);
 break;
 case 3:
 send(new_socket ,"3" , 1 , 0);
 break;
 case 4:
 send(new_socket ,"4" , 1 , 0);
 break;
 case 5:
 send(new_socket ,"5" , 1 , 0);
 break;
 case 6:
 send(new_socket ,"6" , 1 , 0);
 break;
 case 7:
 send(new_socket ,"7" , 1 , 0);
 break;
 case 8:
 send(new_socket ,"8" , 1 , 0);
 break;
}*/
        }}

        break;
    case WM_CLOSE:
        DestroyWindow( hwnd );
        break;

    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;

        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
}
