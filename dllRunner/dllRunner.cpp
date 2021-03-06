#include <windows.h>
#include <iostream>
#define ignore 1

typedef int(__cdecl* mai)(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	if (argc <= 1) {
		std::cerr << "Need DLL ARG" << "\n";
		std::cout << "Usage:\ndllRunner.exe <dllToRun> <argumentsForDll>" << std::endl;
		return EXIT_FAILURE;
	}

	HINSTANCE hGetProcIDDLL = LoadLibraryA(argv[1]);

	if (!hGetProcIDDLL) {
		std::cerr << "could not load the dynamic library" << std::endl;
		return EXIT_FAILURE;
	}

	// resolve function address here
	mai funci = (mai)GetProcAddress(hGetProcIDDLL, "main");
	if (!funci) {
		std::cerr << "could not locate the function main in dll " << argv[1] <<  std::endl;
		return EXIT_FAILURE;
	}
	return funci(argc - ignore, &argv[ignore]);
}