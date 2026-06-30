#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    int points[10] = {120, 100, 220, 80, 320, 140, 280, 260, 160, 240};
    setcolor(LIGHTGREEN);
    drawpoly(5, points);

    getch();
    closegraph();
    return 0;
}
