#include "BMP.h"

BMP::BMP(const char* file_name) {
    read(file_name);
}

BMP::BMP(int32_t width, int32_t height, bool has_alpha) {
    if (width <= 0 || height <= 0) {
        throw std::runtime_error("Высота и длина изображения должны быть положительными числами.");
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

void BMP::read(const char* file_name) {
    //
}

void BMP::write(const char* file_name) {
    std::ofstream out_file(file_name, std::ios_base::binary);

    if (!out_file) {
        throw std::runtime_error("Невозможно открыть файл выходного изображения.");
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
                out_file.write(reinterpret_cast<char*>(bmp_data.data() + row_stride * y), row_stride);
                out_file.write(reinterpret_cast<char*>(padding_row.data()), padding_row.size());
            }
        }
    }
    else {
        throw std::runtime_error("Программа может обрабатывать только файлы BMP с разрешением 24 или 32 бита на пиксель.");
    }

    out_file.close();
}

void BMP::WriteHeaders(std::ofstream &out_file) {
    out_file.write(reinterpret_cast<char*>(&file_header),sizeof(file_header));
    out_file.write(reinterpret_cast<char*>(&bmp_info_header), sizeof(bmp_info_header));
    if (bmp_info_header.bit_count == 32) {
        out_file.write(reinterpret_cast<char*>(&bmp_color_header), sizeof(bmp_color_header));
    }
}

void BMP::WriteHeadersAndData(std::ofstream &out_file) {
    WriteHeaders(out_file);
    out_file.write(reinterpret_cast<char*>(bmp_data.data()), bmp_data.size());
}
