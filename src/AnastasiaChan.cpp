#include <cerrno>
#include "AnastasiaChan.h"
#include "FuncionesPantalla.h"
#include "stringConvert.h"
#include "Constantes.h"

AnastasiaChan::AnastasiaChan()
{
    AnastasiaChan::renderizador = NULL;
    AnastasiaChan::inicializar();
}

AnastasiaChan::AnastasiaChan(SDL_Renderer* ren)
{
    AnastasiaChan::renderizador = ren;
    AnastasiaChan::inicializar();
}

AnastasiaChan::~AnastasiaChan()
{
    AnastasiaChan::liberar();
}

///Getters
int AnastasiaChan::getAccesorio()
{
    return AnastasiaChan::accesorio;
}

int AnastasiaChan::getBoca()
{
    return AnastasiaChan::boca;
}

int AnastasiaChan::getBrazos()
{
    return AnastasiaChan::brazos;
}

int AnastasiaChan::getCabeza()
{
    return AnastasiaChan::cabeza;
}

float AnastasiaChan::getFondo()
{
    return AnastasiaChan::fondo;
}

int AnastasiaChan::getOjos()
{
    return AnastasiaChan::ojos;
}
int AnastasiaChan::getPiernas()
{
    return AnastasiaChan::piernas;
}
int AnastasiaChan::getTraje()
{
    return AnastasiaChan::traje;
}

SDL_Renderer* AnastasiaChan::getRenderizador()
{
    return AnastasiaChan::renderizador;
}

SDL_Texture* AnastasiaChan::getFiguras(string tipo, unsigned int pos)
{
    if (tipo == "accesorio")
    {
        if (pos < 0 || pos > AnastasiaChan::figuras[0].getSize())
        {
            return NULL;
        }
        else
        {
            return AnastasiaChan::figuras[0].recover(pos);
        }
    }
    else if (tipo == "boca")
    {
        if (pos < 0 || pos > AnastasiaChan::figuras[1].getSize())
        {
            return NULL;
        }
        else
        {
            return AnastasiaChan::figuras[1].recover(pos);
        }
    }
    else if (tipo == "brazos")
    {
        if (pos < 0 || pos > AnastasiaChan::figuras[2].getSize())
        {
            return NULL;
        }
        else
        {
            return AnastasiaChan::figuras[2].recover(pos);
        }
    }
    else if (tipo == "cabeza")
    {
        if (pos < 0 || pos > AnastasiaChan::figuras[3].getSize())
        {
            return NULL;
        }
        else
        {
            return AnastasiaChan::figuras[3].recover(pos);
        }
    }
    else if (tipo == "fondo")
    {
        if (pos < 0 || pos > AnastasiaChan::figuras[4].getSize())
        {
            return NULL;
        }
        else
        {
            return AnastasiaChan::figuras[4].recover(pos);
        }
    }
    else if (tipo == "ojos")
    {
        if (pos < 0 || pos > AnastasiaChan::figuras[5].getSize())
        {
            return NULL;
        }
        else
        {
            return AnastasiaChan::figuras[5].recover(pos);
        }
    }
    else if (tipo == "piernas")
    {
        if (pos < 0 || pos > AnastasiaChan::figuras[6].getSize())
        {
            return NULL;
        }
        else
        {
            return AnastasiaChan::figuras[6].recover(pos);
        }
    }
    else if (tipo == "traje")
    {
        if (pos < 0 || pos > AnastasiaChan::figuras[7].getSize())
        {
            return NULL;
        }
        else
        {
            return AnastasiaChan::figuras[7].recover(pos);
        }
    }
    else if (tipo == "txt")
    {
        if (pos < 0 || pos > AnastasiaChan::figuras[8].getSize())
        {
            return NULL;
        }
        else
        {
            return AnastasiaChan::figuras[8].recover(pos);
        }
    }
    else
    {
        return NULL;
    }
}

bool AnastasiaChan::getHablando()
{
	return AnastasiaChan::hablando;
}

Uint32 AnastasiaChan::getTiempoHabla()
{
	return AnastasiaChan::tiempoHabla;
}

bool AnastasiaChan::getHablarAsc()
{
	return AnastasiaChan::hablarAsc;
}

Uint32 AnastasiaChan::getTiempoEsperaParpadeo()
{
	return AnastasiaChan::tiempoEsperaParpadeo;
}

Uint32 AnastasiaChan::getTiempoParpadeo()
{
	return AnastasiaChan::tiempoParpadeo;
}

bool AnastasiaChan::getParpadear()
{
	return AnastasiaChan::parpadear;
}

