import os

''' Class responsible for management of categories. '''


class Categories:

    def __init__(self):
        self.__categories_holder = {}  # dictionary for all categories
        self.__selected_category = ''  # current selected category

    def add_category(self):
        ''' Input category name.
        Check that category is unique.
        Add category to dictionary and generate new key.
        '''
        os.system('cls||clear')
        category_name = str(input('Name of category: '))
        if category_name.strip() != '':
            if self.check_existing_the_same_category(category_name):
                if bool(self.__categories_holder) == False:
                    self.__categories_holder[1] = category_name
                else:
                    last_category = 1
                    for key in self.__categories_holder:
                        if key > last_category:
                            last_category = key
                    self.__categories_holder[last_category + 1] = category_name

    def check_existing_the_same_category(self, new_category):
        ''' Return: Flase - category is not unique
        Return True - category is unique
        '''
        for key in self.__categories_holder:
            if self.__categories_holder[key] == new_category:
                return False
        return True

    def delete_category(self, category_name):
        ''' Check if given category name is in dictionary.
            Delete this category.
            Update all keys in increasing order.
            Return
        '''
        for category_key in self.__categories_holder:
            if self.__categories_holder[category_key] == category_name:
                self.__categories_holder.pop(category_key)
                self.update_categories_holder()
                return

    def update_categories_holder(self):
        ''' Copy values of dictionary to tmp dictionary with keys in increasing order.
        Copy tmp dictionary to dictionary.
        Clear tmp dictionary.
        '''
        tmp_dictionary = {}
        counter = 1

        for key in self.__categories_holder:
            tmp_dictionary[counter] = self.__categories_holder.get(key)
            counter += 1

        self.__categories_holder = tmp_dictionary.copy()
        tmp_dictionary.clear()

    def print_categories(self):
        ''' Print keys and values converted to str '''
        if(self.__categories_holder):
            for category_key in self.__categories_holder:
                print(str(category_key) + ". " +
                      str(self.__categories_holder.get(category_key)))

    def select_category(self):
        ''' Print categories.
        Input category number.
        Check that category with selected number exists.
        Return category number.
        '''
        os.system('cls||clear')
        self.__selected_category = 0
        self.print_categories()
        try:
            if(self.__categories_holder):
                print()
                tmp = int(input("Select category: "))
                for category_key in self.__categories_holder:
                    if(tmp == category_key):
                        self.__selected_category = self.__categories_holder[tmp]
            else:
                print("There are no categories.")
        except ValueError:
            print("\nExpected a number")

    def get_selected_category(self):
        ''' Return selected category number. '''
        return self.__selected_category

    def get_all_categories(self):
        ''' Return dictionary. '''
        return self.__categories_holder

    def set_categories(self, categories):
        ''' Set dictionary '''
        self.__categories_holder = categories
