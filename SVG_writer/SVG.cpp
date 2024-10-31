#include "SVG.h"

SVG::SVG(const int width, const int height, const std::string &fill) {
    _data << FILE_BEGINNING;
    _data << "width=\"" << std::to_string(width) << "\" ";
    _data << "height=\"" << std::to_string(height) << "\" ";
    _data << "fill=\"" << fill << "\" >\n";
}

SVG::SVG(const int width, const int height, const std::string &viewBox, const std::string &fill) {
    _data << FILE_BEGINNING;
    _data << "width=\"" << std::to_string(width) << "\" ";
    _data << "height=\"" << std::to_string(height) << "\" ";
    _data << "viewBox=\"" << viewBox << "\" ";
    _data << "fill=\"" << fill << "\" >\n";
}

void SVG::AddRect(const double width, const double height, const std::string &fill) {
    _data << "<rect ";
    _data << "width=\"" << doubleToString(width) << "\" ";
    _data << "height=\"" << doubleToString(height) << "\" ";
    _data << "fill=\"" << fill << "\" />\n";
}

void
SVG::AddRectWithStroke(const double width, const double height, const std::string &stroke,
                       const double strokeWidth, const std::string &fill) {
    _data << "<rect ";
    _data << "width=\"" << doubleToString(width) << "\" ";
    _data << "height=\"" << doubleToString(height) << "\" ";
    if (fill != "none") {
        _data << "fill=\"" << fill << "\" ";
    }
    _data << "stroke=\"" << stroke << "\" ";
    if (strokeWidth != 1) {
        _data << "stroke-width=\"" << doubleToString(strokeWidth) << "\" />\n";
    }
    else {
        _data << "/>\n";
    }
}

void SVG::AddCircle(const double cx, const double cy, const double r, const std::string &fill) {
    _data << "<circle ";
    _data << "cx=\"" << doubleToString(cx) << "\" ";
    _data << "cy=\"" << doubleToString(cy) << "\" ";
    _data << "r=\"" << doubleToString(r) << "\" ";
    _data << "fill=\"" << fill << "\" />\n";
}

void SVG::AddCircleWithStroke(const double cx, const double cy, const double r, const std::string &stroke,
                              const double strokeWidth, const std::string &fill) {
    _data << "<circle ";
    _data << "cx=\"" << doubleToString(cx) << "\" ";
    _data << "cy=\"" << doubleToString(cy) << "\" ";
    _data << "r=\"" << doubleToString(r) << "\" ";
    if (fill != "none") {
        _data << "fill=\"" << fill << "\" ";
    }
    _data << "stroke=\"" << stroke << "\" ";
    if (strokeWidth != 1) {
        _data << "stroke-width=\"" << doubleToString(strokeWidth) << "\" />\n";
    }
    else {
        _data << "/>\n";
    }
}

void SVG::AddPolyline(const std::string &points, const std::string &fill) {
    _data << "<polyline ";
    _data << "points=\"" << points << "\" ";
    _data << "fill=\"" << fill << "\" />\n";
}

void SVG::AddPolylineWithStroke(const std::string &points, const std::string &stroke,
                                const double strokeWidth, const std::string &fill) {
    _data << "<polyline ";
    _data << "points=\"" << points << "\" ";
    if (fill != "none") {
        _data << "fill=\"" << fill << "\" ";
    }
    _data << "stroke=\"" << stroke << "\" ";
    if (strokeWidth != 1) {
        _data << "stroke-width=\"" << doubleToString(strokeWidth) << "\" />\n";
    }
    else {
        _data << "/>\n";
    }
}

void SVG::AddPath(const std::string &d, const std::string &fill) {
    _data << "<path ";
    _data << "d=\"" << d << "\" ";
    _data << "fill=\"" << fill << "\" />\n";
}

void SVG::AddPathWithStroke(const std::string &d, const std::string &stroke, const double strokeWidth,
                            const std::string &fill) {
    _data << "<path ";
    _data << "d=\"" << d << "\" ";
    if (fill != "none") {
        _data << "fill=\"" << fill << "\" ";
    }
    _data << "stroke=\"" << stroke << "\" ";
    if (strokeWidth != 1) {
        _data << "stroke-width=\"" << doubleToString(strokeWidth) << "\" />\n";
    }
    else {
        _data << "/>\n";
    }
}

void SVG::write(const char *file_name) {
    std::ofstream out_file(file_name);

    if (!out_file.is_open()) {
        throw std::runtime_error("Невозможно открыть файл выходного изображения.");
    }

    _data << FILE_ENDING;
    out_file << _data.str();
    out_file.close();
}

std::string SVG::doubleToString(const double value) {
    std::string result = std::to_string(value);
    result.erase(result.find_last_not_of('0') + 1, std::string::npos);

    if (!result.empty() && result.back() == '.') {
        result.pop_back();
    }

    return result;
}
