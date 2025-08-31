#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <dirent.h>
#include <malloc.h>
#include <cstring>
#include <pspkernel.h>
#include <pspsdk.h>
#include <psputility_sysparam.h>
#include <psploadexec_kernel.h>

#include <mini2d.h>

#include "common.h"
#include "entry.h"
#include "controller.h"
#include "text.h"

#define TEXT_HEIGHT 10
#define TEXT_WIDTH 7

#define POPS_RUNLEVEL        0x144
#define POPS_RUNLEVEL_GO    0x155

#define BOTTOM 260
#define CENTER 90 // GAME Names and Path
#define RIGHT  345
#define TOP    2

extern "C"{
int sctrlKernelLoadExecVSHWithApitype(int apitype, const char * file, struct SceKernelLoadExecVSHParam *param);
}

enum { TYPE_HOMEBREW, TYPE_PSN, TYPE_POPS, UNKNOWN_TYPE };

using namespace std;

class Menu{

    private:
    
        vector<Entry*> eboots;
        TextAnim* txt;
        int index;
        int start;
        
        void readEbootList(string path);
        
        string fullPath(string path, string name);
        
        bool isPOPS(string path);

        void loadIcons();
        
        void updateScreen();
        
        void updateTextAnim();
        
        void moveDown();
        
        void moveUp();
        
        void control();
        
        void loadGame();

        void openSubMenu();
        
    public:
    
        Menu();
        ~Menu();
    
        void run();

        void draw();
        void fadeIn();
        void fadeOut();

};

class SubMenu {
    private:
        int index;
        Menu* menu;
        string options[7];

        void updateScreen();
        void getItems();

        void changeMsCacheSetting();
        void changeSetting(int setting);

    public:
        SubMenu(Menu* menu);
        ~SubMenu();
        void run();
};

#endif

