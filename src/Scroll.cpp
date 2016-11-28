#include "Scroll.h"

Scroll::Scroll()
{
    Scroll::x = 0;
    Scroll::y = 0;
    Scroll::w = 0;
    Scroll::h = 0;
    Scroll::tamBtn = 0;
    Scroll::desplegableY = false;
    Scroll::scrollImage = NULL;
    Scroll::tamSalto = 12;
    Scroll::pos = 0;
    Scroll::maxPos = 0;
    Scroll::pulsado = false;
    Scroll::porcentajeTam = 100;
    Scroll::posPulsacion = 0;
}

Scroll::Scroll(bool des, SDL_Texture* tex)
{
    Scroll::x = 0;
    Scroll::y = 0;
    Scroll::w = 0;
    Scroll::h = 0;
    Scroll::tamBtn = 0;
    Scroll::desplegableY = des;
    Scroll::scrollImage = tex;
    Scroll::tamSalto = 12;
    Scroll::pos = 0;
    Scroll::maxPos = 0;
    Scroll::pulsado = false;
    Scroll::porcentajeTam = 100;
    Scroll::posPulsacion = 0;
}

///Getters
int Scroll::getTamBtn()
{
    return Scroll::tamBtn;
}

float Scroll::getX()
{
    return Scroll::x;
}

float Scroll::getY()
{
    return Scroll::y;
}

float Scroll::getW()
{
    return Scroll::w;
}

float Scroll::getH()
{
    return Scroll::h;
}

float Scroll::getPorcentajeTam()
{
    return Scroll::porcentajeTam;
}

bool Scroll::getDesplegableY()
{
    return Scroll::desplegableY;
}

SDL_Texture* Scroll::getScrollImage()
{
    return Scroll::scrollImage;
}

int Scroll::getMaxPos()
{
    return Scroll::maxPos;
}

int Scroll::getPos()
{
    return Scroll::pos;
}

float Scroll::getTamSalto()
{
    return Scroll::tamSalto;
}

///Setter
void Scroll::setDesplegableY(bool a)
{
    Scroll::desplegableY = a;
}

void Scroll::setTamBtn(int a)
{
    Scroll::tamBtn = a;
}

void Scroll::setX(float a)
{
    Scroll::x = a;
}

void Scroll::setY(float a)
{
    Scroll::y = a;
}

void Scroll::setW(float a)
{
    Scroll::w = a;
}

void Scroll::setH(float a)
{
    Scroll::h = a;
}

void Scroll::setScrollImage(SDL_Texture* a)
{
    Scroll::scrollImage = a;
}

void Scroll::setMaxPos(int a)
{
    Scroll::maxPos = a;
}

void Scroll::setTamSalto(float a)
{
    Scroll::tamSalto = a;
}

void Scroll::setPos(int a)
{
    Scroll::pos = a;

    if (Scroll::pos > Scroll::maxPos)
    {
        Scroll::pos = Scroll::maxPos;
    }

    if (Scroll::pos < 0)
    {
        Scroll::pos = 0;
    }
}

void Scroll::setPorcentajeTam(float a)
{
    Scroll::porcentajeTam = a;
}

List<int> Scroll::calcularSaltosLinea(string* texto, int letrasLinea)
{
    List<int> temp;
    int contador = 0;

    temp.append(0);

    for (unsigned i = 0; i < texto->size(); i++)
    {
        if (int((*texto)[i]) == 10) //enter
        {
            temp.append(i);
            (*texto)[i] = ' ';
            contador = 0;
        }
        else if ((int)(*texto)[i] == 13) //retorno de carro
        {
            (*texto)[i] = ' ';
            contador++;
        }
        else if ((int)(*texto)[i] == -61) //caracter especial
        {
            contador++;
            i++;
        }
        else
        {
            contador++;
        }

        if (contador >= letrasLinea)
        {
            contador = 0;
            temp.append(i+1);
        }
    }

    Scroll::maxPos = temp.getSize() + 1;
    return temp;
}

void Scroll::procesarEventoClick(SDL_Event* ev)
{
    if (ev->type == SDL_MOUSEBUTTONDOWN)
    {
        if(ev->button.button == SDL_BUTTON_LEFT)
        {
            Scroll::pulsado = false;

            int xPrev = ev->button.x;
            int yPrev = ev->button.y;

            if (tamSalto != 0)
            {
                //Apretar en zona del Scroll
                if (xPrev >= x && xPrev <= x + w)
                {
                    if (yPrev >= y - tamBtn && yPrev < y) //BtnArriba
                    {
                        Scroll::setPos(pos-1);
                    }
                    else if (yPrev <= y+h + tamBtn && yPrev >= y+h) //btnAbajo
                    {
                        Scroll::setPos(pos+1);
                    }
                    else //scroll intermedio
                    {
                        int yInit = Scroll::y + Scroll::h * Scroll::tamSalto / 100 * Scroll::pos;
                        int yPost = yInit + Scroll::h * Scroll::porcentajeTam / 100;

                        if (yPrev >= yInit && yPrev <= yPost)
                        {
                            Scroll::posPulsacion = yPrev;
                            Scroll::pulsado = true;
                        }
                        else if (yPrev > yInit)
                        {
                            Scroll::setPos(Scroll::pos+1);
                        }
                        else
                        {
                            Scroll::setPos(Scroll::pos-1);
                        }
                    }
                }
            }
        }
    }
    else if (ev->type == SDL_MOUSEBUTTONUP)
    {
        Scroll::pulsado = false;
    }
    else if (ev->type == SDL_MOUSEMOTION)
    {
        if (Scroll::pulsado)
        {
            int yInit = Scroll::y + Scroll::h * Scroll::tamSalto / 100 * Scroll::pos;
            int aj = Scroll::posPulsacion - yInit;
            int yAct = ev->motion.y - aj;
            int pixSalto = (Scroll::tamSalto * h / 100);

            if (yAct < yInit)
            {
                int difPix = yInit - yAct;

                int prevPos = Scroll::pos;

                Scroll::setPos(Scroll::pos - difPix/pixSalto);

                if (prevPos != Scroll::pos)
                {
                    Scroll::posPulsacion = ev->motion.y;
                }
            }
            else if (yAct > yInit)
            {
                int difPix = yAct - yInit;
                int prevPos = Scroll::pos;

                Scroll::setPos(Scroll::pos + difPix/pixSalto);

                if (prevPos != Scroll::pos)
                {
                    Scroll::posPulsacion = ev->motion.y;
                }
            }
        }
    }
}
