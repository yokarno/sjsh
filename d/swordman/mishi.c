//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","密室");
  set ("long", @LONG

一间干净整齐的密室，密室中间的床上躺着一个面色苍白的
俊美剑客。
LONG);
   set("exits", ([      
              "west" : __DIR__"woshi",
  ]));
   set("objects", ([ 
      __DIR__"npc/zongsi" : 1,
       ]));

  setup();
}









