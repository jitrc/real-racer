#include<SDL.h>

/*void mouseover(void){
    int mouse_x, mouse_y;
    SDL_PumpEvents();

    SDL_GetMouseState(&mouse_x, mouse_y);
    if
}
*/


int main(int argc, char *argv[]){

    //variables
    int done = 0;
    int mouse_x;
    int mouse_y;
    SDL_Init(SDL_INIT_VIDEO);

    //creating the window
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(150, 120, 0, SDL_ANYFORMAT|SDL_HWSURFACE);
    SDL_WM_SetCaption("Real-Racer", NULL);

    // nacitanie obrazku
    // pri exporte obrazkov v Ooffice.o su parametre sirka 201pt a vyska 41pt
    SDL_Surface *bt_start_img;
    bt_start_img = SDL_LoadBMP("data//textures//launcher//start.bmp");

    //tlacitko start
    SDL_Rect bt_start_src, bt_start_dest;
    bt_start_src.x = 0;
    bt_start_src.y = 0;
    bt_start_src.w = bt_start_img->w;
    bt_start_src.h = bt_start_img->h;

    bt_start_dest.x = 0;
    bt_start_dest.y = 0;
    bt_start_dest.w = bt_start_img->w;
    bt_start_dest.h = bt_start_img->h;

    SDL_Surface *bt_manual_img;
    bt_manual_img = SDL_LoadBMP("data//textures//launcher//manual.bmp");

    //tlacitko manual
    SDL_Rect bt_manual_src, bt_manual_dest;
    bt_manual_src.x = 0;
    bt_manual_src.y = 0;
    bt_manual_src.w = bt_manual_img->w;
    bt_manual_src.h = bt_manual_img->h;

    bt_manual_dest.x = 0;
    bt_manual_dest.y = 40;
    bt_manual_dest.w = bt_manual_img->w;
    bt_manual_dest.h = bt_manual_img->h;

    //tlacitko quit

    SDL_Surface * bt_quit_img;
    bt_quit_img = SDL_LoadBMP("data//textures//launcher//exit.bmp");
    SDL_Rect bt_quit_src, bt_quit_dest;
    bt_quit_src.x = 0;
    bt_quit_src.y = 0;
    bt_quit_src.w = bt_quit_img->w;
    bt_quit_src.h = bt_quit_img->h;

    bt_quit_dest.x = 0;
    bt_quit_dest.y = 80;
    bt_quit_dest.w = bt_quit_img->w;
    bt_quit_dest.h = bt_quit_img->h;


    //zobrazenie obrazku
    SDL_BlitSurface(bt_start_img, &bt_start_src,  screen, &bt_start_dest);
    SDL_BlitSurface(bt_manual_img, &bt_manual_src, screen, &bt_manual_dest);
    SDL_BlitSurface(bt_quit_img, &bt_quit_src, screen, &bt_quit_dest);
    SDL_Flip(screen);

    SDL_Event event;

    while(done == 0)
	{
	    SDL_Delay(5);
		// Smycka na spracovanie udalosti
		while(SDL_PollEvent(&event))
		{
			// Vetvenie podla dypu udalosti
			switch(event.type)
			{
			    case SDL_MOUSEMOTION:
                    mouse_x = event.button.x;
                    mouse_y = event.button.y;
                    /*kontrola umiestnenia myši
                     1. bt_nieco_src.x
                     2. bt_nieco_src.w
                     3. bt_nieco_dest.y
                     4. bt_nieco_dest.y + image ->h
                    */
                    case SDL_MOUSEBUTTONDOWN:
                        switch(event.button.button)
                            {
                            case SDL_BUTTON_LEFT:
                                if  ((mouse_x > bt_start_src.x) && (mouse_x < bt_start_src.w) && (mouse_y > bt_start_dest.y) && (mouse_y <bt_start_dest.y + bt_start_img ->h))
                                {
                                system("start.bat");
                                done = 1;
                                break;
                                }

                                if( ( mouse_x > bt_manual_src.x ) && ( mouse_x < bt_manual_src.w ) && ( mouse_y > bt_manual_dest.y ) && ( mouse_y < bt_manual_dest.y + bt_manual_img->h ))
                                {
                                system("readme.bat");
                                break;
                                }

                                if ((mouse_x > bt_quit_src.x) && (mouse_x < bt_quit_src.w) && (mouse_y > bt_quit_dest.y) && (mouse_y < bt_quit_dest.y + bt_quit_img ->h))
                                {
                                done = 1;
                                break;
                                }
                            }
					break;

				// sprava s pozidavkom na ukoncenie
				case SDL_QUIT:
					done = 1;
					SDL_FreeSurface(bt_start_img);
					SDL_FreeSurface(bt_manual_img);
					SDL_FreeSurface(bt_quit_img);
					break;

			}
		}
	}
    return 0;
    }
