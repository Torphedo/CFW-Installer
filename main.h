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

int json_num = 0;

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
	json_num += 1;
	string jsonstr = to_string(json_num) + ".json";

	// Convert std::string input to LPCWSTR required by URLDownloadToFile()
	wstring jsonwstr = wstring(jsonstr.begin(), jsonstr.end());
	LPCWSTR output;
	output = jsonwstr.c_str();

	//Download JSON from GitHub API.
	URLDownloadToFile(NULL, link, output, 0, NULL);

	ptree root;
	try {
		read_json(jsonstr, root);
	}
	catch (int error) {
		cout << "Failed to read JSON!";
	}
	// Get download link for the latest release on GitHub
	string download_link = root.get<string>("assets..browser_download_url", "NOT FOUND");
	wcout << "Downloaded " << filename << ".\n";

	// Convert std::string to LPCWSTR required by URLDownloadToFile()
	wstring wstr = wstring(download_link.begin(), download_link.end());
	output = wstr.c_str();

	// Download file
	URLDownloadToFile(NULL, output, filename, 0, NULL);

	// Convert jsonstr to char and delete JSON file
	char* json_char = &jsonstr[0];
	remove(json_char);
	return 0;
}
