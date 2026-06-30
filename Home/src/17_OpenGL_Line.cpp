#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    setcolor(CYAN);
    line(80, 80, 380, 250);

    getch();
    closegraph();
    return 0;
}
