// helloworld.cpp : Hiermit werden die exportierten Funktionen für die DLL definiert.
//

#include "framework.h"
#include "helloworld.h"

extern "C" {
    HELLOWORLD_API int main(int argc, char* argv[])
    {
        puts("HelloWOrld!\n");
        if(argc > 1){
            puts(argv[1]);
        }
        return 0;
    }
}
