#include <weapon.h>
inherit SPEAR;
void create()
{
        set_name("微型冲锋枪", ({"wei chong", "qiang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把微型冲锋枪，精巧的制造显示着不一般的火力．\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg", "$N从身后解下一把$n，喀碴一声拉了下枪栓，瞄准了你。\n");
                set("unwield_msg", "$N将手中的$n关上保险，背在了身后。\n");
        }
        init_spear(25);
        setup();
}
