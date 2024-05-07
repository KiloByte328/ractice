#include <iostream>

class link_list
{
    public:
    int value;
    link_list *next;
    int list_add(int new_value)
    {
        link_list *temp = this;
        for(;temp->next != NULL;)
        {
            temp = temp->next;
        }
        temp->next = new link_list;
        temp = temp->next;
        temp->value = new_value;
        temp->next = NULL;
        return 0;
    }
    link_list *list_search(int search_value)
    {
        link_list *fst = this;
        link_list *temp = this;
        for(;temp->value != value;)
        {
            temp = temp->next;
            if(temp->next == NULL)
        {
            return fst;
        }
        else
            return temp;
        }
    }
    int list_delete(int deleted_value)
    {
        link_list *temp = this;
        for(;temp->next->value != deleted_value;)
        {
            temp = temp->next;
            if(temp->next == NULL && temp->value != deleted_value)
        {
            return -1;
        }
        }
            delete temp->next;
            temp->next = NULL;
        return 0;
    }
    int list_delete(int deleted_value, int new_delete_value)
    {
        link_list *temp = this;
        for(;temp->next->value != deleted_value;)
        {
            temp = temp->next;
            if(temp->next == NULL && temp->value != deleted_value)
            {
                return -1;
            }
            new_delete_value = temp->value;
            }
            delete temp->next;
            temp->next = NULL;
        return 0;
    }
    
    void print()
    {
        link_list *temp = this;
        for(;temp->next != NULL;)
        {
            std::cout << "value is: " << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "value is: " << temp->value << " ";
        std::cout <<std::endl;
        return;
    }
~link_list()
        {
            link_list **temp;
            temp[0] = this;
            for(int count = 1;temp[0]->next != NULL;)
            {
                temp[count] = temp[0];
                temp[0] = temp[0]->next;
                count++;
            }
            delete[] temp;
            delete temp;
        }
    
};

class ll_stack
{
    public:
    int last_value = 0;
    link_list *stack;
    void s_push(int new_value)
    {
        last_value = new_value;
        stack->list_add(new_value);
    }
    void s_pop()
    {
        if(stack->next == NULL)
        {   
            std::cout << "can't delete last element" << std::endl;
            return;
        }
        stack->list_delete(last_value);
    }
    ll_stack()
    {
        this->stack = new link_list;
        this->stack->next = NULL;
        this->stack->value = 0;
    }
    void print()
    {
        this->stack->print();
    }
    ~ll_stack()
    {
       this->stack->~link_list();
       delete this->stack;
    }
};

int main()
{
    ll_stack *staack = new ll_stack;
    int interact = 1;
    while (interact != 0)
    {
        std::cout << "stack online now stack is: ";
        staack->print();
        std::cout << "print interact with stack 0 - off the programm, 1 - push 2 - pop: ";
        std::cin >> interact;
        switch (interact)
        {
        case 1:
        int value;
            std::cout << "enter a new value you want to push to stack: ";
            int tmep_v;
            std::cin >> tmep_v;
            //scanf("%d", tmep_v);
            if(tmep_v >= INT32_MAX || tmep_v <= INT32_MIN)
            {
                std::cout << "number not supported" << std::endl;
            }
            else
            {
            value = tmep_v;
            staack->s_push(value);
            break;
            }
            break;
        case 2:
            std::cout << "pop element " << staack->last_value << "... ";
            staack->s_pop();
            break;
        case 0:
            std::cout << "shutting down...";
            break;
        default:
        std::cout << "cannot defined operatoin, try again";
            break;
        }
        std::cout <<std::endl;
    }
    staack->~ll_stack();
    return 0;
}