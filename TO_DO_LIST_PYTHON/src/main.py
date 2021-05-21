import menu
import categories
import tasks
import order
import file_json

''' Main file '''


def main():
    fsm = order.OrderFSM()
    _menu = menu.Menu()
    _Categories = categories.Categories()
    _tasks = tasks.Tasks()
    _file_support = file_json.File_Support()
    while True:

        if fsm.state == 'loading_data':
            _Categories.set_categories(
                _file_support.load_from_json_categories())
            _tasks.set_tasks(_file_support.load_from_json_tasks())
            fsm.process(1)

        if fsm.state == 'menu':
            _menu.show_main_menu_options()
            _menu.select_option()
            if 0 < _menu.get_selected_option() < 5:
                fsm.process(_menu.get_selected_option())

        elif fsm.state == 'add':
            _menu.show_add_menu_options()
            _menu.select_option()
            if 0 < _menu.get_selected_option() < 4:
                fsm.process(_menu.get_selected_option())

        elif fsm.state == 'select_category_to_add_task':
            _Categories.select_category()
            if _Categories.get_selected_category():
                _menu.show_add_task_menu_options()
                _menu.select_option()
                if 0 < _menu.get_selected_option() < 3:
                    fsm.process(_menu.get_selected_option())
            else:
                _menu.show_select_catergories_menu()
                _menu.select_option()
                if 1 < _menu.get_selected_option() + 1 < 3:
                    fsm.process(_menu.get_selected_option() + 1)

        elif fsm.state == 'add_category':
            _Categories.add_category()
            fsm.process(1)

        elif fsm.state == 'add_task':
            _tasks.add_task(_Categories.get_selected_category())
            fsm.process(1)

        elif fsm.state == 'show':
            _menu.show_show_menu_options()
            _menu.select_option()
            if 0 < _menu.get_selected_option() < 3:
                fsm.process(_menu.get_selected_option())

        elif fsm.state == 'select_category_to_show_tasks':
            _Categories.select_category()
            _tasks.show_tasks(_Categories.get_selected_category())
            _menu.show_back_option()
            _menu.select_option()
            if 1 == _menu.get_selected_option():
                fsm.process(_menu.get_selected_option())

        elif fsm.state == 'delete':
            _menu.show_delete_menu_options()
            _menu.select_option()
            if 0 < _menu.get_selected_option() < 4:
                fsm.process(_menu.get_selected_option())

        elif fsm.state == 'select_category_to_delete_task':
            _Categories.select_category()
            if _Categories.get_selected_category():
                _tasks.show_tasks(_Categories.get_selected_category())
                _tasks.delete_task(_Categories.get_selected_category())
            _menu.show_back_option()
            _menu.select_option()
            if 0 < _menu.get_selected_option() < 2:
                fsm.process(_menu.get_selected_option())

        elif fsm.state == 'delete_category':
            _Categories.select_category()
            if _Categories.get_selected_category():
                _tasks.delete_tasks_by_delete_category(
                    _Categories.get_selected_category())
                _Categories.delete_category(
                    _Categories.get_selected_category())
            _menu.show_back_option()
            _menu.select_option()
            if 0 < _menu.get_selected_option() < 2:
                fsm.process(_menu.get_selected_option())

        elif fsm.state == 'quit':
            _menu.show_quit_message()
            _file_support.save_categories_and_tasks_to_json(
                _Categories.get_all_categories(), _tasks.get_all_tasks())
            return


if __name__ == "__main__":
    main()
