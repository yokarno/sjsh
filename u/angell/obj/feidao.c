#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
        set_name(HIG"小"HIC"李"HIW"飞"HIB"刀"NOR, ({ "flying blade" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "一把人见人怕的小李飞刀\n");
                set("unit", "把");
                set("value", 100000);
                set("base_unit", "把");
                set("no_get", 1);
                set("base_weight", 20);
                set("base_value", 1);
                set("wield_msg","$N不知从哪里突然间拽出一把薄薄的$n握在手里．\n");
        }
        set_amount(20);
        init_throwing(100);
        setup();
}

