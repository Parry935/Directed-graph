#ifndef HEADER_H
#define HEADER_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

/*Funkcja tworz�ca tablic� dynamiczn� dwywymiarow� - zwraca wska�nik do jej pierwszego elementu*/
int **stworzTablice_x2(int V, int E);

/*Funkcja odczytuj�ca dane z pliku tekstowego*/
void odczyt_z_pliku(string file_name,int &k,int &w, int **tab_poczatek, int **tab_koniec);

/*Funkcja tworz�ca tablic� dynamiczn� jednowymiarow� - zwraca wska�nik do jej pierwszego elementu*/
int *stworzTablice_x1(int n);

/*Funkcja tworz�ca macierz incydencji za pomoc� tabliczy dynamicznej dwuwymiarowej*/
void macierz_incydencji_tablica_dynamiczna(int k, int w, int *tab_poczatek, int *tab_koniec);

/*Funkcja tworz�ca macierz incydencji za pomoc� vectora*/
void macierz_incydencji_vector(int k, int w, int *tab_poczatek, int *tab_koniec);

enum EXCEPTION_CODE
{
	openError
	
};

/*Funkcja wy�wietlaj�ca informacj� o b��dzie w programie*/
void seeExceptions(EXCEPTION_CODE error);

#endif 

