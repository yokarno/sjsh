e_vision ("$N伸出手，鬼鬼祟祟地想偷什么东西。\n",who);
  call_out("no_steal",2,who,me);
  return 1;
}

void no_steal(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N眼露凶光，看样子动了杀机！\n",who);
  call_out("no_kill",2,who,me);
  return 1;
}

void no_kill(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

void die()
{
  fully_recover (this_object());
}

void unconcious()
{
  fully_recover (this_object());
}

