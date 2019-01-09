/* Memory : fichier generation.h */

#ifndef GENERATION_H
#define GENERATION_H


int CliqueS_Zone(int minx, int miny, int maxx, int maxy, int px, int py);
/*Fonction qui permet de détecter un clique dans une zone de minx, miny à maxx et maxy*/

void remplir_tab_a_2(int n, int t[]);
/*Rempli un talbeau à 2 en fonction de la nombre d'image possible*/

void generate_tab(int m, int n, int memory[8][8]);
/*Génere aléatoirement la grille de memory avec le chiffre correspondant aux images*/

void affiche_mem_console(int m, int n, int memory[8][8]);
/*Affiche le memory sur la console*/

void menu_size (int *a,int *b);
/*menu_size : menu pour choisir la taille de la grille*/


#endif /* GENERATION_H */