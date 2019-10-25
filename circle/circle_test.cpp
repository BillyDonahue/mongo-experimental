
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cinttypes>
#include <memory>

struct Raster {
    Raster(size_t w, size_t h) : w(w), h(h), p(std::make_unique<char[]>(w*h)) {
        clear();
    }

    void put(size_t x, size_t y, char c) {
        if (x<w && y<h)
            p[(h-y)*w + x] = c;
    }

    void clear() {
        std::fill_n(p.get(), w*h, ' ');
    }

    void print(std::ostream& os) const {
        auto hr = [&] {
            os.write("+", 1);
            for (size_t x = 0; x < w; ++x) {
                os.write("-", 1);
            }
            os.write("+\n", 2);
        };
        hr();
        for (size_t y = 0; y < h; ++y) {
            const char *row = p.get() + y * w;
            os.write("|", 1);
            for (size_t x = 0; x < w; ++x) {
                os.write(&row[x], 1);
            }
            os.write("|\n", 2);
        }
        hr();
    }

    void circle(size_t xc, size_t yc, size_t r) {
        put(xc, yc, '+');
        int64_t d = 3 - 2 * r;
        size_t x = 0;
        size_t y = r;
        while (y > x) {
            ++x;
            if (d > 0) {
                --y;
                d += 4 * (x - y) + 10;
            } else {
                d += 4 * x + 6;
            }

            fprintf(stderr, "x:%zu, y:%zu, d:%" PRId64 "\n", x, y, d);

            // 8-way symmetry
            const char ch = '.';
            put(xc + x, yc + y, ch);
            put(xc + x, yc - y, ch);
            put(xc - x, yc + y, ch);
            put(xc - x, yc - y, ch);
            put(xc + y, yc + x, ch);
            put(xc + y, yc - x, ch);
            put(xc - y, yc + x, ch);
            put(xc - y, yc - x, ch);
        }
    }

    size_t w;
    size_t h;
    std::unique_ptr<char[]> p;
};

int main(int argc, char**argv) {
    Raster raster(60, 60);
    raster.circle(30, 25, 20);
    raster.print(std::cout);
    return 0;
}
