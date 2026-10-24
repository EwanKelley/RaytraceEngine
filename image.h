#ifndef IMAGE_H
#define IMAGE_H

#include "color.h"
#include <vector>

class Image {
    public:
        Image(int width, int height) : width(width), height(height) { 
            data.reserve(width * height);
        }

        void addPixel(color c) {
            data.push_back(c);
        }

        void exportImage(std::ostream& out = std::cout) const {
            out << "P3\n" << width << ' ' << height << "\n255\n";
            for (const auto& c : data)
                write_color(out, c);
        }

    private:
        int width, height;
        std::vector<color> data;

};

#endif
