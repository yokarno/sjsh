#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIC"小欣如意"NOR,({"ruyi"}));
set("long","一个很容易满足的小女孩，约摸二十岁的样子，
笑起来甜甜的，让人觉得好象喝了蜜。\n");
set("title",HIC"容易满足的MM"NOR);
set("gender","女性");
set("per",30);
set("age",19);
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
"ruyi": "我是总站的“小欣如意”，呵呵，我最喜欢聊天和发呆，有时也练功，不过通常是为了等他上线才发呆的.....xixi\n",
"小欣如意": "我是总站的“小欣如意”，呵呵，我最喜欢聊天和发呆，有时也练功，不过通常是为了等他上线才发呆的.....xixi\n",
"age": "我19岁，mudage和生活中的age一样样，^_*......\n",
]));
setup();
carry_object("/u/rainy/obj/feicui")->wear();
}

