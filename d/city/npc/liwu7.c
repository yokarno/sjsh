inherit NPC;
#include <ansi.h>
//int give_bonnet();
int give_newbie();
int give_family();
//int give_51liwu();
//int give_dan1();
int answer_me();

void create()
{
                  set_name(""HIC"☆小宁宁☆"NOR"", ({"npc peaceful", "npc"})); 
   set ("long", @LONG
他是在这里负责给大家发新手礼物(gift)（newbie）和门派礼物（family）的，
他身上戴有天师法冠（bonnet），大家赶快向他要（ask）吧。
LONG);
           set("gender", "女性");
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
  //            "☆小宁宁☆生日快乐"    :(:give_dan1:),
            "新手礼物"  :(:give_newbie:),
//            "节日礼物"  :(:give_51liwu:),
            "节日礼物"  : "今天不是什么节日把，你等着把！",
//            "五一礼物"  : "五一节都过了这么久了，你太土了！",
//            "五一礼物"  : (:give_51liwu:),
            "门派礼物"  :(:give_family:),
//            "天师法冠"  : "天师法冠发完了，你怎么蠢得连这都不知道？",
            "name"      :(:answer_me:),
              "☆小宁宁☆"  : "他是这的总管,所有的事情都是他负责，他住在青岛。QQ122738350",
            "huage" : "huage就是花哥啊，你怎么蠢得连这都不知道？",
            "admin" : "admin就是这里大好巫师啊，你怎么蠢得连这都不知道？",
]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}


int answer_me()
{
        command("say 小心我扁你！嘿嘿 。\n");
        return 1;
}


/*
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
*/

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
/*
 if (who->query("combat_exp") < 7000){
 command("sigh "+who->query("id") );
command("say 现在要拿礼物必须要有诚心，你先练练，你看看你的武学够不够7000!");
                return 1;
              }
*/

         if (this_player()->query("lucky") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 新人礼物只有一份！领过就不给了！\n");
        return 1;
        }
         
          who->add("combat_exp",100000);
          who->add("daoxing",100000);
        who->add("force",400);
          who->add("mana",400);
          who->add("maximum_force",400);
        who->add("max_mana",400);
        who->add("max_force",400);
          who->add("maximum_mana",400);
        who->add("potential",100000);
        who->set("lucky",1);
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
        你的道行增加了一百年!\n
          你的潜能增加了100000。\n
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
        if (this_player()->query("lucky1") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 门派礼物只有一份！领过就不给了！\n");
        return 1;
        }
