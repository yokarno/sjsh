// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
inherit MACE;

void create()
{
               set_name( HIR "一级神兵"+ HIC"****"+HIY "战神锏"+HIC"****" NOR, ({ "mace", "jian" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                  set("unit", "把");
                  set("no_give", "这么好的兵器你也要给人？？");
        set("value", 1000000000000);
      set("no_sell","小店小本经营，买不起这么贵重的宝物。\n");
		set("material", "gold");
set("no_drop", "怎么，连这样的兵器都舍的扔？");
                 set("replace_file", "/d/obj/weapon/sword/snowsword");
  set("long", query("name")+HIW"是先古时期流传下来的兵器，威力巨大！\n");
    set("wield_msg", HIW "$N脸上杀气一现，手中立时多了一把$n。\n");
      set("unwield_msg", HIY "$N一敛气，将$n藏了起来。\n");
	}
init_mace(200);
	setup();
}
