// by Repoo
#include <ansi.h>
inherit ROOM;

void create ()
{
   set ("short", RED" 众神之殿 "NOR);
  set ("long", @LONG

这里是神殿的大厅。这里一切都是那么的祥和，神殿中心有一个
祭台。你走过去一看，原来是一块神铁铸成的图画。上面画了五
样东西，铁锅、火山、农田、河流和森林。其上五个箭头分别指
向旁边的五个房间。

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"shendian_jin",
  "west" : __DIR__"shendian_shui",
  "east" : __DIR__"shendian_huo",
  "north" : __DIR__"shendian_tu",
  "south" : __DIR__"shendian_mu",
]));
  set("objects", ([
  __DIR__"obj/shaogong" : 1,
  __DIR__"obj/nongfu" : 1,
  __DIR__"obj/tiejiang" : 1,
  __DIR__"obj/chuzi" : 1,
  __DIR__"obj/famugong" : 1,
]));
  set("no_time",1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_quit",1);
  set("no_flee",1);
  set("alternative_die",1);
  setup();
}
void init()
{       object obj;
        object ob = this_player();
       if (ob->query_temp("nongfu") 
        &&ob->query_temp("famugong")
        && ob->query_temp("chuzi")
        && ob->query_temp("shaogong")
        && ob->query_temp("tiejiang")
               )
   {
       call_out( "shendian_stage", 3, ob, 0 );
  /*
        message_vision(HIR"金 木 水 火 土，五行再现生万物！\n"NOR,ob);
          message_vision(HIR"八部天龙，以天为首，既过此界，非枯非荣。\n"NOR,ob);
        message_vision(HIR"众神曰：现封$N为八部天龙之天神。\n"NOR,ob);
        ob->set("title",HIR"八部天龙之天神"NOR);
 message("channel:rumor",HIY+"\n【"+HIR" 众神之殿 "NOR+HIY"】众神曰："+HIR""+ob->query("name")+""NOR+HIY" 破解万物之密，被封为"NOR+HIR" 八部天龙之天神 "NOR+HIY"\n\n"+NOR,users() );
        ob->move("/u/repoo/mofamen/tianshentai");
   ob->delete_temp("nongfu");
   ob->delete_temp("famugong");
   ob->delete_temp("shaogong");
   ob->delete_temp("tiejiang");
   ob->delete_temp("chuzi");
   ob->delete_temp("chilong_killed");
   ob->delete_temp("heilong_killed");
   ob->delete_temp("gulong_killed");
   ob->save();
   */
   }
}
void shendian_stage(object ob, int stage)
{
      message_vision(HIR"\n金 木 水 火 土，五行再现生万物！\n\n"NOR,ob);
         message_vision(HIR"八部天龙，以天为首，既过此界，非枯非荣。\n\n"NOR,ob);
         message_vision(HIR"无欲无求，万物皆空，早登大乘。\n\n"NOR,ob);
        message_vision(HIR"众神曰：现封$N为八部天龙之天神。\n\n"NOR,ob);
        message_vision(HIR"一道彩虹突然出现，很快包围了$N。\n\n"NOR,ob);
        message_vision(HIW"$N不见了。\n\n"NOR,ob);
    ob->set("title",HIR"八部天龙之天神"NOR);
message("channel:rumor",HIY+"\n【"+HIR" 众神之殿 "NOR+HIY"】众神曰："+HIR""+ob->query("name")+""NOR+HIY" 破解万物之密，被封为"NOR+HIR" 八部天龙之天神 "NOR+HIY"\n\n"+NOR,users() );
   ob->move("/u/repoo/mofamen/tianshentai");
   ob->delete_temp("nongfu");
   ob->delete_temp("famugong");
   ob->delete_temp("shaogong");
   ob->delete_temp("tiejiang");
   ob->delete_temp("chuzi");
   ob->delete_temp("chilong_killed");
   ob->delete_temp("heilong_killed");
   ob->delete_temp("gulong_killed");
   ob->save();
                return;
}
