#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Constantes.h"
#include "FuncionesPantalla.h"
#include "Principal.h"
#include "PantallaPrincipal.h"

using namespace std;

///Constructor
Principal::Principal()
{
    Principal::p = NULL;
}

/**
 * Punto de partida del juego a comenzar a jugar
 *
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 */
void Principal::jugar()
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    FuncionesPantalla* f = new FuncionesPantalla();

    //The surface contained by the window
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        exit(1);
    }

    if (TTF_Init() != 0)
    {
        printf( "SDL could not initialize! SDL_TTF: %s\n", SDL_GetError() );
        SDL_Quit();
        exit(1);
    }

    //Create window
    window = SDL_CreateWindow("Anastasia-chan Asistente Personal",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               VENTANA_TAM_X,
                               VENTANA_TAM_Y,
                               SDL_WINDOW_RESIZABLE);

    if(window == NULL)
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        exit(1);
    }

    SDL_Surface* icono = IMG_Load((f->getPath() + "Img/Icons/Icons.png").c_str());
    SDL_SetWindowIcon(window, icono);

    SDL_Renderer *ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (ren == NULL)
    {
        SDL_DestroyWindow(window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(-1);
    }

    //SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    p = new PantallaPrincipal(window, ren, f);
    p->mostrar();

    delete p;
    delete f;

	TTF_Quit();
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
