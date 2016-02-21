
//Room: bashisipan1.c 八十四盘
//Date: Oct. 2 1997 by That

inherit ROOM;
#include <ansi.h>
void create()
{
	  set("short","八十四盘");
	  set("long",@LONG
这是著名的「八十四盘」，道路艰险陡峭，迂回盘折，令人不能喘息。路
左是蔽日遮天的冷杉林，路右是深不见底的绝壁峡谷。由此往上至接引殿，北
下到「九十九道拐」。
LONG);
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
          "southeast"  : __DIR__"jieyindian",
          "eastdown"  : __DIR__"jsjdg",
	  ]));
	  set("no_clean_up", 0);
	  setup();
}
int valid_leave(object me, string dir)
{
	  int c_exp,c_skill;
	  me = this_player();
	  if (dir == "southeast" )
	  {
	 c_exp=me->query("combat_exp");
	 c_skill=me->query_skill("dodge",1);
	 me->add("kee",-100);
	 if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		 me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	 tell_object(me,HIW"你爬上八十四盘，终于到接引殿了，真累人。\n\n"NOR);
	  }
	  return 1;
}

