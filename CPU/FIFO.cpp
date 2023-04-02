#include<iostream>
using namespace std;

int main()
{
    cout << "FIFO" << endl;
    int queue[] = { 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5, 7, 4 ,9 ,6 ,5 ,3 ,5, 2 ,5 ,8 ,9 ,6 ,3 ,5 ,6 ,2 ,1 ,4 ,4 ,5 ,7 ,7, 5, 7 ,3 ,5 ,7 ,9,7,7,3,3,4,6,4,3, 1, 
        2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5, 7, 4 ,9 ,6 ,5 ,3 ,5, 2 ,5 ,8 ,9 ,6 ,3 ,5 ,6 ,2 ,1 ,4 ,4 ,5 ,7 ,7, 5, 7 ,3 ,5 ,7 ,9,7,7,3,3,4,6,4,3,5,7,4,8 };    
    //Tablica stron

    int miss = 0;       //Zmienna uzywana do sledzenia liczby bledow stron
    const int frames = 3;    //Liczba ramek w pamieci glownej, ustawiona na 3
    int m, k, l, page_number;

    page_number = sizeof(queue) / sizeof(queue[0]);  //Dzielimy w razie gdyby tablica byla pusta, zmienna przechowuje ilosc stron

    //cout << "Kolejka\t\t";
    int temp[frames];    //Tworze tablice temp,ktora reprezentuje ramki pamieci glownej
    for (m = 0; m < frames; m++){
        temp[m] = -1;      //Na poczatku wszystkie elementy ustawione sa na -1, co oznacza pusta ramke
        //cout << "Ramka " << m + 1 << "\t\t";    //Wyswietla napis ramka i numer 
    }

    for (m = 0; m < page_number; m++){            //Program iteruje przez strumien przychodzacych stron i symuluje proces dodawania ich do ramek
        l = 0;  
        for (k = 0; k < frames; k++){
            if (queue[m] == temp[k]){      //Program sprawdza czy strona jest juz w ramce
                l++;
                miss--;           //Jesli strona jest juz w ramce to nie ma b³êdu i licznik jest zmniejszany o 1
            }
        }
        miss++;           //Jesli strony nie ma w ramce to blad jest i licznik jest zwiekszany o 1

        if ((miss <= frames) && (l == 0)) {    //Sprawdza czy liczba bledow jest mniejsza lub rowna ilosci ramek i czy biezaca strona nie jest jeszcze w ramce
            temp[m] = queue[m];        //Jesli tak to znaczy ze jest pusta ramka, a strona ktora spowodowala blad juz w niej nie jest, wiec strona jest dodawana do nastepnej ramki
        }
        else if (l == 0){       //Jesli wszystkie ramki sa pelne, a danej strony nie ma jeszcze w ramce
            temp[(miss - 1) % frames] = queue[m];        //Usuwa najstarsza strone zeby zrobic miejsce dla nowej
                                                        //Oblicza ktora strona zostala dodana jako pierwsza i usuwa ja a w jej miejsce daje nowa
        }
        //cout << "\n";
        //cout << queue[m] << "\t\t";
        /*for (k = 0; k < frames; k++) {       //Funkcja do wyœwietlania tablicy temp
            if (temp[k] != -1)          //Jesli jest rozny od -1 dany element, to dana ramka zawiera dane
                cout << temp[k] << "\t\t";
            else
                cout << "- \t\t";       //W innym wypadku dana ramka jest pusta i w jej miejscu jest wpisany minus
        }*/
    }

    cout << "\nIlosc brakow stron: " << miss;
    cout << "\nIlosc trafien: " << page_number - miss;     //Ilosc trafien -> strony ktore sa juz w pamieci
    return 0;


}
