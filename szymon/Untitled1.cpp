#include <iostream>
#include <string>
using namespace std;

void dodaj_ksiazke();
void wyszukaj_ksiazke();
//void wyszukaj_telefon();
void pokaz_wszystkie();
void usun_ksiazke();
void wyszukaj_dostepne_ksiazki();

struct biblioteka
{
	char nazwa[20];
	char autor[30];
	char rok[5];
	bool dostepna;
	bool isdelete;
	biblioteka * next;
};
biblioteka * poczatek = NULL;

int main()
{

	int tmp = 0;
	do
	{

		cout << "	Spis biblioteczny" << endl;
		cout << "" << endl;
		cout << "\t 1. Dodaj ksiazke" << endl;
		cout << "\t 2. Wyszukaj ksiazke po naziwe" << endl;
		cout << "\t 3. Pokaz wszystkie ksiazki" << endl;
		cout << "\t 4. Usun ksiazke" << endl;
		cout << "\t 5. Pokaz dostepne ksiazki" << endl;
		cout << "\t 0. Zakoncz program" << endl;
		cin >> tmp;
		cout << "\t << Wybra³eœ/aœ opcjê " << tmp << " >> " << endl;
		cout << "" << endl;

		switch (tmp)
		{
		case 0:
			cout << "\t << KONIEC PROGRAMU >>" << endl;
			break;

		case 1:
			dodaj_ksiazke();
			break;

		case 2:
			wyszukaj_ksiazke();
			break;

		case 3:
			pokaz_wszystkie();
			break;

		case 4:
			usun_ksiazke();
			break;

        case 5:
			wyszukaj_dostepne_ksiazki();
			break;

		default:
			cout << "\t << Wybra³eœ/aœ opcjê ró¿n¹ od 1-4 >>" << endl;
			cout << "\t << Wybierz jeszcze raz odpowiedni¹ opcjê >>" << endl;
			cout << "" << endl;
			break;
		}
	} while (tmp != 0);

	return 0;
}

void dodaj_ksiazke()
{
	biblioteka * nowa = new biblioteka;
	nowa->next = NULL;
	cout << "Podaj nazwe \t";
	cin >> nowa->nazwa;
	cout << "Podaj autora \t";
	cin >> nowa->autor;
	cout << "Podaj rok \t";
	cin >> nowa->rok;
    cout << "Podaj czy ksi¹¿ka jest dostêpna, 1 lub 0 \t";
	cin >> nowa->dostepna;
	nowa->isdelete = true;

	if (poczatek == NULL)
	{
		poczatek = nowa;
	}
	else
	{
		biblioteka * szukaj = poczatek;
		while (szukaj->next != NULL)
		{
			szukaj = szukaj->next;
		}
		szukaj->next = nowa;
	}
}

void wyszukaj_ksiazke()
{
	string szukacz;
	cout << "Podaj nazwe ksiazki do wyszukania \t";
	cin >> szukacz;
	biblioteka * pokaz = poczatek;
	while (pokaz->next != NULL)
	{
		if (pokaz->nazwa == szukacz)
		{
			cout << "Nazwa: " << pokaz->nazwa << endl
				<< "Autor: " << pokaz->autor << endl
				<< "Rok: " << pokaz->rok << endl
				<< "Dostêpna w tej chwili: " << pokaz->dostepna << endl;
		}
		pokaz = pokaz->next;
	}
	if (pokaz->nazwa == szukacz)
	{
		cout << "Nazwa: " << pokaz->nazwa << endl
			<< "Autor: " << pokaz->autor << endl
			<< "Rok: " << pokaz->rok << endl
			<< "Dostêpna w tej chwili: " << pokaz->dostepna << endl;

	}
	else
	{
		cout << "Brak takiej ksiazki" << endl;
	}
}

void wyszukaj_dostepne_ksiazki()
{
	biblioteka * pokaz = poczatek;
	while (pokaz->next != NULL)
	{
		if (pokaz->dostepna == 1)
		{
			cout << "Nazwa: " << pokaz->nazwa << endl
				<< "Autor: " << pokaz->autor << endl
				<< "Rok: " << pokaz->rok << endl
				<< "Dostêpna w tej chwili: " << pokaz->dostepna << endl;
		}
		pokaz = pokaz->next;
	}
	if (pokaz->dostepna == 1)
	{
		cout << "Nazwa: " << pokaz->nazwa << endl
			<< "Autor: " << pokaz->autor << endl
			<< "Rok: " << pokaz->rok << endl
			<< "Dostêpna w tej chwili: " << pokaz->dostepna << endl;

	}
	else
	{
		cout << "Brak takiej ksiazki" << endl;
	}
}



void pokaz_wszystkie()
{
	if (poczatek != NULL)
	{
		biblioteka * pokaz = poczatek;
		if (pokaz->isdelete != false)
		{
			while (pokaz->next != NULL)
			{
				cout << "-----\n" << pokaz->nazwa << endl;
				cout << pokaz->autor << endl;
				cout << pokaz->rok << endl;
				cout << pokaz->dostepna << endl;
				pokaz = pokaz->next;
			}
		}
		else
		{
			cout << "Brak danych" << endl;
		}

		if (pokaz->isdelete != false)
		{
			cout << "-----\n" << pokaz->nazwa << endl;
			cout << pokaz->autor << endl;
			cout << pokaz->rok << endl;
			cout << pokaz->dostepna << endl;
		}
		else
		{
			cout << "Brak danych" << endl;
		}
	}

}

void usun_ksiazke()
{
	string szukacz;
	cout << "podaj nazwe ksiaki do wyszukania  \t";
	cin >> szukacz;
	biblioteka * pokaz = poczatek;
	while (pokaz->next != NULL)
	{
		if (pokaz->next->nazwa == szukacz)
		{
			biblioteka * usuwany = pokaz->next;
			pokaz->next = usuwany->next;
			delete usuwany;

		}
		else
		{
			pokaz = pokaz->next;
		}
	}
}
