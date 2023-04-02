#include <iostream>
#include <queue>
using namespace std;

struct RR_dane {         //Struktura z danymi 
    int BT;
};

int main() {
    int WT[100];        //Waiting time 
    int RT[100];        //Remaining time 
    int TAT[100];       //Turnaround time 
    int quantum = 2;    //quantum - czas przydzielony na proces
    int CT = 0;         //Current time - aktualny czas


    RR_dane data[] = { {22},{20},{15},{11},{7},{2} };
    int n = sizeof(data) / sizeof(data[0]);     //Ilosc procesow

    for (int i = 0; i < n; i++)             // Funkcja przypisuje czas trwania, jako czas pozoztaly, bo kazdy proces zaczyna prace od poczatku
    {
        RT[i] = data[i].BT;
    }


    while (true) {
        bool finish = true;
        for (int i = 0; i < n; i++) {
            if (RT[i] > 0) {        //Jesli pozostaly czas jest wiekszy od 0 to proces wciaz trwa
                finish = false;
                if (RT[i] > quantum) { // Jeœli pozosta³y czas jest wiêkszy od quantum
                    CT += quantum;              // do aktualnego czasu dodajemy quantum
                    RT[i] -= quantum;      // od pozostalego czasu odejmujemy quantum
                }
                else {                  //Jesli pozostaly czas jest <= quantum
                    CT += RT[i];       //do aktualnego czasu dodajemy pozostaly czas trwania
                    WT[i] = CT - data[i].BT; // czas oczekiwania liczymy jako aktualny czas - czas trwania procesu
                    RT[i] = 0;              //Pozostaly czas trwania danego procesu zerujemy
                }
            }
        }
        if (finish == true) break;           // Konczymy petle, gdy wszystkie procesy sie zakoncza
    }

    float suma_WT = 0;      //Suma waiting time
    float suma_TAT = 0;     //Suma turnaround time
    for (int i = 0; i < n; i++) {
        TAT[i] = data[i].BT + WT[i];
        suma_WT += WT[i];
        suma_TAT += TAT[i];
    }

    float average_WT = suma_WT / n;       //Sredni waiting time
    float average_TAT = suma_TAT / n;   //Sredni turnaround time

    cout << "Nr procesu" << "\t" << "Burst Time" << "\t" << "Waiting Time" << "\t" << "Turnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << data[i].BT << "\t\t" << WT[i] << "\t\t" << TAT[i] << endl;
    }
    cout << "Sredni czas oczekiwania: " << average_WT << endl;
    cout << "Sredni czas realizacji: " << average_TAT << endl;
    return 0;
}
