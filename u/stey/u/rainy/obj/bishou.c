#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
set_name( HIW "匕首" NOR, ({ "bi shou", "bishou", "dao" }) );
set_weight(100);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("Can_avoid_find", 1);
set("value", 5000);
set("material", "gold");
set("long", "冷白色的匕首，刀尖闪过一丝寒光，丰利无比，一滴殷红的鲜血正从刀尖上滴下来”。\n");
set("wield_msg", HIW"$N看到自己冰凉的泪在空中划了一个漂亮的弧，轻叹道“人生何许，独守情冢”，将手里的"+query("name")+HIW"慢慢的剌向手腕上的那根动脉......\n"NOR);
set("unwield_msg", HIW"$N手中的匕首掉落在地，发生一声清脆的响声，雪白的手腕正流着殷红的血，整个世界忽然昏头转向起来，她发现自己在慢慢的飘着...飘着，离“情冢”越来越远，那个方向叫“天  堂”。\n"NOR);;
}
init_blade(100);
setup();
}
