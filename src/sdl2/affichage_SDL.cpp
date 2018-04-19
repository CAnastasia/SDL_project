#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <unistd.h>
#include "affichage_SDL.h"



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
    posListeA.w=400;
    posListeA.h=100;

    tdB.ajouterElement(1);
    tdB.ajouterElement(0);
    tdB.ajouterElement(0);
    tdB.ajouterElement(0);
    posListeB.x=0.25*WINDIMX;
    posListeB.y=0.5*WINDIMY;
    posListeB.w=400;
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
        tabBouton[i].setPos((WINDIMX/11)*i+20, 0.9*WINDIMY,50,50);
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

void affichageSDL::initBoutonsMenus() {
    string file;
    ifstream work("./data/nomactionmenus"); //on attribue a chaque bouton le nom de sa fonction grace a ce fichier
    for (int i=0;  i <=3; i++) {
        file="./data/sprites/buttons/mouse_out/menus";
        file+=to_string(i+1);
        file+=".bmp";
        std::cout << file << std::endl;
        tabBoutonMenus[i].setEvents(events);
        tabBoutonMenus[i].setPos((WINDIMX/2-150), 100+70*(i+1),300,70);
        if(i==3)
        {
          tabBoutonMenus[i].setPos(0.9*WINDIMX, 0.9*WINDIMY,50,50);
        }
        tabBoutonMenus[i].setImg(file.c_str());
        tabBoutonMenus[i].imgTexture = SDL_CreateTextureFromSurface(renderer, tabBoutonMenus[i].getImg());
        if(work.is_open()) {
            work >> file;
            std::cout << file << std::endl;
            tabBoutonMenus[i].setOpStr(file.c_str());
        }
    }
    work.close();
}

void affichageSDL::initBoutonsNiv() {
    string file;
    ifstream work("./data/nomactionniv"); //on attribue a chaque bouton le nom de sa fonction grace a ce fichier
    for (int i=0;  i <=4; i++) {
        file="./data/sprites/buttons/mouse_out/niveau";
        file+=to_string(i+1);
        file+=".bmp";
        std::cout << file << std::endl;
        tabBoutonNiv[i].setEvents(events);
        tabBoutonNiv[i].setPos((WINDIMX/2-150), 50+50*(i+1),200,50);
        if(i==4)
        {
          tabBoutonNiv[i].setPos(0.1*WINDIMX, 0.1*WINDIMY,50,50);
        }
        tabBoutonNiv[i].setImg(file.c_str());
        tabBoutonNiv[i].imgTexture = SDL_CreateTextureFromSurface(renderer, tabBoutonNiv[i].getImg());
        if(work.is_open()) {
            work >> file;
            std::cout << file << std::endl;
            tabBoutonNiv[i].setOpStr(file.c_str());
        }
    }
    work.close();
}
void affichageSDL::initBoutonsVic() {
    string file;
    ifstream work("./data/nomactionvic"); //on attribue a chaque bouton le nom de sa fonction grace a ce fichier
    for (int i=0;  i <=2; i++) {
        file="./data/sprites/buttons/mouse_out/vic";
        file+=to_string(i+1);
        file+=".bmp";
        std::cout << file << std::endl;
        tabBoutonVic[i].setEvents(events);
        tabBoutonVic[i].setPos((WINDIMX/2-150), 100+70*(i+1),200,70);
        tabBoutonVic[i].setImg(file.c_str());
        tabBoutonVic[i].imgTexture = SDL_CreateTextureFromSurface(renderer, tabBoutonVic[i].getImg());
        if(work.is_open()) {
            work >> file;
            std::cout << file << std::endl;
            tabBoutonVic[i].setOpStr(file.c_str());
        }
    }
    work.close();
}



