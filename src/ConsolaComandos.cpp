#include <cerrno>
#include <csignal>
#include <sys/types.h>
#include "Constantes.h"
#include "stringConvert.h"
#include "ConsolaComandos.h"

ConsolaComandos::ConsolaComandos()
{
    ConsolaComandos::anastasia = NULL;
    ConsolaComandos::respuesta = NULL;
    ConsolaComandos::readComando = NULL;
    ConsolaComandos::writeComando = NULL;
    ConsolaComandos::pidComando = 0;
}

ConsolaComandos::ConsolaComandos(AnastasiaChan* a, CuadroTexto* res)
{
    ConsolaComandos::anastasia = a;
    ConsolaComandos::respuesta = res;
    ConsolaComandos::bloqueoActivo = false;
    ConsolaComandos::readComando = NULL;
    ConsolaComandos::writeComando = NULL;
    ConsolaComandos::pidComando = 0;
}

///Getters
bool ConsolaComandos::getBloqueoActivo()
{
    return ConsolaComandos::bloqueoActivo;
}

string ConsolaComandos::getPassBloqueo()
{
    return ConsolaComandos::passBloqueo;
}

FILE* ConsolaComandos::getReadComando()
{
    return ConsolaComandos::readComando;
}

FILE* ConsolaComandos::getWriteComando()
{
    return ConsolaComandos::writeComando;
}

pid_t ConsolaComandos::getPidComando()
{
    return ConsolaComandos::pidComando;
}

///Setters
void ConsolaComandos::setBloqueoActivo(bool a)
{
    ConsolaComandos::bloqueoActivo = a;
}

void ConsolaComandos::setPassBloqueo(string a)
{
    ConsolaComandos::passBloqueo = a;
}

void ConsolaComandos::setReadComando(FILE* a)
{
    if (ConsolaComandos::readComando != NULL)
    {
        fclose(ConsolaComandos::readComando);
    }

    ConsolaComandos::readComando = a;
}

void ConsolaComandos::setWriteComando(FILE* a)
{
    if (ConsolaComandos::writeComando != NULL)
    {
        fclose(ConsolaComandos::writeComando);
    }

    ConsolaComandos::writeComando = a;
}

void ConsolaComandos::setPidComando(pid_t a)
{
    ConsolaComandos::pidComando = a;
}

