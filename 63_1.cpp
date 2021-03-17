#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ciagi_rekurencyjne {
	ifstream plik;
	
	public:
		ciagi_rekurencyjne();
		~ciagi_rekurencyjne();
		void wczytaj();
		bool sprawdzenie(string s);
};
ciagi_rekurencyjne::ciagi_rekurencyjne() {
	plik.open("ciagi.txt");
}
void ciagi_rekurencyjne::wczytaj() {
	string ciag;
	if(plik.good()) {
		while(!plik.eof()) {
			plik>>ciag;
			if(this->sprawdzenie(ciag)) {
				cout<<ciag<<"\n";
			}
		}		
	}
}
bool ciagi_rekurencyjne::sprawdzenie(string ciag) {
	if(ciag.length()%2==0) {
		string s1 = ciag.substr(0, ciag.length()/2);
		string s2 = ciag.substr(ciag.length()/2, ciag.length()/2);
		if(s1==s2) {
			return true;
		}
		else {
			return false;
		}
	}
	else{
		return false;
	}
}
ciagi_rekurencyjne::~ciagi_rekurencyjne() {
	plik.close();
}

int main(int argc, char** argv) {
	ciagi_rekurencyjne c;
	c.wczytaj();
	return 0;
}
