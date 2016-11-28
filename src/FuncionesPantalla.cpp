#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <SDL2/SDL_image.h>

#include "Fuente.h"
#include "FuncionesPantalla.h"
#include "Constantes.h"

using namespace std;

///Constructor
FuncionesPantalla::FuncionesPantalla()
{
    ifstream archivo("pathFile.dat");

    if (archivo)
    {
        FuncionesPantalla::path = "";
    }
    else
    {
        FuncionesPantalla::path = "../../";
    }

    archivo.close();
}

///Getters
string FuncionesPantalla::getPath()
{
    return FuncionesPantalla::path;
}

///Funciones útiles para SDL

/**
 * Escriba una palabra en la pantalla de SDL
 *
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 * @param Pantalla     Apuntador para la pantalla de SDL
 * @param palabra      Palabra que se desea poner en la pantalla
 * @param x            Posicion X de la pantalla
 * @param y            Posicion Y de la pantalla
 * @param nombreFuente Nombre de la fuente en la carpeta "fonts" sin el .ttf
 * @param tamFuente    Tamaño de la fuente a poner en pantalla
 * @param r            Escala RGB tomando la 'R' para el color
 * @param g            Escala RGB tomando la 'G' para el color
 * @param b            Escala RGB tomando la 'B' para el color
 */
/*void FuncionesPantalla::escribirPalabra(SDL_Surface* Pantalla, string palabra, int x, int y,
                                        string nombreFuente, int tamFuente, Uint8 r, Uint8 g,
                                        Uint8 b, int *w, int *h)
{
    if (palabra != "")
    {
        //Creamos una fuente temporal
        Fuente aux;
        aux.setNombre(nombreFuente);
        aux.setTam(tamFuente);

        //Buscamos si ya esta capturada
        int pos = FuncionesPantalla::fuentes.searchInList(aux);

        if (pos == -1)
        {
            //La insertamos de no estar en la lista
            string nFuente = FuncionesPantalla::path + "fonts/" + nombreFuente + ".ttf";
            aux.setPuntero(TTF_OpenFont(nFuente.c_str(), tamFuente));

            if (aux.getPuntero() == NULL)
            {
                cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
            }

            FuncionesPantalla::fuentes.append(aux);
            pos = FuncionesPantalla::fuentes.getSize() -1;
        }

        //Creamos una rectangulo
        SDL_Rect rectangulo;
        SDL_Surface* palabraRender;
        SDL_Color color = {r, g, b};

        //Generamos una superficie para la pantalla
        palabraRender = TTF_RenderUTF8_Blended(FuncionesPantalla::fuentes[pos].getPuntero(),
                                               palabra.c_str(), color);

        //Guardamos los datos de la fuente generada
        rectangulo.x = x;
        rectangulo.y = y;
        rectangulo.w = palabraRender->w;
        rectangulo.h = palabraRender->h;

        *w = palabraRender->w;
        *h = palabraRender->h;

        //insertamos la palabra generada en la pantalla
        SDL_BlitSurface(palabraRender, NULL, Pantalla, &rectangulo);
        SDL_FreeSurface(palabraRender);
    }
}*/

/**
 * Escriba una palabra en la pantalla de SDL
 *
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 * @param Pantalla     Apuntador para la pantalla de SDL
 * @param palabra      Palabra que se desea poner en la pantalla
 * @param x            Posicion X de la pantalla
 * @param y            Posicion Y de la pantalla
 * @param nombreFuente Nombre de la fuente en la carpeta "fonts" sin el .ttf
 * @param tamFuente    Tamaño de la fuente a poner en pantalla
 */
/*void FuncionesPantalla::escribirPalabra(SDL_Surface* Pantalla, string palabra, int x, int y,
                                        string nombreFuente, int tamFuente)
{
    int a,b;
    FuncionesPantalla::escribirPalabra(Pantalla, palabra, x, y, nombreFuente,
                                       tamFuente, 255, 255, 255, &a, &b);
}*/

