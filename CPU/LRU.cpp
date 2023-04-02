#include <iostream>
#include <list>
using namespace std;

const int frame = 7;		//Ilosc ramek w pamieci;


int main() 
{
	cout << "LRU" << endl;
	int queue[] = {  1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5, 7, 4 ,9 ,6 ,5 ,3 ,5, 2 ,5 ,8 ,9 ,6 ,3 ,5 ,6 ,2 ,1 ,4 ,4 ,5 ,7 ,7, 5, 7 ,3 ,5 ,7 ,9,7,7,3,3,4,6,4,3, 1, 2,
		3, 4, 1, 2, 5, 1, 2, 3, 4, 5, 7, 4 ,9 ,6 ,5 ,3 ,5, 2 ,5 ,8 ,9 ,6 ,3 ,5 ,6 ,2 ,1 ,4 ,4 ,5 ,7 ,7, 5, 7 ,3 ,5 ,7 ,9,7,7,3,3,4,6,4,3,5,7,4,8 };	//Tablica stron
	int miss = 0;		//Zmienna uzywana do liczenia bledow stron
	list<int>frames;	//Lista zawierajaca ramki uzywane
	list<int>::iterator it;	//Iterator po liscie

	int page_number = sizeof(queue) / sizeof(queue[0]);		//Zmienna przechowuje ilosc liczb z tablicy, czyli ilosc stron
	for (int i = 0; i < page_number; i++) {
		//cout << "Ramka " <<  "\t ";
		if (find(frames.begin(), frames.end(), queue[i]) == frames.end()) {			//Sprawdza czy strona jest juz w pamieci, jesli prawda to nie ma
			miss++;				//Ilosc bledow wzrasta

			if (frames.size() == frame) {				//Jesli prawda to wszystkie ramki sa zajete
				frames.pop_back();			//Usuwa najdawniej uzywana strone
			}
			frames.push_front(queue[i]);    //Wstawia now¹ stronê
		}
		else {
			frames.remove(queue[i]);
			frames.push_front(queue[i]);		//Strona jest juz w pamieci i przesuwamy ja na poczatek
		}
		for (it = frames.begin(); it != frames.end(); ++it) {
			//cout << *it << " ";
		}
		//cout << endl;
	}
	cout << "Ilosc bledow: " << miss << endl;
	cout << "Ilosc trafien: " << page_number - miss;
	return 0;

}