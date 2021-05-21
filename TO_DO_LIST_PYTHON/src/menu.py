import os

''' Class responsible for displaying messages to user and management selected option '''


class Menu():
    def __init__(self):
        self.__selected_option = 0

    def show_main_menu_options(self):
        ''' Print main menu options. '''
        os.system('cls||clear')
        print("Main Menu\n")
        print("1. Add task")
        print("2. Show tasks")
        print("3. Delete task")
        print("4. Quit")

    def show_add_menu_options(self):
        ''' Print add menu options. '''
        os.system('cls||clear')
        print("Add menu\n")
        print("1. Select category")
        print("2. Add Category")
        print("3. back")

    def show_show_menu_options(self):
        ''' Print show menu options. '''
        os.system('cls||clear')
        print("Show menu\n")
        print("1. Select category")
        print("2. back")

    def show_delete_menu_options(self):
        ''' Print delete menu options. '''
        os.system('cls||clear')
        print("Delete menu\n")
        print("1. Select category")
        print("2. delete category")
        print("3. back")

    def show_add_task_menu_options(self):
        ''' Print add task menu options. '''
        os.system('cls||clear')
        print("Add menu\n")
        print("1. Add task")
        print("2. back")

    def show_back_option(self):
        ''' Print back option. '''
        print("\n1. back")

    def show_quit_message(self):
        ''' Print quit message. '''
        os.system('cls||clear')
        print('Data has been saved')
        print('Have a nice day!')

    def select_option(self):
        ''' Set selected option. '''
        try:
            print()
            self.__selected_option = int(input("Choose: "))
        except ValueError:
            print("\nExpected a number")

    def get_selected_option(self):
        ''' Return: selected option. '''
        return self.__selected_option
