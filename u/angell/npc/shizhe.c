#include <ansi.h>
#include <mudlib.h>
inherit NPC;
string ask_me();
int ask_cake();
void create()
{
        set_name(HIG "泉州站生日大使" NOR, ({ "liwu shi","shi zhe","shi" }) );

        set("gender", "男性");
        set("age", 19);
        set("per",40);
        set("attitude", "peaceful");
        set("inquiry", ([
                 "生日礼物" : (: ask_cake :),  
                 "奖励" : (: ask_cake :),  
        ]));
        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
int ask_cake()
{ 
        object ob;
        if (this_player()->query("birthday"))    {
            command("say 恭喜恭喜，祝你生日快乐！\n");
          ob=new("/u/angell/obj/cake");  //礼物的路径，自定义。
          ob->set("owner",this_player()->query("id"));
          ob->move(this_player()); 
          message_vision("\n$N给了$n一个特制的生日蛋糕。\n",  this_object(),this_player());
          this_player()->delete("birthday"); 
         return 1;            }
      return 0;
}