bool AnastasiaChan::getParpadeoAsc()
{
	return AnastasiaChan::parpadeoAsc;
}

Uint32 AnastasiaChan::getTiempoFondo()
{
	return AnastasiaChan::tiempoFondo;
}

unsigned AnastasiaChan::getMicrosegEsperaFondo()
{
    return AnastasiaChan::microsegEsperaFondo;
}

unsigned AnastasiaChan::getMicrosegEsperaHabla()
{
    return AnastasiaChan::microsegEsperaHabla;
}

unsigned AnastasiaChan::getMicrosegEsperaParpadeo()
{
    return AnastasiaChan::microsegEsperaParpadeo;
}

unsigned AnastasiaChan::getMicrosegVelParpadeo()
{
    return AnastasiaChan::microsegVelParpadeo;
}

///Setters
void AnastasiaChan::setAccesorio(int x)
{
    AnastasiaChan::accesorio = x;
}
void AnastasiaChan::setBoca(int x)
{
    AnastasiaChan::boca = x;
}
void AnastasiaChan::setBrazos(int x)
{
    AnastasiaChan::brazos = x;
}
void AnastasiaChan::setCabeza(int x)
{
    AnastasiaChan::cabeza = x;
}

void AnastasiaChan::setFondo(float x)
{
    AnastasiaChan::fondo = x;
}

void AnastasiaChan::setOjos(int x)
{
    AnastasiaChan::ojos = x;
}
void AnastasiaChan::setPiernas(int x)
{
    AnastasiaChan::piernas = x;
}
void AnastasiaChan::setTraje(int x)
{
    AnastasiaChan::traje = x;
}

void AnastasiaChan::setRenderizador(SDL_Renderer* x)
{
    AnastasiaChan::renderizador = x;
}

void AnastasiaChan::setHablando(bool a)
{
    Uint32 tiempo = SDL_GetTicks();

	AnastasiaChan::hablando = a;
	AnastasiaChan::tiempoHabla = tiempo;
}

void AnastasiaChan::setTiempoHabla(Uint32 a)
{
	AnastasiaChan::tiempoHabla = a;
}

void AnastasiaChan::setHablarAsc(bool a)
{
	AnastasiaChan::hablarAsc = a;
}

void AnastasiaChan::setTiempoEsperaParpadeo(Uint32 a)
{
	AnastasiaChan::tiempoEsperaParpadeo = a;
}

void AnastasiaChan::setTiempoParpadeo(Uint32 a)
{
	AnastasiaChan::tiempoParpadeo = a;
}

void AnastasiaChan::setParpadear(bool a)
{
	AnastasiaChan::parpadear = a;
}

void AnastasiaChan::setParpadeoAsc(bool a)
{
	AnastasiaChan::parpadeoAsc = a;
}

void AnastasiaChan::setTiempoFondo(Uint32 a)
{
	AnastasiaChan::tiempoFondo = a;
}

void AnastasiaChan::setMicrosegEsperaFondo(unsigned a)
{
    AnastasiaChan::microsegEsperaFondo = a;
}

void AnastasiaChan::setMicrosegEsperaHabla(unsigned a)
{
    AnastasiaChan::microsegEsperaHabla = a;
}

void AnastasiaChan::setMicrosegEsperaParpadeo(unsigned a)
{
    AnastasiaChan::microsegEsperaParpadeo = a;
}

void AnastasiaChan::setMicrosegVelParpadeo(unsigned a)
{
    AnastasiaChan::microsegVelParpadeo = a;
}