/**
 * Escriba una palabra en la pantalla de SDL
 *
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 * @param Pantalla     Apuntador para la pantalla de SDL
 * @param palabra      Palabra que se desea poner en la pantalla
 * @param x            Posicion X de la pantalla
 * @param y            Posicion Y de la pantalla
 * @param nombreFuente Nombre de la fuente en la carpeta "fonts" sin el .ttf
 * @param tamFuente    Tamaño de la fuente a poner en pantalla
 * @param r            Escala RGB tomando la 'R' para el color
 * @param g            Escala RGB tomando la 'G' para el color
 * @param b            Escala RGB tomando la 'B' para el color
 * @param w            Apuntador donde se guardará la longitud de la palabra en la pantalla
 * @param h            Apuntador donde se guardará la altitud de la palabra en la pantalla
 */
/*void FuncionesPantalla::escribirPalabra(SDL_Surface* Pantalla, string palabra, int x, int y,
                                        string nombreFuente, int tamFuente, Uint8 r, Uint8 g,
                                        Uint8 b)
{
    int a,c;
    FuncionesPantalla::escribirPalabra(Pantalla, palabra, x, y, nombreFuente, tamFuente, r, g, b,
                                       &a, &c);
}*/

/**
 * Inserte una imagen en la pantalla
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 * @param  Pantalla Apuntador con la direccion de la pantalla en SDL
 * @param  nombre   Nombre de la imagen a cargar
 * @param  X        Posicion X en la pantalla a insertar la imagen
 * @param  Y        Posicion Y en la pantalla a insertar la imagen
 * @return          Si fue posible cargar la imagen
 */
/*bool FuncionesPantalla::cargarImagen(SDL_Surface* Pantalla, string nombre, int X, int Y)
{
    int a,b;

    return cargarImagen(Pantalla, nombre, X, Y, &a, &b);
}*/

/**
 * Inserte una imagen en la pantalla
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 * @param  Pantalla Apuntador con la direccion de la pantalla en SDL
 * @param  nombre   Nombre de la imagen a cargar
 * @param  X        Posicion X en la pantalla a insertar la imagen
 * @param  Y        Posicion Y en la pantalla a insertar la imagen
 * @param  tamX     Apuntador donde se guardara la longitud de la imagen
 * @param  tamY     Apuntador donde se guardara la altutud de la imagen
 * @return          Si fue posible cargar la imagen
 */
/*bool FuncionesPantalla::cargarImagen(SDL_Surface* Pantalla, string nombre, int X, int Y,
                                     int* tamX, int* tamY)
{
    //Buscamos la ruta del archivo
    string x = FuncionesPantalla::path + nombre;

    const char* buffer = x.c_str();

    //Cargamos la imagen
    SDL_Surface *image;
    image = IMG_Load(buffer);

    if (image != NULL)
    {
        //Dibujamos la imagen en la pantalla
        SDL_Rect rcDest = {(Sint16)X, (Sint16)Y, 0, 0};
        SDL_BlitSurface (image, NULL, Pantalla, &rcDest);

        *tamX = image->w;
        *tamY = image->h;

        SDL_FreeSurface(image);

        return true;
    }

    return false;
}*/

/**
 * Inserte una imagen en la pantalla
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 * @param  Pantalla Apuntador con la direccion de la pantalla en SDL
 * @param  nombre   Nombre de la imagen a cargar
 * @param  X        Posicion X en la pantalla a insertar la imagen
 * @param  Y        Posicion Y en la pantalla a insertar la imagen
 * @param  tamX     Apuntador donde se guardara la longitud de la imagen
 * @param  tamY     Apuntador donde se guardara la altutud de la imagen
 * @return          Si fue posible cargar la imagen
 */
/*SDL_Surface* FuncionesPantalla::cargarImagenSinDesechar(string nombre)
{
    //Buscamos la ruta del archivo
    string x = FuncionesPantalla::path + nombre;

    const char* buffer = x.c_str();

    //Cargamos la imagen
    SDL_Surface *image;
    image = IMG_Load(buffer);

    return image;
}

bool FuncionesPantalla::ponerImagen(SDL_Surface* Pantalla, SDL_Surface* image, int X, int Y)
{
    if (image != NULL)
    {
        //Dibujamos la imagen en la pantalla
        SDL_Rect rcDest = {(Sint16)X, (Sint16)Y, 0, 0};
        SDL_BlitSurface (image, NULL, Pantalla, &rcDest);

        return true;
    }

    return false;
}*/

