#ifndef SVG_WRITER_SVG_H
#define SVG_WRITER_SVG_H


#include <fstream>
#include <sstream>

class SVG {
public:
    SVG(int width, int height, const std::string& fill);
    SVG(int width, int height, const std::string& viewBox, const std::string& fill);

    ~SVG() = default;

    void AddRect(double width, double height, const std::string& fill);
    void AddRectWithStroke(double width, double height, const std::string& stroke, double strokeWidth = 1,
                           const std::string& fill = "none");

    void AddCircle(double cx, double cy, double r, const std::string& fill);
    void AddCircleWithStroke(double cx, double cy, double r, const std::string& stroke, double strokeWidth = 1,
                             const std::string& fill = "none");

    void AddPolyline(const std::string& points, const std::string& fill);
    void AddPolylineWithStroke(const std::string& points, const std::string& stroke, double strokeWidth = 1,
                               const std::string& fill = "none");

    void AddPath(const std::string& d, const std::string& fill);
    void AddPathWithStroke(const std::string& d, const std::string& stroke, double strokeWidth = 1,
                           const std::string& fill = "none");

    void write(const char* file_name);

private:
    std::stringstream _data {};
    const inline static std::string FILE_BEGINNING = "<svg xmlns=\"http://www.w3.org/2000/svg\" ";
    const inline static std::string FILE_ENDING = "</svg>";

    static std::string doubleToString(double value);
};


#endif //SVG_WRITER_SVG_H
