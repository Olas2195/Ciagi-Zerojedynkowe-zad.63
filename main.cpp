#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class liczby_polpierwsze {
	ifstream plik;
	
	public:
		liczby_polpierwsze();
		~liczby_polpierwsze();
		void wczytaj();
		bool sprawdzenie(int);
};
liczby_polpierwsze::liczby_polpierwsze() {
	plik.open("ciagi.txt");
}
void liczby_polpierwsze::wczytaj() {
	vector <int> polpierwsze;
	string ciag;
	int dec;
	if(plik.good()) {
		while(!plik.eof()) {
			plik>>ciag;
			bitset<32> bin(ciag);
			dec = bin.to_ulong();
			if(this->sprawdzenie(dec)) {
				polpierwsze.push_back(dec);
			}
		}		
	}
	cout<<polpierwsze.size()<<"\n";
	cout<<"min: "<< *min_element(polpierwsze.begin(), polpierwsze.end())<<"\n"; 
	cout<<"max: "<< *max_element(polpierwsze.begin(), polpierwsze.end()); 
}
bool liczby_polpierwsze::sprawdzenie(int ciag) {
	vector <int> dzielniki;
	for(int i=2; i<=ciag/2; i++) {
		int c=ciag;
		while(c%i==0){
			c=c/i;
			dzielniki.push_back(c);
		}
	}
	if(dzielniki.size()==2) {
		return true;
	}
	else {
		return false;
	}
}
liczby_polpierwsze::~liczby_polpierwsze() {
	plik.close();
}

int main(int argc, char** argv) {
	liczby_polpierwsze c;
	c.wczytaj();
	return 0;
}
