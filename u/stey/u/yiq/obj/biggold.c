// thousand.c

#include <ansi.h>
inherit MONEY;

void create()
{
    set_name(HIY"大金元宝"NOR, ({ "gold", "big gold" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("money_id", "biggold");
        set("long", "一锭金光闪闪的大元宝。\n");
        set("unit", "锭");
        set("base_value", 1000000);
        set("base_unit", "锭");
		set("base_weight", 3);
	}
	set_amount(1);
}

