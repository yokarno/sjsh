#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "卧室");
  set ("long", @LONG

           江  湖  杀  戮         适  时  退  隐

LONG);
  set("exits", (["up" : __DIR__"pkdao",]));
  set("outdoors", 0);
  set("sleep_room",1);
  set("if_bed",1);
  setup();
  replace_program(ROOM);
}
void greeting(object who) {
if( who->query("combat_exp") < 500000)
{
message_vision(HIR"天上传来一声怒嚎：“$N武学不够50万了，请回去把！”\n"NOR,who);
who->move("/d/city/kezhan");
}
}