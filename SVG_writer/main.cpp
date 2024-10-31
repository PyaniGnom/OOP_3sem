#include "SVG.h"

int main() {
    SVG svg(500, 800, "0 0 100 160", "none");

    svg.AddRect(100, 160, "#C3AE99");

    std::string d = "M 3 125 L 4 80 L 15 12 L 38 11 L 43 10 L 65 10.2 L 70 11.2 L 87 13 L 99.5 35 L 99.5 49 L 89 42 L 92 150 L 14 150 L 18 50 L 12 80 L 11 125 Z";
    svg.AddPathWithStroke(d, "#3C3128", 0.5, "#665A4C");

    std::string points = "42 150, 42 70, 33 35, 39 30, 32 25, 38 11";
    svg.AddPolylineWithStroke(points, "#3C3128", 0.5);

    points = "65 150, 65 70, 74 35, 68.7 30, 75 25, 70 11.2";
    svg.AddPolylineWithStroke(points, "#3C3128", 0.5);

    points = "42 70, 41.2 14, 45 12.2, 63 12.4, 67 14, 65 70";
    svg.AddPolylineWithStroke(points, "#3C3128", 0.5);

    d = "M 18 50 C 20 40, 20 22, 15.2 12";
    svg.AddPathWithStroke(d, "#3C3128", 0.5);

    d = "M 89 42 C 85 35, 85 15, 86.5 13";
    svg.AddPathWithStroke(d, "#3C3128", 0.5);

    points = "76 40, 83 40";
    svg.AddPolylineWithStroke(points, "#3C3128", 1.5);

    svg.AddCircle(37, 80, 2.5, "#41342B");
    svg.AddCircle(37, 110, 2.5, "#41342B");

    svg.write("../PALTO.svg");

    return 0;
}
