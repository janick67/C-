#include <allegro.h>
int main()
{
    al_init();
    al_install_keyboard();
    ALLEGRO_KEYBOARD_STATE klawiatura;
    ALLEGRO_DISPLAY * okno = al_create_display( 320, 240 );
    al_set_window_title( okno, "Allegro5" );
    while( !al_key_down( & klawiatura, ALLEGRO_KEY_ESCAPE ) )
    {
        al_get_keyboard_state( & klawiatura );
        al_clear_to_color( al_map_rgb( 0, 255, 0 ) );
        al_flip_display();
    }
    al_destroy_display( okno );
    return 0;
}
