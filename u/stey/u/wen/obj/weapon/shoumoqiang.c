//shoumoqiang.c
//weiwei
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name("兽魔枪", ({ "shoumoqiang", "spear" }));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "一杆" CYN "兽魔枪" NOR "，乃是万兽天尊以真气所注，万兽之晶造就。\n");
                set("value",      500000);
                set("material", "blacksteel");
                set("wield_msg","$N将万兽枪提在手中，刹时间，一股凶气由枪身溢出。\n");
                set("unwield_msg", "$N将手中的$n系到背后，四周的人都长长出了一口气。\n");
		set("weapon_prop/courage", 4);
        }
        init_spear(100);
        setup();
}

