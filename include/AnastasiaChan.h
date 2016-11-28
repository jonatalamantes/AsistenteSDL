#ifndef ANASTASIACHAN_H
#define ANASTASIACHAN_H

#include <SDL2/SDL.h>
#include "List.h"

class AnastasiaChan
{
    private:
        int accesorio;
        int boca;
        int brazos;
        int cabeza;
        int ojos;
        int piernas;
        int traje;
        float fondo;
        SDL_Renderer* renderizador;
        List< List<SDL_Texture*> > figuras; //Primero para el tipo, segundo para la longitudad

        //Variables para el habla
        bool hablando;
        Uint32 tiempoHabla;
        bool hablarAsc;
        unsigned microsegEsperaParpadeo;
        unsigned microsegVelParpadeo;

        //Variables para el parpadeo
        Uint32 tiempoEsperaParpadeo;
        Uint32 tiempoParpadeo;
        bool parpadear;
        bool parpadeoAsc;
        unsigned microsegEsperaHabla;

        //Variables para el findo
        Uint32 tiempoFondo;
        unsigned microsegEsperaFondo;

    public:
    ///Constructor
        AnastasiaChan();
        AnastasiaChan(SDL_Renderer* ren);
        ~AnastasiaChan();

    ///Getters
        int getAccesorio();
        int getBoca();
        int getBrazos();
        int getCabeza();
        int getOjos();
        int getPiernas();
        int getTraje();
        float getFondo();
        SDL_Renderer* getRenderizador();
        SDL_Texture* getFiguras(string tipo, unsigned int pos);

        bool getHablando();
        Uint32 getTiempoHabla();
        bool getHablarAsc();
        unsigned getMicrosegEsperaHabla();

        Uint32 getTiempoEsperaParpadeo();
        Uint32 getTiempoParpadeo();
        bool getParpadear();
        bool getParpadeoAsc();
        unsigned getMicrosegEsperaParpadeo();
        unsigned getMicrosegVelParpadeo();

        Uint32 getTiempoFondo();
        unsigned getMicrosegEsperaFondo();

    ///Setters
        void setAccesorio(int x);
        void setBoca(int x);
        void setBrazos(int x);
        void setCabeza(int x);
        void setOjos(int x);
        void setPiernas(int x);
        void setTraje(int x);
        void setFondo(float x);
        void setRenderizador(SDL_Renderer* x);

        void setHablando(bool a);
        void setTiempoHabla(Uint32 a);
        void setHablarAsc(bool a);
        void setMicrosegEsperaHabla(unsigned a);

        void setTiempoEsperaParpadeo(Uint32 a);
        void setTiempoParpadeo(Uint32 a);
        void setParpadear(bool a);
        void setParpadeoAsc(bool a);
        void setMicrosegEsperaParpadeo(unsigned a);
        void setMicrosegVelParpadeo(unsigned a);

        void setTiempoFondo(Uint32 a);
        void setMicrosegEsperaFondo(unsigned a);

    ///Inicializar
        void inicializar();
        void desplegar(SDL_Window* ventana);
        void liberar();
        void imprimir();

};

#endif // ANASTASIACHAN_H
