#include <stdio.h>
#include <string.h>

typedef  struct rgb_data {
    float r, g, b;
} rgbData;

void save_bitmap(const char* file_name, int width, int height, int dpi, int color_depth, rgbData* pixel_data);


//0x00 - 0D (14 bytes)
struct bitmap_file_header {
    unsigned char   bitmap_type[2];     // 2 bytes - 0x00  "BC"
    int             file_size;          // 4 bytes - 0x02
    short           reserved1;          // 2 bytes - 0x06
    short           reserved2;          // 2 bytes - 0x08
    unsigned int    offset_bits;        // 4 bytes - 0x0A
} bfh;
// bitmap image header (40 bytes)
struct bitmap_image_header {
    unsigned int    size_header;        // 4 bytes - 0x0E
    unsigned int    width;              // 4 bytes - 0x12
    unsigned int    height;             // 4 bytes - 0x16
    short int       planes;             // 2 bytes - 0x1A
    short int       bit_count;          // 2 bytes - 0x1C
    unsigned int    compression;        // 4 bytes - 0x1E
    unsigned int    image_size;         // 4 bytes - 0x20 
    unsigned int    ppm_x;              // 4 bytes - 0x26
    unsigned int    ppm_y;              // 4 bytes - 0x2A
    unsigned int    clr_used;           // 4 bytes - 0x2E
    unsigned int    clr_important;      // 4 bytes - 0x32
} bih;

void save_bitmap(const char* file_name, int width, int height, int dpi, int color_depth, rgbData* pixel_data)
{
    FILE* image;
    int image_size = width * height;
    int file_size = 54 + (3 * image_size);
    int ppm = dpi * 39.375;

    memcpy(&bfh.bitmap_type, "BM", 2);
    bfh.file_size = file_size;
    bfh.reserved1 = 0;
    bfh.reserved2 = 0;
    bfh.offset_bits = 0;

    bih.size_header = sizeof(bih);
    bih.width = width;
    bih.height = height;
    bih.planes = 1;
    bih.bit_count = color_depth;
    bih.compression = 0;
    bih.image_size = file_size;
    bih.ppm_x = ppm;
    bih.ppm_y = ppm;
    bih.clr_used = 0;
    bih.clr_important = 0;

    image = fopen(file_name, "wb");

    // compiler woes so we will just use the constant 14 we know we have ?? when using sizeof it returns 16
    const int sz = 14;
    fwrite(&bfh, 1, sz, image);
    fwrite(&bih, 1, sizeof(bih), image);
    // // compiler woes so we will just use the constant 14 we know we have
    // fwrite(&bfh, 1, 14, image);
    // fwrite(&bih, 1, sizeof(bih), image);

    // write out pixel data, one last important this to know is the ordering is backwards
    // we have to go BGR as opposed to RGB
    for (int i = 0; i < image_size; i++) {
        rgbData BGR = pixel_data[i];

        float red = (BGR.r);
        float green = (BGR.g);
        float blue = (BGR.b);

        // if you don't follow BGR image will be flipped!
        unsigned char color[3] = {
            blue, green, red
        };

        fwrite(color, 1, sizeof(color), image);
    }

    fclose(image);


}
void main(void)
{
    int width = 16,
        height = 2,
        dpi = 48,
        color_depth = 0x18;

    int low = 4;
    int high = 35;

    struct rgb_data pixels[width * height];

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int a = y * width + x;

            // //center color
            // if ((x > low && x < high) && (y > low && y < high))
            // {
            //     pixels[a].r = 0xee;
            //     pixels[a].g = 0xdd;
            //     pixels[a].b = 0xcc;
            // }
            // //border color
            // else
            {
                pixels[a].r = 0xff;
                pixels[a].g = 0xff;
                pixels[a].b = 0xff;
            }
        }
    }
    save_bitmap("black_border.bmp", width, height, dpi, color_depth, pixels);
}


