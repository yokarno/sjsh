#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIG"小黑儿"NOR,({"xiao", "xiao heier"}));
set("long","晶莹的老公黑儿。\n");
set("title",HIM"晶莹的最爱"NOR);
set("gender","男性");
  set("per",40);
  set("age",22);
  set("str",35);
  set("con",30);
  set("int",30);
  set("max_kee", 1000);
  set("eff_kee", 1000);
  set("kee", 1000);
  set("max_force",2000);
  set("force",400);
  set("combat_exp", 1000000);
    set("inquiry",([
"heier":"我是黑黑的帅帅的神气的大老爷小黑儿，找我有事吗？\n",
"keren":"老婆,没有茶叶了,怎么办?\n",
"love": "我最爱我的莹儿，我知道莹儿也爱我！\n",
"黑儿":"我是黑黑的帅帅的神气的大老爷小黑儿，找我有事吗？\n",
"fayu": "她是我老婆啊！是小黑儿的宝贝晶莹！\n",
"晶莹": "她是我老婆啊！是小黑儿的宝贝晶莹！\n",
        ]));
  set("chat_chance",5);
set("chat_msg", ({
HIG"黑儿轻声告诉你:我最喜欢我的老婆，宝贝和小丫头！\n"NOR,
HIG"黑儿又在盼了:莹儿，怎么还不来啊！\n"NOR,
             }));
setup();
}
