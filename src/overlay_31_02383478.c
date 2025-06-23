#include "overlay_31_02383478.h"

struct loc_struct {
    u8 PAD_0x0[0x1192];
    u8 field_0x1192;
    u8 field_0x1193;
    s8 field_0x1194;
    s8 field_0x1195;
    u8 PAD_0x1196[6];
    s16* field_0x119C;
    u8 PAD_0x11A0[17];
    u8 field_0x11b1;
    u8 field_0x11B2;
    u8 field_0x11B3;
    struct item* field_0x11B4;
    u8 PAD_0x11B8[64];
    u8 field_0x11F8[127];
    u8 field_0x1277;
};


extern struct entity* GetLeader(void);
extern struct item* GetItemToUse(struct entity*, u32, u32);

// Represents arguments that might be passed to the PreprocessString function
struct preprocessor_args {
    u32 flag_vals[4];  // 0x0: These are usually IDs with additional flags attached to them
    u32 id_vals[5];    // 0x10
    s32 number_vals[5]; // 0x24
    u8* strings[5];       // 0x38
    // 0x4C: An optional argument that is used to insert the name of a Pokémon
    // When they're talking through a window. It requires its respective flag to be on
    u32 speaker_id;
};

struct window_extra_info;
struct window_params;

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

extern struct loc_struct* OVERLAY31_UNKNOWN_POINTER__NA_238A26C;
extern struct bag_items* BAG_ITEMS_PTR_MIRROR;
extern u32 OVERLAY31_UNKNOWN_STRUCT__NA_2389EF0;
extern u8 ov31_02389F5C[];

extern struct tile* GetTile(s32 x, s32 y);
extern struct item* GetItemInfo(struct entity*);
extern void sub_0200D310(u8*, struct item*, u32*, u32, u32);
extern void strcpy(u8*, u8*);
extern void sub_0200D894(struct item*);
extern void ov10_022BD394(u8*, s32, u32, u32);

extern struct Window* CreateScrollBoxSingle(
    struct window_params* params, enum window_flags flags,
    struct window_extra_info* window_extra_info,
    u16 string_id1, struct preprocessor_args* args1,
    u16 string_id2, struct preprocessor_args* args2 );
extern void AdvanceFrame(u32);
extern u32 IsScrollBoxActive(struct Window*);
extern void CloseScrollBox(struct Window*);

u32 PositionHasItem(struct position*);

extern u32 ov10_022BCD10(s8);
extern s32 sub_020282F4(s8);
extern void CloseInventoryMenu(s8);

extern void ov29_0234E988(u8*);
extern void CloseTextBox2(void);
extern void MemFree(void*);

extern void DrawTextInWindow(struct Window*, u32, u32, u8*);
extern u8* StringFromId(u32);

extern struct dungeon* DUNGEON_PTR[];

extern struct window_params DUNGEON_WINDOW_PARAMS_8;


u8* ov31_02383478(u8* arg1, s32 arg2, u32 arg3)
{
    u32 a = 1;
    if (arg2 >= 0) {
        OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x11F8[arg2] = 0;
    }
    if ( OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x11B4 != NULL && 
         arg2 >= 0 &&
         ( &(BAG_ITEMS_PTR_MIRROR->bag_items->bag_items[arg2]) == OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x11B4 ||
           BAG_ITEMS_PTR_MIRROR->bag_items->bag_items[arg2].held_by != 0 ) ) {
            OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x11F8[arg2] = 3;
            a = 0;
    }
    if ( OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x11B2 != 0 ||
         arg2 < 0 ) {
        s16 x = OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x119C[2];
        s16 y = OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x119C[3];
        struct tile* tile = GetTile(x, y);
        struct item* item = GetItemInfo(tile->object);

        if (GET_BIT(item->flags, 0)) {
            sub_0200D310(arg1, item, &OVERLAY31_UNKNOWN_STRUCT__NA_2389EF0, a, 1);
            OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x1277 = 0;
        } else {
            strcpy(arg1, ov31_02389F5C);
            OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x1277 = 3;
        }
    } else {
        if (GET_BIT(BAG_ITEMS_PTR_MIRROR->bag_items->bag_items[arg2].flags, 0) &&
            BAG_ITEMS_PTR_MIRROR->bag_items->bag_items[arg2].held_by) {
            u32 r1 = (BAG_ITEMS_PTR_MIRROR->bag_items->bag_items[arg2].held_by - 1);
            if (ov31_02383658(DUNGEON_PTR[0]->party_members[r1]) == 0) {
                sub_0200D894(&(BAG_ITEMS_PTR_MIRROR->bag_items->bag_items[arg2]));
            }
        }
        ov10_022BD394(arg1, arg2, a, arg3);
    }
    return arg1;

}

u8 ov31_02383658(struct entity* arg0)
{
    if (arg0 == NULL) {
        return 0;
    }
    if (arg0->type == 0) {
        return 0;
    } 
    return 1;
}

void ov31_0238367C(void)
{
    struct preprocessor_args f_0xc;
    struct item* item = GetItemToUse(GetLeader(), 0, 11);

    f_0xc.id_vals[0] = item->id;
    f_0xc.number_vals[0] = item->quantity;
    f_0xc.id_vals[2] = item->quantity + 0xbc;
    f_0xc.number_vals[2] = 0;

    enum window_flags flags = (enum window_flags)( FLAG_MENU_LOWER_BAR |
                                                   FLAG_SE_ON          |
                                                   FLAG_B_CANCEL       |
                                                   FLAG_A_ACCEPT );
    struct Window* window = CreateScrollBoxSingle(&DUNGEON_WINDOW_PARAMS_8,
                                                  flags, NULL,
                                                  0x08e4, &f_0xc, 
                                                  item->id + 0x29d1, &f_0xc);
    do {
        AdvanceFrame(0x16);
    } while (IsScrollBoxActive(window));
    CloseScrollBox(window);
    AdvanceFrame(0x16);
}

u8 ov31_0238372C(struct position* x)
{
    if (OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x11b1 != 0 && 
        PositionHasItem(&(x[1]))) {
        return 1;
    }
    return 0;
}

void ov31_02383768(s8* arg1)
{
    s32 x;

    if (arg1[0] == -2) {
        return;
    }
    
    if (ov10_022BCD10(arg1[0])) {
        do {
            AdvanceFrame(0x62);
            x = sub_020282F4(arg1[0]);
        } while (-5 != x && -4 != x);
    }
    CloseInventoryMenu(arg1[0]);
    arg1[0] = -2;
}

// Safely dealocates OVERLAY31_UNKNOWN_POINTER__NA_238A26C
void ov31_023837C8(void)
{
    ov29_0234E988(&(OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x1192));
    if ((OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x1194) != -2)
        CloseTextBox2();
    if ((OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x1195) != -2)
        CloseTextBox2();
    ov31_02383768(&(OVERLAY31_UNKNOWN_POINTER__NA_238A26C->field_0x1193));
    MemFree(OVERLAY31_UNKNOWN_POINTER__NA_238A26C);
    OVERLAY31_UNKNOWN_POINTER__NA_238A26C = NULL;
}

void ov31_02383854(struct Window* w)
{
    DrawTextInWindow(w, 2, 2, StringFromId(0x08e6));
}
