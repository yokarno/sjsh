#include <ansi.h>
#include <weapon.h>

inherit HAMMER;


void create()
{
        set_name( HIC "镇天锤" NOR, ({ "tian hammer", "hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把天宫镇天之宝的佛锤，上面刻了些符篆，集天地之灵。\n");
                set("value", 100000);
		set("no_sell", 1);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，狂啸天地，握住在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
				set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
                                set("no_get","又不是你的，捡什么呀！\n");
     }
        init_hammer(105);
        setup();
}

