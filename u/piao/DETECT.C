// 战斗侦察器 v.90 
// By Arron@xajh2 4/99
// file: detect.c
// Email: szarron@163.net
// http: szarron.163.net

#include <armor.h>
#include <combat.h>
#include <ansi.h>

inherit HEAD;

string* type = ({
"armor/head",
"armor/neck",
"armor/waist",
"armor/wrists",
"armor/finger",
"armor/hands",
"armor/boots",
//"shield",
});

string* people = ({
"   Ο",//head
"┴",//neck
"└┬┘",//waist
"│",//wrists
"┤",//finger
"│",//hands
"┘  └",//boots
});

string* w_color = ({
"└>"+HIR"Ο"NOR,//head
HIM"┴"NOR,//neck
HIC"└┬┘"NOR,//waist
HIB"│"NOR,//wrists
HIY"┤"NOR +" <-",//finger
HIY"│"NOR,//hands
HIC"┘  └"NOR +" <-",//boots
});

string* wear = ({
"1",
"2",
"3",
"4",
"5",
"6",
"7",
});

string* w = ({
"1",
"2",
"3",
"4",
"5",
"6",
"7",
});

int do_detect(string arg);

void init()
{
        add_action("do_detect","detect");
}

void create()
{
        set_name("战斗侦察器", ({ "fighting detect","detect" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
                set("long", "这是一副战斗力侦察器。\n");
                set("material", "steel");
                set("armor_prop/armor", 1);
        }
        setup();
}

int do_detect(string arg)
{
        object me,ob;
//        string *wear, *w;
        string skill_type,line, w1,w2,w3;
        string c1,c2,c3,c4,c5;
        object weapon, we;
        int attack_points, dodge_points, parry_points;

        me = this_player();

        if( !arg ) return notify_fail("你要侦察什么？\n");

        if (arg == "?") {
                write("战斗侦察器用法：\n");
                write("\t探测对方的实力：detect <id>\n");
                write("\t探测某方向是否有战斗力的人：detect <方向>\n");
                return 1;
                }

        if( !query("equipped") )
                return notify_fail("要装备上才能使用。\n");

        if(!wizardp(me) && arg == me->query("id"))
                return notify_fail("你已经戴上侦察器，不能侦察自己。\n");

        if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");
        else {

        for (int i=0;i<sizeof(type);i++) {
                if (we = ob->query_temp(type[i])) {
                 wear[i]= we ->query("name");
                 wear[i] += HIC"(防御："NOR + BLINK + HIR;
                wear[i] += sprintf("%d",we->query("armor_prop/armor"));
                 wear[i] += NOR + HIC")"NOR;
                 w[i]=w_color[i];
                } else {
                 wear[i] = NOR;
                 w[i]=people[i];
                 }
        }

        c1="┌┬"+w[1]+"┬┐";
        c2="│  │";
        c3=w[2];
        c4="┌┴┐";
        c5="│  │";

        if( ob->query_temp("armor/cloth") ){
                c1=HIW"┌┬"NOR+w[1]+HIW"┬┐"NOR;
                c1 += "<-" + ob->query_temp("armor/cloth")->query("name");
                c1 += HIC"(防御："NOR + BLINK + HIR +
                ob->query_temp("armor/cloth")->query("armor_prop/armor")+ NOR + HIC")"NOR;
                c2=HIW + c2 +NOR;
                c3=HIW+ w[2]+NOR;
                c4=HIW + c4 +NOR;
                c5=HIW + c5 +NOR;
        }

        c2 = w[3] +c2 +w[3];
        c3 = w[5] +c3 +w[5];
        
        if( objectp(weapon = ob->query_temp("weapon")) ) {
                skill_type = weapon->query("skill_type");
                w1 =YEL"┼"NOR;
                w2 =YEL"│"NOR;
                w3 =YEL"│"NOR;
        }else{
                w1 ="├";
                w2 ="  ";
                w3 ="  ";
		skill_type = "unarmed";
        }

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

        message_vision(CYN"“哔哔！”"NOR"$N朝着$n按了下战斗侦察器。\n", me, ob);

        line = "过了一会，液晶镜上显示出：\n";
        line += ob->query("name") + "战斗侦察结果：\n\n";
        line += "\t " + wear[0] +"\n";
        line += "\t "+ w[0] + wear[1]+"\n";
        line += "\t" + c1 + "\n";
        line += "\t" + c2 + wear[3] + "\n";
        line += "\t" + c3 + wear[5] + "\n";
        line += "\t"+w1 + c4 +w[4]+wear[4]+"\n";
        line += "\t"+w2+c5 +"\n";
        line += "\t"+w3+c5+"\n";
        line += "\t  " + w[6] +wear[6]+"\n";
        line += "\n\t另类防具：";

        if( ob->query_temp("armor/0") ){
                line += ob->query_temp("armor/0")->query("name");
                line += HIC"(防御："NOR + BLINK + HIR +
                ob->query_temp("armor/0")->query("armor_prop/armor")+ NOR + HIC")\n"NOR;
                } else
                line += "无\n";
        
        line +="\t战斗武器：";

        if( w2 !="  " ){
                line += weapon->query("name");
                line += HIC"(攻击力："NOR + BLINK + HIR +
                weapon->query("weapon_prop/damage")+ NOR + HIC")\n"NOR;
                } else
                line += "无\n";

        if( ob->query_temp("apply/attack")) {
                line += "\t潜在攻击力：(";
                line += sprintf("%d",ob->query_temp("apply/attack")) +")\n";
                }

        if( ob->query_temp("apply/damage")){
                line += "\t潜在破坏力：(";
                line += sprintf("%d",ob->query_temp("apply/damage")) +")\n";
                }

        if( ob->query_temp("apply/defense")){
                line += "\t潜在防御力：(";
                line += sprintf("%d",ob->query_temp("apply/defense")) +")\n";
                }

        if(ob->query_temp("apply/dodge")){
                line += "\t潜在闪躲值：(";
                line +=ob->query_temp("apply/dodge") +")\n";
                }
                
        if(ob->query_temp("apply/armor")){
                line += "\t潜在防护力：(";
                line +=ob->query_temp("apply/armor") +")\n";
                }

        write(line);

        write(sprintf("\n\t战斗攻击力：" HIW "%d (+%d)" NOR "\n\t战斗防御力：" HIW "%d (+%d)\n\n" NOR,
		attack_points/100 + 1, ob->query_temp("apply/damage"),
                (dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1, ob->query_temp("apply/armor")));

                }
        
        return 1;
}
