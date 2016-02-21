#include <ansi.h>
inherit ROOM;

void init()
{
	add_action("do_knock", "knock");
}

int do_knock()
{
   object me,ob,*inv;
	string s;
	int i,num;

	me = this_player();

	inv = all_inventory(environment(me));
	if(sizeof(inv)>10)
	{
		printf(HIW "地上堆满了垃圾，你根本无法靠近墙壁！\n" NOR);
		return 1;
	}
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( !me->visible(inv[i]) ) continue;
		if(living(inv[i])&&!userp(inv[i]))
		{
			printf(HIW "你刚想敲一下墙壁，但是伸出去的手被怪物拉了开来！\n" NOR);
			return 1;
		}
	}
	
	s=query("where");
	num=query("beastnum");
	if(!s||num==0)return 1;
	for(i=0;i<1;i++)
	{
		ob=new(s,num,num,num);
		ob->move(environment(me));
	}
	printf(HIM "你敲了敲墙壁，突然从里面蹦出来几个怪物！\n" NOR);
	return 1;
}
