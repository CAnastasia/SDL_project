#ifndef AFFICHAGESDL_H
#define AFFICHAGESDL_H


#include "TableauDynamique.h"
#include "push_swap.h"
#include "bouton_SDL.h"

using namespace std;

class affichageSDL {
private :
    int WINDIMX,WINDIMY;
    SDL_Window* window = NULL;
//     SDL_Surface* listeA = NULL;
//     SDL_Surface* listeB = NULL;
    Bouton tabBouton [11];
    
    SDL_Rect posListeA, posListeB;
    SDL_Texture* textureListeA = NULL;
    SDL_Texture* textureListeB = NULL;
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
    
    SDL_Texture* CreateTextureFromString(string txt);
    
    void updateListes(const std::string& op);
    
    void boucleSDL();
    
    void detruitSDL();
    
};


#endif
