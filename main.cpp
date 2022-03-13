#include<thread>
#include "main.h"
#pragma comment(lib, "urlmon.lib")
using namespace std;

int main() {
	system("tools\\TegraRcmSmash.exe tools\\memloader.bin -r --dataini=tools\\ums_sd.ini");

	this_thread::sleep_for(chrono::milliseconds(2000));

	download_git_release(L"https://api.github.com/repos/Atmosphere-NX/Atmosphere/releases/latest", L"atmosphere.zip");
	cout << "\nDownloaded Atmosphere.\n";
	extract_zip(L"D:\\test", "atmosphere.zip");

	download_git_release(L"https://api.github.com/repos/CTCaer/hekate/releases/latest", L"hekate.zip");
	cout << "\nDownloaded Hekate.\n";
	extract_zip(L"D:\\test", "hekate.zip");

	cout << "Downloading common homebrew apps...\n";
	download_git_release(L"https://api.github.com/repos/DarkMatterCore/nxdumptool/releases/latest", L"D:\\test\\switch\\nxdumptool.nro");
	download_git_release(L"https://api.github.com/repos/fortheusers/hb-appstore/releases/latest", L"D:\\test\\switch\\appstore.nro");
	download_git_release(L"https://api.github.com/repos/J-D-K/JKSV/releases/latest", L"D:\\test\\switch\\JKSV.nro");
	download_git_release(L"https://api.github.com/repos/shchmue/Lockpick_RCM/releases/latest", L"D:\\test\\bootloader\\payloads\\Lockpick_RCM.bin");
}