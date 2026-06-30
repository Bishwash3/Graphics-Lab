#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    double angle;
    std::cout << "Enter rotation angle in degrees: ";
    std::cin >> angle;
    double rad = angle * 3.14159265 / 180.0;

    int x1 = 100, y1 = 100, x2 = 220, y2 = 180;
    int cx = 160, cy = 140;

    auto rotateX = [&](int x, int y) {
        double dx = x - cx;
        double dy = y - cy;
        return int(cx + dx * cos(rad) - dy * sin(rad));
    };
    auto rotateY = [&](int x, int y) {
        double dx = x - cx;
        double dy = y - cy;
        return int(cy + dx * sin(rad) + dy * cos(rad));
    };

    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
    setcolor(CYAN);
    rectangle(rotateX(x1, y1), rotateY(x1, y1), rotateX(x2, y2), rotateY(x2, y2));

    getch();
    closegraph();
    return 0;
}
