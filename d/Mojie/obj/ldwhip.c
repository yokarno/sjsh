#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIG"六毒鞭"NOR, ({"liudu whip", "whip", "lian"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一条长长的鞭子，上面沾满了血．\n");
                set("unit", "条");
                set("value", 500);
        }
        init_whip(125);
        setup();
}

