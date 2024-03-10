#include <cstdlib>
#include <iostream>
#include <time.h>

#define SIZE 4

using namespace std;

int tabela_stanu[SIZE][SIZE];
int punkty;

bool czy_koniec() {
	int licznik = 0;
	for(int w = 0; w < SIZE; w++)
		for(int h = 0; h < SIZE; h++)
			if(tabela_stanu[w][h] == 0) licznik ++;
	return licznik == 0;
}

void losowanie_dwojek() {
	srand(time(0));
	for(int licznik = 0; licznik < 2;) {
		int l = rand() % (SIZE*SIZE);
		int w = l % SIZE;
		int h = l / SIZE;
		if(tabela_stanu[w][h] == 0) {
			tabela_stanu[w][h] = 2;
			licznik++;
		}
	}
}

void losowanie_liczb() {
	srand(time(0));
	int licznik = 0;
	for(int w = 0; w < SIZE; w++)
		for(int h = 0; h < SIZE; h++)
			if(tabela_stanu[w][h] == 0) licznik ++;
	while (licznik) {
		int l = rand() % (SIZE*SIZE);
		int w = l % SIZE;
		int h = l / SIZE;
		if(tabela_stanu[w][h] == 0) {
			tabela_stanu[w][h] = 2 * (1 + rand() % 2);
			break;
		}
	}
}

void w_gore() {
	for(int w = 0; w < SIZE; w++) {
		bool zamiana;
		do {
			zamiana = false;
			for(int h = 0; h < SIZE - 1; h++) {
				if(tabela_stanu[w][h] == 0 && tabela_stanu[w][h+1] != 0) {
					tabela_stanu[w][h] = tabela_stanu[w][h+1];
					tabela_stanu[w][h+1] = 0;
					zamiana = true;
				}
			}
		} while(zamiana);
		for(int h = 0; h < SIZE - 1; h++) {
			if(tabela_stanu[w][h] == tabela_stanu[w][h+1]) {
				tabela_stanu[w][h] += tabela_stanu[w][h+1];
				tabela_stanu[w][h+1] = 0;
				punkty += tabela_stanu[w][h];
				break;
			}
		}
		do {
			zamiana = false;
			for(int h = 0; h < SIZE - 1; h++) {
				if(tabela_stanu[w][h] == 0 && tabela_stanu[w][h+1] != 0) {
					tabela_stanu[w][h] = tabela_stanu[w][h+1];
					tabela_stanu[w][h+1] = 0;
					zamiana = true;
				}
			}
		} while(zamiana);
	}
}

void w_lewo() {
	for(int h = 0; h < SIZE; h++) {
		bool zamiana;
		do {
			zamiana = false;
			for(int w = 0; w < SIZE - 1; w++) {
				if(tabela_stanu[w][h] == 0 && tabela_stanu[w+1][h] != 0) {
					tabela_stanu[w][h] = tabela_stanu[w+1][h];
					tabela_stanu[w+1][h] = 0;
					zamiana = true;
				}
			}
		} while(zamiana);
		for(int w = 0; w < SIZE - 1; w++) {
			if(tabela_stanu[w][h] == tabela_stanu[w+1][h]) {
				tabela_stanu[w][h] += tabela_stanu[w+1][h];
				tabela_stanu[w+1][h] = 0;
				punkty += tabela_stanu[w][h];
				break;
			}
		}
		do {
			zamiana = false;
			for(int w = 0; w < SIZE - 1; w++) {
				if(tabela_stanu[w][h] == 0 && tabela_stanu[w+1][h] != 0) {
					tabela_stanu[w][h] = tabela_stanu[w+1][h];
					tabela_stanu[w+1][h] = 0;
					zamiana = true;
				}
			}
		} while(zamiana);
	}
}

void w_prawo() {
	for(int h = 0; h < SIZE; h++) {
		bool zamiana;
		do {
			zamiana = false;
			for(int w = SIZE -1 ; w > 0 - 1; w--) {
				if(tabela_stanu[w][h] == 0 && tabela_stanu[w-1][h] != 0) {
					tabela_stanu[w][h] = tabela_stanu[w-1][h];
					tabela_stanu[w-1][h] = 0;
					zamiana = true;
				}
			}
		} while(zamiana);
		for(int w = SIZE -1 ; w > 0 - 1; w--) {
			if(tabela_stanu[w][h] == tabela_stanu[w-1][h]) {
				tabela_stanu[w][h] += tabela_stanu[w-1][h];
				tabela_stanu[w-1][h] = 0;
				punkty += tabela_stanu[w][h];
				break;
			}
		}
		do {
			zamiana = false;
			for(int w = SIZE -1 ; w > 0 - 1; w--) {
				if(tabela_stanu[w][h] == 0 && tabela_stanu[w-1][h] != 0) {
					tabela_stanu[w][h] = tabela_stanu[w-1][h];
					tabela_stanu[w-1][h] = 0;
					zamiana = true;
				}
			}
		} while(zamiana);
	}
}

void w_dol() {
	for(int w = 0; w < SIZE; w++) {
		bool zamiana;
		do {
			zamiana = false;
			for(int h = SIZE - 1; h > 0; h--) {
				if(tabela_stanu[w][h] == 0 && tabela_stanu[w][h-1] != 0) {
					tabela_stanu[w][h] = tabela_stanu[w][h-1];
					tabela_stanu[w][h-1] = 0;
					zamiana = true;
				}
			}
		} while(zamiana);
		for(int h = SIZE - 1; h > 0; h--) {
			if(tabela_stanu[w][h] == tabela_stanu[w][h-1]) {
				tabela_stanu[w][h] += tabela_stanu[w][h-1];
				tabela_stanu[w][h-1] = 0;
				punkty += tabela_stanu[w][h];
				break;
			}
		}
		do {
			zamiana = false;
			for(int h = SIZE - 1; h > 0; h--) {
				if(tabela_stanu[w][h] == 0 && tabela_stanu[w][h-1] != 0) {
					tabela_stanu[w][h] = tabela_stanu[w][h-1];
					tabela_stanu[w][h-1] = 0;
					zamiana = true;
				}
			}
		} while(zamiana);
	}
}

void wyswietlanie() {
	system("cls");
	cout << "Punkty: " << punkty << "\n\n\n";
	for(int h = 0; h < SIZE; h++) {
		for(int w = 0; w < SIZE; w++)
			cout << "\t" << tabela_stanu[w][h];
		cout << "\n\n";
	}
}

int main(int argc, char *argv[])
{
	punkty = 0;

	for(int w = 0; w < SIZE; w++)
		for(int h = 0; h < SIZE; h++)
			tabela_stanu[w][h] = 0;

	losowanie_dwojek();

	wyswietlanie();
	
	unsigned char c;
    do {

    	cout << "\nNacisnij 'w a s z' aby ruszyc albo 'q' by wyjsc ";
		c = cin.get();

		switch(c) {
			case 'w': w_gore(); losowanie_liczb(); break; // w górę
			case 'a': w_lewo(); losowanie_liczb(); break; // w lewo
			case 's': w_prawo(); losowanie_liczb(); break; // w prawo
			case 'z': w_dol(); losowanie_liczb(); break; // w dół
		}

		wyswietlanie();

    } while (c != 'q' && !czy_koniec());
    
    cout << "KONIEC\n\n'q' by wyjsc ";
    while (cin.get() != 'q');

    return EXIT_SUCCESS;
}
