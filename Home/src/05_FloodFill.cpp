#include <graphics.h>
#include <conio.h>

void floodFill4(int x, int y, int oldColor, int newColor) {
    if (x < 0 || y < 0 || x >= getmaxx() || y >= getmaxy()) return;
    int current = getpixel(x, y);
    if (current != oldColor || current == newColor) return;
    putpixel(x, y, newColor);
    floodFill4(x + 1, y, oldColor, newColor);
    floodFill4(x - 1, y, oldColor, newColor);
    floodFill4(x, y + 1, oldColor, newColor);
    floodFill4(x, y - 1, oldColor, newColor);
}

void floodFill8(int x, int y, int oldColor, int newColor) {
    if (x < 0 || y < 0 || x >= getmaxx() || y >= getmaxy()) return;
    int current = getpixel(x, y);
    if (current != oldColor || current == newColor) return;
    putpixel(x, y, newColor);
    floodFill8(x + 1, y, oldColor, newColor);
    floodFill8(x - 1, y, oldColor, newColor);
    floodFill8(x, y + 1, oldColor, newColor);
    floodFill8(x, y - 1, oldColor, newColor);
    floodFill8(x + 1, y + 1, oldColor, newColor);
    floodFill8(x + 1, y - 1, oldColor, newColor);
    floodFill8(x - 1, y + 1, oldColor, newColor);
    floodFill8(x - 1, y - 1, oldColor, newColor);
}

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    setcolor(WHITE);
    rectangle(100, 80, 300, 220);
    rectangle(140, 120, 260, 180);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodFill4(150, 100, BLACK, LIGHTGRAY);

    setcolor(WHITE);
    rectangle(350, 80, 550, 220);
    rectangle(390, 120, 510, 180);
    setfillstyle(SOLID_FILL, GREEN);
    floodFill8(400, 100, BLACK, GREEN);

    getch();
    closegraph();
    return 0;
}
