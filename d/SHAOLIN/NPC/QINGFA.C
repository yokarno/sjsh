// qingfa.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_for_join();

void create()
{
        set_name("�巨����", ({
		"qingfa biqiu",
		"qingfa",
		"biqiu",
	}));

        set("gender", "����");
        set("title", HIB"���������ɮ"NOR);
        set("long",
		"����һλ���ǿ����׳��ɮ�ˣ������û���������ȫ���ƺ��̺�\n"
		"���������������һϮ�ײ��ڱ����ģ��ƺ��������ա�\n"
	);
	create_family("������", 4, "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "bonze");

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

        set("atman", 2000);
        set("max_atman", 2000);

        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 50);

        set("mana", 1200);
        set("max_mana", 1200);

        set("combat_exp", 800000);
        set("daoxing", 850000);

	set("inquiry", ([
		"���" : (: ask_for_join :),
		"����" : (: ask_for_join :),
		]) );

        set_skill("sword", 80);
        set_skill("unarmed", 80);
        set_skill("force", 100);
        set_skill("dodge", 80);
        set_skill("literate", 180);
        set_skill("parry", 80);
        set_skill("spells", 100);
        set_skill("zui-gun", 80);
        set_skill("shaolin-shenfa", 80);
        set_skill("banruo-zhang", 80);
        set_skill("jingang-leg", 80);
        set_skill("stick", 80);
        set_skill("yijinjing", 100);
        set_skill("chanzong", 100);

        set_skill("shaolin-sword", 80);
        map_skill("force", "yijinjing");
        map_skill("sword", "shaolin-sword");
        map_skill("spells", "chanzong");
        map_skill("unarmed", "banruo-zhang");
        map_skill("stick", "zui-gun");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "jingang-leg");

	setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
}


string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("married"))
		return "�����ӷ�ʩ�����˼�ͥ���ۣ��������Ǳ�����\n";
	if( (string)me->query("bonze/class")=="bonze" )
                return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ����Ŀ������Ц��\n";
	if( (string)me->query("gender") != "����" )
                return "�����ӷ����գ����գ�Ůʩ������������ҷ𣬿�ȥ�Ϻ�����ɽ�ܽ䡣\n";
	if( me->query("bonze/justonetime"))
		return "ʩ�����ѻ��ף��ֺο��ٴγ��ң�\n";
	me->set_temp("pending/join_bonze", 1);
	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
        string *prename =
	 ({ "��", "��", "��", "Բ", "��", "��", "��" });
	string name, new_name;

	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
	message_vision(	HIC "$N˫�ֺ�ʮ�����������ع���������\n\n" + 
			"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n" NOR,
		this_player(), this_object() );
        name = this_player()->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say �ӽ�������ķ�������" + new_name + "��");
	command("smile");
	this_player()->delete_temp("pending/join_bonze");
	this_player()->set("name", new_name);
	this_player()->set("bonze/class", "bonze");
	this_player()->set("bonze/justonetime", 1);
	this_player()->set("bonze/old_name", name);
        this_player()->set("class", "bonze");
	this_player()->save();
	return 1;
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "����" )
	{
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}

	if( (string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶɮ�������������׼ҵ��ӡ��ˡ�");
	}
	command("say �����ӷ����գ����գ�");
	command("recruit " + ob->query("id"));
        ob->set("title", HIB"��ɽ���������ŵ���"NOR);
         ob->set("class", "bonze");
}
