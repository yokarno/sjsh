// 神话世界·西游记之（世纪）
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

一条整洁的碎石路面，路面虽然不是很宽，但是人来人往的也是一片繁荣
的景象。街道是东西走向，往东是一眼清泉。
LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao11",
        "east"   : __DIR__"qingquan",
        "northeast"   : __DIR__"jiedao10",        
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

