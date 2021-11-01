#ifdef HELLOWORLD_EXPORTS
#define HELLOWORLD_API __declspec(dllexport)
#else
#define HELLOWORLD_API __declspec(dllimport)
#endif

extern "C" {
	extern HELLOWORLD_API int main(int argc, char* argv[]);
}
