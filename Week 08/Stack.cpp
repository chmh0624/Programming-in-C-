class stack: private container
{
    private:
        int top;
    public:
        stack(){top = 0; len = 1; box = new int[len];}
        stack(int l){len = l; top = 0; box = new int[len];}
        stack(const stack &a)
        {
            this -> len = a.len;
            box = new int[len];
            for (int i=0; i<len; i++)
                box[i] = a.box[i];
            this -> top = a.top;
        }
        bool push(int data)
        {
            if (top == len)
            {
                return false;
            }
            else
            {
                box[top++] = data;
                return true;
            }
        }
        int *pop()
        {
            if (top <= 0)
                return NULL;
            int *tmp = new int;
            *tmp = box[top-1];
            top --;
            return tmp;
        }
        bool increase()
        {
            return reallocate(len*2);
        }
        int getLen()
        {
            return len;
        }
};
