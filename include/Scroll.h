#ifndef SCROLL_H
#define SCROLL_H

#include <SDL2/SDL.h>
#include "List.h"

class Scroll
{
    private:
        float x;
        float y;
        float w;
        float h;
        float tamBtn;
        bool desplegableY;
        SDL_Texture* scrollImage;
        float tamSalto;
        int pos;    //Linea actual
        int maxPos; //Maximas lineas de texto encontradas
        bool pulsado;
        float porcentajeTam;
        int posPulsacion;

    public:
        Scroll();
        Scroll(bool des, SDL_Texture* tex);

        ///Getters
        int getTamBtn();
        float getX();
        float getY();
        float getW();
        float getH();
        bool getDesplegableY();
        SDL_Texture* getScrollImage();
        float getTamSalto();
        int getPos();
        int getMaxPos();
        bool getPulsado();
        float getPorcentajeTam();
        int getPosPulsacion();

    ///Setters
        void setTamBtn(int a);
        void setX(float a);
        void setY(float a);
        void setW(float a);
        void setH(float a);
        void setDesplegableY(bool a);
        void setScrollImage(SDL_Texture* tex);
        void setTamSalto(float a);
        void setPos(int a);
        void setMaxPos(int a);
        void setPulsado(bool a);
        void setPorcentajeTam(float a);
        void setPosPulsacion(int a);

    ///Métodos
        List<int> calcularSaltosLinea(string* texto, int letrasLinea);
        void procesarEventoClick(SDL_Event* ev);
};

#endif // SCROLL_H
