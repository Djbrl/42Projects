#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct	s_rgb{
	float r;
	float g;
	float b;
}		t_rbg;

struct bitmap_file_header {
	unsigned char   bitmap_type[2];     // 2 bytes
	int             file_size;          // 4 bytes
	short           reserved1;          // 2 bytes
	short           reserved2;          // 2 bytes
	unsigned int    offset_bits;        // 4 bytes
} bfh;

// bitmap image header (40 bytes)
struct bitmap_image_header {
	unsigned int    size_header;        // 4 bytes
	unsigned int    width;              // 4 bytes
	unsigned int    height;             // 4 bytes
	short int       planes;             // 2 bytes
	short int       bit_count;          // 2 bytes
	unsigned int    compression;        // 4 bytes
	unsigned int    image_size;         // 4 bytes
	unsigned int    ppm_x;              // 4 bytes
	unsigned int    ppm_y;              // 4 bytes
	unsigned int    clr_used;           // 4 bytes
	unsigned int    clr_important;      // 4 bytes
} bih;

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s1;

	s1 = (char *)dst;
	i = 0;
	while (i < n)
	{
		*(char *)s1 = *(char *)src;
		s1++;
		src++;
		i++;
	}
	return (dst);
}

void	save_bitmap(const char *filename, int width, int height, int dpi, t_rgb *pixel_data)
{
	char *file;

	int img_size = width * height;
	int file_size = 54 + 4 * img_size;
	int ppm = dpi * 39.375;

	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size       = file_size;
	bfh.reserved1       = 0;
	bfh.reserved2       = 0;
	bfh.offset_bits     = 0;

	bih.size_header     = sizeof(bih);
	bih.width           = width;
	bih.height          = height;
	bih.planes          = 1;
	bih.bit_count       = 24;
	bih.compression     = 0;
	bih.image_size      = file_size;
	bih.ppm_x           = ppm;
	bih.ppm_y           = ppm;
	bih.clr_used        = 0;
	bih.clr_important   = 0;

	
}
