// Room: /d/shaolin/cjlou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�ؾ���һ¥");
	set("long", @LONG
����Ϊ��ԭ�𷨵���Դ�������´˴��ؾ�֮�������º�����
ƥ�����ﶼ���������飬�߼��������ܣ���ܼ��������һ��
ͨ�еĿ�϶�����Ŵ�����м䣬����ط������ɳ���������Ŀ��
�������㿴�����Ϸ��˼����𾭡�
LONG );
	set("exits", ([
                "east" : __DIR__"hsyuan4",
		"up" : __DIR__"cjlou1",
	]));
	set("objects",([
                "d/shaolin/obj/book-iron.c":1,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{

    mapping myfam;
    me = this_player();
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "������")) && (dir == "up"))
      return notify_fail("�����ֵ��ӣ�����ֹ���ɡ�\n");
    else  return 1;
}


