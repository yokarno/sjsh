//Cracked by Roath
// Room: /moon/ontop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "七重 超俗天 ");
  set ("long", @LONG

你好不容易爬了上来,只觉得眼前忽然一亮,原来你已经置身
于天界之中了.这里就是"七重天",不过你看了看"千紫藤(qi
anzi teng)似乎还没爬到顶 ... ...
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "qianzi teng" : "一株高耸入云的紫色树藤 。上面开着无数的小花
正散发出阵阵清香,你可以(climb tree)试试能不能爬上去。
",
]));
  set("objects", ([ /* sizeof() == 2 */
     "/d/zj/npc/qi" : 1,
]));

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 3 */
//    "north" : "/d/calvin/lanling/kingziminggong",
]));

  setup();
}
void init()
{
  add_action("do_climb", "climb");
  add_action("do_kan", "kan");
}


int valid_leave(object me, string dir)
{
        object wugang;
    if (me->query("gender") == "男性" && dir == "north" ) {
        if(objectp(wugang=present("wu gang", environment(me))) && living(wugang) )

            return notify_fail("桂花树后转出吴刚，伸出一把大板斧拦住你道：\n慢着...院子里住的全是女人，你跑进去想干什么？\n");
    }
    return ::valid_leave(me, dir);
}

int do_climb(string arg)
{
	object wugang;
  object me=this_player();
 
  if( (!arg) || !((arg == "tree") || (arg == "桂树")))
    return notify_fail("爬什么？\n");
  if (me->is_busy()) return notify_fail("你现在正忙着呢。");
  if( me->query("kee") < (int)(me->query("max_kee")/3)){
    me->receive_damage("kee",(int)me->query("max_kee")*20/100);
    return notify_fail("你身子发虚，一头栽了下来，哎呀！\n");
}
  if (!((string)me->query("family/family_name")=="平民")
	 && objectp(wugang=present("wu gang", environment(me))) && living(wugang) )
    {
      message_vision("七重天神拦道：此间并非戏耍之处，请立即离开!\n", me);
    }
  else
    {
      if ((int)me->query_skill("dodge", 1)<145 && (int)me->query_skill("moondance", 1) < 100)
        {
	  message_vision("$N小心翼翼的往上爬了一点，觉得头晕眼花，就赶紧爬了下来．\n", me);
          me->improve_skill("dodge", 60-me->query("str"));
          tell_object(me, "你领悟出一些基本轻功方面的窍门。\n");
        }
      else
        {
          message_vision("$N轻轻地一腾就上了树藤,一会便消失在无尽的香花之中了。\n", me);
           me->move("/d/calvin/lanling/ba.c");
        }
    }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}

int do_kan(string arg)
{
  object me=this_player();
  object ob; 
  object wugang;
  if( (!arg) || !((arg == "tree") || (arg == "千紫藤")))
    return notify_fail("你要砍什么？\n");
    if (me->is_busy()) return notify_fail("你现在正忙着呢。");
   if( !(ob = me->query_temp("weapon"))|| (string)ob->query("skill_type") != "axe")
    return notify_fail("先去找把斧头吧！\n");
  if( me->query("kee") < (int)(me->query("max_kee")/3))
    return notify_fail("再砍下去手都要磨破了！\n");
  if (!((string)me->query("family/family_name")=="平民" )&&
	objectp(wugang = present("wugang", environment(me))) && living(wugang))
    {
      message_vision("八重天神拦道：此间并非戏耍之处，请立即离开!\n", me);
    }
  else
    {
      message_vision("$N朝千紫藤使劲儿砍了几下．\n", me);
      if ((int)me->query_skill("unarmed", 1)< 50 )
        {
          me->improve_skill("unarmed", me->query("str"));
          tell_object(me, "累得个快死，你总算领悟出一些运劲使力方面的窍门。\n");
        }
      else {
	tell_object(me, "你试着砍了几下，不明白为什么有人会做这种傻事。\n"); 
	}

    }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}
