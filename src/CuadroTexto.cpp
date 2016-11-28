#include <cctype>
#include "stringConvert.h"
#include "CuadroTexto.h"

///Constructor
CuadroTexto::CuadroTexto()
{
    CuadroTexto::renderizador = NULL;
    CuadroTexto::x = 0;
    CuadroTexto::y = 0;
    CuadroTexto::w = 0;
    CuadroTexto::h = 0;
    CuadroTexto::careta = 0;
    CuadroTexto::foco = false;
    CuadroTexto::texto = "";
    CuadroTexto::tamFuente = 12;
    CuadroTexto::habilitado = true;
    CuadroTexto::centrarX = false;
    CuadroTexto::centrarY = false;
    CuadroTexto::scroll = NULL;
    CuadroTexto::unilineaPos = 0;
    CuadroTexto::teclaApretada = false;
    CuadroTexto::posCaretaDesplegable = 0;
}

CuadroTexto::CuadroTexto(SDL_Renderer* ren)
{
    CuadroTexto::renderizador = ren;
    CuadroTexto::x = 0;
    CuadroTexto::y = 0;
    CuadroTexto::w = 0;
    CuadroTexto::h = 0;
    CuadroTexto::careta = 0;
    CuadroTexto::foco = false;
    CuadroTexto::texto = "";
    CuadroTexto::tamFuente = 12;
    CuadroTexto::habilitado = true;
    CuadroTexto::centrarX = false;
    CuadroTexto::centrarY = false;
    CuadroTexto::scroll = NULL;
    CuadroTexto::multiLinea = false;
    CuadroTexto::unilineaPos = 0;
    CuadroTexto::teclaApretada = false;
    CuadroTexto::posCaretaDesplegable = 0;
}

CuadroTexto::CuadroTexto(SDL_Renderer* ren, Scroll* s)
{
    CuadroTexto::renderizador = ren;
    CuadroTexto::x = 0;
    CuadroTexto::y = 0;
    CuadroTexto::w = 0;
    CuadroTexto::h = 0;
    CuadroTexto::careta = 0;
    CuadroTexto::foco = false;
    CuadroTexto::texto = "";
    CuadroTexto::tamFuente = 12;
    CuadroTexto::habilitado = true;
    CuadroTexto::centrarX = false;
    CuadroTexto::centrarY = false;
    CuadroTexto::scroll = s;
    CuadroTexto::multiLinea = false;
    CuadroTexto::unilineaPos = 0;
    CuadroTexto::teclaApretada = false;
    CuadroTexto::posCaretaDesplegable = 0;
}

CuadroTexto::~CuadroTexto()
{
    if (CuadroTexto::scroll != NULL)
    {
        delete scroll;
    }
}

///Getters
SDL_Renderer* CuadroTexto::getRenderizador()
{
    return CuadroTexto::renderizador;
}

int CuadroTexto::getTamFuente()
{
    return CuadroTexto::tamFuente;
}

float CuadroTexto::getX()
{
    return CuadroTexto::x;
}

float CuadroTexto::getY()
{
    return CuadroTexto::y;
}

float CuadroTexto::getW()
{
    return CuadroTexto::w;
}

float CuadroTexto::getH()
{
    return CuadroTexto::h;
}

int CuadroTexto::getCareta()
{
    return CuadroTexto::careta;
}

bool CuadroTexto::getFoco()
{
    return CuadroTexto::foco;
}

bool CuadroTexto::getHabilitado()
{
    return CuadroTexto::habilitado;
}

string CuadroTexto::getTexto()
{
    return CuadroTexto::texto;
}

SDL_Color CuadroTexto::getColorTexto()
{
    return CuadroTexto::colorTexto;
}

bool CuadroTexto::getCentrarX()
{
    return CuadroTexto::centrarX;
}

bool CuadroTexto::getCentrarY()
{
    return CuadroTexto::centrarY;
}

Scroll* CuadroTexto::getScroll()
{
    return CuadroTexto::scroll;
}

bool CuadroTexto::getMultiLinea()
{
    return CuadroTexto::multiLinea;
}

int CuadroTexto::getUnilineaPos()
{
    return CuadroTexto::unilineaPos;
}

