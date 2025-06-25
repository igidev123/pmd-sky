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
    s8 window_id[4];
    u32 f;
    struct entity* entity; // 0x8: Seems to always point to the leader?
    // 0xC: Used for switching in HandleStairsMenu.
    // Seems to be 0 when opening the main stairs menu, 1 when the main stairs menu is open,
    // 3 when opening the info menu, and 4 when the info menu is open.
    u32 state;
    u32 unk_info_menu_var; // 0x10: Has something to do with opening the "Info" menu
    enum stairs_type stairs_type; // 0x14: Which stairs menu to display
};

struct window;
typedef void (*update_window_fn_t)(struct window* window);

struct window_params {
    update_window_fn_t update; // 0x0: A function to update the window
    // 0x4: Window left (or right in tandem with the x_offset_end window flag)
    // edge x coordinate, divided by 8.
    u8 x_offset;
    // 0x5: Window top (or bottom in tandem with the y_offset_end window flag)
    // edge y coordinate, divided by 8.
    u8 y_offset;
    u8 width;          // 0x6: Window width, divided by 8.
    u8 height;         // 0x7: Window height, divided by 8.
    u8 screen; // 0x8: Screen where the window resides
    // 0x9: The box type can affect the window frame and/or the backdrop.
    u8 box_type;
    u8 unk_field_0xa;
    u8 unk_field_0xb;
    // 0xC: heap-allocated contents for the window, varying by type.
    // See callers of NewWindowScreenCheck for the different types
    void* contents;
};
// Corner coordinates of the rectangle a window occupies.
struct window_rectangle {
    int y_min; // 0x0: Window top y coordinate
    int y_max; // 0x4: Window bottom y coordinate
    int x_min; // 0x8: Window left x coordinate
    int x_max; // 0xC: Window right x coordinate
};

// This struct is used when a menu needs extra information like the title
// and custom height. It also seems to be used for other non-menu window types,
// so it's probably generic?
struct window_extra_info {
    // 0x0: The choice to have selected initally when window_flags::set_choice
    // is true.
    u32 set_choice_id;
    // 0x4: Custom height value for a single option
    u32 custom_height;
    // 0x8: Menu title string id
    u16 title_string_id;
    u8 unk_field_0xA;
    u8 unk_field_0xB;
    // 0xC: Height of the title?
    u32 title_height;
    // 0x10: Preprocess arguments for the title.
    struct preprocessor_args* title_args;
    u8 unk_field_0x14;
    u8 unk_field_0x15;
    u8 unk_field_0x16;
    u8 unk_field_0x17;
    u8 unk_field_0x18;
    u8 unk_field_0x19;
    u8 unk_field_0x1A;
    u8 unk_field_0x1B;
    u8 unk_field_0x1C;
    u8 unk_field_0x1D;
    u8 unk_field_0x1E;
    u8 unk_field_0x1F;
    u8 unk_field_0x20;
    u8 unk_field_0x21;
    u8 unk_field_0x22;
    u8 unk_field_0x23;
    u8 unk_field_0x24;
    u8 unk_field_0x25;
    u8 unk_field_0x26;
    u8 unk_field_0x27;
    u8 unk_field_0x28;
    u8 unk_field_0x29;
    u8 unk_field_0x2A;
    u8 unk_field_0x2B;
    u8 unk_field_0x2C;
    u8 unk_field_0x2D;
    u8 unk_field_0x2E;
    u8 unk_field_0x2F;
    u8 unk_field_0x30;
    u8 unk_field_0x31;
    u8 unk_field_0x32;
    u8 unk_field_0x33;
    u8 unk_field_0x34;
    u8 unk_field_0x35;
    u8 unk_field_0x36;
    u8 unk_field_0x37;
    u8 unk_field_0x38;
    u8 unk_field_0x39;
    u8 unk_field_0x3A;
    u8 unk_field_0x3B;
    u8 unk_field_0x3C;
    u8 unk_field_0x3D;
    u8 unk_field_0x3E;
    u8 unk_field_0x3F;
    u8 unk_field_0x40;
    u8 unk_field_0x41;
    u8 unk_field_0x42;
    u8 unk_field_0x43;
    u8 unk_field_0x44;
    u8 unk_field_0x45;
    u8 unk_field_0x46;
    u8 unk_field_0x47;
    u8 unk_field_0x48;
    u8 unk_field_0x49;
    u8 unk_field_0x4A;
    u8 unk_field_0x4B;
    u8 unk_field_0x4C;
    u8 unk_field_0x4D;
    u8 unk_field_0x4E;
    u8 unk_field_0x4F;
    u8 unk_field_0x50;
    u8 unk_field_0x51;
    u8 unk_field_0x52;
    u8 unk_field_0x53;
    u8 unk_field_0x54;
    u8 unk_field_0x55;
    u8 unk_field_0x56;
    u8 unk_field_0x57;
    u8 unk_field_0x58;
    u8 unk_field_0x59;
    u8 unk_field_0x5A;
    u8 unk_field_0x5B;
    u8 unk_field_0x5C;
    u8 unk_field_0x5D;
    u8 unk_field_0x5E;
    u8 unk_field_0x5F;
    // 0x60: A list of states per menu option. Enabled is 0x0 and Disabled is 0x3.
    u8* option_states;
    u8 unk_field_0x64;
    u8 unk_field_0x65;
    u8 unk_field_0x66;
    u8 unk_field_0x67;
    u8 unk_field_0x68;
    u8 unk_field_0x69;
    u8 unk_field_0x6A;
    u8 unk_field_0x6B;
    u8 unk_field_0x6C;
    u8 unk_field_0x6D;
    u8 unk_field_0x6E;
    u8 unk_field_0x6F;
    u8 unk_field_0x70;
    u8 unk_field_0x71;
    u8 unk_field_0x72;
    u8 unk_field_0x73;
    u8 unk_field_0x74;
    u8 unk_field_0x75;
    u8 unk_field_0x76;
    u8 unk_field_0x77;
    u8 unk_field_0x78;
    u8 unk_field_0x79;
    u8 unk_field_0x7A;
    u8 unk_field_0x7B;
    u8 unk_field_0x7C;
    u8 unk_field_0x7D;
    u8 unk_field_0x7E;
    u8 unk_field_0x7F;
    u8 unk_field_0x80;
    u8 unk_field_0x81;
    u8 unk_field_0x82;
    u8 unk_field_0x83;
    u8 unk_field_0x84;
    u8 unk_field_0x85;
    u8 unk_field_0x86;
    u8 unk_field_0x87;
    u8 unk_field_0x88;
    u8 unk_field_0x89;
    u8 unk_field_0x8A;
    u8 unk_field_0x8B;
    u8 unk_field_0x8C;
    u8 unk_field_0x8D;
    u8 unk_field_0x8E;
    u8 unk_field_0x8F;
    u8 unk_field_0x90;
    u8 unk_field_0x91;
    u8 unk_field_0x92;
    u8 unk_field_0x93;
    u8 unk_field_0x94;
    u8 unk_field_0x95;
    u8 unk_field_0x96;
    u8 unk_field_0x97;
};


