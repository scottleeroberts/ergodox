#pragma once

// Home-row mod anti-misfire: resolve as tap when both keys are on the same hand.
#define CHORDAL_HOLD

// Engage home-row mods after 170ms hold (default 200ms).
#define TAPPING_TERM 170

// Activate mod immediately when another key is tapped during hold (no TAPPING_TERM wait).
#define PERMISSIVE_HOLD

// Disable hold behavior during fast typing bursts (keys within 100ms always tap).
#define FLOW_TAP_TERM 100

// RGB lighting step sizes (override keyboard defaults)
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 8
#undef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 8
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 8
