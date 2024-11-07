#ifndef SVG_WRITER_SVGELEMENTS_H
#define SVG_WRITER_SVGELEMENTS_H


#include <string>
#include <utility>
#include <fstream>

namespace svg {
    const std::string FILE_BEGINNING = "<svg xmlns=\"http://www.w3.org/2000/svg\" ";
    const std::string FILE_ENDING = "</svg>";

    std::string doubleToString(const double value) {
        std::string result = std::to_string(value);
        result.erase(result.find_last_not_of('0') + 1, std::string::npos);

        if (!result.empty() && result.back() == '.') {
            result.pop_back();
        }

        return result;
    }

    class Property {
    public:
        int width;
        int height;
        std::string viewBox;
        std::string fill;

        Property(int width, int height, std::string viewBox = "none", std::string fill = "none") {
            this->width = width;
            this->height = height;
            this->viewBox = std::move(viewBox);
            this->fill = std::move(fill);
        }

        std::ostream& write(std::ostream& os) {
            os << FILE_BEGINNING;
            os << "width=\"" << std::to_string(width) << "\" ";
            os << "height=\"" << std::to_string(height) << "\" ";
            if (viewBox != "none") {
                os << "viewBox=\"" << viewBox << "\" ";
            }
            os << "fill=\"" << fill << "\" >\n";
            return os;
        }
    };

    class Rect {
    public:
        double width;
        double height;
        std::string fill;
        std::string stroke;
        double strokeWidth;

        Rect(double width, double height, std::string fill, std::string stroke = "none", double strokeWidth = 1) {
            this->width = width;
            this->height = height;
            this->fill = std::move(fill);
            this->stroke = std::move(stroke);
            this->strokeWidth = strokeWidth;
        }

        std::ostream& write(std::ostream& os) {
            os << "<rect ";
            os << "width=\"" << doubleToString(width) << "\" ";
            os << "height=\"" << doubleToString(height) << "\" ";
            if (fill != "none") {
                os << "fill=\"" << fill << "\" ";
            }
            if (stroke != "none") {
                os << "stroke=\"" << stroke << "\" ";
            }
            if (strokeWidth != 1) {
                os << "stroke-width=\"" << doubleToString(strokeWidth) << "\" />\n";
            }
            else {
                os << "/>\n";
            }
            return os;
        }
    };

    class Circle {
    public:
        double cx;
        double cy;
        double r;
        std::string fill;
        std::string stroke;
        double strokeWidth;

        Circle(double cx, double cy, double r, std::string fill, std::string stroke = "none", double strokeWidth = 1) {
            this->cx = cx;
            this->cy = cy;
            this->r = r;
            this->fill = std::move(fill);
            this->stroke = std::move(stroke);
            this->strokeWidth = strokeWidth;
        }

        std::ostream& write(std::ostream& os) {
            os << "<circle ";
            os << "cx=\"" << doubleToString(cx) << "\" ";
            os << "cy=\"" << doubleToString(cy) << "\" ";
            os << "r=\"" << doubleToString(r) << "\" ";
            if (fill != "none") {
                os << "fill=\"" << fill << "\" ";
            }
            if (stroke != "none") {
                os << "stroke=\"" << stroke << "\" ";
            }
            if (strokeWidth != 1) {
                os << "stroke-width=\"" << doubleToString(strokeWidth) << "\" />\n";
            }
            else {
                os << "/>\n";
            }
            return os;
        }
    };

    class Polyline {
    public:
        std::string points;
        std::string fill;
        std::string stroke;
        double strokeWidth;

        explicit Polyline(std::string points, std::string fill = "none", std::string stroke = "none",
                          double strokeWidth = 1) {
            this->points = std::move(points);
            this->fill = std::move(fill);
            this->stroke = std::move(stroke);
            this->strokeWidth = strokeWidth;
        }

        std::ostream& write(std::ostream& os) {
            os << "<polyline ";
            os << "points=\"" << points << "\" ";
            if (fill != "none") {
                os << "fill=\"" << fill << "\" ";
            }
            if (stroke != "none") {
                os << "stroke=\"" << stroke << "\" ";
            }
            if (strokeWidth != 1) {
                os << "stroke-width=\"" << doubleToString(strokeWidth) << "\" />\n";
            }
            else {
                os << "/>\n";
            }
            return os;
        }
    };

    class Path {
    public:
        std::string d;
        std::string fill;
        std::string stroke;
        double strokeWidth;

        explicit Path(std::string d, std::string fill = "none", std::string stroke = "none", double strokeWidth = 1) {
            this->d = std::move(d);
            this->fill = std::move(fill);
            this->stroke = std::move(stroke);
            this->strokeWidth = strokeWidth;
        }

        std::ostream& write(std::ostream& os) {
            os << "<path ";
            os << "d=\"" << d << "\" ";
            if (fill != "none") {
                os << "fill=\"" << fill << "\" ";
            }
            if (stroke != "none") {
                os << "stroke=\"" << stroke << "\" ";
            }
            if (strokeWidth != 1) {
                os << "stroke-width=\"" << doubleToString(strokeWidth) << "\" />\n";
            }
            else {
                os << "/>\n";
            }
            return os;
        }
    };
}


#endif //SVG_WRITER_SVGELEMENTS_H
