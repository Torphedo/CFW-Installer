#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include<iostream>
#include<thread>
#include "include\bitextractor.hpp"
#include "include\bitexception.hpp"
#pragma comment(lib, "urlmon.lib")
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

int main() {
	system("tools\\TegraRcmSmash.exe tools\\memloader_usb.bin -r --dataini=tools\\ums_sd.ini");

	this_thread::sleep_for(chrono::milliseconds(2000));

	URLDownloadToFile(NULL, L"https://github.com/Atmosphere-NX/Atmosphere/releases/download/1.2.6/atmosphere-1.2.6-master-173d5c2d3+hbl-2.4.1+hbmenu-3.5.0.zip", L"D:\\test\\atmosphere.zip", 0, NULL);
	cout << "\nDownloaded Atmosphere.\n";
	extract_zip(L"D:\\test", L"D:\\test\\atmosphere.zip", "D:\\test\\atmosphere.zip");

	URLDownloadToFile(NULL, L"https://github.com/CTCaer/hekate/releases/download/v5.7.0/hekate_ctcaer_5.7.0_Nyx_1.2.0.zip", L"D:\\test\\hekate.zip", 0, NULL);
	cout << "Downloaded Hekate.\n";
	extract_zip(L"D:\\test", L"D:\\test\\hekate.zip", "D:\\test\\hekate.zip");

	cout << "Downloading common homebrew apps...";
	URLDownloadToFile(NULL, L"https://github.com/DarkMatterCore/nxdumptool/releases/download/v1.1.15/nxdumptool.nro", L"D:\\test\\switch\\nxdumptool.nro", 0, NULL);
	URLDownloadToFile(NULL, L"https://github.com/fortheusers/hb-appstore/releases/download/2.2/appstore.nro", L"D:\\test\\switch\\appstore.nro", 0, NULL);
	URLDownloadToFile(NULL, L"https://github.com/J-D-K/JKSV/releases/download/09%2F01%2F2021/JKSV.nro", L"D:\\test\\switch\\JKSV.nro", 0, NULL);
	URLDownloadToFile(NULL, L"https://github.com/shchmue/Lockpick_RCM/releases/download/v1.9.6/Lockpick_RCM.bin", L"D:\\test\\bootloader\\payloads\\Lockpick_RCM.bin", 0, NULL);
}