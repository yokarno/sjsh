inherit NPC;
#include <ansi.h>
//int give_bonnet();
int give_newbie();
int give_family();
int give_51liwu();
int give_buchang();
//int give_dan1();
int answer_me();

void create()
{
         set_name("小小财神", ({"xiao caishen","caishen"}));
   set ("long", @LONG
他是在这里负责给大家发新手礼物(gift)（newbie）和门派礼物（family）的，
他身上戴有天师法冠（bonnet），大家赶快向他要（ask）吧。
LONG);
           set("gender", "男性");
        set("title",HIY"发礼物的"NOR);
        set("age", 20);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([
            "bonnet"    : "天师法冠发完了，你怎么蠢得连这都不知道？",
            "newbie"    :(:give_newbie:),
            "gift"    :(:give_newbie:),
            "礼物"    :(:give_newbie:),
            "family"    :(:give_family:),
//            "金宝宝生日快乐"    :(:give_dan1:),
            "新手礼物"  :(:give_newbie:),
//            "节日礼物"  :(:give_51liwu:),
            "节日礼物"  : (:give_51liwu:),
            "五一礼物"  : (:give_51liwu:),
            "门派礼物"  :(:give_family:),
            "补偿"    :(:give_buchang:),
            "天师法冠"  : "天师法冠发完了，你怎么蠢得连这都不知道？",
            "name"      :(:answer_me:),
            "金宝宝"  : "金宝宝他住在深圳，有空可以打电话，tel：0755-6888808",
            "stey" : "stey就是宝宝啊，你怎么蠢得连这都不知道？",
            "flydance" : "flydance就是飞舞啊，他是好巫师，你怎么蠢得连这都不知道？",
            "admin" : "admin就是这里大好巫师啊，你怎么蠢得连这都不知道？",
            "calvin" : "calvin就是这里的美丽的巫师啊，你怎么蠢得连这都不知道？",
//            "corpsed" : "corpsed就是这里的大巫师啊，你连这都不知道还混啊？",
//           "小枯骨" : "如果有事找小枯骨,请找QQ5765442!",
]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}


int answer_me()
{
        command("say 小心我扁你！嘿嘿 。\n");
        return 1;
}


int give_51liwu()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say 什么小猫小狗也来要礼物？！");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 150000 ){
                command("hammer "+who->query("id") );
                command("say 你武学这么差，等到15万武学再来，你不会是大米把！");
                return 1;
         }

         if (this_player()->query("liwuu") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 五一节礼物只有一份！领过就不给了！\n");
        return 1;
        }
        who->add("balance",2000000); 
        who->add("daoxing",100000);
        who->add("force",200);
        who->add("mana",200);
 //       who->add("maximum_force",200);
//        who->add("max_mana",200);
//        who->add("max_force",200);
//      who->add("maximum_mana",200);
        who->add("potential",20000);
        who->set("liwuu",1);
        if (this_player()->query("age") > 24 ){
        who->add("mud_age",-500000);	
         message_vision("$N对着$n说道，恭喜你又变成小孩了!\n",this_object(),this_player());
                                                   }
                              
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 你的道行增加了六十年! 你的潜能增加了20000。\n");
        command("chat 恭喜恭喜，"+who->query("name")+"得到了五一节礼物！\n",);
        command("say 你现在最好backup!\n");
        return 1;
}

