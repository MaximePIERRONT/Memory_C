#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "generation.h"
#include "play.h" 

#define SIZE_MEM_IMG 100
#define TAILLEX 1000
#define TAILLEY 900

int menu() {
	couleur gris_c = CouleurParComposante(88,88,88); /*couleur gris clair*/
	int z1 = 0, z2 = 0, z3 = 0, choix = -1, px = -1, py = -1, test = 0, x, y, midx, midy;
	int l_menu_img = 600, h_menu_img = 100; /*taille des images des boutons des menus */
	x = TAILLEX; y = TAILLEY; /* Taille de la fenêtre */
	int hauteur0 = 50, hauteur1 = 350, hauteur2 = 550, hauteur3 = 750; /*Définit les hauteurs du logo et des boutons*/
	int taille_logo = 250; /*taille logo memory*/
	midx = x/2; midy = y/2; /* Trouve la moitié de l'écran en pixel */
	EffacerEcran(gris_c); /* Rempli la fenêtre avec du gris clair */
	ChargerImage("./img/menu/logo.png",midx-(taille_logo/2),hauteur0,0,0,l_menu_img,(taille_logo));/*Affiche le logo*/
	ChargerImage("./img/menu/play.png",midx-(l_menu_img/2),hauteur1,0,0,l_menu_img,(h_menu_img)); /* Affiche le bouton JOUER */
	ChargerImage("./img/menu/size_mem.png",midx-(l_menu_img/2),hauteur2,0,0,l_menu_img,h_menu_img); /* Affiche le bouton TAILLE DU MEMORY*/
	ChargerImage("./img/menu/quit.png",midx-(l_menu_img/2),hauteur3,0,0,l_menu_img,h_menu_img); /* Affiche le bouton QUITTER*/
	while (test != 1) { /* test est un drapeau qui passe à 1 (sort de la boule ) si l'utilisateur clique sur un bouton */
		if (SourisCliquee()) {
			px = _X;
			py = _Y;
		z1 = (CliqueS_Zone(midx-(l_menu_img/2),hauteur1,midx+(l_menu_img/2),hauteur1+h_menu_img,px,py));
		if (z1 == 1) {
			choix = 0;
			test = 1;
		}
		z2 = (CliqueS_Zone(midx-(l_menu_img/2),hauteur2,midx+(l_menu_img/2),hauteur2+h_menu_img,px,py));
		if (z2 == 1) {
			choix = 1;
			test = 1;
		}
		z3 = (CliqueS_Zone(midx-(l_menu_img/2),hauteur3,midx+(l_menu_img/2),hauteur3+h_menu_img,px,py));
		if (z3 == 1) {
			choix = 2;
			test = 1;
		}
	}
	}
	return choix; /* choix revoie quel bouton a été cliqué */
}



int main(void){  

	couleur gris_f = CouleurParComposante(88,88,88); /*couleur gris foncé*/
	int x, y, choix = -1, midx, midy; 
	int m = 6,n = 6; /* on configure une taille de memory de base qui correspond au mode normal */
	int memory[8][8], status[8][8]; /* on initialise un tableau de memory[8][8] et le statut du memory[8][8], on prend 8 car c'est la taille maximale du memory */ 
	srand(time(NULL)); /*Pour les tirages aléatoires */
	InitialiserGraphique();
	x = TAILLEX; y = TAILLEY; /*Taille de la fenetre*/
	midx = x/2; midy = y/2; /*calcul des milieux en pixels*/
	CreerFenetre(0,0,x,y);	/*Créer une fenetre de 1000,900*/
	EffacerEcran(gris_f); /*Rempli la fentre en gris clair*/
	
	
	do {
		choix = menu(); /*On lance le menu et renvoie soit 0 ou 1 ou 2*/
		if (choix == 0) {
		play(m,n,memory,status,x,y,midx,midy); /*Si le choix==0 on lance la fonction play*/
		} else if (choix == 1) {
		menu_size(&m,&n);  /*Si le choix==1 on lance la fonction menu_size*/
		} else if (choix == 2) {
		FermerGraphique(); /*Si le choix==2 quitte le jeu*/
		choix = 4; /*permet de quitter la boucle pour finir le programme*/
		}
	} while (choix != 4); /* quand on ferme la fenêtre on sort de cette boucle*/
	return EXIT_SUCCESS;
}