/**
 * Date: 2020-10-06
 * Author: MambaZhang
 **/
typedef struct {
    int top;
    int *data;
    int *min_data;
} MinStack;
#define MAX_PUSH_NUM    1024
/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *min_stack = (MinStack *)malloc(sizeof(MinStack));
    if (NULL == min_stack)
    {
        return NULL;
    }
    memset(min_stack, 0, sizeof(MinStack));
    min_stack->data = (int *)malloc(MAX_PUSH_NUM*sizeof(int));
    if (NULL == min_stack->data)
    {
        free(min_stack);
        return NULL;
    }
    min_stack->min_data = (int *)malloc(MAX_PUSH_NUM*sizeof(int));
    if (NULL == min_stack->data)
    {
        free(min_stack);
        free(min_stack->data);
        return NULL;
    }
    min_stack->top = -1;
    memset(min_stack->data, 0, MAX_PUSH_NUM*sizeof(int));
    memset(min_stack->min_data, 0, MAX_PUSH_NUM*sizeof(int));
    return min_stack;
}

void minStackPush(MinStack* obj, int x) {
    if (NULL == obj || obj->top>=(MAX_PUSH_NUM-1))
    {
        return;
    }
    obj->top++;
    obj->data[obj->top] = x;
    if (obj->top == 0)
    {
        obj->min_data[obj->top] = x;
    }
    else
    {
        obj->min_data[obj->top] = obj->min_data[obj->top-1] <= x ? obj->min_data[obj->top-1] : x;
    }
}

void minStackPop(MinStack* obj) {
    if (NULL == obj || -1 == obj->top )
    {
        return;
    }
    obj->data[obj->top] = 0;
    obj->min_data[obj->top] = 0;
    obj->top--;
}

int minStackTop(MinStack* obj) {
    if (NULL == obj || -1 == obj->top)
    {
        return -1;
    }
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if (NULL == obj || -1 == obj->top)
    {
        return -1;
    }
    return obj->min_data[obj->top];
}

void minStackFree(MinStack* obj) {
    if (NULL == obj || -1 == obj->top)
    {
        return;
    }
    if (obj->data != NULL)
    {
        free(obj->data);
        obj->data = NULL;
    }
    if (obj->min_data != NULL)
    {
        free(obj->min_data);
        obj->min_data = NULL;
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/