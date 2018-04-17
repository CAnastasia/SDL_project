#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>

#include "TableauDynamique.h"
#include "push_swap.h"
#include "affichage_SDL.h"
#include "bouton_SDL.h"

using namespace std;

int main() {

    affichageSDL aff;
    
    aff.initSDL();
    aff.initListes();
    aff.initBoutons();
    aff.boucleSDL();
    aff.detruitSDL();
 
    
    return 0;
}
