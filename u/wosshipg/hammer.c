// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
    inherit HAMMER;

void create()
{
               set_name( HIR "一级神兵"+ HIC"****"+HIY "战神锤"+HIC"****" NOR, ({ "hammer", "chui" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                  set("unit", "把");
                  set("no_give", "这么好的兵器你也要给人？？");
        set("value", 1000000000000);
      set("no_sell","小店小本经营，买不起这么贵重的宝物。\n");
		set("material", "gold");
                  set("no_drop", "怎么，连这轩辕先祖用过的兵器都舍的扔？");
                 set("replace_file", "/d/obj/weapon/sword/snowsword");
                  set("long", "此剑是轩辕先帝曾经使用的兵器，锋利无比，威力巨大，手柄上刻着：“轩辕”二字。\n");
          set("wield_msg", "$N一伸手，连喝几声：赐与我力量吧，我是黑曼！手中立时多了一把$n。\n");
          set("unwield_msg", "$N一敛气，将$n在$N手中舞了个剑花，忽然不见了。\n");
	}
         init_hammer(200);
	setup();
}
