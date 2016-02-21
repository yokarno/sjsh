// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(HIG "青布鞋" NOR, ({ "xie", "shoes" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一双精致别巧的草辫布鞋。  \n");
                set("material", "cloth");
                set("unit", "双");
                set("armor_prop/armor", 5);
                set("armor_prop/personality", 5);
                set("female_only", 1);
        }
        setup();
}
