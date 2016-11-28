#ifndef CUADROTEXTO_H
#define CUADROTEXTO_H

#include <iostream>
#include <SDL2/SDL.h>
#include "FuncionesPantalla.h"
#include "Scroll.h"

using namespace std;

class CuadroTexto
{
    private:
        SDL_Renderer* renderizador;
        SDL_Color colorTexto;
        float x;
        float y;
        float w;
        float h;
        int tamFuente; //0 = cambiante
        int careta;
        int posCaretaDesplegable;
        bool foco;
        bool habilitado;
        bool centrarX;
        bool centrarY;
        bool multiLinea;
        bool teclaApretada;
        int unilineaPos;      //Posicion Después del Cuadro de Texto
        List<int> posAcentos;
        string texto;
        Scroll* scroll;

    public:
    ///Constructor
        CuadroTexto();
        CuadroTexto(SDL_Renderer* ren);
        CuadroTexto(SDL_Renderer* ren, Scroll* s);
        ~CuadroTexto();

    ///Getters
        SDL_Renderer* getRenderizador();
        SDL_Color getColorTexto();
        int getTamFuente();
        float getX();
        float getY();
        float getW();
        float getH();
        bool getCentrarX();
        bool getCentrarY();
        bool getMultiLinea();
        int getCareta();
        bool getFoco();
        bool getHabilitado();
        string getTexto();
        Scroll* getScroll();
        int getUnilineaPos();
        bool getTeclaApretada();
        int getPosCaretaDesplegable();

    ///Setters
        void setRenderizador(SDL_Renderer* a);
        void setTamFuente(int a);
        void setColorTexto(SDL_Color a);
        void setX(float a);
        void setY(float a);
        void setW(float a);
        void setH(float a);
        void setMultiLinea(bool a);
        void setCentrarX(bool a);
        void setCentrarY(bool a);
        void setFoco(bool a);
        void setCareta(int a);
        void setHabilitado(bool a);
        void setTexto(string a);
        void setScroll(Scroll* a);
        void setUnilineaPos(int a);
        void setTeclaApretada(bool a);
        void setPosCaretaDesplegable(int a);

    ///Métodos Públicos
        void desplegar(FuncionesPantalla* f);
        void agregarTexto(string n);
        void procesarEvento(SDL_Event* ev);
        int pixelFuente();
        int maxCharLinea();
};

#endif // CUADROTEXTO_H
