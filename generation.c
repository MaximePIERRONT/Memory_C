#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graph.h>
#include <unistd.h>





int CliqueS_Zone(int minx, int miny, int maxx, int maxy, int px, int py) {/*Fonction qui permet de détecter un clique dans une zone de minx, miny à maxx et maxy*/
	int valide = 0;
		if ((minx <= px)&&(maxx >= px)) {
			if ((miny <= py)&&(maxy >= py)) {
				valide = 1;
			}
		}
	return valide;
}

void remplirtaba2(int n, int t[]) {/*Rempli un talbeau à 2 en fonction de la nombre d'image possible*/
	int compteur;
	for (compteur = 0; compteur < n; compteur++) {
		 		t[compteur] = 2;
	}                                                                        
}

void generate_tab(int m, int n, int memory[8][8]){ /*Génere aléatoirement la grille de memory avec le chiffre correspondant aux images*/
	int mem_case = m*n, nb_img = mem_case/2, compteur, compteur2, tirage;
	int compte[32];	
	remplirtaba2(nb_img, compte);
	for (compteur = 0; compteur < n; compteur++) /* rempli tableau du memory */ {
		for (compteur2 = 0; compteur2 < m;) {			
		 	tirage = (rand() % nb_img) ; /*tire un nombre entre 0 et nb_img*/
		 	if (compte[tirage] > 0) { /* Si il reste encore de ce nombre dans le tableau */
		 		memory[compteur][compteur2] = tirage; /* alors la case prend ce nombre*/
		 		compte[tirage]--; /*on décrémente d'1 la valeur du talbeau des nombre d'image restant */
		 		compteur2++; /*on avance dans le tableau*/
		 	}			
		}		
	} 
}

void affiche_mem_console(int m, int n, int memory[8][8]) { /*Affiche le memory sur la console*/
	int compteur, compteur2;
	for (compteur = 0; compteur < n; compteur++) {
		for (compteur2 = 0; compteur2 < m; compteur2++)
		{
			printf("|%3d ", memory[compteur][compteur2] );
		}
	printf("|\n");
	}
}


void menu_size(int *a, int *b) { /*menu_size : menu pour choisir la taille de la grille*/
	couleur m = CouleurParComposante(88,88,88);
	int facile = 0, normal = 0, difficile = 0, choix = -1, px = -1, py = -1, test = 0, x, y, midx, midy;
	int l_menu_img = 600, h_menu_img = 100; /*taille des images des boutons des menus */
	EffacerEcran(m); /*Rempli l'éran en gris clair*/
	x = 1000; y = 900;
	midx = x/2; midy = y/2;
	ChargerImage("./img/menu/facile.png",midx-(l_menu_img/2),350,0,0,l_menu_img,h_menu_img); /* Affiche le bouton Facile */
	ChargerImage("./img/menu/normal.png",midx-(l_menu_img/2),550,0,0,l_menu_img,h_menu_img); /* Affiche le bouton Normal */
	ChargerImage("./img/menu/difficile.png",midx-(l_menu_img/2),750,0,0,l_menu_img,h_menu_img); /* Affiche le bouton Difficile */
	while (test != 1) {/* test est un drapeau qui passe à 1 (sort de la boule ) si l'utilisateur clique sur un bouton */
		if (SourisCliquee()) {
			px = _X;
			py = _Y;
		

		facile = (CliqueS_Zone(midx-300,350,midx+300,350+100,px,py));
		if (facile == 1) {
				*a = 4;
				*b = 4;
			test = 1;
		}
		normal = (CliqueS_Zone(midx-300,550,midx+300,550+100,px,py));
		if (normal == 1) {
				*a = 6;
				*b = 6;
			test = 1;
		}
		difficile = (CliqueS_Zone(midx-300,750,midx+300,750+100,px,py));
		if (difficile == 1) {
				*a = 8;
				*b = 8;
			test = 1;
		}
	}
	}
} 

