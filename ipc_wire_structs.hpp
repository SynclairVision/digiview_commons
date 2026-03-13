#pragma once

#ifndef DIGIVIEW_COMMONS_IPC_WIRE_STRUCTS_HPP
#define DIGIVIEW_COMMONS_IPC_WIRE_STRUCTS_HPP

#include <cstdint>

#ifdef IPC_GPU
#include <cuda.h>
#include <cuda_runtime_api.h>
#else
#include <nvbufsurface.h>
#include <cuda_runtime.h>
#endif

struct digiview_metadata {
    uint8_t  start_byte = 0xFF;
    uint64_t timestamp;
    float    acc[3];
    float    vel[3];
    float    dir[3];
    float    system_coordinate[2];
    float    system_altitude;
    float    home_altitude;
    float    auto_pilot_euler[3];
    float    auto_pilot_acc[3];

#ifdef IPC_GPU
    int32_t  frame_width;
    int32_t  frame_height;
#else
    NvBufSurfaceMapParams params;
#endif

    int32_t  flags;
};

struct acknowledgment {
    char message[16];
};

static_assert(sizeof(acknowledgment) == 16, "acknowledgment wire contract changed");

#endif
