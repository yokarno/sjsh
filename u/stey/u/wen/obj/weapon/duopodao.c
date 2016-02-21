// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("夺魄刀", ({"duopo dao", "dao", "blade"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500000);
		set("material", "steel");
		set("long", "呜呜的怪叫不绝于耳，好怪异的一把刀。\n");
		set("wield_msg", "$N抽出一柄$n，唰地握在手中，漫山遍野似乎被一种阴森之气所笼罩。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘，一切又都平静了。\n");
	}
	init_blade(125);
	setup();
}
