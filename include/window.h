#ifndef PMDSKY_WINDOW_H
#define PMDSKY_WINDOW_H

#include "enums.h"

// Represents the state of a portrait to be displayed inside a window
typedef struct {
    enum monster_id monster_id; // 0x0: The species id, or the set index inside kaomado.kao
    // 0x2: Index of the emote in the species set of portraits
    u32 portrait_emotion;
    u8 layout_idx; // 0x3: Represents the current layout to display the portrait
    u32 offset_x;  // 0x4: Tile offset (x / 8) in the X axis to draw the portrait
    u32 offset_y;  // 0x8: Tile offset (y / 8) in the Y axis to draw the portrait
    u8 try_flip;      // 0xC: Whether to try to get a flipped portrait from kaomado.kao
    u8 has_flip;      // 0xD: Whether the specified emote has a flipped variant
    u8 hw_flip;       // 0xE: Whether the portrait should be flipped using the hardware
    u8 allow_default; // 0xF: If true, try using emote index 0 if the desired emote can't be found
} portrait_params;


// Used for creating the stairs menu.
struct stairs_menu {
    // 0x0: Seems to hold window IDs
    // 0x0 is the parent window?
    // 0x1 and 0x2 are text boxes?
    u8 window_id[4];
    u32 f;
    struct entity* entity; // 0x8: Seems to always point to the leader?
    // 0xC: Used for switching in HandleStairsMenu.
    // Seems to be 0 when opening the main stairs menu, 1 when the main stairs menu is open,
    // 3 when opening the info menu, and 4 when the info menu is open.
    u32 state;
    u32 unk_info_menu_var; // 0x10: Has something to do with opening the "Info" menu
    enum stairs_type stairs_type; // 0x14: Which stairs menu to display
};

#endif //PMDSKY_WINDOW_H
