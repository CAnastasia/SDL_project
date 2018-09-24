MAM
Cotorobai Anastasia 11713175
Barros Mikel-Ange   11508726
Oran Mikail	    11608112
Identifiant sur forge : ANASTASIA COTOROBAI p1713175
Commande de compilatoin : make test exemple sdl serveur 
Regles de jeu:

• Le jeu est constitué de 2 piles nommées a et b.
• Au départ :
	◦ a contient un nombre arbitraire d’entiers positifs ou négatifs, sans doublons.
	◦ b est vide
• Le but du jeu est de trier a dans l’ordre croissant.
• Pour ce faire, on ne dispose que des opérations suivantes :
1)sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
rien s’il n’y en a qu’un ou aucun.
2)sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait
rien s’il n’y en a qu’un ou aucun.
3)ss : sa et sb en même temps.
4)pa : push a - prend le premier élément au sommet de b et le met sur a. Ne fait
rien si b est vide.
5)pb : push b - prend le premier élément au sommet de a et le met sur b. Ne fait
rien si a est vide.
6)ra : rotate a - décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
7)rb : rotate b - décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
8)rr : ra et rb en même temps.
9)rra : reverse rotate a - décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
10)rrb : reverse rotate b - décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.
11)rrr : rra et rrb en même temps.

Pour illustration, trions une liste arbitraire pour constater l’effet de quelques instructions.
0. Init a and b :
2
1
3
6
5
8
a b
1. Exec sa :
1
2
3
6
5
8
a b
2. Exec pb pb pb :
6 3
5 2
8 1
a b
3. Exec ra rb :
(equiv. to rr)
5 2
8 1
6 3
a b
4. Exec rra rrb :
(equiv. to rrr)
6 3
5 2
8 1
a b
5. Exec sa :
5 3
6 2
8 1
a b
6. Exec pa pa pa :
1
2
3
5
6
8
a b
Cet exemple trie les entiers de a en 12 instructions.

Fonctionnalités du programme:
1)Saisir nom jouer 
2)Plusieurs niveaux 
3)leader board
4)Application des instructions sur les listes 
5)Muli-joueur incomplet 
6)timer

Archive:
readme.txt
dossier bin: les execut
dossier data: assets de  l'application
obj: les .o
doc: doxygen,power point presentation, diagramme de gantt, diagramme des modules 
src : 
	dossiers:
			main: fonctionnalités pour l'algorithme 
			sdl2: fonctionnalités sdl
			serveur: fonctionnalités pour server et la gestion des clients 
			socklib: fonctionnalités pour la connexion et l'acceptation client-server
			test: test regression 
			txt: verssion txt 
makefile 


