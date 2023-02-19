#include "manager.h"
#include "pages.h"

manager_t manager;

void manager_init()
{
    // manager.count =  ;
    // if (manager.count==0)
    //     return;
    manager.index = 0;
    manager.cur = pages[manager.index];
    manager.cur->init(NULL);
    manager.cur->enter(NULL);




}



//用于处理相关任务事件，可以在ch582的tmos中循环触发调用
void manager_event()
{
    if (manager.busy == false)
    {
        manager.cur->event(NULL);

    }
    else
    {

    }
}


void manager_startEvent(unsigned long x)
{
    tmos_start_reload_task(show_TaskID, SHOW_MANAGER_EVT_EVENT, MS1_TO_SYSTEM_TIME(x));
}

void manager_startEventOnce(unsigned long x)
{
    tmos_start_task(show_TaskID, SHOW_MANAGER_EVT_EVENT, MS1_TO_SYSTEM_TIME(x));
}

void manager_stopEvent()
{
    tmos_stop_task(show_TaskID, SHOW_MANAGER_EVT_EVENT);
    tmos_clear_event(show_TaskID, SHOW_MANAGER_EVT_EVENT);
}

void manager_loop()
{
    if (manager.busy == false)
    {
        manager.cur->loop(NULL);

    }
    else
    {

    }
}

void manager_switch()
{
}
void manager_switchToChild()
{
    //
    manager.cur->exit(NULL);

    manager.cur = pages[manager.index];

    manager.cur->init(NULL);
    manager.cur->enter(NULL);
}
void manager_switchToParent()
{
    manager.cur->exit(NULL);

    //修改当前页面
    manager.cur = pages[0];

    manager.cur->init(NULL);
    manager.cur->enter(NULL);
}

void manager_switchToNext()
{
    //old exit
    // manager.cur->exit;
    // if(manager.index<(manager.count-1))
    // {
    //     manager.index ++;
    // }
    // else
    // {
    //     manager.index=0;
    // }

    //new enter
    manager.cur = pages[manager.index];

    manager.cur->init(NULL);
    manager.cur->enter(NULL);
}

void manager_setBusy(bool state)
{
    manager.busy = state;
}

bool manager_getBusy()
{
    return manager.busy;
}
