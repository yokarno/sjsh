// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("桃木剑", ({"taomu jian", "sword", "jian"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","一把桃木制成的长剑，一般是用来写咒画符的．\n");
                set("unit", "把");
                set("value", 200);
              set("keenness", 5);
                        set( "material", wood);

        }
        init_sword(15);
        setup();
}

