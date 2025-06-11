#include "overlay_31_02383248.h"

extern struct struct_4 ov31_0238A2A0;

extern void DrawTextInWindow(struct Window*, u32, u32, u8*);
extern u8* StringFromId(u32);

void ov31_02383248(struct Window* window)
{
    u8* a;
    a = StringFromId(OVERLAY31_UNKNOWN_STRING_IDS[ov31_0238A2A0.st3->d * 2]);
    DrawTextInWindow(window, 4, 20, a);
}
