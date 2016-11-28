#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Constantes.h"
#include "FuncionesPantalla.h"
#include "PantallaPrincipal.h"

/**
* Clase Encargada de generar el inicio de la aplicacion e inicializacion
*
* @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
**/
class Principal
{
    private:
    ///Atributos
        PantallaPrincipal* p;

    public:
    ///Constructor
        Principal();

    ///Metodo
        void jugar();
};

#endif // PRINCIPAL_H
