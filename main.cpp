#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include<iostream>
#include <tchar.h>
#include <stdio.h>
#include <cstdio>
#include<chrono>
#include<thread>
#pragma comment(lib, "urlmon.lib")

using namespace std;
int main() {

	system("tools\\TegraRcmSmash.exe tools\\memloader_usb.bin -r --dataini=tools\\ums_sd.ini");

    this_thread::sleep_for(chrono::milliseconds(2000));

    URLDownloadToFile(NULL, L"https://github.com/Atmosphere-NX/Atmosphere/releases/download/1.2.6/atmosphere-1.2.6-master-173d5c2d3+hbl-2.4.1+hbmenu-3.5.0.zip", L"D:\\test\\atmosphere.zip", 0, NULL);
	cout << "\nDownloaded Atmosphere.\n";

	cout << "Extracting...\n";
	system("tools\\7z.exe x -oD:\\test D:\\test\\atmosphere.zip > NUL");
	remove("D:\\test\\atmosphere.zip");

	URLDownloadToFile(NULL, L"https://github.com/CTCaer/hekate/releases/download/v5.7.0/hekate_ctcaer_5.7.0_Nyx_1.2.0.zip", L"D:\\test\\hekate.zip", 0, NULL);
	cout << "Downloaded Hekate.\n";

	cout << "Extracting...\n";
	system("tools\\7z.exe x -oD:\\test D:\\test\\hekate.zip > NUL");
	remove("D:\\test\\hekate.zip");

	return 1;
}