#include <ansi.h>
inherit MONEY;

void create()
{
    set_name(HIW"眼泪"NOR, ({ "gold" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("money_id", "gold");
        set("long", "月凉如水，天边划过一丝清亮的光，滴在手腕上，凉丝丝的，原来是一滴泪。\n");
        set("unit", "滴");
        set("base_value", 1000000);
        set("base_unit", "滴");
                set("base_weight", 3);
        }
        set_amount(1);
}

