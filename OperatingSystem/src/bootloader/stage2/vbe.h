#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    char VbeSignature[4];
    uint16_t VbeVersion;
    uint16_t OemStringPtr[2];
    uint8_t Capabilities[4];
    uint32_t VideoModePtr;
    uint16_t TotalMemory;
    uint8_t _Reserved[236+256];

} __attribute__((packed)) VbeInfoBlock;

typedef struct {
    uint16_t attributes;
    uint8_t window_a;
    uint8_t window_b;
    uint16_t granuality;
    uint16_t window_size;
    uint16_t segment_a;
    uint16_t segment_b;
    uint32_t win_func_ptr;
    uint16_t pitch;
    uint16_t width;
    uint16_t height;
    uint8_t w_char;
    uint8_t y_char;
    uint8_t planes;
    uint8_t bpp;
    uint8_t banks;
    uint8_t memory_model;
    uint8_t bank_size;
    uint8_t image_pages;
    uint8_t reserved0;

    uint8_t red_mask;
    uint8_t red_position;
    uint8_t green_mask;
    uint8_t green_position;
    uint8_t blue_mask;
    uint8_t blue_position;
    uint8_t researved_mask;
    uint8_t researved_position;
    uint8_t direct_color_attributes;

    uint32_t framebuffer;
    uint32_t off_screen_mem_off;
    uint16_t off_screen_mem_size;
    uint8_t reserved[206];
} __attribute__ ((packed)) VbeModeInfo;

bool VBE_GetControllerInfo(VbeInfoBlock* info);
bool VBE_GetModeInfo(uint16_t mode, VbeModeInfo* info);
bool VBE_SetMode(uint16_t mode);