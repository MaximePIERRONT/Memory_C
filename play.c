#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <graph.h>
#include <unistd.h>
#include "generation.h"

#define SIZE_MEM_IMG 100
#define TAILLEX 1000
#define TAILLEY 900


int affihage_win(couleur a, int x, int y, int midx, int midy) { /* Affichage lors de la victoire */
	int test =0, px, py;
	int bouton_size = 512;
	EffacerEcran(a); /* Rempli la fenêtre avec du gris clair*/
	ChargerImage("./img/menu/WIN.png",midx-(bouton_size/2),midy-(bouton_size/2),0,0,bouton_size,bouton_size); /* Affiche l'image de victoire au mileu de l'écran*/ 
	while (test != 1) { /* test est le drapeau ; dès que le joueur a cliqué sur l'imgage on quitte la boucle*/
		if (SourisCliquee()) {
			px = _X;
			py = _Y;
		test = CliqueS_Zone(midx-(bouton_size/2),midy-(bouton_size/2),midx+(bouton_size/2),midy+(bouton_size/2),px,py); /*regarde si on clique sur l'image*/
		}
	}
return 1; /*retourne 1*/
}



void return_card_triche (int m, int n, double tx[], double ty[], int memory[8][8], int status[8][8], int code) {
	int compteur, compteur2;
	char nom[25];
	for (compteur = 0; compteur < n; compteur++) { /*Cette double boucle soit : si code = 1 retourne tout les cartes face cachées ; si code = 0 retourne les carte avec face retournée */
		for (compteur2 = 0; compteur2 < m; compteur2++) {
			if (status[compteur2][compteur] == 0) { /*permet de retourner que les images non découvertes*/
				if (code == 0) {
					sprintf(nom,"./img/memory_card/%d.png",memory[compteur2][compteur]); /*Prend comme chaine de caractère celle de l'image*/
					ChargerImage(nom,tx[compteur],ty[compteur2],0,0,SIZE_MEM_IMG,SIZE_MEM_IMG); /*Affiche les images*/ 
				} else if (code == 1) {
					RemplirRectangle(tx[compteur],ty[compteur2],SIZE_MEM_IMG,SIZE_MEM_IMG);/*Affiche les carrés gris*/
				}
			}
		}
	}
}

void tricheur (int m, int n, double tx[], double ty[], int memory[8][8], int status[8][8]) {/*La fonction tricheur*/
	int t, t2, code = 0;
	int bin; /*poubelle*/
		return_card_triche(m,n,tx,ty,memory,status,code);/*Appelle la fonction triche (code=0)*/
	
		while ( t2 != 't' ) {
			if (ToucheEnAttente()) {
			t2=Touche();/*Regarde si la touche est le 't'*/
		}
		}
		code = 1;/*passe le code à 1 pour retourner les cartes face cachés*/
		return_card_triche(m,n,tx,ty,memory,status,code);/*Appelle la fonction triche (code=0)*/
		while (SourisCliquee()) { /* faire un vide du cache des clics souris */
			bin =_X;
			bin =_Y;
		}
}


void tabstatus (int status[8][8], int m, int n) { /* Rempli le tableau avec des zeros */
	int mem_case = m*n, nb_img = mem_case/2, compteur, compteur2, tirage;

	for (compteur = 0; compteur < n; compteur++) {
		for (compteur2 = 0; compteur2 < m; compteur2++) {			
		 	status[compteur][compteur2] = 0;
		 	
		 	}			
		}		
} 

void remplirtab_p (double tx[],double ty[], int a, int b) { /* Rempli le tableau des place des case en x et y*/
	int x, y, compteur;

	double cinqprcent = 0.05; /*représente 5%*/
	double qprcent = 0.95; /*représente 95%*/
	x = TAILLEX; y = TAILLEY;
	double placex = x/(a+2), placey = y/(b+2);


	for (compteur = 0; compteur < (b); compteur++)
	{
		ty[compteur] = (SIZE_MEM_IMG+(((y*qprcent)-b*SIZE_MEM_IMG)/b-1)) * (compteur)+ (y*cinqprcent);
	}
		for (compteur = 0; compteur < (a); compteur++)
	{
		tx[compteur] = ty[compteur] + (x-y);
	}
}

