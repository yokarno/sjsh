#include <armor.h>;
#include <ansi.h>
inherit HANDS;

void create()
{
        set_name(HIW"冰玉指环"NOR,({"huan"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
        set("long","一个白色的指环。\n");        
                set("material", "cloth");
                set("armor_prop/armor", 5);

        }
        setup();
}

