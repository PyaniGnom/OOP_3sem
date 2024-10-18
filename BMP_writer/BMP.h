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

    BMP(const char* file_name) {
        read(file_name);
    }

    BMP(int32_t width, int32_t height, bool has_alpha = true) {
        if (width <= 0 || height <= 0) {
            throw std::runtime_error("The image width and height must be positive numbers.");
        }

        bmp_info_header.width = width;
        bmp_info_header.height = height;

        if (has_alpha) {
            bmp_info_header.size = sizeof(BMPInfoHeader) + sizeof(BMPColorHeader);
            file_header.offset_data = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + sizeof(BMPColorHeader);

            bmp_info_header.bit_count = 32;
            bmp_info_header.compression = 3;
            row_stride = width * 4;
            bmp_data.resize(row_stride * height);
            file_header.file_size = file_header.offset_data + bmp_data.size();
        }
        else {
            bmp_info_header.size = sizeof(BMPInfoHeader);
            file_header.offset_data = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);

            bmp_info_header.bit_count = 24;
            bmp_info_header.compression = 0;
            row_stride = width * 3;
            bmp_data.resize(row_stride * height);
            file_header.file_size = file_header.offset_data + bmp_data.size() + height * (row_stride % 4);
        }
    }

    void read(const char* file_name) {
        //
    }

    void write(const char* file_name) {
        std::ofstream out_file(file_name, std::ios_base::binary);

        if (!out_file) {
            throw std::runtime_error("Unable to open the output image file.");
        }

        if (bmp_info_header.bit_count == 32) {
            WriteHeadersAndData(out_file);
        }
        else if (bmp_info_header.bit_count == 24) {
            if (bmp_info_header.width % 4 == 0) {
                WriteHeadersAndData(out_file);
            }
            else {
                std::vector<uint8_t> padding_row(bmp_info_header.width % 4);

                WriteHeaders(out_file);

                for (int y = 0; y < bmp_info_header.height; ++y) {
                    out_file.write((const char*)(bmp_data.data() + row_stride * y), row_stride);
                    out_file.write((const char*)padding_row.data(), padding_row.size());
                }
            }
        }
        else {
            throw std::runtime_error("The program can treat only 24 or 32 bits per pixel BMP files");
        }
    }

private:
    uint32_t row_stride{ 0 };

    void WriteHeaders(std::ofstream &out_file) {
        out_file.write((const char*)&file_header,sizeof(file_header));
        out_file.write((const char*)&bmp_info_header, sizeof(bmp_info_header));
        if (bmp_info_header.bit_count == 32) {
            out_file.write((const char*)&bmp_color_header, sizeof(bmp_color_header));
        }
    }

    void WriteHeadersAndData(std::ofstream& out_file) {
        WriteHeaders(out_file);
        out_file.write((const char*)bmp_data.data(), bmp_data.size());
    }
};


#endif //BMP_WRITER_BMP_H
