//add keenness by ziye 2001/3

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("短剑", ({ "duan jian", "sword", "duanjian", "jian" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄剑身短小的精钢剑。\n");
		set("value", 500);
		set("material", "steel");
              set("keenness", 5);
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(15);
	setup();
}
