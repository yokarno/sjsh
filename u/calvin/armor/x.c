#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("蚂蝗刀", ({"mahuang dao", "dao"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500);
                set("material", "stone");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，样貌令人恶心！\n");
                set("unwield_msg", "$N将手中的$n插入石头做的刀鞘里。\n");
        set("weapon_prop/courage", 15);
        }
        init_blade(50);
        setup();
}