// Placeholder name; not sure what this struct is
struct window_trailer {
    int field_0x0;
    u8 field_0x4;
    u8 unk_field_0x5;
    u8 unk_field_0x6;
    u8 unk_field_0x7;
    u8 unk_field_0x8;
    u8 unk_field_0x9;
    u8 unk_field_0xa;
    u8 unk_field_0xb;
    u8 unk_field_0xc;
    u8 unk_field_0xd;
    u8 unk_field_0xe;
    u8 unk_field_0xf;
    u8 unk_field_0x10;
    u8 unk_field_0x11;
    u8 unk_field_0x12;
    u8 unk_field_0x13;
    u8 unk_field_0x14;
    u8 unk_field_0x15;
    u8 unk_field_0x16;
    u8 unk_field_0x17;
    u8 field_0x18;
    u8 field_0x19;
    // Not actually sure where this struct ends; these might just be part of
    // the parent window
    u8 unk_field_0x1a;
    u8 unk_field_0x1b;
    u8 unk_field_0x1c;
    u8 unk_field_0x1d;
    u8 unk_field_0x1e;
    u8 unk_field_0x1f;
    u8 unk_field_0x20;
    u8 unk_field_0x21;
    u8 unk_field_0x22;
    u8 unk_field_0x23;
};


// Generic structure for a window containing content
struct window {
    struct window_params params; // 0x0
    // 0x10: it seems like some windows, such as the scroll box, can have an
    // associated sub-window within the main window
    s8 subwindow_id;
    u8 field_0x11;
    u16 field_0x12;
    // Some heap-allocated struct pointer with size (hdr.width * hdr.height * 64)
    void* unk_field_0x14;
    int field_0x18;
    int field_0x1c; // hdr.width * hdr.height * 0x40
    u32 field_0x20;
    u8 unk_field_0x24;
    u8 unk_field_0x25;
    u8 unk_field_0x26;
    u8 unk_field_0x27;
    int field_0x28;
    u8 unk_field_0x2c;
    u8 unk_field_0x2d;
    u8 unk_field_0x2e;
    u8 unk_field_0x2f;
    u16 field_0x30;
    u8 unk_field_0x32;
    u8 unk_field_0x33;
    u64 backdrop; // 0x34: type RENDER64_RECTANGLE
    u64 frame;    // 0x74: type RENDER64_WINDOW_FRAME
    u8 field_0xb4;
    u8 unk_field_0xb5;
    s8 valid; // 0xB6: usually seems to be 0-3
    u8 field_0xb7;
    s32 field_0xb8;
    struct window_trailer trailer; // 0xBC
};


struct window_list {
    struct window windows[20];
};


// These flags are used to modify windows by adding (or taking away) elements.
enum window_flags {
    FLAG_A_ACCEPT               = 0x1,
    FLAG_B_CANCEL               = 0x2,
    FLAG_ACCEPT_BUTTON          = 0x4,
    FLAG_UP_DOWN_BUTTONS        = 0x8,
    FLAG_SE_ON                  = 0x10,
    FLAG_SET_CHOICE             = 0x20,
    FLAG_DISABLE_OPTIONS        = 0x200,
    FLAG_CUSTOM_HEIGHT          = 0x400,
    FLAG_MENU_TITLE             = 0x800,
    FLAG_MENU_LOWER_BAR         = 0x1000,
    FLAG_LIST_BUTTON            = 0x2000,
    FLAG_SEARCH_BUTTON          = 0x4000,
    FLAG_FIRST_LAST_PAGE_BUTTON = 0x10000,
    FLAG_UP_DOWN                = 0x20000,
    FLAG_Y_OFFSET_END           = 0x100000,
    FLAG_X_OFFSET_END           = 0x200000,
    FLAG_PARTIAL_MENU           = 0x400000,
    FLAG_NO_CURSOR              = 0x800000,
    FLAG_NO_UP_DOWN             = 0x1000000,
    FLAG_NO_LEFT_RIGHT          = 0x2000000,
    FLAG_INVISIBLE_CURSOR       = 0x4000000,
    FLAG_ONLY_LIST              = 0x8000000,
    FLAG_NO_ACCEPT_BUTTON       = 0x10000000,
};

#endif //PMDSKY_WINDOW_H
