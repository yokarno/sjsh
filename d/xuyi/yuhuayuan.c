// 神话世界·西游记之（世纪）
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "御花园");
  set ("long", @LONG

这里是蠙城皇宫的御花园，两旁的百花齐放，争奇斗艳，边上有一个小水
池，山上流下来的泉水就汇集在这里，水池边有一只异兽正在俯首喝水。
只见它身披龙鳞，鹿角鲤须，竟然是传说中的麒麟。
LONG);

  set("exits", ([
        "north"   : __DIR__"hualang",
        "south"  : __DIR__"qiandian",
      ]));
  set("objects", ([
        __DIR__"npc/qilin" : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

