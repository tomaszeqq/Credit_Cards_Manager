#include <iostream>
#include "manager.h"
#include "colors.h"

using namespace std;

int main() {
    
    
     CardsReader cm;
     while (true) {
         int choice, nm;
         string number;
         string bank_name,expiry_date;

         cout << MAGENTA << "\nChoose: " << RESET <<"\n1.Show all credit cards\n2.Show selected credit card\n3.Add credit card\n4.Delete credit card\n5.Quit program\nYour choice: ";
         cin >> choice;
         switch (choice) {
         case 1:
             cout << endl;
             cm.print_all_cards();
             cout << endl;
                 break;
         case 2:
             cout << endl;
             cout << MAGENTA << "Choose a card number: " << RESET;
             cin >> nm;
             cm.print_card(nm);
             cout << endl;
             break;
         case 3:
             cout << endl;
             cout << MAGENTA << "\tBank name: " << RESET; cin >> bank_name;
             cout << MAGENTA << "\tCard number: (16 numbers)" << RESET; cin >> number;
             if (cm.check_card(number)) {
                 cout << YELLOW << "\tThis card number is valid" << RESET << endl;
                 cout << MAGENTA << "\tExpiry date: (write with '/' between month and year)" << RESET; cin >> expiry_date;
                 cm.add_card(bank_name, number, expiry_date);
                 cout << MAGENTA << "Added card: "<< RESET << bank_name << "," << number << "," << expiry_date << endl;
             }
             else
                 cout << YELLOW << "\tThis card number is not valid! You can try again"<< RESET << endl;
             break;
         case 4:
             cout << MAGENTA << "Choose card number: " << RESET;
             cin >> nm;
             cm.delete_card(nm);
             cout << MAGENTA << "Deleted card's number: " << RESET << nm << endl;
             break;
         case 5:
             cout << MAGENTA << "\nQuitting program..." << RESET << endl;
             return 0;
         default:
             cout << MAGENTA << "\nWrong number. Try again" << RESET << endl;
             break;

    }
     }
}