// credit_cards_manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "manager.h"
#include "colors.h"

using namespace std;

template <class Container>
void split_string(const string& str, Container& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

string left(const string s, const int w) {
    stringstream ss, spaces;
    int padding = w - s.size();
    for (int i = 0; i < padding; ++i)
        spaces << " ";
    ss << s << spaces.str();
    return ss.str();
}

stringstream CardsReader::read_data(string filename) {
    ifstream ReadFile(filename);
    stringstream buffer;
    buffer << ReadFile.rdbuf();
    ReadFile.close();
    return buffer;
}

void CardsReader::print_header() {
    cout << RED << left("ID:", 5);
    cout << left("Bank name:",20);
    cout << left("Card number:",30);
    cout << left("Expiry date:",10);
    cout << RESET << endl;
}

void CardsReader::print_all_cards() {
    string line;
    stringstream cm = read_data(cm_file);
    print_header();
    while (getline(cm, line)) {
        vector <string> cards;
        split_string(line, cards, ',');
        max_nm = stoi(cards[0]);
        cout << left(cards[0],5);
        cout << left(cards[1],20);
        cout << left(cards[2],30);
        cout << left(cards[3],10);
        cout << endl;
    }
}

void CardsReader::print_card(int nm) {
    string line;
    stringstream cm = read_data(cm_file);
    while (getline(cm, line)) {
        vector <string> cards;
        split_string(line, cards, ',');

        if (cards[0] == to_string(nm)) {
            print_header();
            cout << left(cards[0], 5);
            cout << left(cards[1], 20);
            cout << left(cards[2], 30);
            cout << left(cards[3], 10);
            cout << endl;

        }
    }
}

void CardsReader::write_data(string filename, string data) {
    ofstream WriteCardsFile(filename);
    WriteCardsFile << data;
    WriteCardsFile.close();
}

void CardsReader::add_card(string bank_name,string number, string expiry_date) {
    string temporary;
    int nm = max_nm + 1;
    temporary = to_string(nm) + ',' + bank_name + ',' + number + ',' + expiry_date;
    string cm_temporary = read_data(cm_file).str();
    cm_temporary = cm_temporary + "\n" + temporary;
    write_data(cm_file, cm_temporary);
}

void CardsReader::delete_card(int nm) {
    string line;
    stringstream cm = read_data(cm_file);
    string temporary;
    while (getline(cm, line)) {
        vector <string> cards;
        split_string(line, cards, ',');
        if (cards[0] != to_string(nm))
            temporary = temporary + line + "\n";
        
    }
    write_data(cm_file, temporary);
        correct_number();
}

void CardsReader::correct_number() {
    string line;
    stringstream cm = read_data(cm_file);
    int j = 1;
    string temporary;

    while (getline(cm, line)) {
        vector <string> cards;
        split_string(line, cards, ',');
        temporary = temporary + to_string(j) + "," + cards[1] + "," + cards[2] + "," + cards[3] + "\n";
        j++;
    }
    temporary.erase(temporary.length() - 1);
    write_data(cm_file, temporary);
}

bool CardsReader::check_card(string number) {
    int sum = 0;
    for (int i = number.length() - 1; i >= 0; i--) {
        int temp = number[i] - '0';
        if (i % 2 == 0) {
            temp *= 2;
            if (temp > 9)
                temp -= 9;
        }
        sum += temp;
    }
    return (sum % 10 == 0);
}