///Métodos
void ConsolaComandos::execComando(string x)
{
    List<string> attr;
    string aux;

    for (unsigned i = 0; i < x.size(); i++)
    {
        if (x[i] == ' ')
        {
            if (aux != "")
            {
                attr.append(aux);
                aux = "";
            }
        }
        else
        {
            aux.push_back(x[i]);
        }
    }

    if (aux != "")
    {
        attr.append(aux);
    }

    if (!attr.isEmpty())
    {
        string res = "";

        if (attr.getSize() > 2 && attr[1] == "=" && not bloqueoActivo)
        {
            aux = attr[0];

            if (aux == "Anastasia.Traje" || aux == "Anastasia.traje" ||
                aux == "anastasia.Traje" || aux == "anastasia.traje")
            {
                stringConvert s;
                int x;

                try
                {
                    x = s.strToInt(attr[2]);
                    res = "Cambio Exitoso";
                }
                catch (stringConvertException e)
                {
                    x = anastasia->getTraje();
                    res = "Debe poner un número como último argumento";
                }

                if (x < 0 || x >= ANASTASIA_MAX_TRAJES)
                {
                    x = 0;
                    res = "Número Inválido";
                }

                anastasia->setTraje(x);
            }
            else if (aux == "Anastasia.Accesorio" || aux == "Anastasia.accesorio" ||
                     aux == "anastasia.Accesorio" || aux == "anastasia.accesorio")
            {
                stringConvert s;
                int x;

                if (not(attr[2] == "No" || attr[2] == "NO" || attr[2] == "no"))
                {
                    try
                    {
                        x = s.strToInt(attr[2]);
                        res = "Cambio Exitoso";
                    }
                    catch (stringConvertException e)
                    {
                        x = anastasia->getAccesorio();
                        res = "Debe poner un número como último argumento";
                    }

                    if (x < 0 || x >= ANASTASIA_MAX_ACCESORIOS)
                    {
                        x = 0;
                        res = "Número Inválido";
                    }

                    anastasia->setAccesorio(x);
                }
                else
                {
                    anastasia->setAccesorio(100);
                }


            }
            else if (aux == "Anastasia.Boca" || aux == "Anastasia.boca" ||
                     aux == "anastasia.Boca" || aux == "anastasia.boca")
            {
                stringConvert s;
                int x;

                try
                {
                    x = s.strToInt(attr[2]);
                    res = "Cambio Exitoso";
                }
                catch (stringConvertException e)
                {
                    x = anastasia->getBoca();
                    res = "Debe poner un número como último argumento";
                }

                if (x < 0 || x >= ANASTASIA_MAX_BOCAS)
                {
                    x = 0;
                    res = "Número Inválido";
                }

                anastasia->setBoca(x);
            }
            else if (aux == "Anastasia.Brazos" || aux == "Anastasia.brazos" ||
                     aux == "anastasia.Brazos" || aux == "anastasia.brazos")
            {
                stringConvert s;
                int x;

                try
                {
                    x = s.strToInt(attr[2]);
                    res = "Cambio Exitoso";
                }
                catch (stringConvertException e)
                {
                    x = anastasia->getBrazos();
                    res = "Debe poner un número como último argumento";
                }

                if (x < 0 || x >= ANASTASIA_MAX_BRAZOS)
                {
                    x = 0;
                    res = "Número Inválido";
                }

                anastasia->setBrazos(x);
            }
            else if (aux == "Anastasia.Cabeza" || aux == "Anastasia.cabeza" ||
                     aux == "anastasia.Cabeza" || aux == "anastasia.cabeza")
            {
                stringConvert s;
                int x;

                try
                {
                    x = s.strToInt(attr[2]);
                    res = "Cambio Exitoso";
                }
                catch (stringConvertException e)
                {
                    x = anastasia->getCabeza();
                    res = "Debe poner un número como último argumento";
                }

                if (x < 0 || x >= ANASTASIA_MAX_CABEZAS)
                {
                    x = 0;
                    res = "Número Inválido";
                }

                anastasia->setCabeza(x);
            }
            else if (aux == "Anastasia.Ojos" || aux == "Anastasia.ojos" ||
                     aux == "anastasia.Ojos" || aux == "anastasia.ojos")
            {
                stringConvert s;
                int x;

                try
                {
                    x = s.strToInt(attr[2]);
                    res = "Cambio Exitoso";
                }
                catch (stringConvertException e)
                {
                    x = anastasia->getOjos();
                    res = "Debe poner un número como último argumento";
                }

                if (x < 0 || x >= ANASTASIA_MAX_OJOS)
                {
                    x = 0;
                    res = "Número Inválido";
                }

                if (x == 3)
                {
                    anastasia->setParpadeoAsc(true);
                }

                anastasia->setOjos(x);
            }
            else if (aux == "Anastasia.Piernas" || aux == "Anastasia.piernas" ||
                     aux == "anastasia.Piernas" || aux == "anastasia.piernas")
            {
                stringConvert s;
                int x;

                try
                {
                    x = s.strToInt(attr[2]);
                    res = "Cambio Exitoso";
                }
                catch (stringConvertException e)
                {
                    x = anastasia->getPiernas();
                    res = "Debe poner un número como último argumento";
                }

                if (x < 0 || x >= ANASTASIA_MAX_PIERNAS)
                {
                    x = 0;
                    res = "Número Inválido";
                }

                anastasia->setPiernas(x);
            }
            else if (aux == "Anastasia.Hablar" || aux == "Anastasia.hablar" ||
                     aux == "anastasia.Hablar" || aux == "anastasia.hablar")
            {
                if (attr[2] == "1" || attr[2] == "true" || attr[2] == "True" || attr[2] == "TRUE")
                {
                    anastasia->setHablando(true);
                    res = "Anastasia ahora esta hablando";
                }
                else
                {
                    anastasia->setHablando(false);
                    anastasia->setBoca(0);
                    res = "Anastasia ahora no esta hablando";
                }
            }
            else if (aux == "Anastasia.Parpadear" || aux == "Anastasia.parpadear" ||
                     aux == "anastasia.Parpadear" || aux == "anastasia.parpadear")
            {
                if (attr[2] == "1" || attr[2] == "true" || attr[2] == "True" || attr[2] == "TRUE")
                {
                    anastasia->setParpadear(true);
                    anastasia->setMicrosegEsperaParpadeo(2000);
                    res = "Anastasia ahora esta parpadeando";
                }
                else
                {
                    anastasia->setParpadear(false);
                    anastasia->setOjos(0);
                    anastasia->setMicrosegEsperaParpadeo(0);
                    res = "Anastasia ahora no esta parpadeando";
                }
            }
            else if (aux == "Anastasia.Lock" || aux == "Anastasia.lock" ||
                     aux == "anastasia.Lock" || aux == "anastasia.lock")
            {
                if (attr[2] != "")
                {
                    bloqueoActivo = true;
                    passBloqueo = attr[2];

                    res = "Anastasia ha sido bloqueada";
                }
                else
                {
                    res = "Poner una contraseña válida";
                }
            }

            if (res != "")
            {
                respuesta->setTexto(res);
            }
        }
        else if (attr.getSize() > 2 && attr[1] == "=")
        {
            if (attr[0] == "Anastasia.Unlock" || attr[0] == "Anastasia.unlock" ||
                attr[0] == "anastasia.Unlock" || attr[0] == "anastasia.unlock")
            {
                if (attr[2] == passBloqueo)
                {
                    bloqueoActivo = false;
                    passBloqueo = "";
                    respuesta->setTexto("Anastasia ha sido desbloqueada");
                }
                else
                {
                    respuesta->setTexto("Anastasia sigue bloqueada");
                }
            }
            else
            {
                respuesta->setTexto("El Bloqueo esta activo");
            }
        }
        else if (not bloqueoActivo)
        {
            if (attr[0] == "Anastasia.Uso" || attr[0] == "Anastasia.uso" ||
                attr[0] == "anastasia.Uso" || attr[0] == "anastasia.uso")
            {
                string man = "Para usar a Anastasia y configurarla, tendrá que usar algun comando como el siguiente:\n \n";
                man = man + "Anastasia.Traje = NUM para cambiar el traje\n";
                man = man + "Anastasia.Accesorio = NUM|'No' para cambiar el accesorio\n";
                man = man + "Anastasia.Boca = NUM para cambiar la boca\n";
                man = man + "Anastasia.Brazos = NUM para cambiar los brazos\n";
                man = man + "Anastasia.Cabeza = NUM para cambiar la cabeza\n";
                man = man + "Anastasia.Ojos = NUM para cambiar los ojos\n";
                man = man + "Anastasia.Piernas = NUM para cambiar las piernas\n";
                man = man + "Anastasia.Hablar = 0|1|true|false para poner animacion de hablar\n";
                man = man + "Anastasia.Parpadear = 0|1|true|false para poner animacion del parpadeo\n";
                man = man + "Anastasia.Default para el traje de maid de anastasia\n";
                man = man + "Anastasia.Lock =  Pass    para bloquear la aplicación\n";
                man = man + "Anastasia.Unlock = Pass   para desbloquear la aplicación\n \n";
                man = man + "Con algun otro comando Anastasia tratará de ejecutarlo con el interprete de comandos (bash)\n";

                respuesta->setTexto(man);
            }
            else if (attr[0] == "Anastasia.Default" || attr[0] == "Anastasia.default" ||
                     attr[0] == "anastasia.Default" || attr[0] == "anastasia.default")
            {
                anastasia->setAccesorio(0);
                anastasia->setBoca(0);
                anastasia->setBrazos(0);
                anastasia->setCabeza(0);
                anastasia->setOjos(0);
                anastasia->setPiernas(0);
                anastasia->setTraje(0);

                anastasia->setHablando(false);
                anastasia->setHablarAsc(false);

                respuesta->setTexto("Anastasia esta usando el traje de Maid");
            }
            else if (attr[0] == "Cls" || attr[0] == "cls")
            {
                respuesta->setTexto("");
            }
            else if (attr[0] == "bye" || attr[0] == "Bye")
            {
                exit(0);
            }
            else
            {
                //Comando de Terminal
                FILE* p = popen(x.c_str(), "r");

                setReadComando(p);

                if (p == NULL)
                {
                    respuesta->setTexto("Comando no encontrado");
                }
            }
        }
        else
        {
            if (attr[0] == "bye" || attr[0] == "Bye")
            {
                exit(0);
            }

            respuesta->setTexto("El Bloqueo esta activo");
        }
    }
}

void ConsolaComandos::actualizarRespuesta()
{
    if (ConsolaComandos::readComando != NULL)
    {
        fseek(readComando, 0, SEEK_SET);

        string cad = "";
        char letra = fgetc(readComando);

        while (letra != EOF)
        {
            cad.push_back(letra);
            letra = fgetc(readComando);
        }

        if (cad != "")
        {
            respuesta->setTexto(cad);
        }
    }
}
