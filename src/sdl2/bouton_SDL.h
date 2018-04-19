#ifndef BOUTONSDL_H
#define BOUTONSDL_H

#include <SDL2/SDL.h>
#include <string>
using namespace std;



class Bouton {
private:
    SDL_Rect pos;

    SDL_Surface* img;

    const char* imgPath;

    //const char* op; //l'operation qu'effectue le bouton
    std::string op;


    const SDL_Event* ptrEvents;//besoin de trouver l'instance générale de SDL_Event afin de gérer les évenements etc.

public:
    SDL_Texture* imgTexture;    // on met la texture en public pour pouvoir l'initialiser
                                //car le faire dans une fonction membre
                                //nécessite d'ajouter un membre renderer à la class

    Bouton();

    void setPos(const int x, const int y,const int w,const int h);

    void setImg(const char* path);
    //définit le chemin de l'image et la charge sur la Surface

    //void setOpStr(const char* opStr);
    //définit le string d'opération

    void setOpStr(std::string opStr);

    void setEvents(const SDL_Event & events);

    SDL_Rect getPos();

    const char* getImgPath();

    SDL_Surface* getImg();

    //const char* getOpStr();
    //retourne le string d'opération
    string getOpStr();


    int handle_events();
    //détecteur d'évenements souris
    //retourne 1 si on clique sur le bouton, 0 sinon
};


#endif
