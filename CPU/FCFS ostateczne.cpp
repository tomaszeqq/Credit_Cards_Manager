#include <iostream>
#include <algorithm>
using namespace std; 

struct FCFS_dane {                  // struktura 
    int AT;     //Arrival Time
    int BT;     //Burst Time
};

bool CompareAT(FCFS_dane a, FCFS_dane b) {      //Funkcja do porownywania arrival time 
    return a.AT < b.AT;
}
int main() 
{
    int WT = 0;     //Waiting Time
    int TAT = 0;    //Turnaround Time
    int CT = 0;     //Current time
    float s_WT = 0;     //Suma Waiting Time
    float s_TAT = 0;    //Suma Turnaround Time
    FCFS_dane data[] = { {3,22},{5,20},{1,15},{7,11},{0,7},{4,2} };       //Tablica danych
    int n = sizeof(data) / sizeof(data[0]);         //Ilosc procesow
    
    sort(data, data + n, CompareAT);                //Sortowanie tablicy wzgledem arrival time

    cout << "Nr procesu\t" << "Arrival Time\t" << "Burst Time\t" << "Waiting Time\t" << "Turnaround Time" << endl;

    for (int i = 0; i < n; i++) {               
        if (CT < data[i].AT) {                     //Funkcja sprawdza czy czas jest mniejszy od arrival time, jesli tak to przypoisuje ta wartosc
            CT = data[i].AT;
        }
    WT = CT - data[i].AT;     //Obliczamy czas czekania
    TAT = CT + data[i].BT - data[i].AT;     //Obliczamy czas obrotu
    s_WT += CT - data[i].AT;        //Sumujemy czas oczekiwania
    s_TAT += CT + data[i].BT - data[i].AT;      //Sumujemy czas obrotu
    CT += data[i].BT;       //CT zwieksza sie z kazdym procesem
    cout << i + 1 << "\t\t" << data[i].AT << "\t\t" << data[i].BT << "\t\t" << WT << "\t\t" << TAT << endl;
    }
    float average_WT = (float)s_WT / n;       //Sredni czas czekania
    float average_TAT = (float)s_TAT / n;     //Sredni czas obrotu
    cout << "Sredni czas oczekiwania: " << average_WT << endl;
    cout << "Sredni czas realizacji: " << average_TAT;

    return 0;
}
