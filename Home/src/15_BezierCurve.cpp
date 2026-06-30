#include <graphics.h>
#include <conio.h>
#include <cmath>

struct Point { int x, y; };

Point bezierPoint(const Point& p0, const Point& p1, const Point& p2, const Point& p3, double t) {
    double u = 1.0 - t;
    double x = u * u * u * p0.x + 3 * u * u * t * p1.x + 3 * u * t * t * p2.x + t * t * t * p3.x;
    double y = u * u * u * p0.y + 3 * u * u * t * p1.y + 3 * u * t * t * p2.y + t * t * t * p3.y;
    return {int(x), int(y)};
}

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    Point p0{50, 250};
    Point p1{160, 50};
    Point p2{320, 350};
    Point p3{480, 200};

    setcolor(WHITE);
    for (int i = 0; i < 4; ++i) {
        putpixel(p0.x, p0.y, YELLOW);
    }
    setcolor(LIGHTGREEN);
    for (double t = 0.0; t <= 1.0; t += 0.001) {
        Point p = bezierPoint(p0, p1, p2, p3, t);
        putpixel(p.x, p.y, WHITE);
    }

    setcolor(YELLOW);
    line(p0.x, p0.y, p1.x, p1.y);
    line(p2.x, p2.y, p3.x, p3.y);
    setcolor(RED);
    line(p1.x, p1.y, p2.x, p2.y);

    getch();
    closegraph();
    return 0;
}
