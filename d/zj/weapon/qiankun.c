// 乾坤棒 by Calvin

#include <weapon.h>
#include <ansi.h>
inherit STICK;
void create()
{
        set_name(HIY"乾坤棒"NOR, ({ "qiankun stick","qiankun", "bang","stick" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 50000);
                set("material", "gold");
                set("no_sell", 1);
                set("no_give", 1);
                set("no_drop", 1);
                set("long", "一根多林寺修行者专用的棒子。\n");
                set("wield_msg", "$N拿起一根$n，顺手舞了个棍花。\n");
                set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
        }
        init_stick(100);
        setup();
}
