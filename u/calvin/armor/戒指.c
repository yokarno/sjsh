// goldring.c 天绝戒指

#include <armor.h>

inherit FINGER;

void create()
{
        set_name("天绝戒指", ({ "tianjue jiezhi", "jiezhi", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 5000);
                set("material", "gold");
                set("armor_prop/armor", 15);
        }
        setup();
}       
