#include "overlay_31_02383478.h"

struct loc_struct {
    u8 PAD_0x0000[4508];
    s16* field_0x119C;
    u8 PAD_0x11A0[18];
    u8 field_0x11B2;
    u8 field_0x11B3;
    struct item* field_0x11B4;
    u8 PAD_0x11B8[64];
    u8 field_0x11F8[127];
    u8 field_0x1277;
};

extern struct loc_struct* OVERLAY31_UNKNOWN_POINTER__NA_238A26C;
extern struct bag_items* BAG_ITEMS_PTR_MIRROR;
extern u32 OVERLAY31_UNKNOWN_STRUCT__NA_2389EF0;
extern u8 ov31_02389F5C[];

extern struct tile* GetTile(s32 x, s32 y);
extern struct item* GetItemInfo(struct entity*);
void sub_0200D310(u8*, struct item*, u32*, u32, u32);
void strcpy(u8*, u8*);
u8 ov31_02383658(struct entity*);
void sub_0200D894(struct item*);
void ov10_022BD394(u8*, s32, u32, u32);

extern struct dungeon* DUNGEON_PTR[];

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
