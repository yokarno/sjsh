inherit ROOM;

void create()
{
	set("short", "方丈室");
	set("long", @LONG
方丈室陈设简洁，正中一几，一蒲团，一矮床。北面墙上写
着大大的一个『禅』字。一位慈眉善目的灰衣老僧正端坐于蒲团
上打坐。
LONG );
	set("exits", ([
		"out" : __DIR__"fzlou",
	]));
	set("objects",([
		__DIR__"npc/xuan-ci" : 1,
	]));

	setup();
	replace_program(ROOM);
}


