inherit ROOM;

void create ()
{
  set ("short", "花园");
  set ("long", @LONG

前面出现了个巨大的花园，正中间的喷水池有三亩地方圆，两旁的停车场上
停放着许多叫不上名字的高级轿车，甚至还有几辆装甲车混杂其间，
前面的一幢大楼宏伟气派，大楼表面的玻璃上贴着一行大字：

      说你行你就行不行也行   说不行就不行行也不行
LONG);
    set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gate.c",
  "north" : __DIR__"menwei.c",
]));
        setup();
}
