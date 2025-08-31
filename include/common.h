#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <pspgu.h>
#include <pspdisplay.h>
#include <pspkernel.h>

#include <ark.h>
#include <mini2d.h>
#include <arkmenu.h>
#include <systemctrl.h>
#include <systemctrl_se.h>

#include "debug.h"

#define THREAD_DELAY 1000

extern SEConfig* se_config;
extern ARKConfig* ark_config;

namespace common{
    extern void setArgs(int c, char** v);
    extern bool fileExists(const std::string &path);
    extern void loadData();
    extern void deleteData();
    extern Image* getBG();
    extern Image* getNoIcon();
    extern void printText(float x, float y, const char *text, u32 color = WHITE_COLOR);
    extern void flip();
    extern void saveConf();
    extern ArkMenuConf* getConf();
    extern void resetConf();
    extern void loadConf();
    extern void rebootMenu();
}

#endif
