import os

''' Class responsible for management of tasks. '''


class Tasks:
    def __init__(self):
        self.__tasks_holder = {}  # dictionary for tasks.

    def add_task(self, category_name):
        '''Param: name of category.
        Input task name.
        Set name of category as value to task name key.
        '''
        os.system('cls||clear')
        self.__tasks_holder[str(input("Task name: "))] = category_name

    def show_tasks(self, category_name):
        '''Param: name of category.
        Print all tasks where value of task name equals name of category.
        '''
        counter = 1
        if(self.__tasks_holder):
            for task in self.__tasks_holder:
                if(self.__tasks_holder[task] == category_name):
                    print(str(counter) + '. ' + str(task))
                    counter += 1

    def delete_task(self, category_name):
        '''Param: name of category.
        Input task name.
        Delete task if exists and where value of task name equals name of category.
        '''
        print()
        tmp = str(input("Task name: "))
        for task in self.__tasks_holder:
            if self.__tasks_holder[task] == category_name:
                if tmp == task:
                    self.__tasks_holder.pop(task)
                    return

    def delete_tasks_by_delete_category(self, category_name):
        '''Param: name of category.
        Check that value of task equals name of category.
        Add correct task to tmp list.
        Iterate in tmp list and delete tasks from dictionary.
        '''
        tasks_to_delete = []
        for task in self.__tasks_holder:
            if self.__tasks_holder[task] == category_name:
                tasks_to_delete.append(task)
        for task in tasks_to_delete:
            self.__tasks_holder.pop(task)

    def get_all_tasks(self):
        ''' Return dictionary. '''
        return self.__tasks_holder

    def set_tasks(self, tasks):
        ''' Set dictionary. '''
        self.__tasks_holder = tasks
