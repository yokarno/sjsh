#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int sort_user(object,object);

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string str, *option, fname = "";
        object *list, *ob;
        int i, ppl_cnt, cnt, count, wcnt = 0;
        int opt_long, opt_id, opt_wiz, opt_party;

        if( arg ) {
                string verbose="", rwho="";
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-l": opt_long = 1;verbose+="-l "; break;
                                case "-i": opt_id = 1; verbose+="-i ";break;
                                case "-w": opt_wiz = 1; verbose+="-w ";break;
                                case "-f":
                                case "-p": opt_party = 1; verbose+="-p ";break;
                                default:

                                        if( option[i][0]=='@' ) {
                                        
                                                rwho = option[i][1..sizeof(option[i])];
                                                if(strlen(rwho)>0) {
                   
                   RWHO_Q->send_rwho_q(rwho, me, verbose);
                   write("��·ѶϢ���ͳ������Ժ�\n");
                   return 1;
                }
                                        
                                        }

                                 return notify_fail("ָ���ʽ��who [-l|-i|-w|-p]\n");
                        
        }
}
        if( opt_long && !wizardp(me)) {
                if( (int)me->query("sen") < 50 )
                        return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
                me->receive_damage("sen", 10);
        }

    str = "�� " + MUD_NAME + "\n";
        str += "��������������������������������������������������������������������������������\n";
        ob = filter_array(objects(), (: userp :));
        if (opt_party)
                ob = filter_array(ob, (: $1->query("family/family_name") ==
                        $2->query("family/family_name") :), me);
        list = sort_array(ob, (: sort_user :));
        ppl_cnt = 0;
        cnt = 0;
        if( opt_long || opt_wiz ) {
                i = sizeof(list);
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( me&&!me->visible(list[i]) ) continue;
                        if( remote && list[i]->query("env/invisibility")  ) continue;
            if( opt_wiz && !wiz_level(list[i]) ) continue;
                        if (interactive(list[i])) ppl_cnt++;
                        else cnt++;
                        str = sprintf("%s%12s%s%s\n",
                                str,
                                RANK_D->query_rank(list[i]),
                                interactive(list[i])?(query_idle(list[i]) > 120?HIM "+" NOR:" "):HIG "*" NOR,
                                list[i]->short(1)
                        );
                }
        } else {
                i = sizeof(list);
                count = 0;
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( me&&!me->visible(list[i]) ) continue;
                        if( remote &&
                        list[i]->query("env/invisibility"))
                                continue;
                        if (!wiz_level(list[i]) && fname != list[i]->query("family/family_name")) {
                            fname = list[i]->query("family/family_name");
                            if (count % 7) str += "\n";
                            str += sprintf(GRN "%-15s" NOR, (fname?fname:"��ͨ����") + "��");
                            count = 1;
                        }
                        if (!wcnt && wiz_level(list[i])) {
                            if (count % 7) str += "\n";
                            str += sprintf(HIY "%-15s" NOR, "��Ϸ����Ա��");
                            wcnt = 1;
                            count = 1;
                        }
                        if (!(count%7)) {
                                count++;
                                str += "               ";
                        }
                        str = sprintf("%s%s%-9s"NOR"%s",
                                str,
                                interactive(list[i])?(query_idle(list[i]) > 120?HIM "+":" "):HIG "*",
                                opt_id?capitalize(list[i]->query("id")): list[i]->name(1),
                                ++count%7 ? "": "\n"
                        );
                        if (interactive(list[i])) ppl_cnt++;
                        else cnt++;
                }
                if( count%7 ) str += "\n";
        }
        str += "��������������������������������������������������������������������������������\n";
        str = sprintf("%s�� %d λ��������У�%d λ��Ҷ����У�ϵͳ������%s\n* ��ʾ������  + ��ʾ������", str, ppl_cnt,
                cnt, query_load_average());

        if( remote ) return str;

        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        string name1, name2;

        reset_eval_cost();
        if( wiz_level(ob1) != wiz_level(ob2) )
                return wiz_level(ob2)
                        - wiz_level(ob1);
        
        name1 = ob1->query("family/family_name");
        name2 = ob2->query("family/family_name");

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP
ָ���ʽ : who [-l|-i|-w|-p]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г��ϳ���ѶϢ��
-i ֻ�г���ҵ�Ӣ�Ĵ��š�
-p ֻ�г�ͬ�ŵ���ҡ�
-w ֻ�г��������е���ʦ��

���ָ� finger
HELP
        );
        return 1;
}
