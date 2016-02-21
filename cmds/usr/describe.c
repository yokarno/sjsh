// describe.c

#include "ansi.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *txt;

	if( !arg ) return notify_fail("ָ���ʽ��describe <����>\n");

	txt = explode(arg, "\n");
        if( (wizardp(me) && sizeof(txt) > 10000) || sizeof(txt) > 10000 )
		return notify_fail("�뽫�����Լ������������ڰ������ڡ�\n");

	arg = implode(txt, "\n") + "\n";

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

	me->set("long", arg + NOR);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��describe <����>

���ָ�������趨�������� look ָ���ʱ�������������ͨ������
����������һ��ʱ������ to describe �ķ�ʽ�����롣
TEXT
	);
	return 1;
}