bool CuadroTexto::getTeclaApretada()
{
    return CuadroTexto::teclaApretada;
}

int CuadroTexto::getPosCaretaDesplegable()
{
    return CuadroTexto::posCaretaDesplegable;
}

///Setter
void CuadroTexto::setRenderizador(SDL_Renderer* a)
{
    CuadroTexto::renderizador = a;
}

void CuadroTexto::setHabilitado(bool a)
{
    CuadroTexto::habilitado = a;
}

void CuadroTexto::setTamFuente(int a)
{
    CuadroTexto::tamFuente = a;
}

void CuadroTexto::setX(float a)
{
    CuadroTexto::x = a;
}

void CuadroTexto::setY(float a)
{
    CuadroTexto::y = a;
}

void CuadroTexto::setW(float a)
{
    CuadroTexto::w = a;
}

void CuadroTexto::setH(float a)
{
    CuadroTexto::h = a;
}

void CuadroTexto::setCentrarX(bool a)
{
    CuadroTexto::centrarX = a;
}

void CuadroTexto::setCentrarY(bool a)
{
    CuadroTexto::centrarY = a;
}

void CuadroTexto::setFoco(bool a)
{
    CuadroTexto::foco = a;
}

void CuadroTexto::setCareta(int a)
{
    if (a >= int(CuadroTexto::texto.size()))
    {
        CuadroTexto::careta = CuadroTexto::texto.size();
    }
    else if (a <= 0)
    {
        CuadroTexto::careta = 0;
    }
    else
    {
        CuadroTexto::careta = a;
    }
}

void CuadroTexto::setTexto(string a)
{
    CuadroTexto::texto = a;
}

void CuadroTexto::setColorTexto(SDL_Color a)
{
    CuadroTexto::colorTexto = a;
}

void CuadroTexto::setScroll(Scroll* a)
{
    CuadroTexto::scroll = a;
}

void CuadroTexto::setMultiLinea(bool a)
{
     CuadroTexto::multiLinea = a;
}

void CuadroTexto::setUnilineaPos(int a)
{
    CuadroTexto::unilineaPos = a;
}

void CuadroTexto::setTeclaApretada(bool a)
{
    CuadroTexto::teclaApretada = a;
}

void CuadroTexto::setPosCaretaDesplegable(int a)
{
    CuadroTexto::posCaretaDesplegable = a;
    int maxC = CuadroTexto::maxCharLinea();

    if (CuadroTexto::posCaretaDesplegable > maxC-1)
    {
        CuadroTexto::posCaretaDesplegable = maxC-1;
    }

    if (CuadroTexto::posCaretaDesplegable < 0)
    {
        CuadroTexto::posCaretaDesplegable = 0;
    }
}

