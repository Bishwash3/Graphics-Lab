#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    int points[6] = {100, 100, 300, 100, 200, 250};
    setcolor(WHITE);
    drawpoly(3, points);

    getch();
    closegraph();
    return 0;
}
