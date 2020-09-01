#include <map>
#include <string>
#include <tuple>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

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

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}