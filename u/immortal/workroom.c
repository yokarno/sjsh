#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIW"神 宫 大 殿"NOR);
set ("long",@LONG

           上  天  下  地         唯  我  独  尊

  out : 出去南城客栈。
  enter : 进去神宫大仙的客厅。
  south : 去神宫大仙的天牢。

LONG);
set("exits",([
"out" : "/d/city/kezhan",
"enter" : __DIR__"parlour",
"south" : __DIR__"prison",
]));
set("outdoors", 0);
set("no_clean_up", 1);
set("valid_startroom", 1);
setup();
}
void init()
{
object who=this_player();
if( (string)who->query("gender")=="男性" || (string)who->query("gender")=="女性" )
add_action("do_stop", "exert");
add_action("do_stop", "cast");
add_action("do_stop", "kill");
add_action("do_stop", "fight");
add_action("do_stop", "perform");
add_action("do_stop", "apply");
add_action("do_stop", "sleep");
add_action("do_stop", "exercise");
add_action("do_stop", "meditate");
{
call_out("heal_up", 9, who);
}
remove_call_out("sounding");
call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
string *msgs=({
HIG"地上飘出躲躲祥云。\n"NOR,
HIM"九彩祥云围绕着你上飘下浮。\n"NOR,
HIY"祥云把你全身都包围起来。\n"NOR,
HIC"你觉得全身上下说不出的舒畅。\n"NOR,
});
tell_room (where,msgs[random(sizeof(msgs))]);
}
int heal_up(object who)
{
if( !who || environment(who) != this_object() )
{
return 1;
}
who->set("eff_gin", (int)who->query("max_gin"));
who->set("eff_kee", (int)who->query("max_kee"));
who->set("eff_sen", (int)who->query("max_sen"));
message_vision(HIW"阵阵祥云飘向$N，$N深深吸了几口气。\n"NOR, who);
write(YEL"你觉得自己的精神气血一下子都恢复了。\n"NOR);
if( (int)who->query("food") < (int)who->max_food_capacity() )
who->set("food", (int)who->max_food_capacity());
if( (int)who->query("water")< (int)who->max_water_capacity())
who->set("water", (int)who->max_water_capacity());
return 1;
}
int do_stop(string arg)
{
object who = this_player();
object me = this_object();
message_vision(HIR"天上传来"NOR+HIC"神宫大仙"NOR+HIR"一声怒嚎：“这里乃我私家重地，岂容$N胡乱捣乱！”\n"NOR,who);
return 1;
}
