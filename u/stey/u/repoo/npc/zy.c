//repoo
#include <ansi.h>
inherit NPC;
void create()
{
       set_name(""HIM"紫叶"NOR"", ({"zi ye","mishu"}));
	set("long", "她是红叶的秘书。\n");
	set("gender", "女性");
	set("age", 20);
	set("per", 50);
          set("title",HIR"红叶"+WHT"的秘书"NOR);
	set_skill("literate", 141);
	set("chat_chance",20);
	setup();
//	carry_object("/u/repoo/obj/cloak")->wear();
}
void init()
{
	::init();
  add_action("do_listmp","listmp");
  add_action("do_suoqu","suoqu");
}
void die()
{
 return;
}
int do_listmp(string arg)
{
	object who = this_player();
	object me = this_object();
  message("vision",""HIG"\n─────────────────────────────────────
          \n"HIY"门派："HIR"
          1. 南海普陀山(putuo)     2. 乱石山碧波潭(bibotan)  
          3. 昆仑山月宫(moon)      4. 灵台方寸山(fangcun)
          5. 阴曹地府(hell)        6. 东海龙宫(longgong)
          7. 枯松涧火云洞(hyd)     8. 陷空山无底洞(wdd)
          9. 万寿山五庄观(wzg)    10. 大雪山万兽谷(xueshan)
         11. 大唐将军府(jjf)      12. 万剑之尊蜀山(shushan)
"HIG"\n─────────────────────────────────────\n"NOR"",who,me);
  return 1;
}
int do_suoqu(string arg)
{
	string type;
	object ob;
	object who=this_player();
	object me=this_object();
    if (who->query("id") != "repoo")
		return notify_fail("别想!\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
case "putuo":
           who->set_skill("staff",400);
        who->set_skill("force",400);
       who->set_skill("parry",400);
       who->set_skill("dodge",400);
       who->set_skill("literate",400);
       who->set_skill("unarmed",400);
       who->set_skill("spells",400);
       who->set_skill("staff",400);
       who->set_skill("jienan-zhi",400);
       who->set_skill("lotusforce",400);
       who->set_skill("buddhism",400);
       who->set_skill("lunhui-zhang",400);
          who->set_skill("lotusmove",400);
        who->create_family("南海普陀山", 2, "弟子");
          who->set("family/master_name","小叶子"); 
         who->set("class", "bonze");		
	  break;
case "bibotan":
	  who->set_skill("huomoforce", 400);
        who->set_skill("pingtian-dafa", 400);
        who->set_skill("unarmed", 400);
        who->set_skill("dodge", 400);
        who->set_skill("force", 400);
        who->set_skill("parry", 400);
        who->set_skill("spells", 400);
        who->set_skill("fork", 400);
        who->set_skill("yueya-chan", 400);        
        who->set_skill("moshenbu", 400);
        who->set_skill("moyun-shou", 400);
        who->set_skill("literate",400);
        who->map_skill("unarmed", "moyun-shou");
        who->map_skill("dodge", "moshenbu");
        who->map_skill("parry", "yueya-chan");
        who->map_skill("fork", "yueya-chan");
        who->create_family("火云洞", 2, "弟子");
        who->set("family/master_name","小叶子"); 
        who->set("class", "yaomo");
              break;
case "moon":
	who->set_skill("literate", 400);
       who->set_skill("unarmed", 400);
       who->set_skill("dodge", 400);
       who->set_skill("force", 400);
       who->set_skill("parry", 400);
       who->set_skill("sword", 400);
       who->set_skill("spells", 400);
          who->set_skill("moonshentong", 400);
          who->set_skill("baihua-zhang", 400);
          who->set_skill("moonforce", 400);
          who->set_skill("snowsword", 400);
          who->set_skill("moondance", 400);
          who->map_skill("spells", "moonshentong"); 
          who->map_skill("unarmed", "baihua-zhang");
          who->map_skill("force", "moonforce");
          who->map_skill("sword", "snowsword");
          who->map_skill("parry", "snowsword");
          who->map_skill("dodge", "moondance");
            who->create_family("月宫", 2, "弟子");
       who->set("family/master_name","小叶子"); 
       who->set("class", "xian");
            break;
case "fangcun":
           who->set_skill("literate", 400);
       who->set_skill("unarmed", 400);
       who->set_skill("dodge", 400);
       who->set_skill("parry", 400);
       who->set_skill("stick", 400);
       who->set_skill("sword", 400);
       who->set_skill("liangyi-sword", 400);
       who->set_skill("spells", 400);
       who->set_skill("dao", 400);
       who->set_skill("puti-zhi", 400);
       who->set_skill("wuxiangforce", 400);
       who->set_skill("force", 400);
       who->set_skill("qianjun-bang", 400);
       who->set_skill("jindouyun", 400);
       who->map_skill("spells", "dao");
       who->map_skill("unarmed", "puti-zhi");
        who->map_skill("force", "wuxiangforce");
       who->map_skill("stick", "qianjun-bang");
       who->map_skill("parry", "qianjun-bang");
       who->map_skill("dodge", "jindouyun");
       who->map_skill("sword", "liangyi-sword");
            who->create_family("方寸山三星洞", 2, "弟子");
       who->set("family/master_name","小叶子"); 
       who->set("class", "taoist");
            break;
case "hell":
         who->set_skill("unarmed", 400);
          who->set_skill("whip", 400);
          who->set_skill("hellfire-whip", 400);
          who->set_skill("dodge", 400);
         who->set_skill("parry", 400);
         who->set_skill("literate", 400);
         who->set_skill("spells", 400);
          who->set_skill("force", 400);
          who->set_skill("tonsillit", 40);
          who->set_skill("ghost-steps", 400);
       who->set_skill("gouhunshu", 400);
        who->set_skill("jinghun-zhang", 400);
         who->set_skill("kusang-bang", 400);
         who->set_skill("zhuihun-sword", 400);
         who->set_skill("sword", 400);
         who->set_skill("stick", 400);
           who->map_skill("force", "tonsillit");
         who->map_skill("unarmed", "jinghun-zhang");
         who->map_skill("dodge", "ghost-steps");
         who->map_skill("spells", "gouhunshu");
         who->map_skill("parry", "hellfire-whip");
         who->map_skill("whip", "hellfire-whip");
        who->map_skill("sword", "zhuihun-sword");	
          who->create_family("阎罗地府", 2, "弟子");
       who->set("family/master_name","小叶子"); 
      who->set("class", "youling");
           break;
case "longgong":
        who->set_skill("huntian-hammer", 400);
        who->set_skill("hammer", 400);
        who->set_skill("literate", 400);
         who->set_skill("unarmed", 400);
         who->set_skill("dodge", 400);
         who->set_skill("force", 400);
          who->set_skill("parry", 400);
         who->set_skill("fork", 400);
         who->set_skill("spells", 400);
        who->set_skill("seashentong", 400);
        who->set_skill("dragonfight", 400);
        who->set_skill("dragonforce", 400);
        who->set_skill("fengbo-cha", 400);
        who->set_skill("dragonstep", 400);
        who->map_skill("hammer", "huntian-hammer");
        who->map_skill("spells", "seashentong");
        who->map_skill("unarmed", "dragonfight");
        who->map_skill("force", "dragonforce");	
          who->map_skill("fork", "fengbo-cha");
          who->map_skill("parry", "fengbo-cha");
          who->map_skill("dodge", "dragonstep");		
            who->create_family("东海龙宫", 2, "弟子");
        who->set("family/master_name","小叶子"); 
        who->set("class", "dragon");
              break;
				
case "hyd":
        who->set_skill("unarmed", 400);
        who->set_skill("dodge", 400);
        who->set_skill("force", 400);
        who->set_skill("parry", 400);
        who->set_skill("spear", 400);
        who->set_skill("spells", 400);
        who->set_skill("huoyun-qiang", 400);
        who->set_skill("moshenbu", 400);
        who->set_skill("moyun-shou", 400);
        who->set_skill("huomoforce", 400);
        who->set_skill("pingtian-dafa", 400);
        who->set_skill("stick", 400);
        who->set_skill("dali-bang", 400);
        who->map_skill("stick", "dali-bang");
        who->map_skill("force", "huomoforce");
        who->map_skill("spells", "pingtian-dafa");
        who->map_skill("unarmed", "moyun-shou");
        who->map_skill("dodge", "moshenbu");
        who->map_skill("parry", "huoyun-qiang");
        who->map_skill("spear", "huoyun-qiang");
        who->create_family("火云洞", 2, "弟子");
        who->set("family/master_name","小叶子"); 
        who->set("class", "yaomo");
              break;
case "wdd":
  who->set_skill("unarmed", 400);
  who->set_skill("dodge", 400);
  who->set_skill("parry", 400);
  who->set_skill("spells", 400); 
  who->set_skill("yaofa", 400);
  who->set_skill("sword",400);
  who->set_skill("qixiu-jian",400);
  who->set_skill("blade", 400);
  who->set_skill("kugu-blade", 400);
  who->set_skill("lingfu-steps", 400);
  who->set_skill("yinfeng-zhua", 400);
  who->set_skill("force", 400);   
  who->set_skill("huntian-qigong", 400);
  who->map_skill("force", "huntian-qigong");
  who->map_skill("spells", "yaofa");
  who->map_skill("unarmed", "yinfeng-zhua");
  who->map_skill("sword", "qixiu-jian");
  who->map_skill("parry", "kugu-blade");
  who->map_skill("blade", "kugu-blade");
  who->map_skill("dodge", "lingfu-steps");
  who->create_family("陷空山无底洞", 2, "弟子");
   who->set("family/master_name","小叶子"); 
  who->set("class", "yaomo");
			
   break;
case "wzg":
   who->set_skill("unarmed", 400);
   who->set_skill("wuxing-quan", 400);
   who->set_skill("dodge", 400);
   who->set_skill("baguazhen", 400);
   who->set_skill("parry", 400);
   who->set_skill("sword", 400);
   who->set_skill("sanqing-jian", 400);
   who->set_skill("staff", 400);
   who->set_skill("fumo-zhang", 400);
   who->set_skill("hammer", 400);
   who->set_skill("kaishan-chui", 400);
   who->set_skill("blade", 400);
   who->set_skill("yange-blade", 400);
     who->set_skill("force", 400);   
   who->set_skill("zhenyuan-force", 400);
   who->set_skill("literate", 400);
   who->set_skill("spells", 400);
   who->set_skill("taiyi", 400);
   who->map_skill("spells", "taiyi");
   who->map_skill("force", "zhenyuan-force");
   who->map_skill("unarmed", "wuxing-quan");
   who->map_skill("sword", "sanqing-jian");
   who->map_skill("dodge", "baguazhen");
   who->map_skill("staff", "fumo-zhang");
   who->map_skill("blade", "yange-blade");
   who->map_skill("hammer", "kaishan-chui");	
 who->create_family("五庄观", 2, "弟子");
                    who->set("family/master_name","小叶子"); 
                     who->set("class", "xian");
        break;
case "xueshan":
        who->set_skill("unarmed", 400);
        who->set_skill("cuixin-zhang", 400);
        who->set_skill("dodge", 400);
             who->set_skill("xiaoyaoyou", 400);
        who->set_skill("parry", 400);
        who->set_skill("sword", 400);
        who->set_skill("bainiao-jian", 400);
        who->set_skill("blade", 400);
        who->set_skill("bingpo-blade", 400);
        who->set_skill("throwing", 400);
        who->set_skill("force", 400);   
        who->set_skill("ningxie-force", 400);
        who->set_skill("literate", 400);
        who->set_skill("spells", 400);
        who->set_skill("dengxian-dafa", 400);
        who->map_skill("spells", "dengxian-dafa");
        who->map_skill("force", "ningxie-force");
        who->map_skill("unarmed", "cuixin-zhang");
        who->map_skill("sword", "bainiao-jian");
        who->map_skill("blade", "bingpo-blade");
        who->map_skill("dodge", "xiaoyaoyou");	
              who->create_family("大雪山", 2, "弟子");
                    who->set("family/master_name","小叶子"); 
                     who->set("class", "yaomo");
                break;
 case "jjf":
  who->set_skill("literate", 400);
  who->set_skill("unarmed", 400);
  who->set_skill("force", 400);
    who->set_skill("spear",400);
    who->set_skill("bawang-qiang",400);
      who->set_skill("archery", 400);
  who->set_skill("mace", 400);
  who->set_skill("wusi-mace", 400);
who->set_skill("xuanyuan-archery",400);
  who->set_skill("lengquan-force", 400);
  who->set_skill("axe", 400);
  who->set_skill("sword", 400);
  who->set_skill("dodge", 400);
  who->set_skill("parry", 400);
  who->set_skill("sanban-axe", 400);
  who->set_skill("xiaofeng-sword", 400);
 who->set_skill("spells", 400);
  who->set_skill("baguazhou", 400);
  who->set_skill("yanxing-steps", 400);
  who->map_skill("force", "lengquan-force");
  who->map_skill("spells", "baguazhou");
  who->map_skill("axe", "sanban-axe");
  who->map_skill("parry", "sanban-axe");
  who->map_skill("dodge", "yanxing-steps");
  who->map_skill("sword", "xiaofeng-sword");	
  who->map_skill("spear", "bawang-qiang");
  who->map_skill("mace", "wusi-mace");
   who->map_skill("archery", "xuanyuan-archery");	
   who->create_family("将军府", 2, "弟子");
    who->set("family/master_name","小叶子"); 
    who->set("class", "fighter");
       break;
case "shushan":
        who->set_skill("spells",400);
        who->set_skill("force", 400);
        who->set_skill("dodge", 400);
        who->set_skill("parry", 400);
        who->set_skill("sword", 400);
        who->set_skill("zixia-shengong", 400);
        who->set_skill("sevensteps", 400);
        who->set_skill("hunyuan-zhang", 400);
              who->set_skill("literate", 400);
        who->set_skill("unarmed", 400);
          who->set_skill("canxin-jian", 400);
              who->set_skill("yujianshu", 400);
        who->set_skill("taoism",400);
        who->map_skill("spells", "taoism");
        who->map_skill("dodge", "sevensteps");
        who->map_skill("force", "zixia-shengong");
          who->map_skill("parry", "canxin-jian");
          who->map_skill("sword", "canxin-jian");
        who->map_skill("unarmed", "hunyuan-zhang");
        who->create_family("蜀山剑派", 2, "弟子");
        who->set("family/master_name","小叶子"); 
        who->set("class", "fighter");
break;
			}
	}
return 1;
}
