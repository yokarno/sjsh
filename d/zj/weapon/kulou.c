// 骷髅枪 by Calvin

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE; 
inherit SPEAR;
void create()
{
        set_name(HIW "骷髅枪" NOR, ({"kulou spear","kulou","qiang", "spear"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是把无数小骷髅制成的长抢。\n");
                set("value", 10000);
                set("material", "gold");
                set("replace_file", "/d/obj/weapon/spear/tieqiang");
                set("wield_msg","$N拿出一把$n握在手中，眼前闪过一道寒光．\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_spear(100);
        setup();
}
