#include <allegro.h>
int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth( 8 );
    set_gfx_mode( GFX_AUTODETECT, 800, 600, 0, 0 );
    set_palette( default_palette );
    clear_to_color( screen, 48 );
    textout_ex( screen, font, "Witaj w Allegro !", 20, 20, makecol( 255, 0, 255 ), - 1 );

    readkey();

    allegro_exit();
    return 0;
}
END_OF_MAIN()
