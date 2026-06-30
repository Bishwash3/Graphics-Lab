#include <graphics.h>
#include <conio.h>
#include <iostream>

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    double sx, sy;
    std::cout << "Enter scale factors sx sy: ";
    std::cin >> sx >> sy;

    int x1 = 100, y1 = 100, x2 = 220, y2 = 180;
    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);

    setcolor(MAGENTA);
    rectangle(int(x1 * sx), int(y1 * sy), int(x2 * sx), int(y2 * sy));

    getch();
    closegraph();
    return 0;
}