void AnastasiaChan::inicializar()
{
    FuncionesPantalla f;
    stringConvert s;
    string aux = "";
    List<SDL_Texture*> lista;
    SDL_Texture* obj;

    AnastasiaChan::accesorio = 0;
    AnastasiaChan::boca = 0;
    AnastasiaChan::brazos = 0;
    AnastasiaChan::cabeza = 0;
    AnastasiaChan::ojos = 0;
    AnastasiaChan::piernas = 0;
    AnastasiaChan::traje = 0;

    AnastasiaChan::hablando = false;
    AnastasiaChan::hablarAsc = false;
    AnastasiaChan::tiempoHabla = 0;
    AnastasiaChan::tiempoFondo = 0;

    AnastasiaChan::parpadear = false;
    AnastasiaChan::parpadeoAsc = false;
    AnastasiaChan::tiempoEsperaParpadeo = 0;
    AnastasiaChan::tiempoParpadeo = 0;

    AnastasiaChan::microsegEsperaFondo = 1;
    AnastasiaChan::microsegEsperaParpadeo = 2000;
    AnastasiaChan::microsegEsperaHabla = 49;
    AnastasiaChan::microsegVelParpadeo = 40;

    AnastasiaChan::liberar();

    //Recuperacion de Figuras de Accesorios
    for (int i = 0; i < ANASTASIA_MAX_ACCESORIOS; i++)
    {
        aux = "Img/Accesorio/Accesorio" + s.intToStr(i+1) + ".png";
        obj = f.cargarTextura(aux, renderizador);
        lista.append(obj);
    }

    figuras.append(lista);
    lista.nullify();

    //Recuperacion de Figuras de Boca
    for (int i = 0; i < ANASTASIA_MAX_BOCAS; i++)
    {
        aux = "Img/Boca/Boca" + s.charToStr(i + 'A') + ".png";
        obj = f.cargarTextura(aux, renderizador);
        lista.append(obj);
    }

    figuras.append(lista);
    lista.nullify();

    //Recuperacion de Figuras de Brazos
    for (int i = 0; i < ANASTASIA_MAX_BRAZOS; i++)
    {
        aux = "Img/Brazos/Brazos" + s.intToStr(i+1) + ".png";
        obj = f.cargarTextura(aux, renderizador);
        lista.append(obj);
    }

    figuras.append(lista);
    lista.nullify();

    //Recuperacion de Figuras de Cabeza
    for (int i = 0; i < ANASTASIA_MAX_CABEZAS; i++)
    {
        aux = "Img/Cabeza/Cabeza" + s.intToStr(i+1) + ".png";
        obj = f.cargarTextura(aux, renderizador);
        lista.append(obj);
    }

    figuras.append(lista);
    lista.nullify();

    //Recuperacion de Figuras de Cabeza
    for (int i = 0; i < ANASTASIA_MAX_FONDOS; i++)
    {
        aux = "Img/Fondo/Fondo" + s.intToStr(i+1) + ".png";
        obj = f.cargarTextura(aux, renderizador);
        lista.append(obj);
    }

    figuras.append(lista);
    lista.nullify();

    //Recuperacion de Figuras de Ojos
    for (int i = 0; i < ANASTASIA_MAX_OJOS; i++)
    {
        aux = "Img/Ojos/Ojos" + s.intToStr(i+1) + ".png";
        obj = f.cargarTextura(aux, renderizador);
        lista.append(obj);
    }

    figuras.append(lista);
    lista.nullify();

    //Recuperacion de Figuras de Piernas
    for (int i = 0; i < ANASTASIA_MAX_PIERNAS; i++)
    {
        aux = "Img/Piernas/Piernas" + s.intToStr(i+1) + ".png";
        obj = f.cargarTextura(aux, renderizador);
        lista.append(obj);
    }

    figuras.append(lista);
    lista.nullify();

    //Recuperacion de Figuras de Trajes
    for (int i = 0; i < ANASTASIA_MAX_TRAJES; i++)
    {
        aux = "Img/Traje/Traje" + s.intToStr(i+1) + ".png";
        obj = f.cargarTextura(aux, renderizador);
        lista.append(obj);
    }

    figuras.append(lista);
    lista.nullify();

    //Recuperacion de Figuras de Txt
    for (int i = 0; i < ANASTASIA_MAX_TXT; i++)
    {
        aux = "Img/Txt/Txt" + s.intToStr(i+1) + ".png";
        obj = f.cargarTextura(aux, renderizador);
        lista.append(obj);
    }

    figuras.append(lista);
    lista.nullify();


    int iW, iH;
    SDL_QueryTexture(getFiguras("fondo", 0), NULL, NULL, &iW, &iH);

    AnastasiaChan::fondo = 0;
}

void AnastasiaChan::liberar()
{
    if (!figuras.isEmpty())
    {
        for (unsigned i = 0; i < figuras.getSize(); i++)
        {
            if (!figuras[i].isEmpty())
            {
                for (unsigned j = 0; j < figuras[i].getSize(); j++)
                {
                    SDL_DestroyTexture(figuras[i].recover(j));
                }
            }

            figuras[i].nullify();
        }
    }

    figuras.nullify();
}

