#ifndef PANTALLAPRINCIPAL_H
#define PANTALLAPRINCIPAL_H

#include <SDL2/SDL.h>
#include "FuncionesPantalla.h"
#include "AnastasiaChan.h"
#include "CuadroTexto.h"
#include "ConsolaComandos.h"

class PantallaPrincipal
{
    private:
        SDL_Window* ventana;
        SDL_Renderer* renderizador;
        FuncionesPantalla* f;
        AnastasiaChan *anastasia;
        CuadroTexto* cuadroBievenida;
        CuadroTexto* cuadroComandos;
        CuadroTexto* cuadroRespuesta;
        ConsolaComandos* consola;

    public:
        PantallaPrincipal();
        ~PantallaPrincipal();
        PantallaPrincipal(SDL_Window* w, SDL_Renderer* p, FuncionesPantalla* func);

        void mostrar();
        void imprimirPantallaInterna();
        string tiempoActual();
        void cargarImagen();
};

#endif // PANTALLAPRINCIPAL_H