void affichageSDL::updateListes(const std::string& op,niveau niveau1,int & m) {
  if(niveau1.getFonctionActivee(0))
  {
    if(op=="sa")
    {
      niveau1.sa(tdA);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(1))
  {
    if(op=="sb")
    {
      niveau1.sa(tdB);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(2))
  {
    if(op=="ss")
    {
      niveau1.ss(tdA,tdB);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(3))
  {
    if(op=="pb")
    {
      niveau1.pa(tdA,tdB);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(4))
  {
    if(op=="pa")
    {
      niveau1.pa(tdB,tdA);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(5))
  {
    if(op=="ra")
    {
      niveau1.ra(tdA);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(6))
  {
    if(op=="rb")
    {
      niveau1.ra(tdB);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(7))
  {
    if(op=="rr")
    {
      niveau1.rr(tdA,tdB);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(8))
  {
    if(op=="rra")
    {
      niveau1.rra(tdA);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(9))
  {
    if(op=="rrb")
    {
      niveau1.rra(tdB);
      m++;
    }
  }
  if(niveau1.getFonctionActivee(10))
  {
    if(op=="rrr")
    {
      niveau1.rrr(tdA,tdB);
      m++;
    }
  }
    textureListeA = CreateTextureFromString (tdA.TDtoString());
    textureListeB = CreateTextureFromString (tdB.TDtoString());
}

void affichageSDL::updateListesMenus(const std::string& op, int &choi, jeu &jeu1, niveau &niveau1,int &niveauEC) {
  if(op=="normal")
  {
      choi=1;
  }
  if(op=="endless")
  {
      choi=5;
  }
  if(op=="multi")
  {
      choi=3;
  }
  if(op=="niveau1")
  {
      niveauEC=0;
      TableauDynamique *tabB;
      TableauDynamique *tabA;
      tabA=jeu1.Getniveau(0).getListe();
      tabB=jeu1.Getniveau(0).getListeTransfert();
      tdA.vider();
      tdB.vider();
      for(int i=0;i<tabA->taille_utilisee;i++)
      {
        tdA.ajouterElement(tabA->valeurIemeElement(i));
      }
      textureListeA = CreateTextureFromString(tdA.TDtoString());
      textureListeB = CreateTextureFromString(tdB.TDtoString());
      niveau1=jeu1.Getniveau(0);
      choi=2;
  }
  if(op=="niveau2")
  {
    niveauEC=1;
    TableauDynamique *tabB;
    TableauDynamique *tabA;
    tabA=jeu1.Getniveau(1).getListe();
    tabB=jeu1.Getniveau(1).getListeTransfert();
    tdA.vider();
    tdB.vider();
    for(int i=0;i<tabA->taille_utilisee;i++)
    {
      tdA.ajouterElement(tabA->valeurIemeElement(i));
    }
    textureListeA = CreateTextureFromString(tdA.TDtoString());
    textureListeB = CreateTextureFromString(tdB.TDtoString());
    niveau1=jeu1.Getniveau(1);
    choi=2;
  }
  if(op=="niveau3")
  {
    niveauEC=2;
    TableauDynamique *tabB;
    TableauDynamique *tabA;
    tabA=jeu1.Getniveau(2).getListe();
    tabB=jeu1.Getniveau(2).getListeTransfert();
    tdA.vider();
    tdB.vider();
    for(int i=0;i<tabA->taille_utilisee;i++)
    {
      tdA.ajouterElement(tabA->valeurIemeElement(i));
    }
    textureListeA = CreateTextureFromString(tdA.TDtoString());
    textureListeB = CreateTextureFromString(tdB.TDtoString());
    niveau1=jeu1.Getniveau(2);
    choi=2;
  }
  if(op=="niveau4")
  {
      niveauEC=3;
      TableauDynamique *tabB;
      TableauDynamique *tabA;
      tabA=jeu1.Getniveau(3).getListe();
      tabB=jeu1.Getniveau(3).getListeTransfert();
      tdA.vider();
      tdB.vider();
      for(int i=0;i<tabA->taille_utilisee;i++)
      {
        tdA.ajouterElement(tabA->valeurIemeElement(i));
      }
      textureListeA = CreateTextureFromString(tdA.TDtoString());
      textureListeB = CreateTextureFromString(tdB.TDtoString());
      niveau1=jeu1.Getniveau(3);
      choi=2;
  }
  if(op=="retour")
  {
    choi=0;
  }
  if(op=="menus")
  {
    choi=1;
  }
  if(op=="rejouer")
  {
    TableauDynamique *tabB;
    TableauDynamique *tabA;
    tabA=jeu1.Getniveau(niveauEC).getListe();
    tabB=jeu1.Getniveau(niveauEC).getListeTransfert();
    tdA.vider();
    tdB.vider();
    for(int i=0;i<tabA->taille_utilisee;i++)
    {
      tdA.ajouterElement(tabA->valeurIemeElement(i));
    }
    textureListeA = CreateTextureFromString(tdA.TDtoString());
    textureListeB = CreateTextureFromString(tdB.TDtoString());
    niveau1=jeu1.Getniveau(1);
    choi=2;
  }
  if(op=="nextlvl" && niveauEC<=3)
  {
    niveauEC++;
    TableauDynamique *tabB;
    TableauDynamique *tabA;
    tabA=jeu1.Getniveau(niveauEC).getListe();
    tabB=jeu1.Getniveau(niveauEC).getListeTransfert();
    tdA.vider();
    tdB.vider();
    for(int i=0;i<tabA->taille_utilisee;i++)
    {
      tdA.ajouterElement(tabA->valeurIemeElement(i));
    }
    textureListeA = CreateTextureFromString(tdA.TDtoString());
    textureListeB = CreateTextureFromString(tdB.TDtoString());
    niveau1=jeu1.Getniveau(1);
    choi=2;
  }
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
  int choix=0;
  jeu jeu1;
  jeu1.InitJeu();
  niveau niveau1;
  int niveauEC;
  int nbCoup=0;
  int niveauEnd=3;
  bool endlessInit=1;
  Positionvie.x=(WINDIMX)*0.8;
  Positionvie.y=(WINDIMY)*0.05;
  Positionvie.w=100;
  Positionvie.h=50;
	while(!terminer) {
        SDL_WaitEvent(&events);

        if(events.window.event == SDL_WINDOWEVENT_CLOSE
                    || events.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
          {
            jeu1.SaveJeu();
            terminer = true;
          }
        SDL_RenderClear(renderer);
        if(choix==0)
        {
          for (int i = 0; i <= 3; i++) {
              int op = tabBoutonMenus[i].handle_events();
              std::string currentOp = tabBoutonMenus[i].getOpStr();
              if(op!=0){
                  updateListesMenus(currentOp,choix,jeu1,niveau1,niveauEC);
              }

              SDL_Rect temp = tabBoutonMenus[i].getPos();
              //std::cout << i << " : " << std::endl << "x=" << tabBouton[i].getPos().x << "; y=" << tabBouton[i].getPos().y
              //                                    << "; w=" << tabBouton[i].getPos().w << "; h=" << tabBouton[i].getPos().h << std::endl;
              SDL_RenderCopy(renderer, tabBoutonMenus[i].imgTexture, NULL, &temp);
              /* il est nécessaire de prendre un pointeur sur un SDL_Rect pour la fonction
               * SDL_RenderCopy, cependant il est impossible de prendre directement l'adresse
               * d'un membre d'une classe en c++. Donc on utilise une variable intermédiaire */
          }
        }
        if (choix==1)
        {

          for (int i = 0; i <= 3; i++) {
              string test="";
              if(jeu1.Getniveau(i).getNbEtoilePourDebloquer()<=jeu1.GettotalEtoile())
              {
                if(jeu1.Getniveau(i).getReussi()==1)
                {
                    test+="reussi avec ";
                    test+=jeu1.Getniveau(i).getEtoile()+48;
                    test+=" etoiles";
                    textureTextNiveau[i]=CreateTextureFromString(test);
                    Positiontext[i].x=WINDIMX/2+55;
                    Positiontext[i].y=50+50*(i+1);
                    Positiontext[i].w=200;
                    Positiontext[i].h=50;
                    SDL_RenderCopy(renderer, textureTextNiveau[i], NULL, &Positiontext[i]);
                }
              int op = tabBoutonNiv[i].handle_events();
              std::string currentOp = tabBoutonNiv[i].getOpStr();
              if(op!=0){
                  updateListesMenus(currentOp,choix,jeu1,niveau1,niveauEC);
              }

              SDL_Rect temp = tabBoutonNiv[i].getPos();
              //std::cout << i << " : " << std::endl << "x=" << tabBouton[i].getPos().x << "; y=" << tabBouton[i].getPos().y
              //                                    << "; w=" << tabBouton[i].getPos().w << "; h=" << tabBouton[i].getPos().h << std::endl;
              SDL_RenderCopy(renderer, tabBoutonNiv[i].imgTexture, NULL, &temp);
            }
              /* il est nécessaire de prendre un pointeur sur un SDL_Rect pour la fonction
               * SDL_RenderCopy, cependant il est impossible de prendre directement l'adresse
               * d'un membre d'une classe en c++. Donc on utilise une variable intermédiaire */
          }
          int op = tabBoutonNiv[4].handle_events();
          std::string currentOp = tabBoutonNiv[4].getOpStr();
          if(op!=0){
              updateListesMenus(currentOp,choix,jeu1,niveau1,niveauEC);
          }

          SDL_Rect temp = tabBoutonNiv[4].getPos();
          //std::cout << i << " : " << std::endl << "x=" << tabBouton[i].getPos().x << "; y=" << tabBouton[i].getPos().y
          //                                    << "; w=" << tabBouton[i].getPos().w << "; h=" << tabBouton[i].getPos().h << std::endl;
          SDL_RenderCopy(renderer, tabBoutonNiv[4].imgTexture, NULL, &temp);
        }
        if (choix==2)
        {
          if(jeu1.verifOrdre(tdA) && tdB.taille_utilisee==0)
          {
              #ifdef _WIN32
              Sleep(1000);
              #else
              sleep(1);
              #endif
              choix=3;
          }
          for (int i = 0; i <= 10; i++) {
              int op = tabBouton[i].handle_events();
              std::string currentOp = tabBouton[i].getOpStr();
              if(op!=0){
                  updateListes(currentOp,niveau1,nbCoup);
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
        }
        if (choix==3)
        {
          jeu1.setVp(niveauEC,nbCoup);
          nbCoup=0;
          for (int i = 0; i <= 2; i++) {
              int op = tabBoutonVic[i].handle_events();
              std::string currentOp = tabBoutonVic[i].getOpStr();
              if(op!=0){
                  updateListesMenus(currentOp,choix,jeu1,niveau1,niveauEC);
              }

              SDL_Rect temp = tabBoutonVic[i].getPos();
              //std::cout << i << " : " << std::endl << "x=" << tabBouton[i].getPos().x << "; y=" << tabBouton[i].getPos().y
              //                                    << "; w=" << tabBouton[i].getPos().w << "; h=" << tabBouton[i].getPos().h << std::endl;
              SDL_RenderCopy(renderer, tabBoutonVic[i].imgTexture, NULL, &temp);
              /* il est nécessaire de prendre un pointeur sur un SDL_Rect pour la fonction
               * SDL_RenderCopy, cependant il est impossible de prendre directement l'adresse
               * d'un membre d'une classe en c++. Donc on utilise une variable intermédiaire */
        }
      }
      if (choix==4)
      {
        nbCoup=0;
        for (int i = 0; i <= 1; i++) {
            int op = tabBoutonVic[i].handle_events();
            std::string currentOp = tabBoutonVic[i].getOpStr();
            if(op!=0){
                updateListesMenus(currentOp,choix,jeu1,niveau1,niveauEC);
            }

            SDL_Rect temp = tabBoutonVic[i].getPos();
            //std::cout << i << " : " << std::endl << "x=" << tabBouton[i].getPos().x << "; y=" << tabBouton[i].getPos().y
            //                                    << "; w=" << tabBouton[i].getPos().w << "; h=" << tabBouton[i].getPos().h << std::endl;
            SDL_RenderCopy(renderer, tabBoutonVic[i].imgTexture, NULL, &temp);
            /* il est nécessaire de prendre un pointeur sur un SDL_Rect pour la fonction
             * SDL_RenderCopy, cependant il est impossible de prendre directement l'adresse
             * d'un membre d'une classe en c++. Donc on utilise une variable intermédiaire */
           }
      }
      if (choix==5)
      {
        if(endlessInit)
        {
          string vie= "vie : ";
          vie += niveauEnd+48;
          texturevie=CreateTextureFromString(vie);
          tdA.vider();
          tdB.vider();
          niveau1.getListe()->vider();
          niveau1.getListeTransfert()->vider();
          jeu1.aleatoireGen(niveau1);
          for(int i=0;i<niveau1.getListe()->taille_utilisee;i++)
          {
            tdA.ajouterElement(niveau1.getListe()->valeurIemeElement(i));
          }
          textureListeA = CreateTextureFromString(tdA.TDtoString());
          textureListeB = CreateTextureFromString(tdB.TDtoString());
          endlessInit=0;
        }
        if(jeu1.verifOrdre(tdA) && tdB.taille_utilisee==0)
        {
            #ifdef _WIN32
            Sleep(1000);
            #else
            sleep(1);
            #endif
            endlessInit=1;
        }
        for (int i = 0; i <= 10; i++) {
            int op = tabBouton[i].handle_events();
            std::string currentOp = tabBouton[i].getOpStr();
            if(op!=0){
                updateListes(currentOp,niveau1,nbCoup);
            }

            SDL_Rect temp = tabBouton[i].getPos();
            //std::cout << i << " : " << std::endl << "x=" << tabBouton[i].getPos().x << "; y=" << tabBouton[i].getPos().y
            //                                    << "; w=" << tabBouton[i].getPos().w << "; h=" << tabBouton[i].getPos().h << std::endl;
            SDL_RenderCopy(renderer, tabBouton[i].imgTexture, NULL, &temp);
            /* il est nécessaire de prendre un pointeur sur un SDL_Rect pour la fonction
             * SDL_RenderCopy, cependant il est impossible de prendre directement l'adresse
             * d'un membre d'une classe en c++. Donc on utilise une variable intermédiaire */
        }
        SDL_RenderCopy(renderer, texturevie, NULL, &Positionvie);
        SDL_RenderCopy(renderer, textureListeA, NULL, &posListeA);
        SDL_RenderCopy(renderer, textureListeB, NULL, &posListeB);
      }
        SDL_RenderPresent(renderer);
    }
}
