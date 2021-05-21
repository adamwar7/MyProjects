import dsm

''' Class represents state machine. '''


class OrderFSM(dsm.StateMachine):
    class Meta:
        transitions = (
            # Starting state.
            ('loading_data', 1, 'menu'),

            # "Main menu" states.
            ('menu', 1, 'add'),
            ('menu', 2, 'show'),
            ('menu', 3, 'delete'),
            ('menu', 4, 'quit'),  # "quit" ending state.

            # "Add menu" states.
            ('add', 1, 'select_category_to_add_task'),
            ('add', 2, 'add_category'),
            ('add', 3, 'menu'),

            # "Select category to add" states.
            ('select_category_to_add_task', 1, 'add_task'),
            ('select_category_to_add_task', 2, 'add'),

            #  "Add category" state.
            ('add_category', 1, 'add'),

            # "Add task" state.
            ('add_task', 1, 'add'),

            #  "Show menu" states.
            ('show', 1, 'select_category_to_show_tasks'),
            ('show', 2, 'menu'),

            # "Select category to show tasks" state.
            ('select_category_to_show_tasks', 1, 'show'),

            # "Delete" states.
            ('delete', 1, 'select_category_to_delete_task'),
            ('delete', 2, 'delete_category'),
            ('delete', 3, 'menu'),

            # "Select category to delete task" state.
            ('select_category_to_delete_task', 1, 'delete'),

            # "Delete category" state.
            ('delete_category', 1, 'delete')
        )
        initial = 'loading_data'  # starting state
