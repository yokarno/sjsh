//changan city

inherit ROOM;

void create ()
{
        set ("short", "重要书籍专卖");
        set ("long", @LONG

这是长安城一家新开的书店，相传现在的老板是皇宫中的格格，品
牌绝对可以保证。专卖店的摆设也十分考究，桌椅被勤快的小姐擦的
干干净净。墙上挂满了别人送来的庆贺开张的牌匾。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/city/guozi",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/u/wen/npc/xixi" : 1,
        ]));
          set("no_time",1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);  


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


