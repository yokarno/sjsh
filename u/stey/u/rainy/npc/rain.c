#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIM"舟儿"NOR,({"rain"}));
set("long","一个十八九岁的姑娘，脸上是阳光般的笑容，有惊鸿落雁之容。\n");
set("title",HIY"衣青的乖乖老婆"NOR);
set("gender","女性");
set("per",40);
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
"rainy": "那个成天疯疯闹闹，想哭就哭，想笑就笑的丫头就是我！我深爱着我老公，虽然我很皮，总爱私下里捉弄他，可是我心里总是牵挂着他......\n",
"舟儿": "那个成天疯疯闹闹，想哭就哭，想笑就笑的丫头就是我！我深爱着我老公，虽然我很皮，总爱私下里捉弄他，可是我心里总是牵挂着他......\n",
"yiq": "没有看到办公桌上的那张“全家福”的照片嘛？女主角是我，男主角当然就是衣青啦！这下你明白了吧？嘻嘻\n",
"衣青": "没有看到办公桌上的那张“全家福”的照片嘛？女主角是我，男主角当然就是衣青啦！这下你明白了吧？嘻嘻\n",
"love": "别问我爱情是什么，如果你真想知道答案，去“情冢”就明白了。不过，过去的我已经死了，现在站在你面前的是一只刚从茧里飞出来的蝴蝶。\n",
 ]));
set("chat_chance",9);
set("chat_msg", ({
HIM"舟儿微笑着对你说:我没有发呆，我是在等老公回来。他说七月份要给我讲故事，像从前那样！\n"NOR,
HIM"舟儿微笑着对你说:我像一叶浮萍，东漂西荡，总也无个定数。终于，我找到了根。\n"NOR,
}));
setup();
carry_object("/u/rainy/hunsha")->wear();
carry_object("/u/rainy/obj/rose")->wear();
carry_object("/u/rainy/obj/xue")->wear();
carry_object("/u/rainy/obj/star")->wield();
}
