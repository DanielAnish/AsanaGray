#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;
using namespace sf;

//CopyRight Anishchenko Studios 2018
//Daniel Anishchenko & Sam Kidoguchi
//LanaGrey V 0.1 Pre-Alpha


int main()
{
OPENFILENAME ofn;       // common dialog box structure
char szFile[260];       // buffer for file name
HWND hwnd;              // owner window
HANDLE hf;              // file handle

// Initialize OPENFILENAME
ZeroMemory(&ofn, sizeof(ofn));
ofn.lStructSize = sizeof(ofn);
ofn.hwndOwner = hwnd;
ofn.lpstrFile = szFile;
// Set lpstrFile[0] to '\0' so that GetOpenFileName does not
// use the contents of szFile to initialize itself.
ofn.lpstrFile[0] = '\0';
ofn.nMaxFile = sizeof(szFile);
ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
ofn.nFilterIndex = 1;
ofn.lpstrFileTitle = NULL;
ofn.nMaxFileTitle = 0;
ofn.lpstrInitialDir = NULL;
ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

// Display the Open dialog box.

if (GetOpenFileName(&ofn)==TRUE)
    hf = CreateFile(ofn.lpstrFile,
                    GENERIC_READ,
                    0,
                    (LPSECURITY_ATTRIBUTES) NULL,
                    OPEN_EXISTING,
                    FILE_ATTRIBUTE_NORMAL,
                    (HANDLE) NULL);

    if(GetOpenFileName(&ofn))
    {
        // Do something usefull with the filename stored in szFileName
    }
    RenderWindow window(sf::VideoMode(1920,1080), "lana Grey");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    ContextSettings settings;
    settings.antialiasingLevel = 16;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
    window.display();
    }
    return 0;
}
