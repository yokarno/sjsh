#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(HIW"结婚钻戒"NOR, ({"zhuanjie", "jiezhi"}) );
        set("long", "钻石做成的戒指，是永恒爱情的象征！n");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else { 
                set("armor_type", TYPE_FINGER);
                set("unit", "只");
                set("armor_prop/per", 20);
                set("value", 0);

        }
        setup();
}

