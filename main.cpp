#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class file {		
	public:	
	ifstream inFile;
		
		file();
		~file();
		virtual void wczytaj()=0;
		virtual bool sprawdzenie(string s) = 0;
};
file::file() {
	inFile.open("ciagi.txt");
}
file::~file() {
	inFile.close();
}

class Funkcje : public file{
	public:
		virtual void wczytaj() {
			string ciag;
			int ilosc=0;
			if(inFile.good()) {
				while(!inFile.eof()) {
					inFile>>ciag;
					if(this->sprawdzenie(ciag)) {
						ilosc++;
					}
				}		
			}
			cout<<ilosc;
		}
		virtual bool sprawdzenie(string ciag) {
			for(int i=0; i<ciag.length(); i++) {
				if(ciag[i]=='1' && ciag[i+1]=='1') {
					return false;
				}
			}
			return true;
		}
};

int main(int argc, char** argv) {
	file f;
	f.wczytaj();
	return 0;
}
