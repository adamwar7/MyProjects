import json

''' Class responsible for file support. '''


class File_Support:

    def keystoint(self, x):
        ''' Convert keys in dictionary from str to int. '''
        return {int(k): v for k, v in x.items()}

    def save_categories_and_tasks_to_json(self, categories, tasks):
        ''' Save dictionaries to json files. '''
        self.save_categories_to_json(categories)
        self.save_tasks_to_json(tasks)

    def save_categories_to_json(self, categories):
        ''' Save dictionary with categories to json file. '''
        with open("categories.json", 'w') as outfile:
            json.dump(categories, outfile, sort_keys=True)

    def save_tasks_to_json(self, tasks):
        ''' Save dictionary with tasks to json file. '''
        with open("tasks.json", 'w') as outfile:
            json.dump(tasks, outfile, sort_keys=True)

    def load_from_json_categories(self):
        ''' Load from json file dictionary with categories.
        Convert keys to int.
        Return dictionary.
        '''
        categories = {}
        try:
            with open("categories.json", 'r') as outfile:
                categories = json.load(outfile, object_hook=self.keystoint)
        except FileNotFoundError:
            print()
        finally:
            return categories

    def load_from_json_tasks(self):
        ''' Load from json file dictionary with tasks.
        Return dictionary.
        '''
        tasks = {}
        try:
            with open("tasks.json", 'r') as outfile:
                tasks = json.load(outfile)
        except FileNotFoundError:
            print()
        finally:
            return tasks
