#pragma once

#ifndef DIGIVIEW_COMMONS_PUBLIC_ENUMS_HPP
#define DIGIVIEW_COMMONS_PUBLIC_ENUMS_HPP

#include <cstdint>

enum calibration_command : uint8_t {
    CALIBRATION_CMD_NONE = 0,
    CALIBRATION_CMD_START_ALL = 1,
    CALIBRATION_CMD_START_6DOF = 2,
    CALIBRATION_CMD_START_MAG = 3,
    NUM_CALIBRATION_CMDS = 4
};

static_assert(CALIBRATION_CMD_NONE == 0, "calibration_command contract changed");
static_assert(CALIBRATION_CMD_START_MAG == 3, "calibration_command contract changed");

enum calibration_status : uint8_t {
    CALIBRATION_STATUS_NOT_STARTED = 0,
    CALIBRATION_STATUS_6DOF_X_POS = 1,
    CALIBRATION_STATUS_6DOF_X_NEG = 2,
    CALIBRATION_STATUS_6DOF_Y_POS = 3,
    CALIBRATION_STATUS_6DOF_Y_NEG = 4,
    CALIBRATION_STATUS_6DOF_Z_POS = 5,
    CALIBRATION_STATUS_6DOF_Z_NEG = 6,
    CALIBRATION_STATUS_MAG_IN_PROGRESS = 7,
    NUM_CALIBRATION_STATUSES = 8
};

static_assert(CALIBRATION_STATUS_NOT_STARTED == 0, "calibration_status contract changed");
static_assert(CALIBRATION_STATUS_MAG_IN_PROGRESS == 7, "calibration_status contract changed");

enum class app_status : uint8_t {
    STARTUP = 0,
    LOADING = 1,
    RUNNING = 2,
    ERROR = 3,
    HALT = 4
};

static_assert(static_cast<uint8_t>(app_status::HALT) == 4, "app_status contract changed");

namespace View {
    enum CropMode : uint8_t {
        NONE = 0,
        CARTESIAN = 1,
        PANORAMA = 2,
        LUSTIGA_HUSET = 3,
        FULL_FRAME = 4,
    };

    static_assert(FULL_FRAME == 4, "View::CropMode contract changed");

    enum TargetingMode : uint8_t {
        DIRECTIONAL = 0,
        COORDINAL = 1,
        DETECTION = 2,
        SINGLE_TARGET_TRACKING = 3,
        NUM_TARGETING_MODES = 4,
    };

    static_assert(NUM_TARGETING_MODES == 4, "View::TargetingMode contract changed");
}

namespace Layout {
    enum ID : uint8_t {
        LAYOUT_1 = 0,
        LAYOUT_2_STK = 1,
        LAYOUT_2_SBS = 2,
        LAYOUT_2_SBS_1_STK = 3,
        LAYOUT_4 = 4,
        LAYOUT_3_SBS_1_STK = 5,
        LAYOUT_DEBUG = 6,
        LAYOUT_MAX = LAYOUT_DEBUG,
    };

    static_assert(LAYOUT_MAX == LAYOUT_DEBUG, "Layout::ID contract changed");

    enum DetOverlayMode : uint8_t {
        DET_OVERLAY_NONE = 0,
        DET_OVERLAY_SINGLE_TOP_RIGHT = 1,
        DET_OVERLAY_COLUMN_RIGHT = 2,
        DET_OVERLAY_COLUMN_LEFT = 3,
        DET_OVERLAY_ROW_TOP = 4,
        DET_OVERLAY_ROW_BOTTOM = 5,
        DET_OVERLAY_MAX = DET_OVERLAY_ROW_BOTTOM,
    };

    static_assert(DET_OVERLAY_MAX == DET_OVERLAY_ROW_BOTTOM, "Layout::DetOverlayMode contract changed");
}

enum single_target_tracker_command : uint8_t {
    CMD_OFF = 0,
    CMD_SET_TARGET_VECTOR = 1,
    CMD_SET_TARGET_DETECTION = 2,
    CMD_NUDGE = 3,
    CMD_NONE = 4,
};

static_assert(CMD_NONE == 4, "single_target_tracker_command contract changed");

#endif
