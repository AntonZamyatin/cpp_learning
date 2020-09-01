#include <set>
#include <vector>

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const{
      return devs.at(person);
  }
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person){
      if (persons.count(person)){
        devs[person][TaskStatus::NEW] += 1;
      }
      else {
          persons.insert(person);
          devs[person] = {{TaskStatus::NEW, 1}};
      }
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
             const string& person, int task_count){
        TasksInfo next = devs[person];
        TasksInfo updated;
        TasksInfo untouched = devs[person];
        untouched.erase(TaskStatus::DONE);

        for (int i = 0; i < 3; ++i){
            if (task_count == 0) break;
            TaskStatus st = static_cast<TaskStatus>(i);
            TaskStatus st_next = static_cast<TaskStatus>(i+1);
            if (devs[person].count(st) && (task_count >= devs[person][st])){
                updated[st_next] = devs[person][st];
                next[st] -= devs[person][st];
                if (next[st] == 0)
                    next.erase(st);
                if (next.count(st_next))
                    next[st_next] += devs[person][st];
                else
                    next[st_next] = devs[person][st];
                untouched.erase(st);
                task_count -= devs[person][st];
            } else if (devs[person].count(st) && (task_count < devs[person][st])){
                updated[st_next] = task_count;
                untouched[st] -= task_count;
                if (next.count(st_next))
                    next[st_next] += task_count;
                else
                    next[st_next] = task_count;
                next[st] -= task_count;
                break;
            }
        }
        devs[person] = next;
        return make_tuple(updated, untouched);
    }

private:
    set<string> persons;
    map<string, TasksInfo> devs;
};
