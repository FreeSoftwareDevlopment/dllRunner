// helloworld.cpp : Hiermit werden die exportierten Funktionen für die DLL definiert.
//

#include "framework.h"
#include "helloworld.h"

extern "C" {
    HELLOWORLD_API int main(int argc, char* argv[])
    {
        puts("HelloWOrld!\n");
        if(argc > 2){
            puts(argv[2]);
        }
        return 0;
    }
}