void affiche_mem_case(int m, int n, double tx[], double ty[]) { /* Affiche le memory sur la console */
	int compteur, compteur2;	
	couleur gris_f = CouleurParComposante(48,48,48);

	ChoisirCouleurDessin(gris_f);
	for (compteur = 0; compteur < m; compteur++) { /*Rempli dans les cases avec des rectangles*/
		for (compteur2 = 0; compteur2 < n; compteur2++) {
			RemplirRectangle(tx[compteur],ty[compteur2],SIZE_MEM_IMG,SIZE_MEM_IMG);
		}
	}
			
}

void flip_card (double tx[], double ty[],int memory[8][8], int a, int b) { /* Retourne la carte en face cachée */
	couleur gris_f = CouleurParComposante(48,48,48);

	ChoisirCouleurDessin(gris_f);
	RemplirRectangle(tx[a],ty[b],SIZE_MEM_IMG,SIZE_MEM_IMG);
}

int return_card (int m, int n, double tx[], double ty[],int memory[8][8], int *a, int *b, int status[8][8], int px, int py, int *flag, int nb) { /* Retourne la carte avec son image */
	int compteur, compteur2, swap, i;
	char nom[500];

	for (compteur = 0; compteur < n; compteur++) { /*vérifie si le clique correspond à une case non-retourné*/
		for (compteur2 = 0; compteur2 < m; compteur2++) {
			swap = (CliqueS_Zone(tx[compteur],ty[compteur2],tx[compteur]+SIZE_MEM_IMG,ty[compteur2]+SIZE_MEM_IMG,px,py));
			if (swap == 1 && status[compteur2][compteur] == 0) {
				*flag = nb + 1;
				sprintf(nom,"./img/memory_card/%d.png",memory[compteur2][compteur]); 
				status[compteur2][compteur] = 1;
				ChargerImage(nom,tx[compteur],ty[compteur2],0,0,SIZE_MEM_IMG,SIZE_MEM_IMG); /*Affiche l'image correspondante à l'emplacement de la case*/
				*a = compteur;
				*b = compteur2;
				return (memory[compteur2][compteur]);
			}
		}	
	}
}

