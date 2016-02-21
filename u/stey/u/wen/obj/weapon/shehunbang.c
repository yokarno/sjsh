#include <weapon.h>

inherit STICK;


void create()
{
        set_name("摄魂棒", ({"shehun bang", "bang"}));
        set_weight(21000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("long", "一把暗红的棒子，不时发出丝丝阴嚎．\n");
                set("value", 500000);
                set("material", "steel");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中，一股鬼气遍布四野！\n");
				set("replace_file", "/d/obj/weapon/stick/qimeigun");
        }
        init_stick(120);
        setup();
}

