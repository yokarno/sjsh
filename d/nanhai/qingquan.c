// 神话世界·西游记之（世纪）
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "清池");
  set ("long", @LONG

在这里你能享受到城内少有的清净。清池是天然的温泉，在园林工匠的修
葺下，更添姿彩。池内鱼虾龟虫倒也养了不少，在这四季如春的气候下，
荷花睡莲无比妖娆。
LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao12",     
      ]));
  set("objects", ([
        __DIR__"npc/girl"   : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}

