#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("高脚椅", ({ "seat" }));
        set_weight(20000);
        set("long", "这是一个特殊材料制成的椅子。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "stone");
                set("value", 2000);
                set("no_get", 1);
                set("amount",30);
        }
        setup();
}