///Métodos Públicos
void CuadroTexto::desplegar(FuncionesPantalla* f)
{
    if (not CuadroTexto::multiLinea)
    {
        if (texto != "")
        {
            SDL_Texture* fuenteCuadro1 = f->renderizarTexto(texto, "monospace", colorTexto, tamFuente, renderizador);

            int iW, iH;
            SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);

            bool cambiante = false;

            if (CuadroTexto::tamFuente == 0)
            {
                CuadroTexto::tamFuente = 5;
                cambiante = true;
            }

            int uPos = CuadroTexto::unilineaPos;
            string textoUsar = texto.substr(uPos, texto.size()-uPos);

            if (textoUsar == "")
            {
                textoUsar = " ";
            }

            if (cambiante)
            {
                while (iH < h * 0.70)
                {
                    SDL_DestroyTexture(fuenteCuadro1);
                    tamFuente++;

                    fuenteCuadro1 = f->renderizarTexto(textoUsar, "monospace", colorTexto, tamFuente, renderizador);
                    SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
                }
            }

            while (iW > w)
            {
                SDL_DestroyTexture(fuenteCuadro1);
                textoUsar = textoUsar.substr(0, textoUsar.size() - 1);

                fuenteCuadro1 = f->renderizarTexto(textoUsar, "monospace", colorTexto, tamFuente, renderizador);
                SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
            }

            if (centrarX && centrarY)
            {
                int tempX = (2*x+w - iW)/2;
                int tempY = (2*y+h - iH)/2;

                f->renderizarTextura(fuenteCuadro1, renderizador, tempX, tempY, iW, iH);

                if (foco)
                {
                    SDL_DestroyTexture(fuenteCuadro1);
                    fuenteCuadro1 = f->renderizarTexto("|", "monospace", colorTexto, tamFuente, renderizador);
                    SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
                    f->renderizarTextura(fuenteCuadro1, renderizador, tempX + CuadroTexto::posCaretaDesplegable * iW - iW/2, tempY);
                }
            }
            else if (centrarX)
            {
                int tempX = (2*x+w - iW)/2;

                f->renderizarTextura(fuenteCuadro1, renderizador, tempX, y, iW, iH);

                if (foco)
                {
                    SDL_DestroyTexture(fuenteCuadro1);
                    fuenteCuadro1 = f->renderizarTexto("|", "monospace", colorTexto, tamFuente, renderizador);
                    SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
                    f->renderizarTextura(fuenteCuadro1, renderizador, tempX + CuadroTexto::posCaretaDesplegable * iW - iW/2, y);
                }
            }
            else if (centrarY)
            {
                int tempY = (2*y+h - iH)/2;

                f->renderizarTextura(fuenteCuadro1, renderizador, x, tempY, iW, iH);

                if (foco)
                {
                    SDL_DestroyTexture(fuenteCuadro1);
                    fuenteCuadro1 = f->renderizarTexto("|", "monospace", colorTexto, tamFuente, renderizador);
                    SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
                    f->renderizarTextura(fuenteCuadro1, renderizador, x + CuadroTexto::posCaretaDesplegable * iW - iW/2, tempY);
                }
            }
            else
            {
                f->renderizarTextura(fuenteCuadro1, renderizador, x, y, iW, iH);

                if (foco)
                {
                    SDL_DestroyTexture(fuenteCuadro1);
                    fuenteCuadro1 = f->renderizarTexto("|", "monospace", colorTexto, tamFuente, renderizador);
                    SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
                    f->renderizarTextura(fuenteCuadro1, renderizador, x + CuadroTexto::posCaretaDesplegable * iW - iW/2, y);
                }
            }

            SDL_DestroyTexture(fuenteCuadro1);
        }
        else
        {
            if (foco)
            {
                SDL_Texture* fuenteCuadro1;
                bool cambiante = false;
                int iH, iW;

                if (CuadroTexto::tamFuente == 0)
                {
                    CuadroTexto::tamFuente = 5;
                    cambiante = true;
                }

                fuenteCuadro1 = f->renderizarTexto("|", "monospace", colorTexto, tamFuente, renderizador);
                SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);

                if (cambiante)
                {
                    while (iH < h * 0.70)
                    {
                        SDL_DestroyTexture(fuenteCuadro1);
                        tamFuente++;

                        fuenteCuadro1 = f->renderizarTexto("|", "monospace", colorTexto, tamFuente, renderizador);
                        SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
                    }
                }

                SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
                f->renderizarTextura(fuenteCuadro1, renderizador, x, y);
                SDL_DestroyTexture(fuenteCuadro1);
            }
        }
    }
    else
    {
        int iW, iH, tamLetrasLineas, tamLetra, lineasVentana;
        float yPrev = y;
        string textoUsar = texto;

        SDL_Texture* tex = f->renderizarTexto("O", "monospace", colorTexto, tamFuente, renderizador);
        SDL_QueryTexture(tex, NULL, NULL, &iW, &iH);
        SDL_DestroyTexture(tex);

        tamLetra = iW;
        tamLetrasLineas = (w/iW);
        lineasVentana = h/iH -1;

        string textoAux = texto;
        List<int> posiciones = scroll->calcularSaltosLinea(&textoAux, tamLetrasLineas);

        unsigned int i, lineasImpresas = 0;
        bool finTxt = true;
        for (i = scroll->getPos() + 1; i < posiciones.getSize() + 1; i++)
        {
            string aux;

            if (i == posiciones.getSize())
            {
                aux = textoAux.substr(posiciones[i-1], aux.size()-1);
            }
            else
            {
                aux = textoAux.substr(posiciones[i-1], posiciones[i]-posiciones[i-1]);
            }

            if (aux[0] == ' ')
            {
                aux.erase(0,1);
            }

            if (aux != "")
            {
                lineasImpresas++;

                tex = f->renderizarTexto(aux, "monospace", colorTexto, tamFuente, renderizador);
                f->renderizarTextura(tex, renderizador, x, yPrev);
                SDL_DestroyTexture(tex);

                yPrev = yPrev + tamLetra + 9;

                if (yPrev * 1.01 >= y+h)
                {
                    finTxt = false;
                    break;
                }
            }
        }

        if (finTxt && scroll->getPos() == 0) //Todo el texto cupo en el cuadro
        {
            scroll->setTamSalto(0);
            scroll->setPorcentajeTam(100);

            if (scroll->getDesplegableY())
            {
                f->renderizarTextura(scroll->getScrollImage(), renderizador, scroll->getX(),
                                     scroll->getY(), scroll->getW(), scroll->getH());
            }
        }
        else
        {
            float porcentajeTamScroll = (lineasVentana * 100 / scroll->getMaxPos());
            float saltoScroll = (100 - porcentajeTamScroll)/(scroll->getMaxPos()-lineasVentana);

            scroll->setMaxPos(scroll->getMaxPos()-lineasVentana);
            scroll->setTamSalto(saltoScroll);
            scroll->setPorcentajeTam(porcentajeTamScroll);

            f->renderizarTextura(scroll->getScrollImage(), renderizador, scroll->getX(),
                                 scroll->getY() + (scroll->getH() * saltoScroll / 100 * scroll->getPos()),
                                 scroll->getW(),
                                 scroll->getH() * porcentajeTamScroll / 100);
        }
    }
}

