#include "framework.h"
#include "crashHandler.h"

void errmsg(const char* x) {
	printf("%s failed (%d).\n", x, GetLastError());
}

extern "C" {
	CRASHHANDLER_API int main(int argc, char* argv[])
	{
		const char* ending = "Process exited with %lu";
		STARTUPINFOA si;
		PROCESS_INFORMATION pi;

		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));

		if (argc < 2)
		{
			printf("Usage: %s [cmdline]\n", argv[0]);
			return 0;
		}

		// Start the child process. 
		if (!CreateProcessA(NULL,   // No module name (use command line)
			argv[1],        // Command line
			NULL,           // Process handle not inheritable
			NULL,           // Thread handle not inheritable
			FALSE,          // Set handle inheritance to FALSE
			0,              // No creation flags
			NULL,           // Use parent's environment block
			NULL,           // Use parent's starting directory 
			&si,            // Pointer to STARTUPINFO structure
			&pi)           // Pointer to PROCESS_INFORMATION structure
			)
		{
			errmsg("CreateProcess");
			return 0;
		}

		// Wait until child process exits.
		WaitForSingleObject(pi.hProcess, INFINITE);
		DWORD* exitc = new DWORD{ 100 };
		if (GetExitCodeProcess(pi.hProcess, exitc) != FALSE) {
			printf(ending, *exitc);
			putchar('\n');
			if (*exitc != 0) {
				char buf[sizeof(ending) + 20];
				std::snprintf(buf, sizeof(buf), ending, *exitc);
				MessageBoxA(NULL, buf, "Shark Crash Handler", MB_ICONERROR | MB_OK);
			}
		}
		else {
			errmsg("GetExitCode");
		}
		// Close process and thread handles. 
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		return 0;
	}
}
