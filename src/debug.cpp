#include <mini2d.h>

#include "debug.h"

void debugScreen(const char* text, uint16_t w, uint16_t h){
    clearScreen(CLEAR_COLOR);
    printTextScreen(w, h, text, WHITE_COLOR);
    flipScreen();
}


void debugFile(const char* text){
    FILE* fp = fopen("DEBUG.TXT", "a+");
    fwrite(text, 1, strlen(text), fp);
    fclose(fp);
}
