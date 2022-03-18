#include<thread>
#include "main.h"
using namespace std;

int main() {
	system("tools\\TegraRcmSmash.exe tools\\memloader.bin -r --dataini=tools\\ums_sd.ini");

	system("cls");
	cout << "SD Card mounted.\n\n";
	this_thread::sleep_for(chrono::milliseconds(2000));

	download_git_release(L"https://api.github.com/repos/Atmosphere-NX/Atmosphere/releases/latest", L"atmosphere.zip");
	extract_zip(L"D:\\", "atmosphere.zip");

	download_git_release(L"https://api.github.com/repos/CTCaer/hekate/releases/latest", L"hekate.zip");
	extract_zip(L"D:\\", "hekate.zip");
	system("copy D:\\*.bin . > NUL");

	cout << "Downloading common homebrew apps...\n";
	download_git_release(L"https://api.github.com/repos/DarkMatterCore/nxdumptool/releases/latest", L"D:\\switch\\nxdumptool.nro");
	download_git_release(L"https://api.github.com/repos/fortheusers/hb-appstore/releases/latest", L"D:\\switch\\appstore.nro");
	download_git_release(L"https://api.github.com/repos/J-D-K/JKSV/releases/latest", L"D:\\switch\\JKSV.nro");
	download_git_release(L"https://api.github.com/repos/shchmue/Lockpick_RCM/releases/latest", L"D:\\bootloader\\payloads\\Lockpick_RCM.bin");

	cout << "\nDone! Hold the Switch's power button for 5 seconds to exit.\n";
	system("pause");
}