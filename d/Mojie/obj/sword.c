
#include <weapon.h>
#include <ansi.h>
//   inherit SWORD;
inherit "/d/xueshan/obj/anqi-jian.c";

void create()
{
        set_name(HIW"阴阳长生剑"NOR, ({"changsheng sword", "sword", "changsheng", "jian"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "降妖除魔所用兵器之一。\n");
                set("orilong", "降妖除魔所用兵器之一。\n");
                set("value", 30000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N冷笑一声，从背后拔出了$n。\n");
                set("unwield_msg", "$N将手中的$n插回鞘中，嘴角多了一丝笑意。\n");
                set("weapon_prop/int", 1);
                set("anqi/max", 60);
                set("anqi/now", 0);

        }
        init_sword(130);
        setup();
}

