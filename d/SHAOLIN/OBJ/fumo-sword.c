// fumo-sword.c 伏魔剑
// writed by piao 2001-10-04

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY"伏魔剑"NOR, ({ "fumo sword", "sword" }));
        set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long", HIW"这是一把银光雪亮的伏魔剑，剑刃间隐隐有血光流动，锋利无匹，
映面生寒。此剑数百年前由达摩老祖携入中原，一路用之除妖灭魔，
乃是佛家无上降魔法宝。\n"NOR);
        set("value", 100000);
		set("material", "steel");
		set("wield_msg", HIY "只听「铮」的一声，伏魔剑脱鞘飞出，自行跃入$N掌中。
瞬时天际间风云变色，电闪雷鸣，弥漫着一片无边杀意。\n" NOR);
		set("unwield_msg", HIY "伏魔剑自$N掌中飞起，在半空中一转，「唰」地跃入刀鞘。\n" NOR);
	}
        init_sword(160);
	setup();
}