void AnastasiaChan::desplegar(SDL_Window* ventana)
{
    FuncionesPantalla f;

    Uint32 tiempo = SDL_GetTicks();

    int ventanaW, ventanaH;
    SDL_GetWindowSize(ventana, &ventanaW, &ventanaH);

    if (tiempo - AnastasiaChan::tiempoFondo > AnastasiaChan::microsegEsperaFondo)
    {
        tiempoFondo = tiempo;

        int iW, iH;
        SDL_QueryTexture(AnastasiaChan::getFiguras("fondo", 0), NULL, NULL, &iW, &iH);

        if (AnastasiaChan::getFondo() >= 0)
        {
            AnastasiaChan::setFondo(-iH/2);
        }
        else
        {
            AnastasiaChan::setFondo(AnastasiaChan::getFondo()+0.50);
        }
    }

    if (AnastasiaChan::hablando)
    {
        if (tiempo - AnastasiaChan::tiempoHabla > AnastasiaChan::microsegEsperaHabla)
        {
            AnastasiaChan::tiempoHabla = tiempo;

            int n = AnastasiaChan::boca;

            if (hablarAsc)
            {
                n--;
                AnastasiaChan::boca = n;

                if (n <= 0)
                {
                    hablarAsc = false;
                }
            }
            else
            {
                n++;
                AnastasiaChan::boca = n;

                if (n >= 3)
                {
                    AnastasiaChan::hablarAsc = true;
                }
            }
        }
    }

    if (AnastasiaChan::parpadear)
    {
        AnastasiaChan::tiempoEsperaParpadeo = tiempo;
        int n = AnastasiaChan::ojos;

        if (tiempo - AnastasiaChan::tiempoParpadeo > AnastasiaChan::microsegVelParpadeo)
        {
            AnastasiaChan::tiempoParpadeo = tiempo;

            if (AnastasiaChan::parpadeoAsc)
            {
                n--;
                AnastasiaChan::ojos = n;

                if (n <= 0)
                {
                    AnastasiaChan::parpadear = false;
                    AnastasiaChan::parpadeoAsc = false;
                }
            }
            else
            {
                n++;
                AnastasiaChan::ojos = n;

                if (n >= 3)
                {
                    AnastasiaChan::parpadeoAsc = true;
                }
            }
        }
    }
    else
    {
        if (AnastasiaChan::microsegEsperaParpadeo != 0)
        {
            //Imprimimos un punto si han pasado 2 segundos
            if (tiempo - AnastasiaChan::tiempoEsperaParpadeo > AnastasiaChan::microsegEsperaParpadeo)
            {
                AnastasiaChan::parpadear = true;
                AnastasiaChan::tiempoParpadeo = tiempo;
            }
        }
    }

    int ajusteW = ventanaW * ANASTASIACHAN_X / 100;
    int ajusteH = ventanaH * ANASTASIACHAN_Y / 100;
    int ajusteX = -1 * ventanaW * 3 / 100;
    int ajusteY = ventanaH - ajusteH + (ventanaH * 5 / 100);

    //Escribimos el fondo de la pantalla
    f.renderizarTextura(getFiguras("fondo", 0), renderizador, 0, fondo);
    f.renderizarTextura(getFiguras("fondo", 0), renderizador, VENTANA_TAM_X, fondo);

    f.renderizarTextura(getFiguras("cabeza", cabeza), renderizador, ajusteX, ajusteY , ajusteW, ajusteH);
    f.renderizarTextura(getFiguras("traje", traje), renderizador, ajusteX, ajusteY, ajusteW, ajusteH);

    f.renderizarTextura(getFiguras("boca", boca), renderizador, ajusteX, ajusteY, ajusteW, ajusteH);
    f.renderizarTextura(getFiguras("brazos", brazos), renderizador, ajusteX, ajusteY, ajusteW, ajusteH);
    f.renderizarTextura(getFiguras("ojos", ojos), renderizador, ajusteX, ajusteY, ajusteW, ajusteH);
    f.renderizarTextura(getFiguras("piernas", piernas), renderizador, ajusteX, ajusteY, ajusteW, ajusteH);
    f.renderizarTextura(getFiguras("accesorio", accesorio), renderizador, ajusteX, ajusteY, ajusteW, ajusteH);
}

void AnastasiaChan::imprimir()
{
    cout << "Accesorio: " << AnastasiaChan::accesorio << endl;
    cout << "Boca:      " << AnastasiaChan::boca << endl;
    cout << "Brazo:     " << AnastasiaChan::brazos << endl;
    cout << "Cabeza:    " << AnastasiaChan::cabeza  << endl;
    cout << "Ojos:      " << AnastasiaChan::ojos << endl;
    cout << "Piernas:   " << AnastasiaChan::piernas << endl;
    cout << "Traje:     " << AnastasiaChan::traje << endl;
    cout << "Fondo:     " << AnastasiaChan::fondo << endl;
    cout << "Figuras    " << AnastasiaChan::figuras << endl;
}
