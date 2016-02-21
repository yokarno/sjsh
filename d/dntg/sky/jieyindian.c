 // Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "接引殿");
  set ("long", @LONG

进了南天门，已经可以看到一座座天宫放着七彩霞光，忽隐忽现
于云遮雾绕之中。里壁厢有几根大柱，柱上缠绕着金鳞耀日赤须
龙；一座白玉桥弯弯曲曲地向北延伸，东西两边各有一座大殿，
也不知是干什么用的，你可以隐约听到东边殿中有喧哗之声，似
乎人不少。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"nantian",
  "north" : __DIR__"caihongqiao",
  "west" : __DIR__"caifengdian",
  "east" : __DIR__"jinlongdian",
]));

  create_door("south", "南天门", "north", DOOR_CLOSED);
        set("no_clean_up", 0);

  setup();
}
void init()
{
       add_action("do_shen", "sheng");
}

int do_shen(string arg)
{
   object me;
	string s;
	int my_exp,my_level,temp,price,afford;

	me = this_player();
	my_exp=me->query("combat_exp");
	my_level=me->query("level");
	temp=(my_level+1)*(my_level+1)*100;
	if(my_exp>=temp)
	{
		price=10*10000*(my_level+1);		  
		if( afford = me->can_afford(price) ) {
			me->pay_money(price, 0);
			                                                                    temp=me->query("scorepoint")+(my_level/10+100)*100;
			me->set("level",my_level+1);
			me->set("scorepoint",temp);
			me->set("kee",me->query("max_kee"));
			me->set("mana",me->query("max_mana"));
			message_vision("$N静静的闭上眼睛，人突然显得神采奕奕起来！\n", me);
			printf(HIW "你的级别得到了提升！\n" NOR);
		}
		else
		{
			printf(HIW"你没有足够的钱来为三界造福，升级到" HIY "%d" HIW "级的捐助为" HIM "%d" HIW "金！\n "NOR,
				my_level+1,price/10000);
		}
	}
	else
		printf(HIW "你的武学不够训练成" HIY "%d" HIW "级，需要你的武学达到" HIM "%d" HIW "才行！\n" NOR,
				my_level+1,temp);
	return 1;
}

 
