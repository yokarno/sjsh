// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("石锁", ({"stone hammer","stone", "hammer"}));
        set_weight(5000);
              set("keenness", 0);
              set("material" , iron);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long", "一把沉重的石锁。\n");
        }
        init_hammer(25);
        setup();
}

