//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","剑客警示厅");
  set ("long", @LONG

这里就是东瀛剑客警示厅，几个腰配长剑的剑客警官正用警惕的眼神
扫视着来往的行人。
LONG);
   set("exits", ([      
       "west" : __DIR__"dalu10",
       "east" : __DIR__"workroom",
  ]));
   set("objects", ([ 
      __DIR__"npc/jingguan" : 2,
       ]));

  setup();
}