int lap (int m,int n, int memory[8][8], int status[8][8], int test, int x, int y, unsigned long time_base, unsigned long* time_temp, long* time_triche) { /* Fonction pour un tour de jeu */
	int carte[2];
	int dif_hauteur = 30 /*diffrence de hauteur entre le "temps :" et le hiffre représentant le temps*/, partx = 120 /*Partie de la fenêtre coordonnée x a effacer*/;
	int aligntext1 = 10, aligntext2 = 60 ; /*alignement du texte coordonnée x*/
	int to, flag = -1, px, py;
	int ligne[2], colonne[2];
	int compteur, compteur2;
	double tab_px[8], tab_py[8];
	remplirtab_p(tab_px,tab_py, m, n);
	carte[0] = -1;
	int compteur_temps, seconde;
	unsigned long time_1;
	unsigned long temps;
	couleur noir = CouleurParComposante(0,0,0);
	couleur gris_c = CouleurParComposante(88,88,88);
	couleur gris_f = CouleurParComposante(48,48,48);
	char nom[500];



	while (flag != 1) { /*tant que soit le joueur ne retourne pas deux cartes*/
		
		if (ToucheEnAttente()) { /* Si touche t lance la fonction tricheur*/
			to=Touche();
			if (to=='t') {
				time_1 = Microsecondes();
				tricheur(m,n,tab_px,tab_py,memory,status);
				*time_triche = *time_triche + Microsecondes() - time_1;
			}
		}
		if (SourisCliquee()) {/*Test pour retourner une carte du memory quand il y a clique*/
			px = _X;
			py = _Y;
			carte[flag+1] = return_card(m,n,tab_px,tab_py,memory,&ligne[flag+1],&colonne[flag+1],status,px,py,&flag, flag);
		}
		
		temps = (Microsecondes() - time_base - *time_triche)/1000000UL; /*il s'agit du temps écoulé depuis le début de la partie*/
		if (temps > *time_temp) { /*si le nouveau temps est superieur à l'ancien*/
			sprintf(nom,"%3lu", temps);
			ChoisirCouleurDessin(gris_c);
			RemplirRectangle(0,0,partx,TAILLEY); /*Rempli la partie où se trouve le chrono*/
			ChoisirCouleurDessin(noir);
			EcrireTexte(aligntext2,(TAILLEY/2),nom,2); /*Affiche le temps*/
			EcrireTexte(aligntext1,((TAILLEY/2)-dif_hauteur),"Temps :",2);/*Affiche temps*/
			ChoisirCouleurDessin(gris_f);

			*time_temp = temps; /* time_temp est la vieille valeur de temps*/
		}
	}
	if (carte[0] != carte[1] || (ligne[0] == ligne[1] && colonne[0] == colonne[1])) {
		usleep(1000000); /*Temps de mémorisation de 1 seocnde*/
		
		*time_triche = *time_triche - 1000000UL; /*On ajoute les une seconde au temps, mais comme on l'ajoute dans triche c'est l'inverse on retire 1 seconde*/
		flip_card (tab_px,tab_py,memory,ligne[0],colonne[0]);/*retourne la première carte*/
		status[colonne[0]][ligne[0]] = 0;
		flip_card (tab_px,tab_py,memory,ligne[1],colonne[1]);/*retourne la deuxième*/
		status[colonne[1]][ligne[1]] = 0;
		return test;
	} else {
	for (test = 0, compteur = 0; compteur < n; compteur++) {/*Ajoute deux à test pour savoir quand toute les cartes sont retournées*/
		for (compteur2 = 0; compteur2 < m; compteur2++) {
			test = test + status[compteur2][compteur];
		}
	}
	return test;
	}
}

void play (int m, int n, int memory[8][8], int status[8][8], int x, int y, int midx, int midy) { /* Fonction jouer */
	couleur gris_c = CouleurParComposante(88,88,88);
	couleur noir = CouleurParComposante(0,0,0);
	double tab_px[8], tab_py[8];
	int aligntext1 = 10, aligntext2 = 60 ; /*alignement du texte coordonnée x*/
	int test = 0, code = 0, antibug = 0;
	int dif_hauteur = 30 /*diffrence de hauteur entre le "temps :" et le hiffre représentant le temps*/, partx = 120 /*Partie de la fenêtre coordonnée x a effacer*/;
	int a; /*sert de poubelle*/
	unsigned long time_base; /* Temps de microseconde au début du jeu */
	unsigned long time_temp = 0UL, t;
	long time_triche = 0UL;
	EffacerEcran(gris_c); /*rempli ecran avec du gris clair*/
	generate_tab(m,n,memory); /*genere en random la table du memory*/
	remplirtab_p(tab_px, tab_py, m, n);/*genere les emplacements des cartes memorys*/
	tabstatus(status,m,n);/*crée le tab status avec que des 0*/
	affiche_mem_case(m,n,tab_px,tab_py);/*Affiche memory à l'éran*/
	while (antibug != 1) { /*Cette partie permet d'enlever tout les touche en attente avant de lancer le jeu*/
		if (ToucheEnAttente()) {
			a = Touche();
		} else {
			antibug = 1;
		}
	}
	ChoisirCouleurDessin(noir);
	EcrireTexte(aligntext2,(TAILLEY/2),"  0",2);
	EcrireTexte(aligntext1,((TAILLEY/2)-dif_hauteur),"Temps :",2);/*Affiche temps à 0*/
	time_base = Microsecondes();/*Prend le temps de base avant de lancer le jeu*/
	
	while (test != m*n) {	
		test = lap(m,n,memory,status,test,x,y,time_base,&time_temp,&time_triche); /* fait autant de tour que le joueur met à trouver toutes les paires*/

	}	
	while (test != 1) {
		test = affihage_win(gris_c, x, y, midx, midy); /*Affiche le logo quand on a gagné*/
	}
}
