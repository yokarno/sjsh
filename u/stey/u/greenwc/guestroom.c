// Room: /u/yudian/workroom.c
inherit ROOM;
void create ()
{
    set ("short", "客房");
  set ("long", @LONG

这是一间客房，收拾得干干净净。
屋里有个大美女会全心全意为可以服务。
LONG);

     set("exits", ([
                "west" : __DIR__"workroom",
     ]));    
  set("outdoors", 0);
      set("objects", ([
            __DIR__"waiteress" : 1,
              __DIR__"new_jing" : 1,
    ]));           
  setup();
}
