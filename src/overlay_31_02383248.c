#include "overlay_31_02383248.h"

extern struct struct_4 ov31_0238A2A0;

extern u8 ov31_0238A2A8;
extern u8 OVERLAY31_UNKNOWN_POINTER__NA_238A268[];

extern void DrawTextInWindow(struct Window*, u32, u32, u8*);
extern u8* StringFromId(u32);

extern void CloseAdvancedTextBox(s8);
extern void CloseParentMenu(s8);

extern void MemFree(void*);

extern u8 sub_0204AEA0(void(*)(void));
extern void ov29_02E8708(void);

void ov31_02383248(struct Window* window)
{
    u8* a;
    a = StringFromId(OVERLAY31_UNKNOWN_STRING_IDS[ov31_0238A2A0.st3->d * 2]);
    DrawTextInWindow(window, 4, 20, a);
}

void ov31_0238328C(void)
{
    if (ov31_0238A2A0.st3->e[0] != -2) {
        CloseAdvancedTextBox(ov31_0238A2A0.st3->e[0]);
        ov31_0238A2A0.st3->e[0] = -2;
    }
    if (ov31_0238A2A0.st3->e[1] != -2) {
        CloseParentMenu(ov31_0238A2A0.st3->e[1]);
        ov31_0238A2A0.st3->e[1] = -2;
    }
}

// Safely frees ov31_0238A2A0.st3
void ov31_023832F0(void)
{
    if (ov31_0238A2A0.st3 == NULL) {
        return;
    }
    ov31_0238328C();
    MemFree(ov31_0238A2A0.st3);
    ov31_0238A2A0.st3 = NULL;
}

void ov31_02383328(void (*f)(void))
{
    if (sub_0204AEA0(f) != ov31_0238A2A8) {
        ov29_02E8708();
        OVERLAY31_UNKNOWN_POINTER__NA_238A268[0] = 1;
    }
}
