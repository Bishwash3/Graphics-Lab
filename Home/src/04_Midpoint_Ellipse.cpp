#include <graphics.h>
#include <conio.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    int xc = 250, yc = 180;
    int rx = 120, ry = 70;
    int x = 0, y = ry;
    long long p1 = ry * ry - rx * rx * ry + (rx * rx) / 4;

    setcolor(MAGENTA);
    while (2 * ry * ry * x <= 2 * rx * rx * y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p1 < 0) {
            x++;
            p1 += 2 * ry * ry * x + ry * ry;
        } else {
            x++;
            y--;
            p1 += 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
        }
    }

    long long p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p2 > 0) {
            y--;
            p2 += rx * rx - 2 * rx * rx * y;
        } else {
            x++;
            y--;
            p2 += 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
        }
    }

    getch();
    closegraph();
    return 0;
}
