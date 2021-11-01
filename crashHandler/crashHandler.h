#ifdef CRASHHANDLER_EXPORTS
#define CRASHHANDLER_API __declspec(dllexport)
#else
#define CRASHHANDLER_API __declspec(dllimport)
#endif

extern "C" {
    CRASHHANDLER_API int main(int argc, char* argv[]);
}
