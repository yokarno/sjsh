// Room: /d/shaolin/gulou7.c
// Date: YZC 96/01/19

inherit ROOM;


void create()
{
        set("short", "鼓楼顶层");
	set("long", @LONG
这里就是鼓楼之顶。直入眼帘的便是一只大鼓。大鼓鼓身通红，
似由白杨木箍成。两头包以水牛皮，用一匝大铜钉钉在鼓身边缘。
鼓心有一圈白渍，看来是因为多次击打形成的。整个大鼓放在一
个一人高的架子上，架子底层搁着两根大鼓槌。尽管山风吹人欲
倒，谁都禁不住想击一下鼓试试。往外看，有个很大的汉
白玉窗台，上面足可站一个人。
LONG );
	set("exits", ([
                "out" : __DIR__"gulou",
	]));
	set("objects",([
                __DIR__"npc/saodiseng" : 1,
                        ]));
//	set("no_clean_up", 0);
	setup();
}


