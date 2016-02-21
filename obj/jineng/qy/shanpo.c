// 药材 路径 shanxia by Calvin
#include <room.h>
inherit ROOM;
int grass_number;
void create()
{
  set ("short", "山坡");
  set ("long", @LONG

这里是山坡之上,一眼看过去全是光溜溜的石头,到是再上一点
似乎有个小小的山洞。这里的山坡上长着的小草似乎像是一种
上等的药材,你可以试试采集一点带回去研制一下。

LONG);

  set("exits", ([ 
  ]));

  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
  add_action ("do_jump","jump");
 add_action("do_dig", "dig");
 grass_number=1;
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N奋力向上爬去。\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 100)
  {
    message_vision ("$N手一松连人带石哗啦一声滑了下来。\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-100);
  who->move(__DIR__"shanpo1");
  return 1;
}

int do_jump (string arg)
{
  object who = this_player();
  message_vision ("$N奋力向下跳去。\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 100)
  {
    message_vision ("$N手一松连人带石哗啦一声滑了下来。\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-100);
  who->move(__DIR__"shanxia");
  return 1;
}


 int do_dig(string arg)
{
   object me = this_player();
   object cao;
   if ( !arg || ( arg != "grass" ) ) 
     return notify_fail("你要拔什么？\n");
   else if(grass_number==0)  
     return notify_fail("药草已经被拔光了，别费劲了。\n");
   else if(me->query("kee")<100) 
     {
     me->unconcious();
     return 1;
     }
   else 
     {
     me->add("kee",-100);
     cao = new ("/obj/jineng/medicals/tianqi.c");
     cao->move(me);
     message_vision("$N拔了一颗药草。\n", me);
     grass_number--;
     }
     return 1;
}
