#ifndef CONSOLACOMANDOS_H
#define CONSOLACOMANDOS_H

#include <unistd.h>
#include <cstdio>
#include "AnastasiaChan.h"
#include "CuadroTexto.h"

class ConsolaComandos
{
    private:
        AnastasiaChan* anastasia;
        CuadroTexto* respuesta;
        bool bloqueoActivo;
        string passBloqueo;
        FILE* readComando;
        FILE* writeComando;
        pid_t pidComando;
        int PadreHijo[2];
        int HijoPadre[2];

    public:
    ///Constructor
        ConsolaComandos();
        ConsolaComandos(AnastasiaChan* p, CuadroTexto* res);

    ///Getters
        bool getBloqueoActivo();
        string getPassBloqueo();
        FILE* getReadComando();
        FILE* getWriteComando();
        pid_t getPidComando();

    ///Setters
        void setBloqueoActivo(bool a);
        void setPassBloqueo(string a);
        void setReadComando(FILE* a);
        void setWriteComando(FILE* a);
        void setPidComando(pid_t a);

    ///Comandos
        void execComando(string x);
        pid_t execSystem(string comando);
        void actualizarRespuesta();
        void killComando();
        void padre(pid_t p);
        void hijo();
};

#endif // CONSOLACOMANDOS_H