/**
 * Dibuje un circulo en la pantalla
 *
 * @author Jonathan Sandoval <jonathan_s_pisis@yahoo.com.mx>
 * @param Pantalla Apuntador con la direccion de la pantalla en SDL
 * @param radio    Radio en pixeles que tendra el circulo
 * @param x        Posicion X en donde se comenzará a evaluar e lcirculo
 * @param y        Posicion Y donde se comenzará a evaluar el circulo
 * @param r            Escala RGB tomando la 'R' para el color
 * @param g            Escala RGB tomando la 'G' para el color
 * @param b            Escala RGB tomando la 'B' para el color
 */
/*void FuncionesPantalla::dibujarCirculo(SDL_Surface* Pantalla, int radio, int x, int y,
                                       int r, int g, int b)
{
    //Copiamos el radio
    int tam = radio;

    //Creamos un cuadrado con el tamaño de un pixel
    SDL_Rect rect;
    rect.w = 1;
    rect.h = 1;

    //Creamos el color
    Uint32 color = SDL_MapRGB(Pantalla->format, r, g, b);

    //Recorremos un cuadrado en relacion del radio
    for (int i = tam/2; i < tam; i++) //y
    {
        for (int j = 0; j < tam; j++) //x
        {
            //Evaluamos la funcion matemtica x² + y² = r²
            int uper = sqrt( (((tam/2)*(tam/2)) - ((j- (tam/2))*(j-(tam/2))) )) + (tam/2);

            //Si nos encontramos dentro de la funcion dibujamos en ambos lados
            if (i <= uper)
            {
                //Dibujamos el circulo en ambos lados
                rect.x = j + x;
                rect.y = i + y;

                SDL_FillRect(Pantalla, &rect, color);

                rect.x = j + x;
                rect.y = (tam-i) + y;

                SDL_FillRect(Pantalla, &rect, color);
            }
        }
    }
}*/

/**
* Loads an image into a texture on the rendering device
* @param file The image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* FuncionesPantalla::cargarTextura(string file, SDL_Renderer *ren)
{
    string url = (path + file);
	SDL_Texture *texture = IMG_LoadTexture(ren, url.c_str());

	if (texture == NULL)
	{
		cout << "No File: " << url << endl;
	}

	return texture;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
* width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param w The width of the texture to draw
* @param h The height of the texture to draw
*/
void FuncionesPantalla::renderizarTextura(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
*/
void FuncionesPantalla::renderizarTextura(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	renderizarTextura(tex, ren, x, y, w, h);
}

/**
* Render the message we want to display to a texture for drawing
* @param message The message we want to display
* @param fontFile The font we want to use to render the text
* @param color The color we want the text to be
* @param fontSize The size we want the font to be
* @param renderer The renderer to load the texture in
* @return An SDL_Texture containing the rendered message, or nullptr if something went wrong
*/
SDL_Texture* FuncionesPantalla::renderizarTexto(string message, string fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
    if (message != "")
    {
        //Creamos una fuente temporal
        Fuente aux;
        aux.setNombre(fontFile);
        aux.setTam(fontSize);

        //Buscamos si ya esta capturada
        int pos = FuncionesPantalla::fuentes.searchInList(aux);

        if (pos == -1)
        {
            //La insertamos de no estar en la lista
            string nFuente = FuncionesPantalla::path + "fonts/" + fontFile + ".ttf";
            aux.setPuntero(TTF_OpenFont(nFuente.c_str(), fontSize));

            if (aux.getPuntero() == NULL)
            {
                cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
            }

            FuncionesPantalla::fuentes.append(aux);
            pos = FuncionesPantalla::fuentes.getSize() -1;
        }

        TTF_Font *font = FuncionesPantalla::fuentes[pos].getPuntero();

        if (font == NULL)
        {
            cout << "Error al abrir TTF_OpenFont" << endl;
            return NULL;
        }

        //We need to first render to a surface as that's what TTF_RenderText
        //returns, then load that surface into a texture
        SDL_Surface *surf = TTF_RenderUTF8_Blended(font, message.c_str(), color);

        if (surf == NULL)
        {
            TTF_CloseFont(font);
            cout << "Error al abrir TTF_RenderText";
            return NULL;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);

        if (texture == NULL)
        {
            cout << "Error al abrir CreateTexture: " << SDL_GetError() << endl;
        }

        //Clean up the surface and font
        SDL_FreeSurface(surf);

        return texture;
    }
    else
    {
        return NULL;
    }
}
