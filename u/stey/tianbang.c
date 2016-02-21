#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name( HIC "斩天棒" NOR, ({"tian bang", "bang"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("no_sell", 1);
                set("long", "一把天地浑圆棒，上面有暗红流动，如同一条火龙般绕在棒上。\n");
                set("value", 100000);
                set("material", "steel");
                set("wield_msg", "$N「轰」地一声抽出一把$n握在手中。\n");
				set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
                                set("no_get","又不是你的，捡什么呀！\n");

        }
        init_stick(140);
        setup();
}

