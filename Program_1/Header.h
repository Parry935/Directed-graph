#ifndef HEADER_H
#define HEADER_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

/*Funkcja tworz¹ca tablicê dynamiczn¹ dwywymiarow¹ - zwraca wskaŸnik do jej pierwszego elementu*/
int **stworzTablice_x2(int V, int E);

/*Funkcja odczytuj¹ca dane z pliku tekstowego*/
void odczyt_z_pliku(string file_name,int &k,int &w, int **tab_poczatek, int **tab_koniec);

/*Funkcja tworz¹ca tablicê dynamiczn¹ jednowymiarow¹ - zwraca wskaŸnik do jej pierwszego elementu*/
int *stworzTablice_x1(int n);

/*Funkcja tworz¹ca macierz incydencji za pomoc¹ tabliczy dynamicznej dwuwymiarowej*/
void macierz_incydencji_tablica_dynamiczna(int k, int w, int *tab_poczatek, int *tab_koniec);

/*Funkcja tworz¹ca macierz incydencji za pomoc¹ vectora*/
void macierz_incydencji_vector(int k, int w, int *tab_poczatek, int *tab_koniec);

enum EXCEPTION_CODE
{
	openError
	
};

/*Funkcja wyœwietlaj¹ca informacjê o b³êdzie w programie*/
void seeExceptions(EXCEPTION_CODE error);

#endif 

