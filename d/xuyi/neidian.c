// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "内殿");
  set ("long", @LONG

    这里是一个大殿，殿内香烟燎绕，幔角叮咚。堂上供着西天诸佛，
计有八菩萨，四金刚，五百阿罗，三千揭谛，十一大曜，十八伽蓝，以
及众优婆塞，优婆夷等。直看得你眼花缭乱。东西边各放着一对美轮美
奂的大花瓶，上插檀香数枝，室内一片祥和之气。
LONG);

  set("exits", ([
  "southdown" : "/d/xuyi/taijie",
  "west" : __DIR__"zoulang",
]));

  setup();
  replace_program(ROOM);
}

