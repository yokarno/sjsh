#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
set_name( HIY "太阳之神" NOR, ({ "sun staff", "sun", "staff" }) );
set_weight(100);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "根");
set("Can_avoid_find", 1);
set("value", 5000);
set("material", "gold");
set("long", "太阳之神，众神之颠”。\n");
set("wield_msg", "$N俊美的面宠上抹过一丝无情的冷笑，拿出一根"+query("name")+"握在手中，英姿飒爽，大有成者之势。\n");
set("unwield_msg", "$N将"+query("name")+"收回，天地为之黯然，不愧乃‘惊天地，泣鬼魂’之魔杖。\n");
}
init_staff(1000);
setup();
}
