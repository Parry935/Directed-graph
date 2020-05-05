#include "pch.h"
#include "Header.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int **stworzTablice_x2(int V, int E)
{
	int **T = nullptr;
	T = new int *[V];

	for (int i = 0; i < V; i++)
	{
		T[i] = new int[E];
	}

	return T;
}

int *stworzTablice_x1(int n)
{
	int *T = new int[n];
	return T;
}

void odczyt_z_pliku(string file_name, int &k, int &w, int **tab_poczatek, int **tab_koniec)
{
	fstream file;
	file.open(file_name.c_str(), ios::in);
	if (file.good() != true)
	{
		throw EXCEPTION_CODE::openError;

	}

	
	file >> k;
	*tab_poczatek = stworzTablice_x1(k);
	*tab_koniec = stworzTablice_x1(k);
	int help = 0;

	// odczyt z pliku i okleœlenie iloœci wierzcho³ków grafu
	for (int i = 0; i < k; i++)
	{
		file >> help;
		if (help > w)
			w = help;

		(*tab_poczatek)[i] = help;

		file >> help;
		if (help > w)
			w = help;


		(*tab_koniec)[i] = help;
	}

	file.close();
}


void macierz_incydencji_tablica_dynamiczna(int k, int w, int *tab_poczatek, int *tab_koniec)
{
	int **macierz = stworzTablice_x2(w, k);

	//wype³nianie macierzy odpowiednimy liczbami
	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < w; i++)
		{
			if (tab_poczatek[j] == i+1)
				macierz[i][j] = 1;

			else if (tab_koniec[j] == i+1)
				macierz[i][j] = -1;

			else
				macierz[i][j] = 0;
		}
	}

	// wyœwietlanie macierzy
	cout << "   ";
	for (int i = 0; i < k; i++)
	{
		cout << "e" << i+1 << "\t";
	}
	
	cout << endl;
	

	for (int j = 0; j < w; j++)

	{
		cout << "v" << j + 1 << " ";
		for (int i = 0; i < k; i++)
		{
			cout << macierz[j][i] << "\t";
		}

		
		cout << endl;
	}

}


void macierz_incydencji_vector(int k, int w, int *tab_poczatek, int *tab_koniec)
{
	vector<vector<int>> macierz (w, vector<int>(k, 0));

	//wype³nianie macierzy odpowiednimy liczbami
	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < w; i++)
		{
			if (tab_poczatek[j] == i + 1)
				macierz[i][j] = 1;

			else if (tab_koniec[j] == i + 1)
				macierz[i][j] = -1;
		}
	}

	// wyœwietlanie macierzy
	cout << "   ";
	for (int i = 0; i < k; i++)
	{
		cout << "e" << i + 1 << "\t";
	}

	cout << endl;


	for (int j = 0; j < w; j++)

	{
		cout << "v" << j + 1 << " ";
		for (int i = 0; i < k; i++)
		{
			cout << macierz[j][i] << "\t";
		}


		cout << endl;
	}

}

void seeExceptions(EXCEPTION_CODE error)
{
	switch (error) 
	{
	case EXCEPTION_CODE::openError:
		cerr << "Blad otwarcia pliku odczytu";
		break;
	default:
		cerr << "Nieznany blad";
		break;
	}
}