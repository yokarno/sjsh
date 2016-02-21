// changjian.c 长剑

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
    set_name(HIG "鸳鸯蝴蝶刀" NOR, ({"dao", "blade"}));
    set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("unit", "对");
        set("long", "这是一对极锋利的双刀。\n");
        set("value", 1);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回鞘中。\n");
	}
    init_blade(12345);
	setup();
}
