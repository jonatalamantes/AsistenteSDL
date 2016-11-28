#include <ctime>
#include <SDL2/SDL.h>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Constantes.h"
#include "stringConvert.h"
#include "PantallaPrincipal.h"

using namespace std;

PantallaPrincipal::PantallaPrincipal()
{
    PantallaPrincipal::renderizador = NULL;
    PantallaPrincipal::f = NULL;
    PantallaPrincipal::anastasia = new AnastasiaChan(NULL);
    PantallaPrincipal::ventana = NULL;
    PantallaPrincipal::cuadroRespuesta = NULL;
    PantallaPrincipal::cuadroBievenida = NULL;
    PantallaPrincipal::cuadroComandos = NULL;
    PantallaPrincipal::consola = new ConsolaComandos(anastasia, cuadroRespuesta);

    PantallaPrincipal::cuadroComandos->setFoco(true);
}

PantallaPrincipal::PantallaPrincipal(SDL_Window* w, SDL_Renderer* p, FuncionesPantalla* func)
{
    PantallaPrincipal::ventana = w;
    PantallaPrincipal::renderizador = p;
    PantallaPrincipal::f = func;
    PantallaPrincipal::anastasia = new AnastasiaChan(p);

    PantallaPrincipal::cuadroComandos = new CuadroTexto(p);
    PantallaPrincipal::cuadroBievenida = new CuadroTexto(p);

    Scroll* s = new Scroll(true, anastasia->getFiguras("txt", 1));
    PantallaPrincipal::cuadroRespuesta = new CuadroTexto(p, s);
    cuadroRespuesta->setMultiLinea(true);
    PantallaPrincipal::consola = new ConsolaComandos(anastasia, cuadroRespuesta);

    PantallaPrincipal::cuadroComandos->setFoco(true);
}

PantallaPrincipal::~PantallaPrincipal()
{
    if (PantallaPrincipal::anastasia != NULL)
    {
        delete PantallaPrincipal::anastasia;
    }

    if (PantallaPrincipal::cuadroBievenida != NULL)
    {
        delete PantallaPrincipal::cuadroBievenida;
    }

    if (PantallaPrincipal::cuadroComandos != NULL)
    {
        delete PantallaPrincipal::cuadroComandos;
    }

    if (PantallaPrincipal::cuadroRespuesta != NULL)
    {
        delete PantallaPrincipal::cuadroRespuesta;
    }

    if (PantallaPrincipal::consola != NULL)
    {
        delete PantallaPrincipal::consola;
    }
}

string PantallaPrincipal::tiempoActual()
{
    //Conseguimos la hora actual
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    string tiempo = "Hoy es ";
    stringConvert s;
    string meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo",
                        "Junio", "Julio", "Agosto", "Septiembre", "Octubre",
                        "Noviembre", "Diciembre"};

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "%d/%m", timeinfo);
    string fecha = buffer;

    if (fecha == "12/01")
    {
        anastasia->setAccesorio(1);
        tiempo = tiempo + "Cumpleaños de Anastasia";
    }
    else if (fecha == "20/01")
    {
        anastasia->setAccesorio(1);
        tiempo = tiempo + "Cumpleaños de Tina";
    }
    else if (fecha == "01/03")
    {
        anastasia->setAccesorio(1);
        tiempo = tiempo + "Cumpleaños de Amo";
    }
    else if (fecha == "16/09")
    {
        tiempo = tiempo + "Día de la Independencia";
    }
    else if (fecha == "05/02")
    {
        tiempo = tiempo + "Día de la Constitución";
    }
    else if (fecha == "19/07")
    {
        anastasia->setAccesorio(1);
        tiempo = tiempo + "Cumpleaños de Valeria";
    }
    else if (fecha == "14/04")
    {
        anastasia->setAccesorio(1);
        tiempo = tiempo + "Cumpleaños Pentil";
    }
    else if (fecha == "27/10")
    {
        anastasia->setAccesorio(1);
        tiempo = tiempo + "Cumpleaños Lupe";
    }
    else if (fecha == "13/11")
    {
        anastasia->setAccesorio(1);
        tiempo = tiempo + "Cumpleaños Luis";
    }
    else
    {
        strftime(buffer, 80, "%d", timeinfo);
        tiempo = tiempo + buffer;

        strftime(buffer, 80, "%m", timeinfo);
        tiempo = tiempo + " de " + meses[s.strToInt(buffer)-1];

        strftime(buffer, 80, "%Y", timeinfo);
        tiempo = tiempo + " del " + buffer;
    }

    strftime(buffer, 80, " %I:%M:%S", timeinfo);
    tiempo = tiempo + buffer;

    tiempo = tiempo.substr(0, 52);

    return tiempo;
}

