#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"伏魔金刀"NOR,({ "fumo dao", "dao","blade" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500000);
                set("unique", 1);
                set("rigidity", 3);
                set("sharpness", 5);
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);        
                set("material", "gold");
                set("wield_force", 100);
                set("wield_maxforce", 700);
                set("wield_str", 22);
                set("wield_msg",HIY"只听见「唰」地一声，天边飞来一道霞光，定睛一看，$N手中
                多了一把金刀！\n"NOR);
                set("long", HIY"\n这是用纯金打造的一把弯刀，上面刻满伏魔真言。仔细看去，刀柄底部有一个洞 \n
                似乎可以接(jie)什么东西。\n"NOR);               
                set("unwield_msg", HIY "$N手一挥，伏魔金刀化为一道金光，[呼]地一声不见了。\n"NOR);               
        }
        init_blade(70);
        setup();
}

void init()
{
    add_action("do_jie", "jie");
}

int do_jie()
{
     object me,ob, obj, dao;
     me = this_player();
     ob = this_object();
     obj = present("xiangyao chan", me);
     if(!objectp(obj))
           return notify_fail("你手中只有伏魔金刀，先找到降妖铲再说吧。\n");
     if((int)me->query("force") < 500)
		return notify_fail("你感觉全身气血翻腾，原来你真气不够，无法将宝物合并！\n");
     if((int)me->query("mana") < 500)
		return notify_fail("你感觉一阵心烦意乱，原来你魔力不够，无法将宝物合并！\n");
     if((int)me->query_str() < 28)
		return notify_fail("你感觉全身气血翻腾，原来你力量不够，无法将宝物合并！\n");
     me->add("force", -300);
     message_vision(HIY"\n只听伏魔金刀和降妖铲同时发出耀眼的霞光，逐渐接近，最后合为一体！。\n"NOR, me);
     destruct(obj);   
     dao = new("/u/xintai/weapon/suoluodao")->move(me, 1);     
     destruct(ob);
     return 1;
}
