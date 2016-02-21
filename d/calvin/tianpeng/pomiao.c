#include <ansi.h>
inherit ROOM;
void create()
{
set ("short","破庙");
set ("long",@LONG
这是一座破旧不堪的小庙宇,地上零星的撒落着一些大大
小小的香炉,看得出曾几何起这里也是香火鼎沸,可是那都是
昔日的事了.
LONG);
set("exits",([
"east" : __DIR__"luw3",
]));
set("outdoors", 0);
set("chat_room",1);
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
HIG"砰~~~~墙上掉下来一块石头。\n"NOR,
"那石头差点砸到了你,好险啊。\n"NOR,
HIY"忽然一个黑影在你面前闪过。\n"NOR,
HIC"你随之产生了一种莫名其妙的感觉。\n"NOR,
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
message_vision(HIW"砰~~~屋顶又掉下一块瓦片,刚好砸到了$N，$N差点没晕过去。\n"NOR, who);
write(YEL"你抬头看看了破旧的屋顶,看样子这里并不安全。\n"NOR);
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
message_vision(HIR"天上传来"NOR+HIC"泥菩萨"NOR+HIR"一声怒嚎：“谁让$N来我这宝地的,还不给我滚出去！”\n"NOR,who);
return 1;
}
