#ifndef VRAM_H
# define VRAM_H

void* get_static_vram_buffer(unsigned int width, unsigned int height, unsigned int psm);
void* get_static_vram_texture(unsigned int width, unsigned int height, unsigned int psm);

#endif