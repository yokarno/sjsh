// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
inherit AXE;

void create()
{
             set_name( HIR "一级神兵"+ HIC"****"+HIY "战神斧"+HIC"****" NOR, ({ "axe", "fu" }) );
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
                   set("replace_file", "/d/obj/weapon/axe/xuanhua-fu");
  set("long", query("name")+HIW "是先古时期流传下来的兵器，威力巨大！\n");
          set("unwield_msg", CYN "$N一敛气，将$n在$N手中舞了个剑花，忽然不见了。\n");
          set("unwield_msg", "$N一敛气，将$n在$N手中舞了个剑花，忽然不见了。\n");
	}
init_axe(200);
	setup();
}
