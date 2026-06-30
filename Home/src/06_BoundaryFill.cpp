#include <graphics.h>
#include <conio.h>

void boundaryFill4(int x, int y, int fillColor, int boundaryColor) {
    if (x < 0 || y < 0 || x >= getmaxx() || y >= getmaxy()) return;
    int current = getpixel(x, y);
    if (current == boundaryColor || current == fillColor) return;
    putpixel(x, y, fillColor);
    boundaryFill4(x + 1, y, fillColor, boundaryColor);
    boundaryFill4(x - 1, y, fillColor, boundaryColor);
    boundaryFill4(x, y + 1, fillColor, boundaryColor);
    boundaryFill4(x, y - 1, fillColor, boundaryColor);
}

void boundaryFill8(int x, int y, int fillColor, int boundaryColor) {
    if (x < 0 || y < 0 || x >= getmaxx() || y >= getmaxy()) return;
    int current = getpixel(x, y);
    if (current == boundaryColor || current == fillColor) return;
    putpixel(x, y, fillColor);
    boundaryFill8(x + 1, y, fillColor, boundaryColor);
    boundaryFill8(x - 1, y, fillColor, boundaryColor);
    boundaryFill8(x, y + 1, fillColor, boundaryColor);
    boundaryFill8(x, y - 1, fillColor, boundaryColor);
    boundaryFill8(x + 1, y + 1, fillColor, boundaryColor);
    boundaryFill8(x + 1, y - 1, fillColor, boundaryColor);
    boundaryFill8(x - 1, y + 1, fillColor, boundaryColor);
    boundaryFill8(x - 1, y - 1, fillColor, boundaryColor);
}

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    setcolor(WHITE);
    rectangle(80, 80, 280, 220);
    boundaryFill4(120, 120, RED, WHITE);

    setcolor(WHITE);
    rectangle(360, 80, 560, 220);
    boundaryFill8(400, 120, CYAN, WHITE);

    getch();
    closegraph();
    return 0;
}
