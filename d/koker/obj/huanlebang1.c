// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
// 欢乐棒 huanlebang.c
// lizuole 99.12.14
 
#include <weapon.h>

inherit STICK;
inherit F_UNIQUE;

void create()
{
        set_name("欢乐棒", ({"huanle bang", "bang"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
     set("no_sell", 1);
     set("long", "一把淡绿色的玉棒，入手滑腻，颇有些份量。\n");
                set("value", 20000);
                set("material", "steel");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
     set("replace_file", "/d/lizuole/obj/qimeigun");
        }
        init_stick(80);
        setup();
}

