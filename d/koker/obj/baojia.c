
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY "真丝宝甲" NOR, ({ "bao jia", "jia" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\n这是李作乐为雪儿特做的真丝宝甲。\n");
                set("unit", "件");
		set("no_drop","宝物是扔/卖不了的，也不能给别人。");
                set("value", 5000);
                set("no_sell", "这个东西不能卖。\n");
                set("material", "gold");
                set("armor_prop/armor", 50);
        }
        setup();
}

