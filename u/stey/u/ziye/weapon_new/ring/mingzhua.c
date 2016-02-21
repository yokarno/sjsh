// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit UNARMED;

void create()
{
        set_name(RED "冥王爪" NOR, ({"mingwang zhua", "zhua"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long",
"听说这种兵器可以强化鬼族的攻击力，不知道是真是假。\n");
                set("value", 0);
                set("material", "diamond");
                set("wield_msg",
"$N戴上一只$n，周围的人登时不寒而栗。\n");
                set("unwield_msg", "$N放下手中的$n，松了口气。\n");
        }

        init_unarmed(50);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int dam = 0;

    if( (string)me->query("family/family_name") == "阎罗地府"
                && me->query_skill("jinghun-zhang",1) > 1)
    dam = me->query_skill("unarmed");
    dam = (dam+random(dam))/2;

    victim->receive_damage("kee",dam);
    victim->receive_wound("kee",dam/2);
    return HIR"骨头被抓碎的感觉真爽。\n" NOR;
}

