// yuzu.c
// cgm 28/12/1999
// idea 7/4/2000
//By waiwai@2000/12/26 部分优化

#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "他妈的","你妈的","傻B","我操","操你","和你妈睡",
                     "操！","操!","fuck","FUCK","Fuck","婊子","有没有活的",
   "你奶奶的","和你妈做爱","她妈的","你爷爷的","有没有喘气的",
                      "放你妈的屁","tmd","TMD","tmmd","TMMD","操你妈","日死你","干你娘","没死回？",
                      "操你姐","狗屁wiz","狗wiz","破wiz","死wiz","日死你","Nnd",
                      "干你妈","干你的","ｆｕｃｋ","ＦＵＣＫ","F u c k","f u c k","nnd","NND","SB",
               "mlgb","MLGB","mcb","shabi","SHABI","MCB","danzi","蛋子","你妈","你爹",
                      "牛比","放屁","吃屎","你大爷","操你妈","打炮","6mang","大便","小便","caobi",
                      "手淫","t n n d","cb","t m d","T M D","T N N D","日你老母","日你",});

void create()
{
        set_name("狱卒", ({"yu zu","yuzu"}));
        set("title", HIY"「巡查使」"NOR);
        set("gender", "男性" );
        set("age", 30);
        set("per", 25);
        set("long", HIR"一个神秘的狱卒，你碰上他准是你干了什么坏事。\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("str", 50);
   
        set_skill("literate", 800);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("max_force", 1000);
  	
  	set("no_clean_up",1);
        setup();
//在下面添加要监视的频道
	if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
	if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
	if( !clonep() ) CHANNEL_D->register_relay_channel("party");
       if( !clonep() ) CHANNEL_D->register_relay_channel("es");
       if( !clonep() ) CHANNEL_D->register_relay_channel("sldh");
       if( !clonep() ) CHANNEL_D->register_relay_channel("news");
        
}

void relay_channel(object criminal, string channel, string msg)
{

        int i;
        string criname,result;
        int howlong;
        if( !userp(criminal) ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    message_vision(CYN"巡查使然出现，扔出索套，一下就套住$N的脖子。\n$N伸长舌头、翻着白眼地被拖走了。\n"NOR, criminal);
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                    howlong=12;//这里更改自动囚禁时间,12=12分钟
                    
                    result = sprintf("%s在%s频道说脏话(%s)被设囚禁 %d 分\n",
                    criname,channel,msg,howlong);
                    
                    criminal->set("qiushi/howlong",howlong);
                    criminal->set("qiushi/temp",result);
                    criminal->move("/d/wiz/qiushi");
                 
                    message("channel:rumor",HIM"【空穴来风】某人：据说 "HIR+criname+HIM" 在公众频道使用粗言烂语，被巡查使抓走了。\n"NOR, users());
                    return;
                    }
        }
}
