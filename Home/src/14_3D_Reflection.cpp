#include <graphics.h>
#include <conio.h>
#include <vector>

struct Point3D { int x, y, z; };

void drawCube(const std::vector<Point3D>& points) {
    int px[8], py[8];
    for (int i = 0; i < 8; ++i) {
        px[i] = 240 + points[i].x * 10 - points[i].z * 6;
        py[i] = 220 - points[i].y * 10;
    }
    for (int i = 0; i < 4; ++i) {
        line(px[i], py[i], px[(i + 1) % 4], py[(i + 1) % 4]);
        line(px[i + 4], py[i + 4], px[((i + 1) % 4) + 4], py[((i + 1) % 4) + 4]);
        line(px[i], py[i], px[i + 4], py[i + 4]);
    }
}

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    std::vector<Point3D> cube = {
        {0, 0, 0}, {25, 0, 0}, {25, 25, 0}, {0, 25, 0},
        {0, 0, 25}, {25, 0, 25}, {25, 25, 25}, {0, 25, 25}
    };
    std::vector<Point3D> reflected = cube;
    for (auto& p : reflected) {
        p.z = -p.z;
    }

    setcolor(WHITE);
    drawCube(cube);
    setcolor(CYAN);
    drawCube(reflected);

    getch();
    closegraph();
    return 0;
}