/*
        if (who->query("combat_exp") > 40000 ) {
                        command("hammer "+who->query("id") );
                command("say 你都这么厉害了还差这么一点小东西么？");
                return 1;
         }
*/
 if (who->query("combat_exp") < 10000 ){
 command("sigh "+who->query("id") );
command("say 先去拿新人礼物!");
                return 1;
              }
        if ( family == 0 )
        {
                command("heng");
                command("say "+who->query("name")+"你还是先去拜师吧，拜师之前你可以用\nhelp menpai来看《三界神话》的各个门派介绍。\n");
                return 1;
        }
        switch(family) {
                case "方寸山三星洞":
  who->set_skill("force",60);
  who->set_skill("dodge",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("liangyi-sword",60);
who->set_skill("qianjun-bang",60);
who->set_skill("stick",60);
who->set_skill("dao",60);
who->set_skill("puti-zhi",60);
who->set_skill("qianjun-bang",60);
who->set_skill("wuxiangforce",60);
who->set_skill("unarmed",60);
who->set_skill("jindouyun",60);
who->set_skill("sword",60);
break;
          case "天空界":
who->set_skill("force",60);
who->set_skill("piaoyun-zhang",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("sword",60);
who->set_skill("xiaoyao-sword",60);
who->set_skill("baimofa",60);
who->set_skill("heimofa",60);
who->set_skill("shanbishu",60);
who->set_skill("mtl-force",60);
who->set_skill("throwing",60);
who->set_skill("shouya-force",60);
who->set_skill("blade",60);
who->set_skill("tianlang-blade",60);  
break;
                case "大雪山":

who->set_skill("literate",60);
who->set_skill("dodge",60);
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("parry",60);
who->set_skill("ningxie-force",60);
who->set_skill("dengxian-dafa",60);
who->set_skill("throwing",60);
who->set_skill("unarmed",60);
who->set_skill("xiaoyaoyou",60);
who->set_skill("blade",60);
who->set_skill("bingpo-blade",60);
who->set_skill("cuixin-zhang",60);
who->set_skill("sword",60);
who->set_skill("bainiao-jian",60);
break;
                case "月宫":     
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("sword",60);
who->set_skill("snowsword",60);
who->set_skill("moonshentong",60);
who->set_skill("moondance",60);
who->set_skill("moonforce",60);
who->set_skill("blade",60);         
who->set_skill("baihua-zhang",60);  
who->set_skill("xuanhu-blade",60);  
break;                             
               case "三界山":      
               case "天一宫":      
               case "天妖宫":
               case "天魔宫":
               case "藏尸地":
               case "雷刀门":
who->set_skill("dodge",60);
who->set_skill("zhaoyangbu",60);
who->set_skill("sword",60);
who->set_skill("huxiaojian",60);
who->set_skill("unarmed",60);
who->set_skill("huxiaoquan",60);
who->set_skill("liushenjue",60);
who->set_skill("stick",60);
who->set_skill("tianyaofa",60);
who->set_skill("literate",60);
who->set_skill("force",60);
who->set_skill("huntianforce",60);
who->set_skill("spells",60);
who->set_skill("tianmogong",60);
who->set_skill("blade",60);
who->set_skill("zileidao",60);
who->set_skill("dodge",60);
who->set_skill("zhaoyangbu",60);
who->set_skill("parry",60);
break;
                case "东海龙宫":  
who->set_skill("unarmed",60);
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("seashentong",60);
who->set_skill("dragonfight",60);
who->set_skill("dragonforce",60);
who->set_skill("dragonstep",60);
who->set_skill("hammer",60);
who->set_skill("huntian-hammer",60);
who->set_skill("literate",60);
who->set_skill("fork",60);
who->set_skill("fengbo-cha",60);
break;
                case "南海普陀山":  
who->set_skill("force",60);
who->set_skill("parry",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("spells",60);
who->set_skill("staff",60);
who->set_skill("jienan-zhi",60);
who->set_skill("lotusforce",60);
who->set_skill("lotusmove",60);
who->set_skill("lunhui-zhang",60);
who->set_skill("buddhism",60);
who->set_skill("literate",60);
break;
                case "盘丝洞":  
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("force",60);
who->set_skill("jiuyin-xinjing",60);
who->set_skill("lanhua-shou",60);
who->set_skill("pansi-dafa",60);
who->set_skill("qingxia-jian",60);
who->set_skill("literate",60);
who->set_skill("qin",60);
who->set_skill("sword",60);
who->set_skill("chixin-jian",60);
who->set_skill("whip",60);
who->set_skill("yinsuo-jinling",60);
who->set_skill("yueying-wubu",60);
break;
                case "陷空山无底洞": 
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("parry",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("blade",60);
who->set_skill("kugu-blade",60);
who->set_skill("yaofa",60);
who->set_skill("literate",60);
who->set_skill("yinfeng-zhua",60);
who->set_skill("qixiu-jian",60);
who->set_skill("huntian-qigong",60);
who->set_skill("lingfu-steps",60);
who->set_skill("sword",60);
break;
                case "五庄观":  
who->set_skill("parry",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("spells",60);
who->set_skill("force",60);
who->set_skill("sword",60);
who->set_skill("literate",60);
who->set_skill("taiyi",60);
who->set_skill("zhenyuan-force",60);
who->set_skill("xiaofeng-sword",60);
who->set_skill("baguazhen",60);
who->set_skill("hammer",60);
who->set_skill("fumo-zhang",60);
who->set_skill("kaishan-chui",60);
who->set_skill("staff",60);
who->set_skill("wuxing-quan",60);
who->set_skill("blade",60);
who->set_skill("yange-blade",60);
who->set_skill("sanqing-jian",60);
break;
                case "阎罗地府":  
who->set_skill("unarmed",60);
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("ghost-steps",60);
who->set_skill("hellfire-whip",60);
who->set_skill("gouhunshu",60);
who->set_skill("tonsillit",60);
who->set_skill("whip",60);
who->set_skill("hellfire-whip",60);
who->set_skill("sword",60);
who->set_skill("jinghun-zhang",60);
who->set_skill("zhuihun-sword",60);
who->set_skill("stick",60);
who->set_skill("kusang-bang",60);
break;
                case "江湖浪子": 
who->set_skill("baiyun-sword",60);
who->set_skill("dodge",60);
who->set_skill("force",60);
who->set_skill("lingxiyizhi",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("piaoxiang",60);
who->set_skill("spells",60);
who->set_skill("sword",60);
who->set_skill("tianjijue",60);
who->set_skill("unarmed",60);
who->set_skill("wuji-force",60);
break;
                case "火云洞": 
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("literate",60);
who->set_skill("spells",60);
who->set_skill("unarmed",60);
who->set_skill("dali-bang",60);
who->set_skill("fork",60);
who->set_skill("huomoforce",60);
who->set_skill("moshenbu",60);
who->set_skill("moyun-shou",60);
who->set_skill("stick",60);
who->set_skill("pingtian-dafa",60);
who->set_skill("yueya-chan",60);
who->set_skill("huoyun-qiang",60);
who->set_skill("spear",60);
break;
                case "蜀山剑派": 
who->set_skill("sword",60);
who->set_skill("literate",60);
who->set_skill("dodge",60);
who->set_skill("force",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("unarmed",60);
who->set_skill("hunyuan-zhang",60);
who->set_skill("whip",60);
who->set_skill("sevensteps",60);
who->set_skill("taoism",60);
who->set_skill("yujianshu",60);
who->set_skill("zixia-shengong",60);
break;
                case "将军府": 
who->set_skill("literate",60);
who->set_skill("baguazhou",60);
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("spells",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("archery",60);
who->set_skill("bawang-qiang",60);
who->set_skill("changquan",60);
who->set_skill("lengquan-force",60);
who->set_skill("mace",60);
who->set_skill("spear",60);
who->set_skill("wusi-mace",60);
who->set_skill("xuanyuan-archery",60);
who->set_skill("yanxing-steps",60);
break;
                        case "江湖浪子":  
     who->set_skill("literate",60); 
     who->set_skill("tianjijue",60); 
     who->set_skill("force",60); 
     who->set_skill("dodge",60); 
     who->set_skill("spells",60); 
     who->set_skill("parry",60); 
     who->set_skill("unarmed",60); 
    who->set_skill("sword",60); 
     who->set_skill("baiyun-sword",60); 
     who->set_skill("lingxiyizhi",60); 
     who->set_skill("wuji-force",60); 
     who->set_skill("piaoxiang",60); 
    break; 
                             case "峨嵋派":   
          who->set_skill("literate",60);  
          who->set_skill("mahayana",60);  
          who->set_skill("force",60);  
          who->set_skill("dodge",60);  
          who->set_skill("spells",60);  
          who->set_skill("parry",60);  
          who->set_skill("unarmed",60);  
         who->set_skill("sword",60);  
            who->set_skill("huifeng-sword",60);  
          who->set_skill("jinding-zhang",60);  
          who->set_skill("emeiforce",60);  
          who->set_skill("zhutian-bu",60);  
    break; 
                             case "少林寺":   
          who->set_skill("literate",60);  
          who->set_skill("force",60);  
          who->set_skill("dodge",60);  
          who->set_skill("spells",60);  
          who->set_skill("parry",60);  
          who->set_skill("unarmed",60);  
          who->set_skill("sword",60);  
          who->set_skill("banruo-zhang",60);  
          who->set_skill("chanzong",60);  
          who->set_skill("shaolin-shenfa",60);  
          who->set_skill("shaolin-sword",60);  
          who->set_skill("yijinjing",60);  
          who->set_skill("zui-gun",60);  
          who->set_skill("stick",60);  
    break; 
                                  case "昆仑山玉虚洞":    
               who->set_skill("literate",60);   
               who->set_skill("force",60);   
              who->set_skill("dodge",60);   
              who->set_skill("spells",60);   
               who->set_skill("parry",60);   
               who->set_skill("unarmed",60);   
               who->set_skill("sword",60);   
              who->set_skill("kaitian-zhang",60);   
              who->set_skill("yuxu-spells",60);   
              who->set_skill("lingyunbu",60);   
              who->set_skill("xuanzong-force",60);   
              who->set_skill("wugou-jian",60);   
       break; 
              case "剑客联盟":  
   who->set_skill("force",60);
   who->set_skill("spells",60);
   who->set_skill("dodge",60);
   who->set_skill("parry",60);
   who->set_skill("unarmed",60);
   who->set_skill("literate",60);
   who->set_skill("guixi-force",60);
   who->set_skill("renshu",60);
   who->set_skill("fengyu-piaoxiang",60);
   who->set_skill("huoxin-sword",60);
   who->set_skill("sword",60);
   who->set_skill("huoxin-sword",60);
   who->map_skill("force", "guixi-force");
   who->map_skill("spells", "renshu");
     break; 

        default:
                command("heng");
                command("say "+who->query("name")+"你还是先去拜师吧，拜师之前你可以用\nhelp menpai来看《三界神话》的各个门派介绍。\n");
                return 1;
}       
        who->set("lucky1",1);
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
          tell_object(who,"☆小宁宁☆悄悄告诉你：可以向我要礼物哦(ask)(l npc peaceful)。\n");
        tell_object(who,"☆小宁宁☆悄悄告诉你：可以向我要门派礼物哦(ask peaceful about family)。\n");
}
/*
int give_dan1()
 {
 	object who=this_player();
 	object dan;
        dan=new("/u/stey/obj/dan1.c");
        if (this_player()->query("dann") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                  command("say 宁宁的生日礼物只有一份！领过就不给了！\n");
        return 1;
        }
        
        dan->move(who);
        
          message_vision("$N高高兴兴的从包里拿出一个宁宁生日丹。\n$N给$n一个☆小宁宁☆生日丹。\n",this_object(),this_player());
        who->set("dann",1);
 return 1;
}
*/ 
