// 飞仙剑 by Calvin

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW"飞仙剑"NOR, ({ "feixian sword", "feixian","jian", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 10000);
                set("no_sell", "这件东西价值连城,这样的小店可是买不起。\n");
                set("material", "steel");
                set("long", "这是一把雕有飞仙的绝色好剑。\n");
                set("wield_msg", "一道紫光闪过，$N手中已多了把$n。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(100);
        setup();
}
