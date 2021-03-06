//////////////////////////////////////////////
//
//				*PROJCET EULER*
//
//01.09.2018
//////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int problem_001();
int problem_002();
int generate_prime_numbers();
int problem_003();

int main()
{
	problem_003();



	return 0;
}


int problem_001()
{
	int solve = 0;								//stworzenie wartosci inicjalizacyjnych
	int start_3 = 0;
	int start_5 = 0;

	int buffor_3[1000]{ 0 };					//stworzenie tablic buforowych (magazynu na wielokrotnosci)
	int buffor_5[1000]{ 0 };					//nadpisanie komorek zerami, nie uzyje wszystkich komorek a bede je sumowal

	for (int i = 0; 1000 > start_3 + 3; i++)	//wyliczenie wielokrotnosci 3
	{
		start_3 = start_3 + 3;
		buffor_3[i] = start_3;
	}

	for (int y = 0; 1000 > start_5 + 5; y++)	//wyliczenie wielokrotnosci 5
	{
		start_5 = start_5 + 5;
		buffor_5[y] = start_5;
	}

	for (int x = 0; x < 1000; x++)				//usuniecie wielokrotnosci 5 z wieokrotnosci 3 np 5, 10, 15, ...
	{
		if (buffor_3[x] % 5 == 0)				//sprawdzam czy dana komorka z tablicy jest podzielna przez 5
		{										//jesli tak to nadpisuje ja 0 zeby nie sumowac tych samych liczb
			buffor_3[x] = 0;					//usuniete wielokrotonosci napisuje zerami
		}
	}

	for (int n = 0; n <1000; n++)				//sumowanie wieoktornosci 3 i 5 
	{
		solve += (buffor_3[n] + buffor_5[n]);
	}

	return solve;
}

int problem_002()
{
	int a = 0;						//wprowadzam pierwsze liczby do ciagu fibonacciego
	int b = 1;
	long int fibonacci = 0;
	int fibonacci_bufor[30]{ 0 };	//tworze bufor wynikowy w ktorym bede sumowal parzyste liczby (wg polecenia zdania)
	long int suma = 0;

	for (int i = 0; fibonacci < 4000000; i++)	//szukam ciagu 4 milionowego
	{
		fibonacci = a + b;						//tworze ciag z podanych liczb
		a = b;
		b = fibonacci;

		if (fibonacci % 2 == 0)						//sprawdzam parzystosc liczby fibonacciego
		{
				fibonacci_bufor[i] = fibonacci;				//jesli jest parzysta to przepisuje ja do buforu 
			//	cout << fibonacci_bufor[i] << endl;			//wyswietlam parzyste liczby
				suma += fibonacci_bufor[i];					//sumuje je w buforze wyniokowym
			
		}
	}

	return suma;
}

int problem_003()
{
	const long long int number = 13195;
	int Hi_factor;
	bool aux = true;

	for (int licznik = 1; licznik < number; licznik++)
	{
		for (int mianownik = 1; mianownik < licznik; mianownik++)
		{
			aux = true;
			int rest = licznik % mianownik;

			if ((rest == 0) && (mianownik != 1) && (mianownik != number))
			{
				aux = false;
			
			}
				if( aux == true)
				{
					cout << mianownik << endl;
					break;
				}
	
		}
			

	}



	return 0;
}

int generate_prime_numbers()
{
	const long long int start = 1; //liczba od ktroej sprawdzamy liczbe pierwsza
	const long long int stop = 1000; //liczba do ktroej sprawdzamy liczbe pierwsza
	int rest;	// pomocnicza zmienna,  reszta z dzielania podczas sprawdzania liczby pierwszej
	bool support = true; //liczba pomocnia objasniona nizej

	for (int i = start; i < stop; i++) //generowanie licz z przedzialu start/stop
	{

		for (int y = 1; y <i ; y++) //generowanie dzielnika do sprawdzenia czy liczba jest liczba pierwsza
		{	
			rest = i % y;	//sprawdzenie reszty z dzielenia
			support = true;  //nadpisanie zmiennej pomocniczej wartoscia inicjalizacyjna  wyjasnione nizej

			if ((rest == 0) && (y != i) && (y != 1)) // jezeli ktorys z warunkow jest pelniony to liczba nie jest liczba pierwsza
			{
				support = false; // napisanie wartosci jesli liczba NIE jest liczba pierwsza!
				break; //wyjscie z petli
			}
		}
			if (support == true) //sprawdzenie czy zmienna pomocnicza mowi nam ze "int i" jest liczba pierwsza
			{
				cout << i << endl; //wypisanie liczby pierwszej
			}
	}

return 0;
}
