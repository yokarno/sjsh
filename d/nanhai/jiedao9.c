// 神话世界·西游记之（世纪）
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
  set ("short", "太和街");
  set ("long", @LONG

太和街从蠙城中心广场直达东门外，延伸三里，是城内主要街道。街面是
由碗口大的彩色石块铺成，青兰紫绿，煞是好看。南面是一座高大的竹楼。
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao10",
        "west"   : __DIR__"jiedao8",
        "south"  : __DIR__"feiyue",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

