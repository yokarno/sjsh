// whip.c

#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;
#include <ansi.h>
void create()
{
        set_name(HIC"银索金铃"NOR, ({"yinsuo jinling", "whip"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一条银白色的长索，细看上面缀满了金铃，缠在手上宛然就是一副手链。\n");
                set("unit", "副");
//	set("replace_file", "/d/obj/weapon/whip/pibian");
                set("value", 12000);
		set("wield_msg", "$N左手轻扬，叮叮当当一阵声响一条银色绸带忽地甩了出来\n");
		set("unwield_msg", "$N把手中$n缠回手腕．\n");
		set("weapon_prop/courage", 20);
		}
        init_whip(150);
        setup();
}

