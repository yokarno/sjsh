// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit UNARMED;

void create()
{
        set_name("格斗指环", ({"gedou zhihuan", "ring", "zhihuan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
"拳师专用。\n");
                set("value", 5000);
                set("material", "diamond");
                set("wield_msg",
"$N戴上一个$n。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_unarmed(60);
        setup();
}

