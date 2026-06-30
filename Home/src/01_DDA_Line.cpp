#include <graphics.h>
#include <conio.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    int x0 = 100, y0 = 100, x1 = 400, y1 = 250;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    setcolor(RED);
    for (int i = 0; i <= steps; ++i) {
        int x = x0 + (dx * i) / steps;
        int y = y0 + (dy * i) / steps;
        putpixel(x, y, WHITE);
    }

    getch();
    closegraph();
    return 0;
}
