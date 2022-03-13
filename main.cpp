#include<thread>
#include "main.h"
#pragma comment(lib, "urlmon.lib")
using namespace std;

int main() {
	// system("tools\\TegraRcmSmash.exe tools\\memloader_usb.bin -r --dataini=tools\\ums_sd.ini");

	// this_thread::sleep_for(chrono::milliseconds(2000));

	download_git_release(L"https://api.github.com/repos/Atmosphere-NX/Atmosphere/releases/latest", L"E:\\Git\\CFW-Installer\\test\\atmosphere.zip");
	cout << "\nDownloaded Atmosphere.\n";
	extract_zip(L"E:\\Git\\CFW-Installer\\test", "E:\\Git\\CFW-Installer\\test\\atmosphere.zip");

	download_git_release(L"https://api.github.com/repos/CTCaer/hekate/releases/latest", L"E:\\Git\\CFW-Installer\\test\\hekate.zip");
	cout << "\nDownloaded Hekate.\n";
	extract_zip(L"E:\\Git\\CFW-Installer\\test", "E:\\Git\\CFW-Installer\\test\\hekate.zip");

	cout << "Downloading common homebrew apps...\n";
	download_git_release(L"https://api.github.com/repos/DarkMatterCore/nxdumptool/releases/latest", L"E:\\Git\\CFW-Installer\\test\\switch\\nxdumptool.nro");
	download_git_release(L"https://api.github.com/repos/fortheusers/hb-appstore/releases/latest", L"E:\\Git\\CFW-Installer\\test\\switch\\appstore.nro");
	download_git_release(L"https://api.github.com/repos/J-D-K/JKSV/releases/latest", L"E:\\Git\\CFW-Installer\\test\\switch\\JKSV.nro");
	download_git_release(L"https://api.github.com/repos/shchmue/Lockpick_RCM/releases/latest", L"E:\\Git\\CFW-Installer\\test\\bootloader\\payloads\\Lockpick_RCM.bin");
}