#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "TableauDynamique.h"
#include "affichage_SDL.h"
#include "bouton_SDL.h"


void affichageSDL::initSDL() {
    
    WINDIMX = 800;
    WINDIMY = 600;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    
    window = SDL_CreateWindow(
		 "Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDIMX, WINDIMY, SDL_WINDOW_SHOWN);
    if(window == 0) {
        cout << "Erreur lors de la creation de la window : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    
    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",100);
    if (font == NULL) {
            cout << "Failed to losad OpenSans.ttf! SDL_TTF Error: " << TTF_GetError() << endl;
            SDL_Quit();
            exit(EXIT_FAILURE);
	}
	
	font_color.r = 50;font_color.g = 50;font_color.b = 255;
    
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED); 
    
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
   
    
    
}

SDL_Texture* affichageSDL::CreateTextureFromString(string txt) {
    SDL_Surface* tempSurface = TTF_RenderText_Solid(font, txt.c_str(), font_color);
    return SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

void affichageSDL::initListes() {
     
    tdA.ajouterElement(1);
    tdA.ajouterElement(2);
    tdA.ajouterElement(3);
    tdA.ajouterElement(4);
    posListeA.x=0.25*WINDIMX;
    posListeA.y=0.2*WINDIMY;
    posListeA.w=200;
    posListeA.h=100;
    
    tdB.ajouterElement(0);
    tdB.ajouterElement(0);
    tdB.ajouterElement(0);
    tdB.ajouterElement(0);
    posListeB.x=0.25*WINDIMX;
    posListeB.y=0.5*WINDIMY;
    posListeB.w=200;
    posListeB.h=100;
    
    textureListeA = CreateTextureFromString(tdA.TDtoString());
    textureListeB = CreateTextureFromString(tdB.TDtoString());
    
    /*listeA = TTF_RenderText_Solid(font,tdA.TDtoString().c_str(),font_color);
    listeB = TTF_RenderText_Solid(font,tdB.TDtoString().c_str(),font_color);
    
    std::cout << "tda: " << tdA.TDtoString() << std::endl << "tdb :" << tdB.TDtoString() << std::endl;
    
    textureListeA = SDL_CreateTextureFromSurface(renderer, listeA);
    textureListeB = SDL_CreateTextureFromSurface(renderer, listeB);
    */
}


void affichageSDL::initBoutons() {
    string file;
    ifstream work("./data/nomaction"); //on attribue a chaque bouton le nom de sa fonction grace a ce fichier
    for (int i=0;  i <=10; i++) {
        file="./data/sprites/buttons/mouse_out/fct";
        file+=to_string(i+1);
        file+=".bmp";
        std::cout << file << std::endl;
        tabBouton[i].setEvents(events);
        tabBouton[i].setPos((WINDIMX/11)*i+20, 0.9*WINDIMY);
        tabBouton[i].setImg(file.c_str());
        tabBouton[i].imgTexture = SDL_CreateTextureFromSurface(renderer, tabBouton[i].getImg());
        if(work.is_open()) {
            work >> file;
            std::cout << file << std::endl;
            tabBouton[i].setOpStr(file.c_str());
        }
    }
    work.close();
}

void affichageSDL::updateListes(const std::string& op) {
    TableauDynamique tdtest;
    tdtest.ajouterElement(5);
    tdtest.ajouterElement(6);
    tdtest.ajouterElement(7);
    tdtest.ajouterElement(8);
    
    textureListeA = CreateTextureFromString (tdtest.TDtoString());
    
}


void affichageSDL::detruitSDL() {
 
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(textureListeA);
    SDL_DestroyTexture(textureListeB);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
}

void affichageSDL::boucleSDL() {
    
	while(!terminer) {        
        SDL_WaitEvent(&events);

        if(events.window.event == SDL_WINDOWEVENT_CLOSE
                    || events.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            terminer = true;
        
        SDL_RenderClear(renderer);
        
        
        
        
        for (int i = 0; i <= 10; i++) {
            int op = tabBouton[i].handle_events();
            std::string currentOp = tabBouton[i].getOpStr();
            if(op!=0){
                updateListes(currentOp);             
            
            }
            
            SDL_Rect temp = tabBouton[i].getPos();
            //std::cout << i << " : " << std::endl << "x=" << tabBouton[i].getPos().x << "; y=" << tabBouton[i].getPos().y
            //                                    << "; w=" << tabBouton[i].getPos().w << "; h=" << tabBouton[i].getPos().h << std::endl;
            SDL_RenderCopy(renderer, tabBouton[i].imgTexture, NULL, &temp);
            /* il est nécessaire de prendre un pointeur sur un SDL_Rect pour la fonction
             * SDL_RenderCopy, cependant il est impossible de prendre directement l'adresse 
             * d'un membre d'une classe en c++. Donc on utilise une variable intermédiaire */
        }
        
        SDL_RenderCopy(renderer, textureListeA, NULL, &posListeA);
        SDL_RenderCopy(renderer, textureListeB, NULL, &posListeB);
        
        SDL_RenderPresent(renderer);
    }
    
}