int CuadroTexto::pixelFuente()
{
    int iW, iH;
    FuncionesPantalla f;
    SDL_Texture* fuenteCuadro1 = f.renderizarTexto("O", "monospace", colorTexto, tamFuente, renderizador);
    SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
    SDL_DestroyTexture(fuenteCuadro1);

    return iW;
}

int CuadroTexto::maxCharLinea()
{
    FuncionesPantalla f;
    string textoUsar = "A";
    SDL_Texture* fuenteCuadro1 = f.renderizarTexto(textoUsar, "monospace", colorTexto, tamFuente, renderizador);

    int iW, iH;
    SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
    SDL_DestroyTexture(fuenteCuadro1);

    while (iW < w)
    {
        textoUsar = textoUsar + "A";

        fuenteCuadro1 = f.renderizarTexto(textoUsar, "monospace", colorTexto, tamFuente, renderizador);
        SDL_QueryTexture(fuenteCuadro1, NULL, NULL, &iW, &iH);
        SDL_DestroyTexture(fuenteCuadro1);
    }

    return textoUsar.size();
}

void CuadroTexto::procesarEvento(SDL_Event* ev)
{
    if (ev->type == SDL_MOUSEBUTTONDOWN)
    {
        if(ev->button.button == SDL_BUTTON_LEFT)
        {
            CuadroTexto::foco = false;

            int xPrev = ev->button.x;
            int yPrev = ev->button.y;

            //Apretar en zona del Scroll
            if (xPrev >= CuadroTexto::x && xPrev <= CuadroTexto::x + CuadroTexto::w)
            {
                if (yPrev >= y && yPrev < y+h) //posicion de careta con mouse
                {
                    CuadroTexto::foco = true;

                    if (not CuadroTexto::multiLinea)
                    {
                        if (CuadroTexto::habilitado)
                        {
                            float actPos = xPrev - CuadroTexto::x;
                            float tamLetra = CuadroTexto::pixelFuente();
                            unsigned posiblePos = actPos/tamLetra;

                            CuadroTexto::setCareta(posiblePos + unilineaPos);

                            if (int(texto.size()) < maxCharLinea())
                            {
                                CuadroTexto::setPosCaretaDesplegable(careta);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (ev->type == SDL_TEXTINPUT)
    {
        if (CuadroTexto::foco && CuadroTexto::habilitado)
        {
            string nuevaLetra = ev->text.text;

            if (posAcentos.isEmpty())
            {
                if (nuevaLetra.size() == 2)
                {
                    posAcentos.append(careta);
                }
            }
            else
            {
                posAcentos.sorted();

                //Recorrimiento de Lista de Acentos
                List<int> prev;
                for (unsigned int i = 0; i < posAcentos.getSize(); i++)
                {
                    if (posAcentos[i] >= careta)
                    {
                        prev.append(posAcentos[i]+1);
                    }
                    else
                    {
                        prev.append(posAcentos[i]);
                    }
                }

                if (nuevaLetra.size() == 2)
                {
                    prev.append(careta);
                }

                prev.sorted();
                posAcentos = prev;
            }

            if (texto == "")
            {
                texto = nuevaLetra;

                CuadroTexto::setCareta(+nuevaLetra.size());
                CuadroTexto::setPosCaretaDesplegable(1);
            }
            else
            {
                texto = texto.substr(0, careta) +
                        nuevaLetra +
                        texto.substr(careta, texto.size()-careta);

                CuadroTexto::setCareta(careta+nuevaLetra.size());
                CuadroTexto::setPosCaretaDesplegable(posCaretaDesplegable+1);

                if (careta > maxCharLinea())
                {
                    CuadroTexto::setUnilineaPos(unilineaPos+1);
                }
            }
        }
    }
    else if (ev->type == SDL_KEYUP)
    {
        if (CuadroTexto::foco && CuadroTexto::habilitado)
        {
            if (not CuadroTexto::multiLinea)
            {
                if (ev->key.keysym.sym == SDLK_LEFT)
                {
                    int contadorAcentos = 0;
                    bool proximoAcento = false;

                    //Recorrimiento de Lista de Acentos
                    for (unsigned int i = 0; i < posAcentos.getSize(); i++)
                    {
                        if (posAcentos[i] == careta-2)
                        {
                            proximoAcento = true;
                        }

                        if (posAcentos[i] < careta)
                        {
                            contadorAcentos++;
                        }
                    }

                    if (careta == unilineaPos) //Careta al final
                    {
                        int pasCar = careta;

                        if (proximoAcento)
                        {
                            CuadroTexto::setCareta(CuadroTexto::careta-2);
                        }
                        else
                        {
                            CuadroTexto::setCareta(CuadroTexto::careta-1);
                        }

                        if (pasCar != careta)
                        {
                            if (proximoAcento)
                            {
                                CuadroTexto::setUnilineaPos(CuadroTexto::unilineaPos-2);
                            }
                            else
                            {
                                CuadroTexto::setUnilineaPos(CuadroTexto::unilineaPos-1);
                            }
                        }
                    }
                    else
                    {
                        if (proximoAcento)
                        {
                            CuadroTexto::setCareta(CuadroTexto::careta-2);
                        }
                        else
                        {
                            CuadroTexto::setCareta(CuadroTexto::careta-1);
                        }

                        CuadroTexto::setPosCaretaDesplegable(CuadroTexto::posCaretaDesplegable-1);
                    }
                }
                else if (ev->key.keysym.sym == SDLK_RIGHT)
                {
                    int contadorAcentos = 0;
                    bool proximoAcento = false;

                    //Recorremos la lista de acentos
                    for (unsigned int i = 0; i < posAcentos.getSize(); i++)
                    {
                        if (posAcentos[i] == careta)
                        {
                            proximoAcento = true;
                            contadorAcentos++;
                        }
                        else if (posAcentos[i] < careta)
                        {
                            contadorAcentos++;
                        }
                    }

                    if (careta - unilineaPos == maxCharLinea()-1) //Sale del cuadro de texto
                    {
                        int posCareta = careta;

                        if (proximoAcento)
                        {
                            CuadroTexto::setCareta(careta+2);
                        }
                        else
                        {
                            CuadroTexto::setCareta(careta+1);
                        }

                        CuadroTexto::setPosCaretaDesplegable(CuadroTexto::posCaretaDesplegable+1);

                        if (posCareta != careta)
                        {
                            if (proximoAcento)
                            {
                                CuadroTexto::setUnilineaPos(CuadroTexto::unilineaPos+2);
                            }
                            else
                            {
                                CuadroTexto::setUnilineaPos(CuadroTexto::unilineaPos+1);
                            }

                            if (int(texto.size())-contadorAcentos < maxCharLinea())
                            {
                                CuadroTexto::setPosCaretaDesplegable(careta-contadorAcentos);
                            }
                        }
                    }
                    else //Esta en el cuadro de texto
                    {
                        if (proximoAcento)
                        {
                            CuadroTexto::setCareta(careta+2);
                        }
                        else
                        {
                            CuadroTexto::setCareta(careta+1);
                        }

                        CuadroTexto::setPosCaretaDesplegable(CuadroTexto::posCaretaDesplegable+1);

                        if (int(texto.size())-contadorAcentos < maxCharLinea())
                        {
                            CuadroTexto::setPosCaretaDesplegable(careta-contadorAcentos);
                        }
                    }
                }
                else if (ev->key.keysym.sym == SDLK_END)
                {
                    int maxC = maxCharLinea();
                    int acentosBarra = 0;

                    if (not posAcentos.isEmpty())
                    {
                        posAcentos.sorted();

                        for (unsigned int i = 0; i < posAcentos.getSize(); i++)
                        {
                            if (posAcentos[i] < maxC)
                            {
                                acentosBarra++;
                            }
                            else
                            {
                                break;
                            }
                        }

                    }

                    if ((int)texto.size()-acentosBarra < maxC)
                    {
                        CuadroTexto::setPosCaretaDesplegable(texto.size()-acentosBarra);
                        CuadroTexto::setUnilineaPos(0);
                        CuadroTexto::setCareta(CuadroTexto::texto.size() + 1);
                    }
                    else
                    {
                        CuadroTexto::setPosCaretaDesplegable(maxC-1);
                        CuadroTexto::setUnilineaPos(CuadroTexto::texto.size() - maxC + 1);
                        CuadroTexto::setCareta(CuadroTexto::texto.size() + 1);
                    }
                }
                else if (ev->key.keysym.sym == SDLK_HOME)
                {
                    CuadroTexto::setCareta(0);
                    CuadroTexto::setUnilineaPos(0);
                    CuadroTexto::setPosCaretaDesplegable(0);
                }
                else if (ev->key.keysym.sym == SDLK_DELETE)
                {
                    int posProximoAcento = -1;

                    //Recorremos la lista de acentos
                    for (unsigned int i = 0; i < posAcentos.getSize(); i++)
                    {
                        if (posAcentos[i] == careta)
                        {
                            posProximoAcento = i;
                        }
                    }

                    if (texto != "" && careta != int(texto.size()))
                    {
                        if (posProximoAcento == -1)
                        {
                            CuadroTexto::setTexto(texto.erase(careta, 1));
                        }
                        else
                        {
                            CuadroTexto::setTexto(texto.erase(careta, 2));
                            posAcentos.deleteForPosition(posProximoAcento);
                        }
                    }
                }
                else if (ev->key.keysym.sym == SDLK_BACKSPACE)
                {
                    int posProximoAcento = -1;

                    //Recorremos la lista de acentos
                    for (unsigned int i = 0; i < posAcentos.getSize(); i++)
                    {
                        if (posAcentos[i] == careta-2)
                        {
                            posProximoAcento = i;
                        }
                    }

                    if (texto != "" && careta != 0)
                    {
                        if (posProximoAcento != -1)
                        {
                            CuadroTexto::setTexto(texto.erase(careta-2, 2));

                            CuadroTexto::setCareta(careta-2);
                            CuadroTexto::posCaretaDesplegable = posCaretaDesplegable-1;

                            posAcentos.deleteForPosition(posProximoAcento);
                        }
                        else
                        {
                            CuadroTexto::setTexto(texto.erase(careta-1, 1));

                            CuadroTexto::setCareta(careta-1);
                            CuadroTexto::posCaretaDesplegable = posCaretaDesplegable-1;
                        }
                    }
                }
                else if (ev->key.keysym.sym == SDLK_KP_ENTER ||
                         ev->key.keysym.sym == SDLK_RETURN   ||
                         ev->key.keysym.sym == SDLK_RETURN2)
                {
                    posAcentos.nullify();
                }
            }
        }
    }
}
