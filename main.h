#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <bitextractor.hpp>
#include <bitexception.hpp>
using namespace std;
using namespace  bit7z;
using namespace boost::property_tree;

int extract_zip(wstring path, string filestr) {
	wstring file = wstring(filestr.begin(), filestr.end());
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

int download_git_release(LPCWSTR link, LPCWSTR filename) {
	//Download JSON from GitHub API.
	URLDownloadToFile(NULL, link, L"api.json", 0, NULL);

	ptree root;
	try {
		read_json("api.json", root);
	}
	catch (int error) {
		cout << "Failed to read JSON!";
	}
	// Get download link for the latest release on GitHub
	string download_link = root.get<string>("assets..browser_download_url", "NOT FOUND");
	wcout << "Downloaded " << filename << ".\n";

	// Convert std::string to LPCWSTR required by URLDownloadToFile()
	wstring wstr = wstring(download_link.begin(), download_link.end());
	LPCWSTR output;
	output = wstr.c_str();

	// Download file
	URLDownloadToFile(NULL, output, filename, 0, NULL);

	remove("api.json");
	return 0;
}
