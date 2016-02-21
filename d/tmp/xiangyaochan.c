#include <weapon.h>
#include <ansi.h>

inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"降妖铲"NOR,({ "xiangyao chan", "cha","fork" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "副");
                set("value", 500000);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 1);
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);        
                set("material", "gold");
                set("wield_force", 100);
                set("wield_maxforce", 700);
                set("wield_str", 22);
                set("wield_msg",HIY"只听见「唰」地一声，天边飞来一道霞光，定睛一看，$N手中
                多了一把金铲！\n"NOR);
                set("long", HIY"\n一把闪闪发光地金叉，上面刻满斩妖法诀。仔细看去，叉头似乎有点古\n
                怪，好象可以接什么东西。\n"NOR);                
                set("unwield_msg", HIY "斩妖金铙向半空飞出，又飞回了$N的手中。\n"NOR);               
        }
        init_fork(80);
        setup();
}

