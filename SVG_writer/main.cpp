#include "SVG.h"
#include "SvgElements.h"

template<typename T>
std::ostream& operator<<(std::ostream& os, T object) {
    return object.write(os);
}

int main() {
    /*SVG svg(500, 800, "0 0 100 160", "none");

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

    svg.write("../PALTO.svg");*/

    svg::Property svgProperty(500, 800, "0 0 100 160", "none");
    svg::Rect rect(100, 160, "#C3AE99");

    std::string d = "M 3 125 L 4 80 L 15 12 L 38 11 L 43 10 L 65 10.2 L 70 11.2 L 87 13 L 99.5 35 L 99.5 49 L 89 42 L 92 150 L 14 150 L 18 50 L 12 80 L 11 125 Z";
    svg::Path firstPath(d, "#665A4C", "#3C3128", 0.5);

    std::string points = "42 150, 42 70, 33 35, 39 30, 32 25, 38 11";
    svg::Polyline firstPolyline(points, "none", "#3C3128", 0.5);

    points = "65 150, 65 70, 74 35, 68.7 30, 75 25, 70 11.2";
    svg::Polyline secondPolyline(points, "none", "#3C3128", 0.5);

    points = "42 70, 41.2 14, 45 12.2, 63 12.4, 67 14, 65 70";
    svg::Polyline thirdPolyline(points, "none", "#3C3128", 0.5);

    d = "M 18 50 C 20 40, 20 22, 15.2 12";
    svg::Path secondPath(d, "none", "#3C3128", 0.5);

    d = "M 89 42 C 85 35, 85 15, 86.5 13";
    svg::Path thirdPath(d, "none", "#3C3128", 0.5);

    points = "76 40, 83 40";
    svg::Polyline forthPolyline(points, "none", "#3C3128", 1.5);

    svg::Circle firstCircle(37, 80, 2.5, "#41342B");
    svg::Circle secondCircle(37, 110, 2.5, "#41342B");

    std::ofstream out_file("../PALTO.svg");

    if (!out_file.is_open()) {
        throw std::runtime_error("Невозможно открыть файл выходного изображения.");
    }

    out_file << svgProperty;
    out_file << rect;
    out_file << firstPath;
    out_file << firstPolyline;
    out_file << secondPolyline;
    out_file << thirdPolyline;
    out_file << secondPath;
    out_file << thirdPath;
    out_file << forthPolyline;
    out_file << firstCircle;
    out_file << secondCircle;
    out_file.write(svg::FILE_ENDING.c_str(), svg::FILE_ENDING.length());
    out_file.close();

    return 0;
}
