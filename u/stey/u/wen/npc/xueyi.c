//xiaojie.c

inherit F_VENDOR_SALE;
// inherit NPC;
void create()
{
        

	set_name("雪怡", ({"boss xueyi", "xueyi","boss"}));
	set("gender", "女性" );
	set("age", 21);
        set("title", "专卖店小姐");
	set("long", "巫师无双派来凡间体恤民情的,由于雪怡驻地盛产药材,故她这个女孩身上带了不少名贵药材。\n");
	set("combat_exp", 26000);
	set("attitude", "peaceful");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set("per", 40);
	set("max_kee", 350);

        set("vendor_goods", ([
                "mihoutao" : "/u/wen/obj/drug/mihoutao",
         "dan" : "/u/wen/obj/drug/dan",
         "smoke" : "/u/wen/obj/drug/xiangyan",
         "jiaoli" : "/u/wen/obj/drug/jiaoli",
         "huozao" : "/u/wen/obj/drug/huozao",
         "biou"   : "/u/wen/obj/drug/biou",
	 "tdhgdan"   : "/u/wen/obj/drug/huagongdan",
	 "tdzhdan"   : "/u/wen/obj/drug/zhuanhuadan",
	 "huagongdan"   : "/u/wen/obj/drug/dan2",
	 "zhuanhuadan"   : "/u/wen/obj/drug/dan3",
         "bawangdan"   : "/u/wen/obj/drug/bawangdan",
         "panshi"      : "/u/wen/obj/drug/panshidan",
        ]) );


	setup();
	carry_object("/d/obj/cloth/sunglass")->wear();
       add_money("coin", 100);

        
}

void init()
{
   add_action("do_vendor_list", "list");
}


int ask_name() {
  this_object()->command("shutup xiao jie");  
  return 1;
}