/**
 * Refresca el contenido de la renderizador interna para mostrar
 *
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 */
void PantallaPrincipal::imprimirPantallaInterna()
{
    //cout << consola->getPidComando() << endl;

    //if (consola->getPidComando() > 0)
    //{
        consola->actualizarRespuesta();
    //}

    anastasia->desplegar(ventana);

    int ventanaW, ventanaH;
    SDL_GetWindowSize(ventana, &ventanaW, &ventanaH);

    float ajusteW = ventanaW * 100 / 100;
    float ajusteX = ventanaW * 0 / 100;
    float ajusteY = ventanaH * 0 / 100;
    float ajusteH = ventanaH - ajusteY;

    f->renderizarTextura(anastasia->getFiguras("txt", 0), renderizador, ajusteX, ajusteY, ajusteW, ajusteH);

    //Ponemos el texto del texto
    SDL_Color color;

    color.r = 226;
    color.g = 28;
    color.b = 24;

    ajusteW = ventanaW * 80 / 100;
    ajusteX = ventanaW * 5 / 100;
    ajusteY = ventanaH * 0 / 100;
    ajusteH = ventanaH - ajusteY;

    cuadroBievenida->setColorTexto(color);
    cuadroBievenida->setX(ventanaW * 3 / 100);
    cuadroBievenida->setY(ventanaH * 7.9 / 100);
    cuadroBievenida->setW(ventanaW * 91.8 / 100);
    cuadroBievenida->setH(ventanaH * 8.8 / 100);
    cuadroBievenida->setTamFuente(0);
    cuadroBievenida->setHabilitado(false);
    cuadroBievenida->setCentrarX(true);
    cuadroBievenida->setCentrarY(true);
    cuadroBievenida->setTexto(tiempoActual());

    cuadroBievenida->desplegar(f);

    //Cuadro de Comandos
    color.r = 0;
    color.g = 80;
    color.b = 0;

    cuadroComandos->setColorTexto(color);
    cuadroComandos->setX(ventanaW * 35.45 / 100);
    cuadroComandos->setY(ventanaH * 24 / 100);
    cuadroComandos->setW(ventanaW * 59 / 100);
    cuadroComandos->setH(ventanaH * 5.8 / 100);
    cuadroComandos->setTamFuente(0);
    cuadroComandos->setHabilitado(true);
    cuadroComandos->setCentrarX(false);
    cuadroComandos->setCentrarY(true);

    cuadroComandos->desplegar(f);

    //Cuadro de Respuestas
    color.r = 0;
    color.g = 0;
    color.b = 0;

    cuadroRespuesta->setColorTexto(color);
    cuadroRespuesta->setHabilitado(false);
    cuadroRespuesta->setX(ventanaW * 35.45 / 100);
    cuadroRespuesta->setY(ventanaH * 34.5 / 100);
    cuadroRespuesta->setW(ventanaW * 56.5 / 100);
    cuadroRespuesta->setH(ventanaH * 56.84 / 100);
    cuadroRespuesta->setTamFuente(13);

    int tamBtnScroll = ventanaH * 3.1 / 100;
    cuadroRespuesta->getScroll()->setTamBtn(tamBtnScroll);
    cuadroRespuesta->getScroll()->setX(ventanaW * 92.75 / 100);
    cuadroRespuesta->getScroll()->setY(ventanaH * 32.85 / 100 + tamBtnScroll);
    cuadroRespuesta->getScroll()->setW(ventanaW * 1.6 / 100);
    cuadroRespuesta->getScroll()->setH(ventanaH * 60.2 / 100 - tamBtnScroll*2);

    cuadroRespuesta->desplegar(f);

    //Actualizamos la pantalla
    SDL_RenderPresent(renderizador);
}

/**
 * Funcion encargada de gestionar los eventos en la aplicacion
 *
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 */
void PantallaPrincipal::mostrar()
{
    srand(time(NULL));

    SDL_Event Evento1;
    bool Fin = false;
    SDL_StartTextInput();

    while (!Fin)
    {
        PantallaPrincipal::imprimirPantallaInterna();

        int res = SDL_PollEvent(&Evento1);

        if (!res)
        {
            continue;
        }

        if (Evento1.type == SDL_KEYUP)
        {
            if (Evento1.key.keysym.sym == SDLK_RETURN ||
                Evento1.key.keysym.sym == SDLK_KP_ENTER)
            {
                if (cuadroComandos->getFoco())
                {
                    consola->execComando(cuadroComandos->getTexto());
                    cuadroComandos->setTexto("");
                }
            }
        }
        else if (Evento1.type == SDL_WINDOWEVENT)
        {
            if (Evento1.window.event == SDL_WINDOWEVENT_MOVED)
            {
                if (consola->getBloqueoActivo())
                {
                    SDL_SetWindowFullscreen(ventana, 0);
                    SDL_SetWindowFullscreen(ventana, SDL_WINDOW_FULLSCREEN_DESKTOP);
                }
            }
            else if (Evento1.window.event == SDL_WINDOWEVENT_RESIZED)
            {
                if (not consola->getBloqueoActivo())
                {
                    int ventanaW, ventanaH;
                    SDL_GetWindowSize(ventana, &ventanaW, &ventanaH);

                    if (ventanaW < VENTANA_TAM_X)
                    {
                        SDL_SetWindowSize(ventana, VENTANA_TAM_X, ventanaH);
                        ventanaW = VENTANA_TAM_X;
                    }

                    if (ventanaH < VENTANA_TAM_Y)
                    {
                        SDL_SetWindowSize(ventana, ventanaW, VENTANA_TAM_Y);
                        ventanaH = VENTANA_TAM_Y;
                    }
                }
            }
        }
        else if (Evento1.type == SDL_QUIT)
        {
            if (not consola->getBloqueoActivo())
            {
                Fin = true;
            }
        }

        cuadroComandos->procesarEvento(&Evento1);
        cuadroRespuesta->getScroll()->procesarEventoClick(&Evento1);
    }

    SDL_StopTextInput();
}
