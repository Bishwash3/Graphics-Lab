#include <graphics.h>
#include <conio.h>

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    int x1 = 100, y1 = 100, x2 = 220, y2 = 180;
    int tx = 120, ty = 60;

    setcolor(WHITE);
    drawRectangle(x1, y1, x2, y2);
    setcolor(YELLOW);
    drawRectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);

    getch();
    closegraph();
    return 0;
}
