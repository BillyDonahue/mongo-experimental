
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <cinttypes>
#include <memory>
#include <utility>

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

    void put8(size_t xc, size_t yc, size_t x, size_t y, char ch) {
	for (size_t i = 0; i < 8; ++i) {
	    auto bit = [](auto x, size_t b) {
		return (x >> b) & 1;
	    };
	    size_t xx = x;
	    size_t yy = y;
	    if (bit(i, 0))
		std::swap(xx,yy);
	    xx *= 1 - 2 * bit(i, 1);
	    yy *= 1 - 2 * bit(i, 2);
	    put(xc + xx, yc + yy, ch);
	}
    }

    void circle(size_t xc, size_t yc, size_t r, char ch) {
        put(xc, yc, '+');
        int64_t d = 3 - 2 * r;
        size_t x = 0;
        size_t y = r;

	// auto out = std::ostream_iterator<char>(std::cout);

        while (y >= x) {
	    //out = fmt::format_to(out, "(x,y):({:4}, {:4}), d:{:3}\n", x, y, d);
	    put8(xc, yc, x, y, ch);
	    auto dd = (4 * x) + 10;
            if (d > 0) {
		dd += -(4 * y) + 8;
                --y;
            }
            //out = fmt::format_to(out, "dd:{:4}\n", (long long)dd);
	    d += dd;
            ++x;
        }
    }

    size_t w;
    size_t h;
    std::unique_ptr<char[]> p;
};

int main(int argc, char** argv) {
    Raster raster(80, 45);
    int z=0;
    for (int z=0; z!=10; ++z) {
	system("clear");
	raster.clear();
	raster.circle(21+z, 21, 20, '+');
	raster.circle(31, 16-z, 15, '*');
	raster.print(std::cout);

	sleep(1);

    }
    return 0;
}
