
//Room: jsjdg4.c ��ʮ�ŵ���
//Date: Oct. 2 1997 by That

inherit ROOM;
#include <ansi.h>


void create()
{
	  set("short","��ʮ�ŵ���");
	  set("long",@LONG
���������ġ���ʮ�ŵ��ա�����·����������ǧ�۰ٻء���˵��ȥ���и�
����ķ�ɮ���ˣ���һ������·�������������������ǵ�֪�˴��о�����û��
������Ҳ���˸�������Ĳ�ľ�����ԡ����ӡ���֮���ɴ�����������ʮ���̡�
�����µ��׶�ƺ��
LONG);
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
          "westup"  : __DIR__"bashisipan",
	  "eastdown" : __DIR__"leidongping",
	  ]));
	  set("no_clean_up", 0);
	  setup();
}
int valid_leave(object me, string dir)
{
	  int c_exp,c_skill;
	  me = this_player();
          if (dir == "westup" )
	  {
	 c_exp=me->query("combat_exp");
	 c_skill=me->query_skill("dodge",1);
	 me->add("kee",-100);
	 if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		 me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	 tell_object(me,HIW"���ؾ�ʮ�ŵ�������������һ������������ʮ���̣������ˡ�\n"NOR);
	  }
	  return 1;
}
