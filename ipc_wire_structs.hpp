#pragma once

#ifndef DIGIVIEW_COMMONS_IPC_WIRE_STRUCTS_HPP
#define DIGIVIEW_COMMONS_IPC_WIRE_STRUCTS_HPP

#include <cstddef>
#include <cstdint>

#ifdef IPC_GPU
#include <cuda.h>
#include <cuda_runtime_api.h>
#else
#include <nvbufsurface.h>
#include <cuda_runtime.h>
#endif

namespace ipc {

// GPU frame format occupies bits 24-27 of digiview_metadata::flags.
enum class GpuFramePixelFormat : std::uint32_t {
    kUnspecified = 0,
    kBgr8 = 1,
    kBgra8 = 2,
};

constexpr std::uint32_t kGpuFramePixelFormatShift = 24U;
constexpr std::uint32_t kGpuFramePixelFormatMask = 0x0F000000U;

constexpr std::int32_t with_gpu_frame_pixel_format(
    const std::int32_t flags,
    const GpuFramePixelFormat format) noexcept {
    const auto format_bits = static_cast<std::uint32_t>(format)
        << kGpuFramePixelFormatShift;
    return static_cast<std::int32_t>(
        (static_cast<std::uint32_t>(flags) & ~kGpuFramePixelFormatMask) |
        (format_bits & kGpuFramePixelFormatMask));
}

constexpr GpuFramePixelFormat gpu_frame_pixel_format_from_flags(
    const std::int32_t flags) noexcept {
    const auto format = (static_cast<std::uint32_t>(flags) &
                         kGpuFramePixelFormatMask) >>
                        kGpuFramePixelFormatShift;
    switch (format) {
    case static_cast<std::uint32_t>(GpuFramePixelFormat::kBgr8):
        return GpuFramePixelFormat::kBgr8;
    case static_cast<std::uint32_t>(GpuFramePixelFormat::kBgra8):
        return GpuFramePixelFormat::kBgra8;
    default:
        return GpuFramePixelFormat::kUnspecified;
    }
}

constexpr std::size_t gpu_frame_bytes_per_pixel(
    const GpuFramePixelFormat format) noexcept {
    switch (format) {
    case GpuFramePixelFormat::kBgr8:
        return 3U;
    case GpuFramePixelFormat::kBgra8:
        return 4U;
    default:
        return 0U;
    }
}

} // namespace ipc

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
