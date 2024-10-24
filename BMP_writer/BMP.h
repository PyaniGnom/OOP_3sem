#ifndef BMP_WRITER_BMP_H
#define BMP_WRITER_BMP_H

#include <vector>
#include <cstdint>
#include <fstream>

#pragma pack(push, 1)

struct BMPFileHeader {
    uint16_t file_type { 0x4D42 };
    uint32_t file_size { 0 };
    uint16_t reserved_1 { 0 };
    uint16_t reserved_2 { 0 };
    uint32_t offset_data { 0 };
};

#pragma pack(pop)

struct BMPInfoHeader {
    uint32_t size { 0 };
    int32_t width { 0 };
    int32_t height { 0 };

    uint16_t planes { 1 };
    uint16_t bit_count { 0 };
    uint32_t compression { 0 };
    uint32_t size_image { 0 };
    int32_t x_pixels_per_meter { 0x130B0000 };
    int32_t y_pixels_per_meter { 0x130B0000 };
    uint32_t colors_used { 0 };
    uint32_t colors_important { 0 };
};

struct BMPColorHeader {
    uint32_t red_mask { 0x00FF0000 };
    uint32_t green_mask { 0x0000FF00 };
    uint32_t blue_mask { 0x000000FF };
    uint32_t alpha_mask { 0xFF000000 };
    uint32_t color_space_type { 0x73524742 };
    uint32_t unused[16] { 0 };
};

class BMP {
public:
    BMPFileHeader file_header;
    BMPInfoHeader bmp_info_header;
    BMPColorHeader bmp_color_header;
    std::vector<uint8_t> bmp_data;

    BMP(const char* file_name);
    BMP(int32_t width, int32_t height, bool has_alpha = true);

    void read(const char* file_name);

    void write(const char* file_name);

private:
    uint32_t row_stride{ 0 };

    void WriteHeaders(std::ofstream &out_file);

    void WriteHeadersAndData(std::ofstream& out_file);
};


#endif //BMP_WRITER_BMP_H
