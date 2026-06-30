#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    setcolor(WHITE);
    for (int i = 0; i < 200; ++i) {
        putpixel(200 + i / 2, 150 + i / 3, YELLOW);
    }

    getch();
    closegraph();
    return 0;
}