int give_newbie()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say 什么小猫小狗也来要礼物？！");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") > 40000 ){
                command("hammer "+who->query("id") );
                command("say 你都这么厉害了还差这么一点小东西么？");
                return 1;
         }

         if (this_player()->query("lucky") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 新人礼物只有一份！领过就不给了！\n");
        return 1;
        }
         
        who->add("combat_exp",20000);
        who->add("daoxing",20000);
        who->add("force",400);
        who->add("mana",400);
        who->add("maximum_force",400);
        who->add("max_mana",400);
        who->add("max_force",400);
        who->add("maximum_mana",400);
        who->add("balance",10000);
        who->add("potential",20000);
        who->set("lucky",1);
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
        你的道行增加了二十年!\n
        你的潜能增加了20000。\n
        你现在有400点内力和法力。\n");
        command("chat 恭喜恭喜，"+who->query("name")+"得到了新人礼物！\n");
        return 1;
}
int give_family()
{
        object who=this_player();
        string family;
        family=who->query("family/family_name");
        if (!userp(who))
        {
                command("heng");
                command("say 什么小猫小狗也来要礼物？！");
                command("qi");
                return 1;
        }
        if (this_player()->query("lucky") > 1 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 门派礼物只有一份！领过就不给了！\n");
        return 1;
        }
        if (who->query("combat_exp") > 40000 ) {
                        command("hammer "+who->query("id") );
                command("say 你都这么厉害了还差这么一点小东西么？");
                return 1;
         }
        if ( family == 0 )
        {
                command("heng");
                command("say "+who->query("name")+"你还是先去拜师吧，拜师之前你可以用\nhelp menpai来看《仙履情缘》的各个门派介绍。\n");
                return 1;
        }
        switch(family) {
                case "方寸山三星洞":

who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("spells",50);
who->set_skill("literate",50);
who->set_skill("parry",50);
who->set_skill("liangyi-sword",50);
who->set_skill("stick",50);
who->set_skill("dao",50);
who->set_skill("puti-zhi",50);
who->set_skill("qianjun-bang",50);
who->set_skill("wuxiangforce",50);
who->set_skill("unarmed",50);
who->set_skill("jindouyun",50);
who->set_skill("sword",50);
break;
                case "大雪山":

who->set_skill("literate",50);
who->set_skill("dodge",50);
who->set_skill("force",50);
who->set_skill("spells",50);
who->set_skill("parry",50);
who->set_skill("ningxie-force",50);
who->set_skill("dengxian-dafa",50);
who->set_skill("throwing",50);
who->set_skill("unarmed",50);
who->set_skill("xiaoyaoyou",50);
who->set_skill("blade",50);
who->set_skill("bingpo-blade",50);
who->set_skill("cuixin-zhang",50);
who->set_skill("sword",50);
who->set_skill("bainiao-jian",50);
break;
                case "月宫":     
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("literate",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("sword",50);
who->set_skill("snowsword",50);
who->set_skill("moonshentong",50);
who->set_skill("moondance",50);
who->set_skill("moonforce",50);
who->set_skill("whip",50);         
who->set_skill("jueqingbian",50);  
break;                             
               case "三界山":      
               case "天一宫":      
               case "天妖宫":
               case "天魔宫":
               case "藏尸地":
               case "雷刀门":
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("sword",50);
who->set_skill("huxiaojian",50);
who->set_skill("unarmed",50);
who->set_skill("huxiaoquan",50);
who->set_skill("liushenjue",50);
who->set_skill("stick",50);
who->set_skill("tianyaofa",50);
who->set_skill("literate",50);
who->set_skill("force",50);
who->set_skill("huntianforce",50);
who->set_skill("spells",50);
who->set_skill("tianmogong",50);
who->set_skill("blade",50);
who->set_skill("zileidao",50);
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("parry",50);
break;
                case "东海龙宫":  
who->set_skill("unarmed",50);
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("seashentong",50);
who->set_skill("dragonfight",50);
who->set_skill("dragonforce",50);
who->set_skill("dragonstep",50);
who->set_skill("hammer",50);
who->set_skill("huntian-hammer",50);
who->set_skill("literate",50);
who->set_skill("fork",50);
who->set_skill("fengbo-cha",50);
break;
                case "南海普陀山":  
who->set_skill("force",50);
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("spells",50);
who->set_skill("staff",50);
who->set_skill("jienan-zhi",50);
who->set_skill("lotusforce",50);
who->set_skill("lotusmove",50);
who->set_skill("lunhui-zhang",50);
who->set_skill("buddhism",50);
who->set_skill("literate",50);
break;
                case "盘丝洞":  
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("force",50);
who->set_skill("jiuyin-xinjing",50);
who->set_skill("lanhua-shou",50);
who->set_skill("pansi-dafa",50);
who->set_skill("qingxia-jian",50);
who->set_skill("sword",50);
who->set_skill("literate",50);
who->set_skill("qin",50);
who->set_skill("sword",50);
who->set_skill("chixin-jian",50);
who->set_skill("whip",50);
who->set_skill("yinsuo-jinling",50);
who->set_skill("yueying-wubu",50);
break;
                case "陷空山无底洞": 
who->set_skill("force",50);
who->set_skill("spells",50);
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("blade",50);
who->set_skill("kugu-blade",50);
who->set_skill("yaofa",50);
who->set_skill("literate",50);
who->set_skill("yinfeng-zhua",50);
who->set_skill("sword",50);
who->set_skill("qixiu-jian",50);
who->set_skill("huntian-qigong",50);
who->set_skill("lingfu-steps",50);
who->set_skill("sword",50);
break;
                case "五庄观":  
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("spells",50);
who->set_skill("force",50);
who->set_skill("sword",50);
who->set_skill("literate",50);
who->set_skill("taiyi",50);
who->set_skill("zhenyuan-force",50);
who->set_skill("xiaofeng-sword",50);
who->set_skill("baguazhen",50);
who->set_skill("hammer",50);
who->set_skill("fumo-zhang",50);
who->set_skill("staff",50);
who->set_skill("wuxing-quan",50);
who->set_skill("blade",50);
who->set_skill("yange-blade",50);
who->set_skill("sanqing-jian",50);
break;
                case "阎罗地府":  
who->set_skill("unarmed",50);
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("literate",50);
who->set_skill("ghost-steps",50);
who->set_skill("gouhunshu",50);
who->set_skill("tonsillit",50);
who->set_skill("whip",50);
who->set_skill("hellfire-whip",50);
who->set_skill("sword",50);
who->set_skill("jinghun-zhang",50);
who->set_skill("zhuihun-sword",50);
who->set_skill("stick",50);
who->set_skill("kusang-bang",50);
break;
                case "火云洞": 
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("parry",50);
who->set_skill("literate",50);
who->set_skill("spells",50);
who->set_skill("unarmed",50);
who->set_skill("dali-bang",50);
who->set_skill("fork",50);
who->set_skill("huomoforce",50);
who->set_skill("moshenbu",50);
who->set_skill("moyun-shou",50);
who->set_skill("pingtian-dafa",50);
who->set_skill("yueya-chan",50);
who->set_skill("fork",50);
who->set_skill("huoyun-qiang",50);
who->set_skill("spear",50);
break;
                case "蜀山剑派": 
who->set_skill("sword",50);
who->set_skill("literate",50);
who->set_skill("dodge",50);
who->set_skill("force",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("unarmed",50);
who->set_skill("hunyuan-zhang",50);
who->set_skill("whip",50);
who->set_skill("sevensteps",50);
who->set_skill("taoism",50);
who->set_skill("yujianshu",50);
who->set_skill("zixia-shengong",50);
break;
                case "将军府": 
who->set_skill("literate",50);
who->set_skill("baguazhou",50);
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("spells",50);
who->set_skill("parry",50);
who->set_skill("unarmed",50);
who->set_skill("archery",50);
who->set_skill("bawang-qiang",50);
who->set_skill("changquan",50);
who->set_skill("lengquan-force",50);
who->set_skill("mace",50);
who->set_skill("spear",50);
who->set_skill("wusi-mace",50);
who->set_skill("xuanyuan-archery",50);
who->set_skill("yanxing-steps",50);
break;
        default:
                command("heng");
                command("say "+who->query("name")+"你还是先去拜师吧，拜师之前你可以用\nhelp menpai来看《仙履情缘》的各个门派介绍。\n");
                return 1;
}       
        who->set("lucky",2);
        command("nod "+who->query("id") );
        command("chat "+family+"弟子"+who->query("name")+"得到了门派奖励，希望以后多为本门派争光。\n");
        return 1;
}
/*
int give_bonnet()
 {
        object bonnet;
        object who=this_player();
        bonnet=new("/d/lingtai/obj/faguan.c");
        bonnet->move(who);
        
        message_vision("$N哆哆嗦嗦的从包里拿出一顶天师法冠。\n$N给$n一顶天师法冠。\n",this_object(),this_player());
//who->set("yudian/bonnet","got");
 return 1;
} 


void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}
*/

void greeting(object who) {
if( who->query("combat_exp") < 1000)
        tell_object(who,"小小财神悄悄告诉你：可以向我要礼物哦(ask)(l xiao caishen)。\n");
        tell_object(who,"小小财神悄悄告诉你：可以向我要门派礼物哦(ask caishen about family)。\n");
}
/*
int give_dan1()
 {
 	object who=this_player();
 	object dan;
        dan=new("/u/stey/obj/dan1.c");
        if (this_player()->query("dann") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 宝宝的生日礼物只有一份！领过就不给了！\n");
        return 1;
        }
        
        dan->move(who);
        
        message_vision("$N高高兴兴的从包里拿出一个宝宝生日丹。\n$N给$n一个金宝宝生日丹。\n",this_object(),this_player());
        who->set("dann",1);
 return 1;
}
*/ 
int give_buchang()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say 什么小猫小狗也来要礼物？！");
                command("qi");
                return 1;
        }
        /*
         if (who->query("combat_exp") < 150000 ){
                command("hammer "+who->query("id") );
                command("say 你武学这么差，等到15万武学再来，你不会是大米把！");
                return 1;
         }
         */
         if (this_player()->query("age") < 15 ){
                   command("tell "+who->query("id")+" 你的年龄不过15，没有补偿。\n");  
                     return 1;
                     }  
         if (this_player()->query("liwun") > 0 ){
         message_vision("$N对着$n哼了一声。领过就不给了！\n",this_object(),this_player());
                command("hammer "+who->query("id") ); 
                command("say 补偿只有一次！领过就不给了！\n");
        return 1;
        }
//        who->add("balance",2000000); 
//        who->add("daoxing",100000);
//       who->add("force",200);
//       who->add("mana",200);
 //       who->add("maximum_force",200);
//        who->add("max_mana",200);
//        who->add("max_force",200);
//      who->add("maximum_mana",200);
        who->add("potential",10000);
        who->set("liwun",1);

//        who->add("mud_age",-500000);	

message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());

//        command("chat 恭喜恭喜，"+who->query("name")+"得到了五一节礼物！\n",);
        command("say 你得到10000qn补偿了，你现在最好backup!\n");
        return 1;
}
