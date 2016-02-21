#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name( HIY "星星棒" NOR, ({ "star bang", "starbang", "bang" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("Can_avoid_find", 1);
                       set("value", 5000);
                set("material", "gold");
set("long", "棒棒糖样的小魔棒,头上点着一颗金黄色的小星星”。\n");
                set("wield_msg", "嘻嘻一笑，嘴里‘依依呀呀’念了几句咒语，把一根米老鼠棒棒糖变成一根"+query("name")+"拿在手里，舞了个棒花儿。\n");
                set("unwield_msg", "$N一吹气，几声轻喝：小！小！小！$n在$N掌中转了几转，忽然不见了。\n");
        }
        init_stick(1000);
        setup();
}
