inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","杀手药铺" );
  set ("long", @LONG

            打  斗  伤  身         灵  药  治  疗

LONG);
  set("exits", (["down" : __DIR__"pkdao",]));
  set("objects", ([__DIR__"npc/boss" : 1,]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", 0);
  setup();
}
void greeting(object who) {
if( who->query("combat_exp") < 500000)
{
message_vision(HIR"天上传来一声怒嚎：“$N武学不够50万了，请回去把！”\n"NOR,who);
who->move("/d/city/kezhan");
}
}