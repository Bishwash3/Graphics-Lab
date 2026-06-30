#include <graphics.h>
#include <conio.h>
#include <vector>
#include <cmath>

struct Point3D { int x, y, z; };

void drawCube(const std::vector<Point3D>& points) {
    int px[8], py[8];
    for (int i = 0; i < 8; ++i) {
        px[i] = 250 + points[i].x * 12 - points[i].z * 8;
        py[i] = 220 - points[i].y * 12;
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
        {0, 0, 0}, {30, 0, 0}, {30, 30, 0}, {0, 30, 0},
        {0, 0, 30}, {30, 0, 30}, {30, 30, 30}, {0, 30, 30}
    };

    double angle = 35.0 * 3.14159265 / 180.0;
    std::vector<Point3D> rotated = cube;
    for (auto& p : rotated) {
        int x = p.x;
        int z = p.z;
        p.x = int(x * cos(angle) - z * sin(angle));
        p.z = int(x * sin(angle) + z * cos(angle));
    }

    setcolor(WHITE);
    drawCube(cube);
    setcolor(CYAN);
    drawCube(rotated);

    getch();
    closegraph();
    return 0;
}
