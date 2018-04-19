#ifndef AFFICHAGESDL_H
#define AFFICHAGESDL_H


#include "../main/jeu.h"
#include "bouton_SDL.h"


using namespace std;

class affichageSDL {
private :
    int WINDIMX,WINDIMY;
    SDL_Window* window = NULL;
//     SDL_Surface* listeA = NULL;
//     SDL_Surface* listeB = NULL;
    Bouton tabBouton [11];
    Bouton tabBoutonMenus[4];
    Bouton tabBoutonNiv[5];
    Bouton tabBoutonVic[3];
    SDL_Rect posListeA, posListeB;
    SDL_Texture* textureListeA = NULL;
    SDL_Texture* textureListeB = NULL;
    SDL_Texture* textureTextNiveau[4];
    SDL_Texture* texturevie = NULL;
    SDL_Rect Positiontext[4];
    SDL_Rect Positionvie;
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Color font_color;
    SDL_Event events;
    bool terminer = false;

    TableauDynamique tdA, tdB;

public :

    void initSDL();

    void initListes();

    void initBoutons();

    void initBoutonsMenus();

    void initBoutonsNiv();

    void initBoutonsVic();

    SDL_Texture* CreateTextureFromString(string txt);

    void updateListes(const std::string& op,niveau niveau1,int &m);

    void updateListesMenus(const std::string& op, int &choix,jeu &jeu1, niveau &niveau1,int &niveauEC);

    void boucleSDL();

    void detruitSDL();

};


#endif
