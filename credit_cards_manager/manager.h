#pragma once
#include <sstream>
using namespace std;

class CardsReader {
private:
	stringstream read_data(string filename);
	void write_data(string filename, string data);
	void print_header();
	void correct_number();
	string cm_file = "card_data.csv.csv";
	int max_nm;
public:
	void print_all_cards();
	void print_card( int nm);
	void delete_card( int nm);
	void add_card(string bank_name, string number, string expiry_date);
	bool check_card(string number);
};