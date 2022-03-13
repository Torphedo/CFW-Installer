#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include<iostream>
#include <bitextractor.hpp>
#include <bitexception.hpp>
using namespace std;
using namespace  bit7z;

int extract_zip(wstring path, wstring file, std::string filestr) {
	cout << "Extracting...\n";
	try {
		Bit7zLibrary lib{ L"7z.dll" };
		BitExtractor extractor{ lib, BitFormat::Zip };

		extractor.extract(file, path);
	}
	catch (const BitException& ex) {
		cout << "Error when extracting!";
	}

	char* file_char;
	file_char = &filestr[0];
	remove(file_char);
	return 0;

}
