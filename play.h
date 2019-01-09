/* Memory : fichier play.h */

#ifndef PLAY_H
#define PLAY_H

int affihage_win(couleur a, int x, int y, int midx, int midy);
/* Affichage lors de la victoire */

void tricheur (int m, int n, double tx[], double ty[], int memory[8][8], int status[8][8]);
/* Fonction quand on appuis sur 't' bloque le temps et retourne les cartes */

void return_card_triche (int m, int n, double tx[], double ty[], int memory[8][8], int status[8][8], int code);

void tabstatus (int status[8][8], int m, int n);
/* Rempli le tableau avec des zeros */

void remplirtab_p (double tx[],double ty[], int a, int b) ;
/* Rempli le tableau avec des zeros */

void affiche_mem_case(int m, int n, double tx[], double ty[]);
/* Rempli le tableau des place des case en x et y*/

void flip_card (double tx[], double ty[],int memory[8][8], int a, int b);
/* Affiche le memory sur la console */

int return_card (int m, int n, double tx[], double ty[],int memory[8][8], int *a, int *b, int status[8][8], int px, int py, int *flag, int nb);
/* Retourne la carte en face cachée */

int lap (int m,int n, int memory[8][8], int status[8][8], int test, int x, int y, unsigned long time_base, unsigned long* time_temp, long* time_triche);
/* Fonction pour un tour de jeu */

void play (int m, int n, int memory[8][8], int status[8][8], int x, int y, int midy, int midx);
/* Fonction jouer */


#endif /* PLAY_H */

