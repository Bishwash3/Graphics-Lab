#include <graphics.h>
#include <conio.h>
#include <vector>

struct Point3D { int x, y, z; };

void drawCube(const std::vector<Point3D>& points) {
    int px[8], py[8];
    for (int i = 0; i < 8; ++i) {
        px[i] = 200 + points[i].x * 18 - points[i].z * 10;
        py[i] = 200 - points[i].y * 18 + points[i].z * 6;
    }
    line(px[0], py[0], px[1], py[1]);
    line(px[1], py[1], px[3], py[3]);
    line(px[3], py[3], px[2], py[2]);
    line(px[2], py[2], px[0], py[0]);
    line(px[4], py[4], px[5], py[5]);
    line(px[5], py[5], px[7], py[7]);
    line(px[7], py[7], px[6], py[6]);
    line(px[6], py[6], px[4], py[4]);
    line(px[0], py[0], px[4], py[4]);
    line(px[1], py[1], px[5], py[5]);
    line(px[2], py[2], px[6], py[6]);
    line(px[3], py[3], px[7], py[7]);
}

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    std::vector<Point3D> cube = {
        {0, 0, 0}, {40, 0, 0}, {40, 40, 0}, {0, 40, 0},
        {0, 0, 40}, {40, 0, 40}, {40, 40, 40}, {0, 40, 40}
    };
    std::vector<Point3D> translated = cube;
    for (auto& p : translated) {
        p.x += 20;
        p.y += 10;
        p.z += 15;
    }

    setcolor(WHITE);
    drawCube(cube);
    setcolor(YELLOW);
    drawCube(translated);

    getch();
    closegraph();
    return 0;
}
