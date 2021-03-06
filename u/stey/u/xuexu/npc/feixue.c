inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
set_name(HIW"飞雪"NOR, ({"fei xue"}));
set("long",
"一个活泼中带着俏皮的妙龄少女，传说她就是柳絮的前生。\n");
set("title", HIM"少女"NOR);
set("gender", "女性");
set("age", 18);
set("class", "yaomo");
set("attitude", "friendly");
set("rank_info/respect", "小姑娘");
set("per", 30);
set("int", 30);
set("max_kee", 2900);
//       set("max_gin", 2600);
set("max_sen", 2800);
set("force", 3500);
set("max_force", 7000);
set("force_factor", 170);
set("max_mana", 3500);
set("mana", 7000);
set("mana_factor", 170);
set("combat_exp", 4800000);
set("daoxing", 4500000);
set("eff_dx", 200000);
set("nkgain", 350);

set_skill("literate", 180);
set_skill("unarmed", 180);
set_skill("dodge", 220);
set_skill("force", 220);
set_skill("parry", 220);
set_skill("sword", 220);
set_skill("spells", 220);
set_skill("whip", 230);
set_skill("moonshentong", 230);
set_skill("dragonfight", 220);
set_skill("snowsword", 230);
set_skill("moondance", 230);
set_skill("parry", 230);
set_skill("jueqingbian", 230);
map_skill("spells", "moonshentong");
map_skill("unarmed", "dragonfight");
map_skill("force", "moonforce");
map_skill("sword", "snowsword");
map_skill("parry", "snowsword");
map_skill("dodge", "moondance");
map_skill("whip", "jueqingbian");
//   set("chat_chance_combat", 50);
   set("inquiry", ([
"name": "我就是飞雪，柳絮的前生。",
"here": "此景非彼景，彼景非此景，君为何还不醒悟？",
"柳絮":"她是个冷酷绝情的女子，也许是我的另一面吧。",
]));
set("chat_chance",5);
set("chat_msg", ({
HIW"飞雪轻声告诉你: 我就是飞雪，我佛如来告诉我，我就是柳絮的前生。\n"NOR,
HIW"飞雪轻声告诉你:雪舞庭前不沾衣，絮落流水无人怜。\n"HIC,
HIW"飞雪轻声告诉你:活泼而温情表露于外的我，一点都不象我的名字那么冷。
真正冷酷而绝情的是一个拿着蓝色情丝的女子。\n"NOR,
HIW"飞雪轻声告诉你:柳絮如雪，而飞雪如风。\n"NOR,
HIW"飞雪轻声告诉你:她那么冷傲，那么孤独，和春天飘扬的柳絮一点都不符合。
她也杀人无数，曾经只身一人以一条情丝在雪山绝顶独战三大雪山高手，最后长鞭起处，
无人幸免。\n"NOR,
HIW"飞雪轻声告诉你:她就一点和我相同，就是讨厌鲜血。每当她确定手中的情丝已经缠上了对手
的喉咙，她总是冷冷的看着对手临死前的眼睛，然后不等对手的冒出美丽的血花，就转身而去。\n"NOR,
HIW"飞雪轻声告诉你:飞雪就是柳絮，柳絮也是飞雪。在不同的季节里交互飞扬于天空。\n"NOR,
}));

create_family("月宫", 2, "弟子");
setup();
set("chat_msg_combat", ({
(: cast_spell, "arrow" :),   
        }) );
set("inquiry", ([
]));

carry_object("/d/moon/obj/luoyi")->wear();
}
