#include <graphics.h>
#include <conio.h>
#include <iostream>

void drawReflected(int choice, int x1, int y1, int x2, int y2, int cx, int cy) {
    int nx1, ny1, nx2, ny2;
    switch (choice) {
        case 1:
            nx1 = x1; ny1 = -y1 + 2 * cy; nx2 = x2; ny2 = -y2 + 2 * cy;
            break;
        case 2:
            nx1 = -x1 + 2 * cx; ny1 = y1; nx2 = -x2 + 2 * cx; ny2 = y2;
            break;
        default:
            nx1 = -x1 + 2 * cx; ny1 = -y1 + 2 * cy; nx2 = -x2 + 2 * cx; ny2 = -y2 + 2 * cy;
            break;
    }
    setcolor(CYAN);
    rectangle(nx1, ny1, nx2, ny2);
}

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    int x1 = 100, y1 = 100, x2 = 220, y2 = 180;
    int cx = 320, cy = 240;
    int choice;
    std::cout << "1. X-axis  2. Y-axis  3. Origin: ";
    std::cin >> choice;

    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
    drawReflected(choice, x1, y1, x2, y2, cx, cy);

    getch();
    closegraph();
    return 0;
}
